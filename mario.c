#include <cs50.h>
#include <math.h>
#include <stdio.h>
// 10/10/2022 Mario code
/*
we create two functions that can print a specified amount of spaces and hashes respectively
we ask the user for a valid height
we run a for loop that runs "height" amount of times
we print (height - current row's hash height) spaces in order to make sure that each row
has the same amount of total hashes and spaces. This way, the pyramid will be centered
we print out the left side of the pyramid, the middle spaces, and then the right side of the pyramid
we create a new line for the next row of the pyramid.


function for printing spaces*/
void lol(w)
{
    for (int j = 0; j < w; j++)
    {
        printf(" ");
    }
}
// function for printing hashes
void kek(w)
{
    for (int j = 0; j < w; j++)
    {
        printf("#");
    }
}
int main(void)
{
    // gets the user height
    double bruh;
    int limit;
    do
    {
        limit = get_int("How tall: ");
    } while (limit < 1 || limit > 8);
    for (int i = 1; i < limit + 1; i++)
    {
        // prints out spaces to center the pyramid
        lol(limit - i);
        // prints out the left side of the pyramid
        kek(i);
        // prints out the middle space
        printf("  ");
        // prints out the right side of the pyramid
        kek(i);
        printf("\n");
    }
}