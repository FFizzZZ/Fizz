## Broadcasting
* A router simply forwards a copy of any message it receives out of every interface other than the one on which the message arrived.
* On an Ethernet or similar network, a multicast MAC address has the low-order bit of the high-order byte turned on. In hexadecimal this looks like 01:00:00:00:00:00. We may consider the Ethernet broadcast address ff:ff:ff:ff:ff:ff as a special case of the Ethernet multicast address.
* In IPv4, each subnet has a local subnet-directed broadcast address formed by placing all 1 bits in the hosot portion of the address, and the special address 255.255.255.255 corresponds to a local network (also called "limited") broadcast.
