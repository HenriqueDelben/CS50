#include <cs50.h>
#include <stdio.h>
#include <math.h>

long long get_number(void);
bool get_checksum(long long card_number);
int get_num_digits(long long card_number);
void get_payment_network(long long card_number, int num_digits, bool is_valid);

int main(void)
{
    // Prompts the user for the card number
    long long card_number = get_number();

    // Calculate the checksum to see if the number is valid
    bool checksum = get_checksum(card_number);

    if (checksum == true)
    {
        // Calculate the number of digits
        int num_digits = get_num_digits(card_number);

        // Get the card brand
        get_payment_network(card_number, num_digits, checksum);
    }

    else
    {
        printf("INVALID\n");
    }


}

long long get_number(void)
{
    long long card_number;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);

    return card_number;
}

bool get_checksum(long long card_number) // bool
{
    int sum = 0;
    int i = 1;
    while (card_number > 1)
    {
        // Gets each digit
        long long digit = card_number % 10;

        // Gets if the digit is even
        if (i % 2 == 0)
        {
            digit *= 2;

            // Gets the sum of a digit which has 2 digits when multiplied by two
            if (digit >= 10)
            {
                int separate_digits = digit % 10;
                separate_digits += (digit % 100) / 10;
                sum += separate_digits;
            }
            // Gets the sum of a digit which has 1 digit when multiplied by two
            else
            {
                sum += digit;
            }
        }

        // Gets if the digit is odd
        else
        {
            sum += digit;
        }

        card_number = card_number / 10;
        i++;
    }
    // Returns if the checksum is valid or not
    bool checksum;

    if (sum % 10 == 0)
    {
        checksum = true;
    }

    else
    {
        checksum = false;
    }
    return checksum;
}

// Returns the number of digits
int get_num_digits(long long card_number)
{
    int num_digits = 0;

    do
    {
        num_digits += 1;
        card_number /= 10;
    }
    while (card_number >= 1);
    return num_digits;
}

// Returns the payment network
void get_payment_network(long long card_number, int num_digits, bool checksum)
{
    // Identify if the card brand is AMEX
    if ((card_number >= 34e13 && card_number < 35e13) || (card_number >= 37e13 && card_number < 38e13))
    {
        printf("AMEX\n");
    }

    // Identify if the card brand is MASTERCARD
    else if (card_number >= 51e14 && card_number < 56e14)
    {
        printf("MASTERCARD\n");
    }

    // Identify if the card brand is VISA
    else if ((card_number >= 4e12 && card_number < 5e12) || (card_number >= 4e15 && card_number < 5e15))
    {
        printf("VISA\n");
    }

    // Identify if the card is not valid
    else
    {
        printf("INVALID\n");
    }
}
