## The Socket Buffer: sk_buff Structure
Its fields can be classified roughly into the following categories: 
* Layout
* General
* Feature-specific
* Management functions

![image](https://user-images.githubusercontent.com/46720890/119327666-cd09b500-bcb5-11eb-9329-8fb298d857c5.png)
![image](https://user-images.githubusercontent.com/46720890/119327751-e874c000-bcb5-11eb-85db-21d1d474d713.png)

* unsigned int len：This is the size of the block of data in the buff. This length includes both the data in the main buffer (i.e., the one pointed to by *head*) and the data in the fragments.
