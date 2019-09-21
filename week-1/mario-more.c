#include <stdio.h>

void print_repeating_character(int n, char c);

int main(void)
{
    int height;
    do 
    { 
        height = get_int("How high should the pyramids be?\n");
    } 
    while (height < 1 || height > 8);
    for (int i = 1; i <= height; i++)
    {
        int spaces = height-i;
        int hashes = i;
        print_repeating_character(spaces, ' ');
        print_repeating_character(hashes, '#');
        printf("  ");
        print_repeating_character(hashes, '#');
        printf("\n");
    }
}

void print_repeating_character(int n, char c)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c", c);
    }
}
