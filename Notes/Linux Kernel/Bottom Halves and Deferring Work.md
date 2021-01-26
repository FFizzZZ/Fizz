# Bottom Halves and Deferring Work

### Softirqs
* Softirqs are statically allocated at compile time. Unlike, you cannot dynamically register and destroy softirqs.
* A softirq never preempts another softirq. The only event that can preempt a softirq is an interrupt handler. Another softirq - even the same one - can run on another processor, however.
* A registered softirq must be marked before it will execute. This is called *raising the softirq*. Usually, an interrupt handler marks its softirq for execution before returning.
###### Pending softirqs are checked for and executed in the following places:
    1. In the return from hardware interrupt code path.
    2. In the ksoftirqd kernel thread.
    3. In any code that explicitly checks for and executes pending softirqs, such as the networking subsytem.
* The softirq handlers run with interrupts enabled and cannot sleep. The raison detre to softirqs is scalability. If you do not need to scale to infinitely many processors, then use a tasklet. Tasklets are essentially softirqs in which multiple instances of the same handler cannot run concurrently on multiple processors.
