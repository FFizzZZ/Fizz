### Address Translation
#### Dynamic (Hardware-based) Relocation
* two hardware registers within each cpu: one is called the *base* register, and the other the *bounds*.
* physical address = virtual address + base
* the processor will first check that the memory reference is within *bounds* to make sure it is legal.

#### Hardware Support: A Summary
* The OS runs in privileged mode (or kernel mode), where it has access to the entire machine; applications run in user mode, where they are limited in what they can do.



