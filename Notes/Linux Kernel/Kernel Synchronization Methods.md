# Kernel Synchronization Methods

### Atomic Operations
* Atomicity requires that either instructions succeed in their entirety, uninterrupted, or instructions fail to execute at all. Put more generally, real atomicity requires that all intermediate states be correctly realized.

### Spin Locks
* Spin locks are not recursive.
* If a lock is used in an interrupt handler, you must also disable local interrupts (interrupt requests on the current processor) before obtaining the lock. Otherwise, it is possible to reacquire the lock. This is an example of the double-acquire deadlock.
