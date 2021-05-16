## Process
![image](https://user-images.githubusercontent.com/46720890/117984648-973a0780-b36a-11eb-9156-29aaa058a22f.png)

## Process API
* control-c sends a SIGINT (interrupt) to the process (normally terminating it) and control-z sends a SIGTSTP (stop) signal thus pausing the process in mid-execution (you can resume it later with a command, e.g., the fg built-in command found in many shells).


## Direct Execution
##### Restricted Operations
* To specify the exact system call, a **system-call number** is usually assigned to each system call. The user code is thus responsible for placing the desired system-call number in a register or at a specified location on the stack.
##### Switching Between Processes
If a process is running on the CPU, this by definition means the OS is **not** running. How can the operating system *regain control* of the CPU so that it can switch between processes?
###### A Cooprative Approach: Wait For System Calls
* In a cooperative scheduling system, the OS regains control of the CPU by waiting for a system call or an illegal operation of some kind to take place.
###### A Non-Cooperative Approach: The OS Takes Control
* The answer turns out to be simple: a **timer interrupt**.
###### Saving and Restoring Context
* A context switch is conceptually simple: all the OS has to do is save a few register values for the currently-executing process (onto its kernel stack, for example) and restore a few for the soon-to-be-executing process (from its kernel stack).
* Note that there are two types of register saves/restores that happen during this protocol. The first is when the timer interrupt occurs; in this case, the user registers of the running process are implicitly saved by the
hardware, using the kernel stack of that process. The second is when the OS decides to switch from A to B; in this case, the kernel registers are explicitly saved by the software (i.e., the OS), but this time into memory in the process structure of the process. The latter action moves the system from running as if it just trapped into the kernel from A to as if it just trapped into the kernel from B.
![image](https://user-images.githubusercontent.com/46720890/118389274-be8b2000-b65b-11eb-833d-b3c2f6dfde99.png)

## CPU Scheduling
###### Shortest Time-to-Completion First (STCF)  
* Any time a new job enters the system, the STCF scheduler determines which of the remaining jobs (including the new job) has the least time left, and schedules that one. 
###### Round Robin (RR)
* Instead of running jobs to completion, RR runs a job for a **time slice** (sometimes called a **scheduling quantum**) and then switches to the next job in the run queue. It repeatedly does so until the jobs are finished.
###### Multi-level Feedback Queue (MLFQ)
* The MLFQ has a number of distinct **queues**, each assigned a different **priority level**.
```
Rule 1：If Priority(A) > Priority(B), A runs (B doesn't).
Rule 2: If Priority(A) == Priority(B), A & B run in RR.
```
