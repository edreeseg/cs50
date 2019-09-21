#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <crypt.h>

const int possible_digits = 52;

void print_combinations(char *arr, int *chosen, int index, int r, int start, int end, char *hash, char *salt);

// This is a program to determine a plain-text password from a hash using brute force.
// Passwords must be 5 characters or less, and only consist of A-Za-z.
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    char salt[2];
    salt[0] = argv[1][0];
    salt[1] = argv[1][1];
    
    // Begin to build an array consisting of all possible values.
    
    char possible_values[possible_digits];
    int counter = 0;
    for (int i = 'A'; i <= 'Z'; i++)
    {
        possible_values[counter++] = i;
    }
    for (int i = 'a'; i <= 'z'; i++)
    {
        possible_values[counter++] = i;
    }
    
    // Call recursive function for length = 1 through length = 5.
    
    for (int i = 0; i < 5; i++)
    {
        int chosen[i + 1];
        print_combinations(possible_values, chosen, 0, i + 1, 0, possible_digits - 1, argv[1], salt);    
    }
    return 0;
}

// This is a recursive function to examine all possible combinations of A-Za-z characters,
// including duplicates.  Function will call exit(0) to end program if a match is found.

void print_combinations(char *arr, int *chosen, int index, int r, int start, int end, char *hash, char *salt)
{
    if (index == r)
    {
        // Constructing possible password
        char password[r];
        for (int i = 0; i < r; i++)
        {
            password[i] = arr[chosen[i]];
        }
        // Comparing hash of password to hash provided as argv[1].
        if (strcmp(crypt(password, salt), hash) == 0)
        {
            printf("%s\n", password);
            exit(0);
        }
        return;
    }
    for (int i = start; i <= end; i++)
    {
        chosen[index] = i;
        print_combinations(arr, chosen, index + 1, r, start, end, hash, salt);
    }
}
