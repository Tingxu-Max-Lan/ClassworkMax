// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <regex.h>
#include <string.h>
bool valid(string password);
//We get a user input, and then run that input through our valid function. The valid function is a for loop that goes through each character of the string.
//If the character we are checking is uppercase, lowercase, number, or symbol, we set the corresponding boolean to true. If all the booleans are true by the end of 
//The for loop, the function returns true. Otherwise, it returns false.
//We print out a message corresponding with whether the password was valid or not 
int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}
bool valid(string password){
    char temp; //this stores the current character we are checking
 int string;
    bool uppercase = false;
    bool lowercase = false;
    bool num = false;
    bool symbol = false;
    for(int i = 0; i < strlen(password); i++){
        temp = password[i];
    if(isupper(lol)){
        uppercase = true;
    }
    if(islower(lol)){
        lowercase = true;
    }
    if(ispunct(lol)){
        num = true;
    }
    if(isdigit(lol)){
        symbol = true;
    }
    }
    if(uppercase && lowercase && num && symbol){
        return true;
    }else{
    return false;
    }

}
