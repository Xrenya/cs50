#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int compute_score(string text);

int main(void)
{
    // Get text input
    string text = get_string("Text: ");

    int score = compute_score(text);

    if (score <= 1)
    {
        printf("Before Grade %i\n", score);
    }
    else if (score < 16)
    {
        printf("Grade %i\n", score);
    }
    else
    {
        printf("Grade 16+\n");
    }

    return 0;
}

int compute_score(string text)
{
    int letters = 0, words = 0, sentences = 0;
    for (int i = 0, n = strlen(text)+1; i < n; i++)
    {
        char s = text[i];
        if ((s >= 65 && s <= 90) || ( s >= 97 && s <= 122))
        {
            letters++;
        }
        else if (s == ' ' || s == '\0')
        {
            words++;
        }
        else if ((s == '.') || (s == '?') || (s == '!'))
        {
            sentences++;
        }
    }
    int index = round(0.0588 * (letters / (float) words * 100.0) - 0.296 * (sentences / (float) words * 100.0) - 15.8);
    return index;
}
