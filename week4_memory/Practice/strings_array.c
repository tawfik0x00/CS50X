#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    char *name;
    int number;
}
player;

int main(void)
{
    char *name[1];
    scanf("%s", name[0]);

    printf("%s\n", name[0]);
    /*
    for (int i = 0; i < 3; i++)
    {
        printf("Adresses of array[%i]\n", i);

        for (int j = 0; j < strlen(array[i]); j++)
        {
            printf("%p\n",&array[i][j]);
        }
    }
    */

}