#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long num = get_long("Number: ");

    int odd_summator = 0;
    int even_summator = 0;
    int last_digit = 0;
    int position = 1;
    int two_digit = 0;
    int previous_digit = 0;
    while (num > 0)
    {
        previous_digit = last_digit;
        last_digit = num % 10;
        num = num / 10;

        if (position % 2 == 0)
        {
            int output = last_digit * 2;
            even_summator += output % 10 + output / 10;

        }
        else
        {
            odd_summator += last_digit;
        }

        position++;
    }
    position -= 1;
    two_digit = last_digit * 10 + previous_digit;
    if ((even_summator + odd_summator) % 10 == 0)
    {
        if (position >= 13 && position <= 16 && last_digit == 4)
        {
            printf("VISA\n");
        }
        else if (position == 16 && two_digit >= 51 && two_digit <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (position == 15 && (two_digit == 34 || two_digit == 37))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
