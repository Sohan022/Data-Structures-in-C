# Open Addressing (Closed Hashing)

## Problem Description:

Take a positive integer (say N) from user. Generate N unique numbers (positive integers only). Take another positive integer (say M) from user where M ≥ N. This M denotes the size of the hash table. Let k be the integer which you want to insert and i(0 ≤ i ≤ M − 1) be the probe sequence. 

**(1) Perform the following:**

(a) Insert these N integers into the hash table of size M with collisions resolved by **Linear Probing**. Consider F(i) = i and the hash function be h(k) = k mod M.

(b) Insert these N integers into the hash table of size M with collisions resolved by **Quadratic Probing**. Consider F(i) = i<sup>2</sup> and the hash function be h(k) = k mod M.

(c) Insert these N integers into the hash table of size M with collisions resolved by **Double Hashing**. Consider the hash function be h1(k) = k mod M and h2(k) = 8 − (k mod 8).

**(2) Calculate the following for each Collision resolving technique**

(a) Can all the integers be inserted into the hash table?

(b) Total number of collisions during insertion of all the integers (which have been successfully inserted into the hash table).

(c) Number of empty slots in the hash table.
