#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

// This is a program to identify both whether or
// not a credit card number is valid, and what
// company the card is associated with.

bool is_valid_number(string card);
bool is_visa(string card);
bool is_amex(string card);
bool is_mastercard(string card);

int main(void)
{
    long card = get_long("Enter card number:\n");
    long replica = card;
    int digits = 0;
    while (replica > 1)
    {
        replica /= 10;
        digits++;
    }
    char card_str[digits];
    sprintf(card_str, "%ld", card);
    if (is_valid_number(card_str) && (digits <= 16 && digits >= 13))
    {
        if (is_visa(card_str))
        {
            printf("VISA\n");
        }
        else if (is_amex(card_str))
        {
            printf("AMEX\n");
        }
        else if (is_mastercard(card_str))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

// Checks if card is affiliated with Visa.
bool is_visa(string card)
{
    return card[0] == '4';
}

// Checks if card is affiliated with American Express.
bool is_amex(string card)
{
    return card[0] == '3' && (card[1] == '4' || card[1] == '7');
}

// Checks if card is affiliated with Mastercard.
bool is_mastercard(string card)
{
    return card[0] == '5' && (card[1] == '1' || card[1] == '2' || card[1] == '3' || card[1] == '4' || card[1] == '5');
}

// Checks to ensure card number is valid.
bool is_valid_number(string card)
{
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < strlen(card); i++)
    {
        int current = card[i] - '0';
        if (i % 2 == strlen(card) % 2)
        {
            int ones = current * 2 % 10;
            int tens = current * 2 / 10;
            sum1 += tens + ones;
        }
        else
        {
            sum2 += current;
        }
    }
    int final_sum = sum1 + sum2;
    return final_sum % 10 == 0;
}