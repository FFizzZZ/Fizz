# Kernel Synchronization Methods

### Atomic Operations
* Atomicity requires that either instructions succeed in their entirety, uninterrupted, or instructions fail to execute at all. Put more generally, real atomicity requires that all intermediate states be correctly realized.

### Spin Locks
* Spin locks are not recursive.

* Spin locks provide a quick and simple lock. The spinning behavior is optimal for short hold times and code that cannot sleep (interrupt handlers, for example).
* If a lock is used in an interrupt handler, you must also disable local interrupts (interrupt requests on the current processor) before obtaining the lock. Otherwise, it is possible to reacquire the lock. This is an example of the double-acquire deadlock.

### Reader-Writer Spin Locks
* It is safe for multiple readers to obtain the same lock. In fact, it is safe for the same thread to recursively obtain the same read lock.

* Note that you cannot "upgrade" a read lock to a write lock. If you ever need to write, obtain the write lock from the start.
* Reader-writer spin locks favor readers over writers. If the read lock is held and a writer is waiting for exclusive access, readers that attempt to acquire the lock continue to succeed.

### Semaphores
* When a task attempts to acquire a semaphore that is unavailable, the semaphore places the task onto a wait queue and puts the task to sleep. Because a thread of execution sleeps on lock contention, semaphores must be obtained only in process context because interrupt context is not schedulable.

* You cannot hold a spin lock while you acquire a semaphore, because you might have to sleep while waiting for the semaphore, and you cannot sleep while holding a spin lock.
