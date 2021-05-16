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
Rule 3: When a job enters the system, it is replaced at the highest priority (the topmost queue).
Rule 4: Once a job uses up its time allotment at a given level (regardless of how many times it has given up the CPU), its priority is reduced (i.e., it moves down one queue).
Rule 5: After some time period S, move all the jobs in the system to the topmost queue.
```
* The high-priority queues are usually given short time slices; they are comprised of interactive jobs. The low-priority queues, in contrast,contain long-running jobs that are CPU-bound; hence, longer time slices work well.

## Proportional Share (fair-share)
* Instead of optimizing for turnaround or response time, a scheduler might instead try to guarantee that each job obtain a certain percentage of CPU time.
##### Lottery Scheduling
* Tickets represent your share. Lottery scheduling achieves this probabilistically by holding a lottery every so often (say, every time slice).

##### The Linux Completely Fair Scheduler (CFS)
* Goal: to fairly divide a CPU evenly among all competing processes via **virtual runtime(vruntime)**.
* **sched_latency**: CFS uses this value to determine how long one process should run before considering a switch.
* **min_granularity**: CFS will never set the time slice of a process to less than this value, ensuring that not too much time is spent in scheduling overhead.
###### Weighting (Niceness)
* From -20 to +19 for a process, with a default of 0. Positive nice values imply lower priority and negative values imply higher priority.
* CFS maps the nice value of each process to a **weight**, as shown here:
```
static const int prio_to_weight[40] = {
/* -20 */ 88761, 71755, 56483, 46273, 36291,
/* -15 */ 29154, 23254, 18705, 14949, 11916,
/* -10 */ 9548, 7620, 6100, 4904, 3906,
/* -5 */ 3121, 2501, 1991, 1586, 1277,
/* 0 */ 1024, 820, 655, 526, 423,
/* 5 */ 335, 272, 215, 172, 137,
/* 10 */ 110, 87, 70, 56, 45,
/* 15 */ 36, 29, 23, 18, 15,
};
```

![image](https://user-images.githubusercontent.com/46720890/118404556-00d94f00-b6a6-11eb-8e58-a6cac8e03135.png)
![image](https://user-images.githubusercontent.com/46720890/118404538-edc67f00-b6a5-11eb-90f2-738fcc990138.png)

* One smart aspect of the construction of the table of weights above is that the table preserves CPU proportionality ratios when the difference in nice values is constant.
* To deal with I/O and sleeping processes, CFS sets the *vruntime* of that job to the minimum value found in the tree when it wakes up.


