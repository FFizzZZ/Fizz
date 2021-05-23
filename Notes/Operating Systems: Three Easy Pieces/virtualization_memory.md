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

![image](https://user-images.githubusercontent.com/46720890/119234249-74c09f00-bb5f-11eb-81af-370ad8eb5a84.png)


*  A **valid bit** is common to indicate whether the particular translation is valid. We also might have **protection bits**, indicating whether the page could be read from, written to, or executed from.

* Let's simply assume for now that a single **page-table base register** contains the physical address of the starting locatin of the page table. To find the location of the desired PTE, the hardware will thus perform the following functions:
```
// Extract the VPN from the virtual address
VPN = (VirtualAddress & VPN_MASK) >> SHIFT

// Form the address of the page-table entry (PTE)
PTEAddr = PTBR + (VPN * sizeof(PTE))

// Fetch the PTE
PTE = AccessMemory(PTEAddr)

// Check if process can access the page
if (PTE.Valid == False)
	RaiseException(SEGMENTATION_FAULT)
else if (CanAccess(PTE.ProtectBits) == False)
	RaiseException(PROTECTION_FAULT)
else
// Access is OK: form physical address and fetch it
	offset = VirtualAddress & OFFSET_MASK
	PhysAddr = (PTE.PFN << PFN_SHIFT) | offset
	Register = AccessMemory(PhysAddr)
```

## Translation lookaside buffer (TLB)
* In a page table, when a page-table entry (PTE) is marked invalid, it means that the page has not been allocated by the process, and should not be accessed by a correctly-working program. A TBL valid bit, in contrast, simply refers to whether a TLB entry has a valid translation within it.
* T reduce overhead caused by context switch, some hardware systems provide an **address space identifier (ASID)** field in the TLB.

## Multi-level Page Tables
* The basic idea behind a multi-level page table is simple. First, chop up the page table into page-sized units; then, if an entire page of page-table entries (PTEs) is invalid, don’t allocate that page of the page table at all. To track whether a page of the page table is valid (and if valid, where it
is in memory), use a new structure, called the **page directory**.
![image](https://user-images.githubusercontent.com/46720890/119233859-6e312800-bb5d-11eb-8ce1-b70aa1965499.png)

* The multi-level table only allocates page-table space in proportion to the amount of address
space you are using; thus it is generally compact and supports sparse address spaces.
![image](https://user-images.githubusercontent.com/46720890/119233843-61accf80-bb5d-11eb-8ec4-2a87bd17af77.png)

## Swapping
![image](https://user-images.githubusercontent.com/46720890/119250249-5f845880-bbd1-11eb-8874-7479b33175f0.png)
* From the hardware control flow diagram in Figure 21.2, notice that
there are now three important cases to understand when a TLB miss occurs. First, that the page was both present and valid (Lines 18–21); in
this case, the TLB miss handler can simply grab the PFN from the PTE,
retry the instruction (this time resulting in a TLB hit), and thus continue
as described (many times) before. In the second case (Lines 22–23), the
page fault handler must be run; although this was a legitimate page for
the process to access (it is valid, after all), it is not present in physical
memory. Third (and finally), the access could be to an invalid page, due
for example to a bug in the program (Lines 13–14). In this case, no other
bits in the PTE really matter; the hardware traps this invalid access, and
the OS trap handler runs, likely terminating the offending process.

