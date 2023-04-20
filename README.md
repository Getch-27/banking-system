# Banking System with Open Addressing Hash Table c++
This project is a banking system that uses an open addressing hash table to store bank account information. Each account is stored in the hash table with its account number serving as the key.
## bImplementation Details
The program uses an open addressing hash table to store the account information. The hash function used is simply the account number modulo the size of the hash table.

In the case of a collision, the program uses linear probing to find the next available slot in the hash table. If the end of the hash table is reached, the program wraps around to the beginning of the hash table and continues searching.

The program uses a binary file to store the hash table on disk. When the program starts up, it reads the hash table from the file. When the program exits, it writes the hash table back to the file.
