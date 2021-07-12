#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int num_steps;
    do
    {
        num_steps = get_int("Height: ");
    }
    while (num_steps < 1 || num_steps > 8);

    int i;
    i = num_steps - 1;
    int cntouter;
    for (cntouter = 0; cntouter < num_steps; cntouter++)
    {
        int cnt;
        for (cnt = 0; cnt < num_steps; cnt++)
        {
           if (cnt < i)
           {
               printf(" ");
           }
           else
           {
               printf("#");
           }
        }
        printf("  ");
        for (cnt = 0; cnt < num_steps; cnt++)
        {
           if (cnt >= i)
           {
               printf("#");
           }
        }

        printf("\n");
        i--;
    }
}
