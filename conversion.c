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

}
void calc(int n, int num){
    int length = countBits(n) - 1;
    int bits;
    if (n == 2){
        bits = twos-1;
    }else{
 bits = ceil((double)twos/length);}

    int array[bits];
    for(int i = 0; i < bits ; i++){

        array[i]=num%n;
        num /= n;
        num = floor(num);
    }

        print(array,bits-1);
}
int main(void){
    int num;
    do{num = get_int("enter number: ");}
while(num < 0);

    twos = countBits(num);
calc(2,num);
printf(" \n");
calc(8,num);
printf(" \n");
calc(16,num);
printf(" \n");
    int yes;
    do{
    yes = get_int("retry? press 1 for yes, 2 for no: ");
    }
    while(yes != 1 && yes!= 2);
    if(yes == 1){
        main();
    }

}