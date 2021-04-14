* From the opertaing system's point of view, distributing the work of outgoing data across CPUs is relatively straightforward.


Question:
* The processes generating data will naturally spread out across the system, so the networking stack does not need to think much about it, especially now that multiple transmit queues are supported. Incoming data is harder to distribute, though, because it is coming from a single source. 
