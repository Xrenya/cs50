#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (!isdigit(*argv[1]))
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
        else
        {
            // Take string input from user and change it data type into int
            int k = atoi(argv[1]);
            // Getting string input from user
            string s = get_string("plaintext:  ");
            for (int i=0, n=strlen(s); i<n; i++)
            {
                // Checking the capital letter
                if (s[i] >= 65 && s[i] <= 90)
                {
                    int c = s[i] - 65;
                    // Calculating positing of the word
                    int pos = 65 + ((c  + k) - (c  + k) / 26 * 26) % 26;
                    s[i] = (char) pos;
                }
                // Else it is not capital letter
                else if (s[i] >= 97 && s[i] <= 122)
                {
                    int c = s[i] - 97;
                    // Calculating positing of the word
                    int pos = 97 + ((c  + k) - (c  + k) / 26 * 26) % 26;
                    s[i] = (char) pos;
                }
            }
            printf("ciphertext: %s\n", s);
            return 0;
        }
    }
    else
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    return 0;
}
