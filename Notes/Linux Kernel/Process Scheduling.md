# Process Scheduling

### Preemption and Context Switching
#### context switch(): 
* It is called by schedule() when a new process has been selected to run. It does two basic jobs:
	1. Calls switch_mm() to switch the virtual memory mapping from the previous process's to that of the new process.
  	2. Call switch_to() to switch the processor state from the previous process's to the current's. This involves saving and restoring stack information and the processor registers and any other architecture-specific state that must be managed and restored on a per-process basis.
  
* The kernel provides the need_resched flag to signify whether a reschedule should be performed.
This flag is set by scheduler_tick() when a process should be preempted, and by try_to_wake_up() when a process that has a higher priority than the currently running process is awakened.

#### User Preemption
	1. When returning to user-space from a system call
	2. When returning to user-space form an interrupt handler
	
#### Kernel Preemption
	1. When an interrupt handler exits, before returning to kernel to kernel-space
	2. When kernel code becomes preemptible again
	3. If a task in the kernel explicitly calls schedule()
	4. If a task in the kernel blocks (which results in a call to schedule()) 
* It is possible to preempt a task at any point, so long as the kernel is in a state in which it is safe to reschedule.

* So when it is safe to reschedule? The kernel can preempt a task running in the kernel so long as it does not hold a lock. Because the kernel is SMP-safe, if a lock is not held, the current code is reentrant and capable of being preempted.

* Preemption counter: When the counter is zero, the kernel is preemptible.


