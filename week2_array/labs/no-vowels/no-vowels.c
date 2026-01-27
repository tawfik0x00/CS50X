// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string input);

int main(int argc, string argv[])
{
    // check args
    if (argc != 2)
    {
        printf("Usage: %s + word\n", argv[0]);
        return 1;
    }
    // print replaced word
    printf("%s\n", replace(argv[1]));
}
string replace(string input)
{

    for (int i = 0; i < strlen(input); i++)
    {
        switch (input[i])
        {
            case 'a':
                input[i] = '6';
                break;
            case 'e':
                input[i] = '3';
                break;
            case 'i':
                input[i] = '1';
                break;
            case 'o':
                input[i] = '0';
                break;
            default:
                input[i] = input[i];
        }
    }

    return input;
}
