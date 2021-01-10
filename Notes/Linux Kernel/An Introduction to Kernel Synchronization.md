# An Introduction to Kernel Synchronization

### Critical Regions and Race Conditions
* Code paths that access and manipulate shared data are called **critical regions** (also called critical sections).


### Locking
* **pseudo-concurrency**: two things do not actually happen at the same time but interleave with each other such that they might as well.
* **true concurrency**: If you have a symmetrical multiprocessing machine, two processes can actually be executed in a critical region at the exact same time.
