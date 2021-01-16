# Process Scheduling

### Preemption and Context Switching
* context switch(): It is called by schedule() when a new process has been selected to run. It does two basic jobs:
	1. Calls switch_mm() to switch the virtual memory mapping from the previous process's to that of the new process.
  2. Call switch_to() to switch the processor state from the previous process's to the current's. This involves saving and restoring stack information and the processor registers and any other architecture-specific state that must be managed and restored on a per-process basis.
