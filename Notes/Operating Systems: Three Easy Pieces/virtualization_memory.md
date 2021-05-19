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

## Paging
* Instead of splitting up a process’s address space into some number of variable-sized logical segments (e.g., code, heap, stack), we divide it into fixed-sized units, each of which we call a **page**. Correspondingly, we view physical memory as an array of fixed-sized slots called **page frames**.
* To record where each virtual page of the address space is placed in physical memory, the operating system usually keeps a per-process data structure known as a **page table**. The major role of the page table is to store **address translations** for each of the virtual pages of the address space.

![image](https://user-images.githubusercontent.com/46720890/118747420-8b7ba300-b88c-11eb-98b5-4a3fb923373f.png)

*  A **valid bit** is common to indicate whether the particular translation is valid. We also might have **protection bits**, indicating whether the page could be read from, written to, or executed from.

* Let's simply assume for now that a single **page-table base register** contains the physical address of the starting locatin of the page table. To find the location of the desired PTE, the hardware will thus perform the following functions:
```
1 // Extract the VPN from the virtual address
2 VPN = (VirtualAddress & VPN_MASK) >> SHIFT
3
4 // Form the address of the page-table entry (PTE)
5 PTEAddr = PTBR + (VPN * sizeof(PTE))
6
7 // Fetch the PTE
8 PTE = AccessMemory(PTEAddr)
9
10 // Check if process can access the page
11 if (PTE.Valid == False)
12 RaiseException(SEGMENTATION_FAULT)
13 else if (CanAccess(PTE.ProtectBits) == False)
14 RaiseException(PROTECTION_FAULT)
15 else
16 // Access is OK: form physical address and fetch it
17 offset = VirtualAddress & OFFSET_MASK
18 PhysAddr = (PTE.PFN << PFN_SHIFT) | offset
19 Register = AccessMemory(PhysAddr)
```
