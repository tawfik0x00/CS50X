#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int check_the_key(string key);
void print_cipher(string text, string key);

int main(int argc, string argv[])
{
    // check command-line argument
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    // validate the key
    int result = check_the_key(argv[1]);
    if (result == -1)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

    // take the input from the user
    string plaintext = get_string("plaintext: ");
    print_cipher(plaintext, argv[1]);
}
int check_the_key(string key)
{
    int length = strlen(key);

    // first check the length
    if (length != 26)
    {
        return -1;
    }
    // check if the key contain any digits or symbols
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            return -1;
        }
    }
    // check if characters repeated
    for (int i = 0; i < length - 1; i++)
    {
        char c1 = tolower(key[i]);
        // compare each character with each character start from the next position
        for (int j = i + 1; j < length; j++)
        {
            // check only on one case
            char c2 = tolower(key[j]);

            if (c1 == c2)
            {
                return -1;
            }
        }
    }

    return 0;
}
void print_cipher(string text, string key)
{
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            // get the index of the letter
            int index;
            if (isupper(text[i]))
            {
                index = text[i] - 'A';
                printf("%c", toupper(key[index]));
            }
            else
            {
                index = text[i] - 'a';
                printf("%c", tolower(key[index]));
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
