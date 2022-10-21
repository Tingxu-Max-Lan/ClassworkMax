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
   int mode = 1;
int twos;
int countBits(int n)
{
   int count = 1;
   while (n)
   {
        count++;
        n >>= 1; //shifts the bits to the right by one, effectly dividing by two
    }
    return count;
}
int find(int start, int base){
    int sum = 0;
    int nDigits = floor(log10(abs(base))) + 1;
    for(int i = 1; i < nDigits; i++){
        sum = sum + pow(floor(start/10^(i-1)),base^i);
    }
    return sum;
}
void print(int array[], int length){

       for(int i = length; i >= 0;i--){
             if(array[i] == 10){
                  printf("A");
            }else if(array[i] == 11){
                 printf("B");
            }else if(array[i] == 12){
                 printf("C");
            }else if(array[i] == 13){
                 printf("D");
            }else if(array[i] == 14){
                 printf("E");
            }else if(array[i] == 15){
                 printf("F");
            }else if(array[i] == 16){
                 printf("G");
            }else{
        printf("%i", array[i]);}
    }
    printf(" \n");
}
void calc(int base, int num){
    int array[32];

    int i = 0;
    while(num >= base){
        array[i]=num%base;
        num /= base;
        i++;
    }
    array[i]=num;
    print(array,i);
}
int main(void){

        int num;
    do{num = get_int("enter number: ");}
    while(num < 0);
    int base;
    do{base = get_int("enter base: ");}
    while(base < 0 || base > 16);
    calc(base,num);


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
