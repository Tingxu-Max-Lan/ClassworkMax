// Max 10/14/2022 credit card checker
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <tgmath.h>
long long num;
/* We ask the user for a long integer.
We create a function that finds the length of the integer
We create a function that implements Luhn's Algorithm
We check the user integer's length and leading numbers to do a first scan.
If it passes the first scan, we check it using Luhn's Algorithm
*/
//This function finds the length by dividing by 10 until the number is smaller than ten
int get_int_len(long long value)
{
    int l = 1;
    while (value > 9)
    {
        l++;
        value /= 10;
    }
    return l;
}
int validate(long n)
{

    //The algorithm records the rightmost digit in "temp" using mod10
    //If the digit needs to be doubled, we double it. If the doubled result is larger than 10, we subtract by 9.
    //We add the result into the variable "sum"
    //It chops the leftmost digit off by dividing by 10, since it has already been calculated
    //It repeats this for all digits, and does mod 10 to the sum to see if it is valid.
    long number = n;
    int sum = 0;
    sum = number % 10;
    number = number / 10;
    while (number)
    {
        int temp = (number % 10) * 2;
        if (temp > 9)
        {
            temp = temp - 9;
        }
        sum = sum + temp;
        number = number / 10;
        temp = number % 10;
        sum = sum + temp;
        number = number / 10;
    }
    while (n > 10)
    {
        n /= 10;
    }


    if (sum % 10)
    {
        return -1;
    }else{
        return 0;
    }

}

int main(void)
{

    num = get_long_long("Enter a number: ");

    long length = get_int_len(num);
    int valid = validate(num);
    if (length == 13)
    {

        if (floor(num / 1000000000000) == 4)
        {

            if (valid == -1)
            {
                printf("INVALID\n");
            }
            else
            {
                printf("VISA\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (length == 15)
    {
        if (floor(num / 10000000000000) == 34 || floor(num / 10000000000000) == 37)
        {

            if (valid == -1)
            {
                printf("INVALID\n");
            }
            else
            {
                printf("AMEX\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (length == 16)
    {
        if (floor(num / 1000000000000000) == 4)
        {

            if (valid == -1)
            {
                printf("INVALID\n");
            }
            else
            {
                printf("VISA\n");
            }
        }
        else if (floor(num / 100000000000000) == 51 || floor(num / 100000000000000) == 52 || floor(num / 100000000000000) == 53
                 || floor(num / 100000000000000) == 54 || floor(num / 100000000000000) == 55)
        {
            if (valid == -1)
            {
                printf("INVALID\n");
            }
            else
            {
                printf("MASTERCARD\n");
            }
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
}