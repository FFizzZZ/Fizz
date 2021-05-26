## Introduction
* The IPv4 datagram. The header is of variable size, limited to fifteen 32-bit words (60 bytes) by the 4-bit IHL field. A typical IPv4 header contains 20 bytes (no options).
![image](https://user-images.githubusercontent.com/46720890/119680204-8a8dd700-be73-11eb-8d88-b4a4e271cba0.png)

* The IPv6 header is of fixed size (40 bytes) and contains 128-bit source and destination address. The *Next Header* field is used to indicate the presence and types of additional extension headers that follow the IPv6 header, forming a daisy chain of headers that may include special extensions or processing directives.
![image](https://user-images.githubusercontent.com/46720890/119680515-d50f5380-be73-11eb-8666-4164f836bf63.png)

## IPv4 and IPv6 Headers
* In our pictures of headers and datagrams, the most significant bit is numbered 0 at the left, and the least significant bit of a 32-bit value is numbered 31 on the right.
* The 4 bytes in a 32-bit value are transmitted in the following order: bits 0–7 first, then bits 8–15, then 16–23, and bits 24–31 last. This is called big endian byte ordering。
* The *Total Length* field is required in the header because some lower-layer protocols that carry IPv4 datagrams do not (accurately) convey the size of encapsulated datagrams on their own. Ethernet, for example, pads small frames to be a minimum length.
