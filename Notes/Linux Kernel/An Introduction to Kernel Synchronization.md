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
