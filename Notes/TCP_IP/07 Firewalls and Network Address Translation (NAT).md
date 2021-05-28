## Network Address Translation (NAT)
* The so-called traditional NAT includes both basic NAT and Network Address Port Translation (NAPT).

![image](https://user-images.githubusercontent.com/46720890/119988019-3b24e380-bff8-11eb-936e-a45f9d8cca5f.png)

* Because of the layering of UDP above IP, an IP fragment other than the first one does not contain the port number information needed by NAPT to operate properly. This also applies to TCP and ICMP. Thus, in general, frag- ments cannot be handled properly by simple NATs or NAPTs.
