#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int start;
    int end;
    int years = 0;

    // 1. input for start size
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // 2. input for end size
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // 3. calculate number of years

    while (start < end)
    {
        int births = start / 3;
        int deaths = start / 4;
        start = start + births - deaths;
        years++;
    }

    // 4. print number of years
    printf("Years: %i\n", years);
}
