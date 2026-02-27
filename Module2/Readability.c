#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // 1 User input
    string text = get_string("Text: ");

    int letters = 0;
    int words = 1;
    int sentences = 0;

    // 2. Count letters, words and phrases
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Counting letters
        if (isalpha(text[i]))
        {
            letters++;
        }
        // Counting words
        else if (text[i] == ' ')
        {
            words++;
        }
        // Counting phrases
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    // 3 L and S
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    // 4 Coleman-Liau
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    // 5 Print out results 
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
