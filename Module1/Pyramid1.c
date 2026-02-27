#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;

    // 1. get user input [1, 8]
    do
    {
        n = get_int("height: ");
    }
    while (n < 1 || n > 8);

    // 2. loop (height)
    for (int i = 0; i < n; i++)
    {
        // print blank spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // print hashes
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}
