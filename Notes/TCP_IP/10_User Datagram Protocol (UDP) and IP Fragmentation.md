## UDP Header
![image](https://user-images.githubusercontent.com/46720890/120106638-7ce89200-c190-11eb-991e-7bae91ffb22d.png)

## UDP Checksum
* It covers the UDP header, the UDP data, and a pseudo-header. Computed at the initial sender and checked at the final destination, it is not modified in transit (except when it passes through a NAT).
![image](https://user-images.githubusercontent.com/46720890/120107250-e10c5580-c192-11eb-88e3-ee36de23ec99.png)
* With UDP, the checksum is optional (although strongly suggested), while with the others it is mandatory. If the sender *did* compute a checksum and the receiver detects a checksum error, the UDP datagram is sliently discarded.

## UDP-Lite
* A *partial checksum* covers only a portion of the payload specified by the application.
* UDP-Lite has its own IPv4 Protocol and IPv6 Next Header field value (136), so it effectively counts as a separate transport protocol.
