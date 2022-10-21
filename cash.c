#include <cs50.h>
#include <stdio.h>
#include <math.h>
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
/* Max Lan 10/11/2022
We first create functions that calculate the number of coins that can be used for a certain amount of money.
For example, 79 cents can have a maximum amount of 3 quarters in it, since 79/25 rounded down is 3. This would be the job of calculate_quarters.
We call these functions from largest (quarters) to smallests, storing each value along the way, ensuring
that the maximum amount of big coins are used before moving to a smaller coin.
This minimizes the amount of coins needed for any payment.
We add the output for each function to get the total amount of coins needed for the payment.
*/
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
    //asks for an amount of money from the user that is valid (larger than zero)
    int cent;
    do
    {
        cent = get_int("Give a number: ");
    }
    while (cent < 0);
    return cent;
}
//each of these are identical: we divide the money by the value of the coin and round down, since we cant have a non-integer amount of coins
int calculate_quarters(int cents)
{
    return floor(cents / 25);
}

int calculate_dimes(int cents)
{
    return floor(cents / 10);
}

int calculate_nickels(int cents)
{
    return floor(cents / 5);
}

int calculate_pennies(int cents)
{
    return cents;
}
