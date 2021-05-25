## Concurrency and Threads
* A **multi-threaded** program has more than one point of execution (i.e., multiple PCs, each of which is being fetched and executed from). They **share** the same address space and thus can access the same data.
* In a multi-threaded process, instead of a single stack in the address space, there will be one per thread.

![image](https://user-images.githubusercontent.com/46720890/119263462-b4e05a00-bc11-11eb-9fcd-82764f1de8dc.png)

## Locks
#### Building Working Spin Locks with Test-And-Set
* Because simple approaches using loads and stores don't work, system designers started to invent hardware support for locking. The simplest bit of hardware support to understand is known as a **test-and-set** (or **atomic exchange**) instruction. 
* What the test-and-set instruction does is as follows. It returns the old value pointed to by the old ptr, and simultaneously updates said value to new. The key, of course, is that this sequence of operations is performed **atomically**.
