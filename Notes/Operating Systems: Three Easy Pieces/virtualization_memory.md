## Address Translation
* limited direct execution (LDE): for the most part, let the program run directly on the hardware; however, at certain key points in time, arrange so that the OS gets involved and makes sure the "right" things happens.
#### Dynamic (Hardware-based) Relocation
* two hardware registers within each cpu: one is called the *base* register, and the other the *bounds*.
* physical address = virtual address + base
* the processor will first check that the memory reference is within *bounds* to make sure it is legal.

#### Hardware Support: A Summary
* The OS runs in privileged mode (or kernel mode), where it has access to the entire machine; applications run in user mode, where they are limited in what they can do.

## Segmentation
* There will be a big chunk of "free" space right in the middle, between the stack and the heap if we put the entire address space of each process in memory.
* To solve this problem, an idea was born, and it is called *segmentation*.

#### Segmentation: Generalized Base/Bounds
* The idea is simple: instead of having just one base and bounds pair in our MTU, why not have a base and bouds pair per logical *sement* of the address space?

#### Which Segment Are We Referring to?
* One common approach, sometimes referred to as an *explicit* approach, is to chop up the address space into segments based on the top few bits of the virtual address.
```
segment = virtual_addr & SEG_MASK) >> SEG_SHIFT;
offset = virtual_addr & OFFSET_MASK;
if (offset >= Bounds[segment])
  RaiseException(PROTECTION_FAULT);
else {
  phy_Addr = Base[segment] + offset;
  register = AccessMemory(phy_Addr);
}
```
* In the *implicit* approach, the hardware determines the segment by noticing how the address was formed. If, for example, the address was generated from the program counter, then the address is within the coded segment; if the address is based off the stack or base pointer, it must be in the stack segment; any other address must be in the heap.
#### What About the Stack?
* One critical difference: it grows backwards (i.e., towards lower addresses).
* The first thing we need is a little extra hardware support. Insteadd of just base and bounds values, the hardware also needs to know which way the segment grows.
* The bounds check can be calculated by ensuring the absolute value of the negative offset is less than or equal to the segment’s current size.

## Free-Space Management
#### Low-level Mechanisms
##### Splitting and Coalescing
##### Tracking The Size of Allocated Regions
* To accomplish this task, most allocators store a little bit of extra information in a header block which is kept in memory, usually just before the handed-out chunk of memory. 
```
typedef struct {
  int size;
  int magic;    /* provide additional integrity checking */
} header_t;
```