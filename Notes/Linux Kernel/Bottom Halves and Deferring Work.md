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
