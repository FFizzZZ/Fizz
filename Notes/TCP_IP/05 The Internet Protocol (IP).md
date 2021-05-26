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
