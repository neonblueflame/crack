# crack
Program that cracks passwords hashed using Unix's crypt() function. Accepts 1 hashed password as command line argument. Prints a message and returns 1 if there is an error.

Assumptions: 
Password is hashed with C's DES-based crypt() function and that it has up to 5 characters only, consisting of alphabetical characters.
