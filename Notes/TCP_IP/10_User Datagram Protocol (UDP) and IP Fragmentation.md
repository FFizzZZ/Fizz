## UDP Header
![image](https://user-images.githubusercontent.com/46720890/120315691-35d4db00-c30f-11eb-910e-a2d32d5dfd7f.png)

## UDP Checksum
* It covers the UDP header, the UDP data, and a pseudo-header. Computed at the initial sender and checked at the final destination, it is not modified in transit (except when it passes through a NAT).

![image](https://user-images.githubusercontent.com/46720890/120315627-20f84780-c30f-11eb-8c0a-be27f09ec5f2.png)

* With UDP, the checksum is optional (although strongly suggested), while with the others it is mandatory. If the sender *did* compute a checksum and the receiver detects a checksum error, the UDP datagram is sliently discarded.

## UDP-Lite
* A *partial checksum* covers only a portion of the payload specified by the application.
* UDP-Lite has its own IPv4 Protocol and IPv6 Next Header field value (136), so it effectively counts as a separate transport protocol.

![image](https://user-images.githubusercontent.com/46720890/120289273-b259c080-c2f3-11eb-8ef4-f1d203122aab.png)

## IP Fragmentation
* When an IP datagram is fragmented, it is not reassembled until it reaches its final destination. Two reasons for this. First, not performing reassembly within the network alleviates the forwarding software (or hardware) in routers. Second, it is possible for different fragments of the same datagram to follow different paths to their common destination.

![image](https://user-images.githubusercontent.com/46720890/120296257-868e0900-c2fa-11eb-8b51-14fa11550c68.png)

* The *identification* field value (set by the original sender) is copied to each fragment and is used to group them together when they arrive. The *Fragment Offset* field gives the offset of the first byte of the fragment payload byte in the original IPv4 datagram (in 8-byte units).

* If one fragment is lost, the entire datagram is lost. To understand why this happens, realize that IP itself has no error
correction mechanism of its own.When a fragment of a TCP segment is lost, TCP retransmits the entire TCP segment, which corresponds to an entire IP datagram. There is no way to resend only one fragment of a datagram. Indeed, if the fragmentation was done by an intermediate router, and not the originating system, there is no way for the originating system to know how the datagram was fragmented. For this reason, fragmentation is often avoided.

### Reassembly Timeout
* The IP layer must start a timer when any fragment of a datagram first arrives. The timer starts when any of the fragments is received and is not reset when new fragments arrive.

## Path MTU Discovery with UDP
## UDP Server Design
![C4145E9D-0355-4BC1-B730-13F650F9B5E2](https://user-images.githubusercontent.com/46720890/120923272-3818aa00-c700-11eb-9e86-c4f10296a1d0.png)

