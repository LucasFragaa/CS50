#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;

    // 1. user input (must be non-negative)
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    // 2. Convert dollars to cents
    int cents = round(dollars * 100);

    // 3. Initialize coin counter
    int coins = 0;

    // 4. greedy algorithm

     while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }

    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }

    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }

    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }

    // 5. Print the total number of coins
    printf("%i\n", coins);
}
