#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int money;
    do
    {
        float total = get_float("Change owed: ");
        money = round(total * 100);
    }
    while (money <= 0);

    int quarters = money / 25;
    int dimes = (money % 25) / 10;
    int nickels = ((money % 25) % 10) / 5;
    int pennies = ((money % 25) % 10) % 5;

    printf("%d\n", quarters + dimes + nickels + pennies);

    return 0;
}
