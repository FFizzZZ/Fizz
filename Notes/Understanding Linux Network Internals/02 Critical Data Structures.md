## The Socket Buffer: sk_buff Structure
Its fields can be classified roughly into the following categories: 
* Layout
* General
* Feature-specific
* Management functions

### Layout Field
![image](https://user-images.githubusercontent.com/46720890/119327666-cd09b500-bcb5-11eb-9329-8fb298d857c5.png)
![image](https://user-images.githubusercontent.com/46720890/119327751-e874c000-bcb5-11eb-85db-21d1d474d713.png)

##### unsigned char *head, *end, *data, *tail
These represent the boundaries of the buffer and the data within it. *head* and *end* point to the begining and end of the space allocated to the buffer, and *data* and *tail* point to the begining and end of the actual data. The layer can then fill in the gap between *head* and *data* with a protocol header, or the gap between *tail* and *end* with new data.

##### unsigned int len
This is the size of the block of data in the buff. This length includes both the data in the main buffer (i.e., the one pointed to by *head*) and the data in the fragments.

##### unsigned int data_len
Unlike *len*, *data_len* accounts only for the size of the data in the fragments.

##### unsigned int truesize
This field represents the total size of the buffer, including the *sk_buff* structure itself (i.e., truesize = len + sizeof(sk_buff)).

### Management Functions
![image](https://user-images.githubusercontent.com/46720890/119330128-79e53180-bcb8-11eb-8207-403a36b3d94f.png)

### Cloning and Copying Buffers
![image](https://user-images.githubusercontent.com/46720890/119339649-021d0400-bcc4-11eb-9b7e-77971f521e1a.png)

* When a buffer is cloned, the contents of the data block cannot be modified. When someone needs to modify only the contents of the data in the area between skb->start and skb->end, he can use **pskb_copy** to clone just that area. When someone thinks he may need to modify the content of the fragment data blocks too, he must use **skb_copy**.

![image](https://user-images.githubusercontent.com/46720890/119340137-ae5eea80-bcc4-11eb-9f86-9f75005ef691.png)
