// Program that calculates the exact amount of coins to be given to a customer in a store cashier, to be applied in both US and EU's currency: 25c, 10c, 5c and 1c

#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;

    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    return cents;
}

// Returns the number of quarters that should be given to the customer
int calculate_quarters(int cents)
{
    int quarters = cents / 25;
    printf("Quarters: %d\n", quarters);
    return quarters;
}

// Returns the number of dimes that should be given to the customer
int calculate_dimes(int cents)
{
    int dimes = cents / 10;
    printf("Dimes: %d\n", dimes);
    return dimes;
}

// Returns the number of nickels that should be given to the customer
int calculate_nickels(int cents)
{
    int nickels = cents / 5;
    printf("Nickels: %d\n", nickels);
    return nickels;
}

// Returns the number of pennies that should be given to the customer
int calculate_pennies(int cents)
{
    int pennies = cents / 1;
    printf("Pennies: %d\n", pennies);
    return pennies;
}
