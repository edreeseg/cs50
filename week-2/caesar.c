#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Program for generating caesar cipher based on argument
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Return error code if any character in argument is
    // not numerical.
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int n = atoi(argv[1]);
    string plain_text = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, len = strlen(plain_text); i < len; i++)
    {
        char c = plain_text[i];
        int new_c = c + n;
        
        // If character is a capital letter
        if (c >= 'A' && c <= 'Z')
        {
            while (new_c > 'Z')
            {
                new_c -= ('Z' - 'A' + 1);
            }
            printf("%c", new_c);
        }
        // If character is a lowercase letter
        else if (c >= 'a' && c <= 'z')
        {
            while (new_c > 'z')
            {
                new_c -= ('z' - 'a' + 1);
            }
            printf("%c", new_c);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}