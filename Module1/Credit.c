#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // 1. get input
    long number = get_long("Number: ");

    // 2. variables for luhn's algorithm
    int sum = 0;
    int count = 0;
    long temp_number = number;
    long start_digits = number;

    // 3. apply luhn's algorithm
    while (temp_number > 0)
    {
        int digit = temp_number % 10;

        // every second digit from the right
        if (count % 2 != 0)
        {
            int product = digit * 2;
            // add digits of the product
            sum += (product / 10) + (product % 10);
        }
        else
        {
            // digits that were not multiplied
            sum += digit;
        }

        temp_number /= 10;
        count++;
    }

    // 4. validate checksum (must end in 0)
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // 5. get the first two digits for brand identification
    while (start_digits >= 100)
    {
        start_digits /= 10;
    }
    int first_two = start_digits;
    int first_one = first_two / 10;

    // 6. check brand 
    if (count == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (count == 16 && (first_two >= 51 && first_two <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((count == 13 || count == 16) && first_one == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
