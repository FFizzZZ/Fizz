## The Socket Buffer: sk_buff Structure
Its fields can be classified roughly into the following categories: 
* Layout
* General
* Feature-specific
* Management functions

![](https://github.com/FFizzZZ/Fizz/blob/master/Notes/Pictures/sk_buff_head.png)
![](https://github.com/FFizzZZ/Fizz/blob/master/Notes/Pictures/sk_buff.png)

* unsigned int len：This is the size of the block of data in the buff. This length includes both the data in the main buffer (i.e., the one pointed to by *head*) and the data in the fragments.
