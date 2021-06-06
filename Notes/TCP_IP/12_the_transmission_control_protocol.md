## Introduction
#### Windows of Packets and Sliding Windows
![BC80CB36-ED7C-4EA0-B947-1263493BA3B1](https://user-images.githubusercontent.com/46720890/120923452-30a5d080-c701-11eb-927b-36ed049a7cb2.png)

This window structure is kept at both the sender and the receiver.
* At the sender, it keeps track of what packets can be released, what packets are awaiting ACKs, and what packets cannot yet be sent.
* At the receiver, it keeps track of what packets have already been received and acknowledged, what packets are expected (and how much memory has been allocated to hold them), and which packets, even if received, will not be kept because of limited memory.

Question  
18.6.2 平静时间的概念
  如果使用处于 2MSL 等待端口的主机出现故障，它会在 MSL 秒内重新启动，并立即使用故障前仍处于 2MSL 的插口对来建立一个新的连接吗？如果是这样，在故障前从这个连接发出而迟到的报文段会被错误地当作属于重启后新连接的报文段。无论如何选择重启后新连接的初始序号，都会发生这种情况。

