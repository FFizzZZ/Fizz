* System timer: a programmable piece of hardware that issues an interrupt at a fixed frequency.
* Dynamic timer: the facility used to schedule events that run once after a specified time has elapsed.

### Kernel Notion of Time
* The frequency of the system timer (the tick rate) is programmed on system boot based on a static preprocessor define, HZ.
* Picking the right value, like a successful relationship, is all about compromise.

### Jiffies



#### Question
* Why macros, such as *time_before(unknown, known)* can prevent errors because of wraparound?
