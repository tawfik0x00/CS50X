#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_cipher_text(string text, int k);
int check_key(string key);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    int result = check_key(argv[1]);
    if (result == -1)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    // Convert argv[1] from a `string` to an `int`
    int k = atoi(argv[1]);

    // stay in the domain
    k = k % 26;

    // Prompt user for plaintext
    string plaintext = get_string("plaintext:  ");

    print_cipher_text(plaintext, k);
    return 0;
}
void print_cipher_text(string text, int k)
{
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        printf("%c", rotate(text[i], k));
    }
    printf("\n");
}
int check_key(string key)
{
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isdigit(key[i]))
        {
            return -1;
        }
    }

    return 0;
}
char rotate(char c, int n)
{
    if (isalpha(c))
    {
        if (isupper(c))
        {
            int ci = c - 'A';
            ci = (ci + n) % 26; // stay in the domain
            return ci + 'A';
        }
        else
        {
            int ci = c - 'a';
            ci = (ci + n) % 26; // stay in the domain
            return ci + 'a';
        }
    }
    else
    {
        return c;
    }
}
