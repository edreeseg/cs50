#include <cs50.h>
#include <stdio.h>
#include <string.h>

int shift(char c);

// This is a program to print ciphertext based on
// vigenere keyword and plaintext provided by user.

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    string keyword = argv[1];
    int kw_len = strlen(keyword);
    for (int i = 0; i < kw_len; i++)
    {
        if (!(keyword[i] >= 'A' && keyword[i] <= 'Z') && !(keyword[i] >= 'a' && keyword[i] <= 'z'))
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }
    string plaintext = get_string("plaintext: ");
    int pt_len = strlen(plaintext);
    printf("ciphertext: ");
    
    // Determine how much value will change based on 
    // keyword[j]'s value.

    for (int i = 0, j = 0; i < pt_len; i++)
    {
        int difference = shift(keyword[j]);
        // Determine whether change will cause new value to be out
        // of acceptable range, and reduce difference to compensate.
        
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            while (plaintext[i] + difference > 'Z')
            {
                difference -= ('Z' - 'A' + 1);
            }
            printf("%c", plaintext[i] + difference);
            j++;
        }
        else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            while (plaintext[i] + difference > 'z')
            {
                difference -= ('z' - 'a' + 1);
            }
            printf("%c", plaintext[i] + difference);
            j++;
        }
        else 
        {
            printf("%c", plaintext[i]);
        }
        
        // Reset j if out of acceptable range

        if (j > kw_len - 1)
        {
            j = 0;
        }
    }
    printf("\n");
    return 0;
}

int shift(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A';
    }
    else 
    {
        return c - 'a';
    }
}