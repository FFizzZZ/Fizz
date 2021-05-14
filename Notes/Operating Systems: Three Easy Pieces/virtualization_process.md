## Process
![image](https://user-images.githubusercontent.com/46720890/117984648-973a0780-b36a-11eb-9156-29aaa058a22f.png)

## Process API
* control-c sends a SIGINT (interrupt) to the process (normally terminating it) and control-z sends a SIGTSTP (stop) signal thus pausing the process in mid-execution (you can resume it later with a command, e.g., the fg built-in command found in many shells).


## Direct Execution
##### Restricted Operations
* To specify the exact system call, a *system-call number* is usually assigned to each system call. The user code is thus responsible for placing the desired system-call number in a register or at a specified location on the stack.
