* System timer: a programmable piece of hardware that issues an interrupt at a fixed frequency.
* Dynamic timer: the facility used to schedule events that run once after a specified time has elapsed.

### Kernel Notion of Time
* The frequency of the system timer (the tick rate) is programmed on system boot based on a static preprocessor define, HZ.
* Picking the right value, like a successful relationship, is all about compromise.

### Hardware Clocks and Timers
* Real-Time Clock: It provides a nonvolatile device for storing the system time. The RTC continues to keep track of time even when the system is off by way of a small battery typically included on the system board.
* System Timer: It provides a mechanism for driving an interrupt at a periodic rate.

### The Timer Interrupt Handler
* The timer interrupt is broken into two pieces: an architecture-dependent and an architecture-independent routine.
##### architecture-dependent routine
    1. Obtain the *xtime_lock* lock, which protects access to jiffies_64 and the wall time value, xtime.
    2. Acknowledge or reset the system timer as required.
    3. Periodically save the updated wall time to the real time clock.
    4. Call the architecture-independent timer routine, tick_periodic().
##### architecture-independent routine, tick_periodic(), performs much more work:
    1. Increment the jiffies_64 count by one. (This is safe, even on 32-bit architectures, because the xtime_lock lock was previously obtained.)
    2. Update resource usages, such as consumed system and user time, for the currently running process.
    3. Run any dynamic timers that have expired.
    4. Execute scheduler_tick().
    5. Update the wall time, which is stored in xtime.
    6. Calculate the infamous load average.


#### Question
* Why macros, such as *time_before(unknown, known)* can prevent errors because of wraparound?
