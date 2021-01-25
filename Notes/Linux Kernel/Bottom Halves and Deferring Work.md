# Bottom Halves and Deferring Work

### Softirqs
* Softirqs are statically allocated at compile time. Unlike, you cannot dynamically register and destroy softirqs.
* A softirq never preempts another softirq. The only event that can preempt a softirq is an interrupt handler. Another softirq - even the same one - can run on another processor, however.
