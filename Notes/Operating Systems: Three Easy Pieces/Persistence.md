## I/O Devices
![image](https://user-images.githubusercontent.com/46720890/119139664-da386100-ba75-11eb-94d0-9a35e01a71f0.png)

## A Canonical Device
![image](https://user-images.githubusercontent.com/46720890/119143392-21c0ec00-ba7a-11eb-871e-2de4516fb269.png)
* a **status** register, which can be read to see the current status of the device; a **command** register, to tell the device to perform a certain task; and a **data** register to pass data to the device, or get data from the device.

* Using interrupts is not *always* the best solution. If a device is fast, it may be best to poll; if it is slow, interrupts, which allow overlap, are best. If the speed of the device is not known, or sometimes fast and sometimes slow, it may be best to use a **hybrid** that polls for a little while and then, if the device is not yet finished, use interrupts.
