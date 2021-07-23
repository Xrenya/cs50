#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else
    {
        if (strlen(argv[1]) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            for (int i=0, m=strlen(argv[1])-1; i<m; i++)
            {
                if ((argv[1][i] > 90 && argv[1][i] < 97) || (argv[1][i] < 65 || argv[1][i] > 122))
                {
                    printf("Key must contain 26 characters.fsdf\n");
                    return 1;
                }
                for (int j=i+1, k=strlen(argv[1]); j<k; j++)
                {
                    if (argv[1][i] == argv[1][j])
                    {
                        printf("Key must contain 26 characters.11\n");
                        return 1;
                    }
                }
            }

            string s = get_string("plaintext:  ");
            for (int p=0, n=strlen(s); p<n; p++)
            {
                if (s[p] >= 65 && s[p] <= 90)
                {
                    int pos = s[p] - 65;
                    s[p] = toupper(argv[1][pos]);
                }
                else if (s[p] >= 97 && s[p] <= 122)
                {
                    int pos = s[p] - 97;
                    s[p] = tolower(argv[1][pos]);
                }
            }
            printf("ciphertext: %s\n", s);
            return 0;
        }
    }
}
