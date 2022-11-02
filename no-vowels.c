// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void replace(string word);

int main(int argc, string argv[])
{
    if(argc != 2){
        printf("You must input one word\n");
        return 1;
    }

    replace(argv[1]);

}
void replace(string word)
{
    for(int i = 0; i <strlen(word); i++){

        switch(word[i])
        {
        case 'a' :
          word[i] = '6';
         break;
         case 'o' :
          word[i] = '0';
         break;
         case 'i' :
          word[i] = '1';
         break;
         case 'e' :
          word[i] = '3';
         break;
         default:
         break;
        }
    }
    printf("%s \n", word);
}
