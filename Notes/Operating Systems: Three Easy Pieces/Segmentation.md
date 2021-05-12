### Segmentation
* There will be a big chunk of "free" space right in the middle, between the stack and the heap if we put the entire address space of each process in memory.
* To solve this problem, an idea was born, and it is called *segmentation*.

#### Segmentation: Generalized Base/Bounds
* The idea is simple: instead of having just one base and bounds pair in our MTU, why not have a base and bouds pair per logical *sement* of the address space?
