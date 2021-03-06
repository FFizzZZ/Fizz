# Timers and Time Management

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

### Timers
* Timers - sometimes called dynamic timers or kernel timers - are essential for managing the flow of time in kernel code.
* The kernel runs the timer handler when the current tick count is equal or greater than the specified expiration. Typically, timers are run fairly close to their expiration; however, they might be delayed until the first timer tick after their expiration. Consequently, timers cannot be used to implement any sort of hard real-time processing.
* To deactivate the timer and wait until a potentially executing handler for the timer exits, use del_timer_sync(). Unlike del_timer(), del_timer_sync() cannot be used from interrupt context.
* The kernel executes timers in bottom-half context, as softirqs, after the timer interrupt completes. The TIMER_SOFTIRQ softirq is handled by run_timer_softirq(). This function runs all the expired timers (if any) on the current processor.
```
update_process_times() -> run_local_timers()

void run_local_timers(void)
{
    hrtimer_run_queues();
    raise_softirq(TIMER_SOFTIRQ);
    softlockup_tick();
}
```
* Timers are stored in linked list. The kernel partitions timers into five groups based on their expiration value. Timers move down through the groups as their expiration time draws close.

#### Question
* Why macros, such as *time_before(unknown, known)* can prevent errors because of wraparound?
