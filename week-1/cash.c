#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    do 
    {
        dollars = get_float("Change owed: ");
    } 
    while (dollars < 0);
    int cents = round(dollars * 100);
    int coin_count = 0;
    int coins[4] = { 25, 10, 5, 1 };
    int length = sizeof(coins)/sizeof(coins[0]);
    for (int i = 0; i < length; i++)
    {
        while (cents >= coins[i])
        {
            cents -= coins[i];
            coin_count++;
        }
    }
    printf("%i\n", coin_count);
    return 0;
}
