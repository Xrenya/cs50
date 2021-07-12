#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Input population size:
    // Start size: 100
    // End size: 200
    // Output years when population size will reach End size
    // if n/3 of population increment every year
    // and n/4 of population decrement every year
    // Ouput:
    // Years: 9
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    int years = 0;
    while (start < end)
    {
        start = start + start / 3 - start / 4;
        years++;
    }
    printf("Years: %i\n", years);
    return 0;
}
