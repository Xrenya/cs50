#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long num = get_long("Number: ");

    int odd_summator = 0;
    int even_summator = 0;

    int position = 1;

    while (num > 0)
    {
        int last_digit = num % 10;
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
    if ((even_summator + odd_summator) % 10 == 0)
    {
        printf("VISA");
    }
    else
    {
        printf("INVALID");
    }

    return 0;
}
