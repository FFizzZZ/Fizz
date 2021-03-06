## I/O Devices
![image](https://user-images.githubusercontent.com/46720890/119257790-7048c480-bbf9-11eb-8d17-2937554e2fa8.png)

#### A Canonical Device
![image](https://user-images.githubusercontent.com/46720890/119143392-21c0ec00-ba7a-11eb-871e-2de4516fb269.png)
* a **status** register, which can be read to see the current status of the device; a **command** register, to tell the device to perform a certain task; and a **data** register to pass data to the device, or get data from the device.

* Using interrupts is not *always* the best solution. If a device is fast, it may be best to poll; if it is slow, interrupts, which allow overlap, are best. If the speed of the device is not known, or sometimes fast and sometimes slow, it may be best to use a **hybrid** that polls for a little while and then, if the device is not yet finished, use interrupts.

#### Methods of Device Interaction
* **I/O instructions**: these instructions specify a way for the OS to send data to specific device registers and thus allow the construction of the protocol. Such instructions are usually **privileged**.
* **memory-mapped I/O**: with this approach, the hardware makes device registers available if they were memory locations. To access a particular register, the OS issues a load (to read) or store (to write) the adress; the hardware then routes the load/store to the device instead of main memory.

#### Fitting Into the OS: The Device Driver
![image](https://user-images.githubusercontent.com/46720890/119258095-d6821700-bbfa-11eb-9ba3-07e80144b7bb.png)
