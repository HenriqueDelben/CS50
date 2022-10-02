#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Validades if it was typed only one argument
bool only_one_argument(int argc);

// Validates if the argument is a integer
bool only_digits(string argv);

// Validates if the argument is a positive integer
bool only_positive_integers(string argv);

// Enciphers each letter of the plain text
char rotate(char letter, int key);

int main(int argc, string argv[])
{
    if (only_one_argument(argc) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    if (only_positive_integers(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string plaintext = get_string("plaintext:  ");

    // Calls the function "rotate" for each letter to be encrypted

    printf("ciphertext: ");

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }

    printf("\n");
    return 0;
}

// Returns if there is only one argument
bool only_one_argument(int argc)
{
    if (argc != 2)
    {
        return false;
    }

    return true;
}

// Returns if the argument is a digit
bool only_digits(string argv)
{
    bool isdigit;
    for (int i = 0, n = strlen(argv); i < n; i++)
    {
        if (isdigit(argv[i]) != 0)
        {
            isdigit = true;
        }
        else
        {
            isdigit = false;
        }
    }

    return isdigit;
}

// Returns if the argument is a positive number
bool only_positive_integers(string argv)
{
    if (atoi(argv) < 0)
    {
        return false;
    }

    return true;
}

// Returns each letter encrypted of the plain text
char rotate(char letter, int key)
{
    if (isalpha(letter) == false)
    {
        return letter;
    }

    if (isupper(letter))
    {
        letter = ((letter + key - 65) % 26) + 65;

        return letter;
    }

    letter = ((letter + key - 97) % 26) + 97;

    return letter;
}