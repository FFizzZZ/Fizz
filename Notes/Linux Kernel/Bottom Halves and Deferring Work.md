# Bottom Halves and Deferring Work

### Softirqs
* Softirqs are statically allocated at compile time. Unlike, you cannot dynamically register and destroy softirqs.
* A softirq never preempts another softirq. The only event that can preempt a softirq is an interrupt handler. Another softirq - even the same one - can run on another processor, however.
* A registered softirq must be marked before it will execute. This is called *raising the softirq*. Usually, an interrupt handler marks its softirq for execution before returning.
###### Pending softirqs are checked for and executed in the following places:
    1. In the return from hardware interrupt code path.
    2. In the ksoftirqd kernel thread.
    3. In any code that explicitly checks for and executes pending softirqs, such as the networking subsystem.
* The softirq handlers run with interrupts enabled and cannot sleep. The raison detre to softirqs is scalability. If you do not need to scale to infinitely many processors, then use a tasklet. Tasklets are essentially softirqs in which multiple instances of the same handler cannot run concurrently on multiple processors.

```
u32 pending;

pending = local_softirq_pending();
if (pending) {
    struct softirq_action *h;
    
    /* retset the pending bitmask, actually with local interrupts disabled but omitted here. */
    set_softirq_pending(0);
    
    h = softirq_vec;
    do {
        if (pending & 1)
            h->action(h);
        h++;
        pending >>= 1;
    } while (pending);
}
```

### Tasklets
* Tasklets are implemented on top of softirqs, they are softirqs, represented by two softirqs: HI_SOFTIRQ and TASKLET_SOFTIRQ.
* Scheduled tasklets (the equivalent of raised softirqs) are stored in two per-processors structures: *tasklet_vec* (for regular tasklets) and *tasklet_hi_vec* (for higher-priority tasklets).
###### Let's Look at the steps tasklet_schedule() undertakes:
        1. Check whether the tasklet's state is TASKLET_STATE_SCHED. If it is, the tasklet is already scheduled to run and the function can immediately return.
        2. Call __tasklet_schedule().
        3. Save the state of the interrupt system, and then disable local interrupts. This ensures tah nothing on this processor will mess with the tasklet code while tasklet_schedule() is manipulating the tasklets.
        4. Add the tasklet to be scheduled to the head of the tasklet_vec or tasklet_hi_vec linked list, which is unique to each processor in the system.
        5. Raise the TASKLET_SOFTIRQ or HI_SOFTIRQ softirq, so do_softirq() executes this tasklet in the near future.
        6. Restore interrupts to their previous state and return.

###### tasklet_action() and tasklet_hi_action(), are the heart of tasklet processing. Let’s look at the steps these handlers perform:
        1. Disable local interrupt delivery (there is no need to first save their state because the code here is always called as a softirq handler and interrupts are always enabled) and retrieve the tasklet_vec or tasklet_hi_vec list for this processor.
        2. Clear the list for this processor by setting it equal to NULL.
        3. Enable local interrupt delivery.Again, there is no need to restore them to their previous state because this function knows that they were always originally enabled.
        4. Loop over each pending tasklet in the retrieved list.
        5. If this is a multiprocessing machine, check whether the tasklet is running on another processor by checking the TASKLET_STATE_RUN flag. If it is currently running, do not execute it now and skip to the next pending tasklet. (Recall that only one tasklet of a given type may run concurrently.)
        6. If the tasklet is not currently running, set the TASKLET_STATE_RUN flag, so another processor will not run it.
        7. Check for a zero count value, to ensure that the tasklet is not disabled. If the tasklet is disabled, skip it and go to the next pending tasklet.
        8. We now know that the tasklet is not running elsewhere, is marked as running so it will not start running elsewhere, and has a zero count value. Run the tasklet handler.
        9. After the tasklet runs, clear the TASKLET_STATE_RUN flag in the tasklet’s state field.
        10. Repeat for the next pending tasklet, until there are no more scheduled tasklets waiting to run.

### ksoftirqd
* The solution ultimately implemented in the kernel is to **not** immediately process reactivated softirqs. Instead, if the number of softirqs grows excessive, the kernel wakes up a family of kernel threads to handle the load. The kernel threads run with the lowest possible priority (nice value of 19), which ensures they do not run in lieu of anything important.
* There is one thread per processor.
```
for (;;) {
    if (!softirq_pending(cpu))
        schedule();
    
    set_current_state(TASK_RUNNING);
    
    while (softirq_pending(cpu)) {
        do_softirq();
        if (need_resched())
            schedule();
    }
    
    set_current_state(TASK_INTERRUPTIBLE);
}
```
* Note that it does this repeatedly to handle any reactivated softirqs. The softirq kernel threads are awakened whenever do_softirq() detects an executed kernel thread reactivating itself.


### Work Queues
* Work queues defer work into a kernel thread - this bottom half always runs in process context. Normally, it is easy to decide between using work queues and softirqs. If the deferred work needs to sleep, work queues are used.

###### Let's look at the heart of worker_thread(), simplified:
```
for (;;) {
    prepare_to_wait(&cwq->more_work, &wait, TASK_INTERRUPTIBLE);
    if (list_empty(&cwq->worklist)
        schedule();
    finish_wait(&cwq->more_work, &wait);
    run_workqueue(cwq);
}
```

###### The function run_workqueue(), in turn, actually performs the deferred work:
```
while (!list_empty(&cwq->worklist)) {
    struct work_struct *work;
    work_func_t f;
    void *data;
    
    work = list_entry(cwq->worklist.next, struct work_struct, entry);
    f = work->func;
    list_del_init(cwq->worklist.next);
    work_clear_pending(work);
    f(work);
}
```
