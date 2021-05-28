## Introduction
* The IPv4 datagram. The header is of variable size, limited to fifteen 32-bit words (60 bytes) by the 4-bit IHL field. A typical IPv4 header contains 20 bytes (no options).
![image](https://user-images.githubusercontent.com/46720890/119680204-8a8dd700-be73-11eb-8d88-b4a4e271cba0.png)

* The IPv6 header is of fixed size (40 bytes) and contains 128-bit source and destination address. The *Next Header* field is used to indicate the presence and types of additional extension headers that follow the IPv6 header, forming a daisy chain of headers that may include special extensions or processing directives.
![image](https://user-images.githubusercontent.com/46720890/119680515-d50f5380-be73-11eb-8666-4164f836bf63.png)

## IPv4 and IPv6 Headers
* In our pictures of headers and datagrams, the most significant bit is numbered 0 at the left, and the least significant bit of a 32-bit value is numbered 31 on the right.
* The 4 bytes in a 32-bit value are transmitted in the following order: bits 0–7 first, then bits 8–15, then 16–23, and bits 24–31 last. This is called big endian byte ordering.
#### IP Header Fields
* The *Total Length* field is required in the header because some lower-layer protocols that carry IPv4 datagrams do not (accurately) convey the size of encapsulated datagrams on their own. Ethernet, for example, pads small frames to be a minimum length.
* The *Identification* field helps indentify each datagram sent by an IPv4 host. The sending host normally increments an internal counter by 1 each time a datagram is sent (from one of its IP address).
* The *Header Checksum* field is calculated *over the IPv4 header only*. Perhaps surprisingly, the IPv6 header does not have any checksum field. Note that when an IPv4 datagram passes through a router, its header checksum must change as a result of decrementing the *TTL* field.
#### The Internet Checksum
![image](https://user-images.githubusercontent.com/46720890/119691507-3851b380-be7d-11eb-9bf0-b1ba8943f09a.png)

## IP Forwarding
*longest prefix match* algorithm
* Search the table for all entries for which the following property holds:
(D ^ mj) = dj, where mj is the value of the mask field associated with the forwarding
entry ej having index j, and dj is the value of the destination field
associated with ej. This means that the destination IP address D is bitwise
ANDed with the mask in each forwarding table entry (mj), and the result is
compared against the destination in the same forwarding table entry (dj).
If the property holds, the entry (ej here) is a “match” for the destination IP
address. When a match happens, the algorithm notes the entry index (j
here) and how many bits in the mask mj were set to 1. The more bits set to
1, the “better” the match.
* The best matching entry ek (i.e., the one with the largest number of 1 bits in
its mask mk) is selected, and its next-hop field nk is used as the next-hop IP
address in forwarding the datagram.

# Host Processing of IP Datagrams
#### Host Models
There are two host models, the strong
host model and the weak host model. In the strong host model, a datagram is accepted
for delivery to the local protocol stack only if the IP address contained in the Destination
IP Address field matches one of those configured on the interface upon which
the datagram arrived. In systems implementing the weak host model, the opposite
is true—a datagram carrying a destination address matching any of the local
addresses may arrive on any interface and is processed by the receiving protocol
stack, irrespective of the network interface upon which it arrived.
* Host models also
apply to sending behavior. That is, a host using the strong host model sends datagrams
from a particular interface only if one of the interface’s configured addresses
matches the Source IP Address field in the datagram being sent.
