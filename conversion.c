#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*
Create a function "countBits" that counts the minimum number of bits needed to represent a decimal number in binary, given an integer as its parameter
Create a function "print" that prints an array given an array and its length as parameters
Create a function "calc" that creates a number of base n in array form, given n and a decimal number.
This function calls the array pinting function to print the array.
Ask the user for a positive integer
We run the calc function using the user input number and bases 2,8,16
We ask the user if they want to try again
*/
int mode = 0;
void print(int *adress){
       for(int i = adress[0]; i >= 1;i--){
        if (adress[i] > 9) printf("%c",adress[i] % 10 + 'A');
        else printf("%i", adress[i]);
        }
         printf("\n");
    }


int * calc(int base, int num){
    static int array[32];
    int i = 1;
    while(num >= base){
        array[i]=num%base;
        num /= base;
        i++;
    }
    array[0] = i;
    array[i]=num;
    return(array);
}
int main(void){
    int num;
    do{num = get_int("enter number: ");}
    while(num < 0);
    int base;
    do{base = get_int("enter base: ");}
    while(base < 0 || base > 16);
    print(calc(base,num));
    int yes;
    do{
    yes = get_int("retry? press 1 for yes, 2 for no ");
    }
    while(yes != 1 && yes!= 2);
    if(yes == 1){
        main();
        mode = 0;
    }
}