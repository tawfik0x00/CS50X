#include <cs50.h>
#include <stdio.h>

long get_credit_number(void);
int check_sum(long number);
void print_card_type(long number);
int get_prefix(long number);
int get_length(long number);

int main(void)
{
    // get the number and check the length of the number
    long number = get_credit_number();
    if (number == -1)
    {
        printf("INVALID\n");
        return 0;
    }

    // make luhan checksum.
    int result = check_sum(number);
    if (result != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // print the type of the card
    print_card_type(number);
    return 0;
}
int get_length(long number)
{
    // to get the length of a decimal number digits
    // every time divide by 10 we delete a number from digits from the right.
    // until it reach 0

    int length = 0;
    while (number != 0)
    {
        number /= 10;
        length++;
    }
    return length;
}
long get_credit_number(void)
{
    // get credit as long number
    long number = get_long("Number: ");
    // get the length of the number
    int length = get_length(number);
    // check the length of the number
    if (length == 13 || length == 15 || length == 16)
    {
        return number;
    }
    else
    {
        return -1;
    }
}
int check_sum(long number)
{
    /*
    Input: take the number of the credit
    Output: its return a 0 if number is correct, otherwise false.
    */

    int last_digit, second_last;
    int sum1 = 0, sum2 = 0;

    // while number not reach 0 keep going.
    while (number != 0)
    {
        // get the last digit
        last_digit = number % 10;
        // delete the last digit from the number
        number = number / 10;
        // add it to sum1
        sum1 += last_digit;

        // the second last digit
        second_last = number % 10;
        // delete the digit from number
        number = number / 10;

        // multiply second last by 2 if greater than 9 subtract 9.
        second_last *= 2;
        second_last -= (second_last > 9) ? 9 : 0;
        sum2 += second_last;
    }

    // return 0 if is ok
    return (sum1 + sum2) % 10;
}
int get_prefix(long number)
{
    // while number >= 100 will give me two digits
    while (number >= 100) // stop at 100 to get first two digits
    {
        number /= 10;
    }

    // return an int cast from long to int.
    return (int) number;
}

void print_card_type(long number)
{
    int prefix = get_prefix(number);
    int length = get_length(number);

    // to define type of card we need to check length and prefix of a number.

    if ((prefix / 10 == 4) && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    else if ((prefix / 10 == 3) && (prefix % 10 == 4 || prefix % 10 == 7) && (length == 15))
    {
        printf("AMEX\n");
    }
    else if ((prefix / 10 == 5) && (prefix % 10 > 0 && prefix % 10 < 6) && (length == 16))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
