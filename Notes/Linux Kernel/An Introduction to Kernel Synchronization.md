# An Introduction to Kernel Synchronization

### Critical Regions and Race Conditions
* Code paths that access and manipulate shared data are called **critical regions** (also called critical sections).


### Locking
* **pseudo-concurrency**: two things do not actually happen at the same time but interleave with each other such that they might as well.

* **true concurrency**: If you have a symmetrical multiprocessing machine, two processes can actually be executed in a critical region at the exact same time.
* **Cause**
  1. *Interrupts* - An interrupt can occur asynchronously at almost any time, interrupting the currently executing code.
  2. *Softirqs and tasklets* - The kernel can raise or schedule a softirq or tasklet at almost any time, interrupting the currently executing code.
  3. *Kernel preemption* - Because the kernel is preemptive, one task in the kernel can preempt another.
  4. *Sleeping and synchronization with user-space* - A task in the kernel can sleep and thus invoke the scheduler, resulting in the running of a new process.
  5. *Symmetrical multiprocessing* - Two or more processors can execute kernel code at exactly the same time.
* **safe**
  1. Code that is safe from concurrent access from an interrupt handler is said to be *interrupt-safe*.
  2. Code that is safe from concurrency on symmetrical multiprocessing machines is *SMP-safe*.
  3. Code that is safe from concurrency with kernel preemption is *preempt-safe*.
  
  
 ### DeadLocks
 * Nested locks must *always* be obtained in the same order.


### Contention and Scalability
* The tern *lock contention*, or simply *contention*, describes a lock currently in use but that another thread is trying to acquire.

* *Scalability* is a measurement of how well a system can be expanded.
* Locking that is too coarse results in poor scalability if there is high lock contention, whereas locking that is too fine results in wasteful overhead if there is little lock contention。
