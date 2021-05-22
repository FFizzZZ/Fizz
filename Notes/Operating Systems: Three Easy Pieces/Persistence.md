## I/O Devices
![image](https://user-images.githubusercontent.com/46720890/119139664-da386100-ba75-11eb-94d0-9a35e01a71f0.png)

## A Canonical Device
![image](https://user-images.githubusercontent.com/46720890/119143392-21c0ec00-ba7a-11eb-871e-2de4516fb269.png)
* a **status** register, which can be read to see the current status of the device; a **command** register, to tell the device to perform a certain task; and a **data** register to pass data to the device, or get data from the device.

```
While (STATUS == BUSY)
; // wait until device is not busy
Write data to DATA register
Write command to COMMAND register
(starts the device and executes the command)
While (STATUS == BUSY)
; // wait until device is done with your request
```
