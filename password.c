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
    char lol;
 int string;
    bool uppercase = false;
    bool lowercase = false;
    bool num = false;
    bool symbol = false;
    for(int i = 0; i < strlen(password); i++){
        lol = password[i];
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
