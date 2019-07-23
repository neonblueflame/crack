/**
 * Program that cracks passwords hashed using Unix's crypt()
 * function. Accepts 1 hashed password as command line
 * argument. Prints a message and returns 1 if there is an
 * error.
 *
 * Assumptions: password is hashed with C's DES-based
 * crypt() function and that it has up to 5 characters only,
 * consisting of alphabetical characters.
 *
 * Author: Neonblueflame
 * Date: 20190715
 *
 * */

#include <crypt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Check if the 1st argument is valid
int is_arg_invalid(int argc, char** argv);

// Gets the first 2 characters of the hash
char* get_salt(char* hash);

// Check if hashed password is in the rainbow dictionary
char* strcmp_in_dictionary(char* hash, char* salt);

// Check if hashed password is a single character
char* strcmp_one_char(char* hash, char* salt);


int main(int argc, char** argv)
{
    int arg_invalid = is_arg_invalid(argc, argv);
    if (arg_invalid != 0)
    {
        printf("Usage: ./crack <hash>\n");
        return arg_invalid;
    }

    char* salt = get_salt(argv[1]);

    // char* plaintext = strcmp_in_dictionary(argv[1], salt);
    // if (plaintext != NULL)
    // {
    //     printf("%s\n", argv[1]);
    // }

    char* plaintext = strcmp_one_char(argv[1], salt);
    if (plaintext != NULL)
    {
        printf("%s\n", plaintext);
    }

    printf("hash: %s\n", argv[1]);
    return arg_invalid;
}

// See declaration above for what these does

int is_arg_invalid(int argc, char** argv)
{
    if (argc != 2)
    {
        return 1;
    }

    return 0;
}

char* get_salt(char* hash)
{
    char* salt = malloc(3);
    salt[0] = hash[0];
    salt[1] = hash[1];
    salt[2] = '\0';
    return salt;
}

char* strcmp_in_dictionary(char* hash, char* salt)
{
    return "A";
}

char* strcmp_one_char(char* hash, char* salt)
{
    for (int letter = 'A'; letter <= 'Z'; letter++)
    {
        char* plaintext = malloc(2);
        plaintext[0] = (char) letter;
        plaintext[1] = '\0';

        char* ciphertext = crypt(plaintext, salt);

        if (strcmp(ciphertext, hash) == 0)
        {
            return plaintext;
        }

        free(plaintext);
    }

    for (int letter = 'a'; letter <= 'z'; letter++)
    {
        char* plaintext = malloc(2);
        plaintext[0] = (char) letter;
        plaintext[1] = '\0';

        char* ciphertext = crypt(plaintext, salt);

        if (strcmp(ciphertext, hash) == 0)
        {
            return plaintext;
        }

        free(plaintext);
    }

    return NULL;
}