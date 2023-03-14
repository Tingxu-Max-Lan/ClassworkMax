#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
//structure for each entry in the leaderboard, containing the points and the player name.
typedef struct
{
    int points;
    char name[20];
    char date[20];
} Player;
void addToScoreboard(int numberOfGuesses, int time, int a)
{
    //a determines whether we want to open the scoreboard or write to it
    if (a == 1)
    {
        char name[20];
        char date[20];
        Player player;
        //calculate the player's points and ensures its not negative.
        player.points = numberOfGuesses * 10 - time;
        if(player.points < 0){
            player.points=0;
        }
        FILE *scoreboardFile = fopen("scoreboard.txt", "a");
        //creates an empty player struct
        //asks for name, copies it to the struct
        printf("\n\nGive name: ");
        scanf("%s", name);
        strcpy(player.name, name);
        //same thing with date
        printf("\n\nGive date: ");
        scanf("%s", date);
        strcpy(player.date, date);
        //adds struct to text
        fprintf(scoreboardFile, "Name: %s \nDate: %s \nPoints: %d\n\n", player.name, player.date, player.points);
        fclose(scoreboardFile);
    }
    else
    {
        system("clear");
        FILE *fptr;
        fptr = fopen("scoreboard.txt", "r");
        char c;
        if (fptr == NULL)
        {
            printf("Cannot open file \n");
            exit(0);
        }
        //prints out the entire scoreboard one character at a time
        c = fgetc(fptr);
        while (c != EOF)
        {
            printf("%c", c);
            c = fgetc(fptr);
        }

        fclose(fptr);
        printf("\nPress 1 to return to menu:\n");
    }
}
//function for adding a character to the end of a string array
void append(char *s, char c)
{
    int len = strlen(s);
    s[len] = c;
    s[len + 1] = '\0';
}
//Function to print out updated information while in the game.
//x is the guessed letter, y is the word, z is the number of guesses.
int printword(char *x, char *y, int z)
{
    system("clear");
    printf("Guesses: %i\n", z);
    int over = 0;
    for (int i = 0; i < strlen(y); i++)
    {
        //if the current letter in the word has been guessed, print that letter
        if (strchr(x, y[i]))
        {
            printf("%c", y[i]);
        }
        //if it has not been guessed, hide it.
        else
        {
            printf("_ ");
            //Since there is a letter within the word that the user hasn't guessed, the game is not over.
            over = 1;
        }
    }
    printf("\nGuessed Letters: %s", x);
    printf("\nEnter Guess:");
    return over;
}
//function that pauses the program until the user inputs a number from x to y, and returns that number.
int listen(int x, int y)
{
    int w = 0;
    while (w == 0)
    {
        //ensures that the user has entered an integer
        if (scanf("%d", &w) != 1)
        {
            //clears the scanf buffer if it doesn't. This prevents crashes.
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
        }
        //checks if the integer inputted is between x and y.
        for (int i = x; i <= y; i++)
        {
            //return the integer if it is between x and y
            if (w == i)
            {
                return w;
            }
        }
        //if it is not between x and y, we set w to zero, effectively repeating the loop
        w = 0;
        printf("\x1b[1F"); // Move to beginning of previous line
        printf("\x1b[2K"); // Clear entire line
    }
    //should never happen
    return -1;
}
//main function for starting a game
void game(int x)
{
    //list of words
    const char *a[10];
    a[0] = "wapiti";
    a[1] = "bibble";
    a[2] = "syzygy";
    a[3] = "ajijic";
    a[4] = "lhotse";
    a[5] = "chador";
    a[6] = "coulee";
    a[7] = "remuda";
    a[8] = "cerous";
    a[9] = "reddit";
    const char *b[10];
    b[0] = "goldenknight";
    b[1] = "archers";
    b[2] = "xbow";
    b[3] = "golem";
    b[4] = "royalrecruits";
    b[5] = "electrogiant";
    b[6] = "dartgoblin";
    b[7] = "elitebarbarians";
    b[8] = "firecracker";
    b[9] = "rocket";
    //set the seed for our randomizer based on time. ensures that the randomizer appears random to the user.
    srand(time(NULL));
    //picks a random number, limits it between 0 and 9
    int r = rand() % 10;
    //declare user guesses and array of guessed characters respectively
    int chances = 7;
    char right[26];
    //clears array to prevent bugs
    right[0] = '\0';
    //array for user input
    char g[2];
    //chooses potential random word from both arrays using the random number
    char answer[strlen(a[r])];
    char answer1[strlen(b[r])];
    //chooses the word to use based on which list the user inputted (stored in x)
    if (x == 1)
    {
        strcpy(answer, a[r]);
    }
    else
    {

        strcpy(answer, b[r]);
    }
    time_t start, end;
    double dif;
    //starts a timer
    time(&start);
    //prints word until the word is completely printed or the user runs out of guesses
    while (chances > 0 && printword(right, answer, chances) == 1)
    {
        //asks for user input until they enter a letter
        if (scanf("%1s", g) != 1)
        {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
        }
        if (strpbrk(answer, &g[0]) != 0)
        {
            //If the guessed letter matches a letter within the word
            //add that letter to guessed letters
            append(right, g[0]);
        }
        else if (strpbrk(right, &g[0]) != 0)
        {
            //If the guessed letter matches a letter already guessed
            //simply don't do anything, and the loop will ask for another
        }
        else
        {
            //If the guessed letter has not been guessed and is not in the word
            //add that letter to guessed letters, decrease chances by one
            append(right, g[0]);
            chances--;
        }
    }
    //game is finished, end timer and calculate time
    time(&end);
    dif = difftime(end, start);
    system("clear");
    //prints correct message depending on whether the user won or not
    if (chances == 0)
    {
        printf("You lose! The answer was: %s.", answer);
    }
    else
    {
        //If they won, print their time and guesses, and ask them to enter their score on the leaderboard
        printf("You win! Guesses left: %i. Time used: %.1f", chances, dif);
        addToScoreboard(chances, dif, 1);
    }
    printf("Press 1 to return to menu: \n");
}

void menu(void)
{
    //menu print
    system("clear");
    printf("------------------------------------------\n");
    printf("|1. Instructions                         |\n");
    printf("|2. Play List 1: Six Letter Words        |\n");
    printf("|3. Play List 2: Toxic Clash Royale Cards|\n");
    printf("|4. Scoreboard                           |\n");
    printf("|5. Exit Program                         |\n");
    printf("------------------------------------------\n");
    //waits for user input from 1-5 and acts correspondingly
    int input = listen(1, 5);
    if (input == 1)
    {
        printf("Instructions: We will give you 7 tries to guess a random word from your selected list.\nAll of the letters in the word is replaced with dashes. You play by guessing one letter at a time.\nIf you guess a letter correctly, all instances of that letter in the word will be revealed.\nOtherwise, it will deduct a guess. There are no spaces or symbols or capitalization.\nYour score is calculated based on number of guesses x 10 minus your time.\nPress 1 time return to menu: \n");
        listen(1, 1);
        menu();
    }
    if (input == 2)
    {
        game(1);
        //this means that the user has to press 1 after the game is finished to return to the menu
        listen(1,1);
        menu();
    }
    if (input == 3)
    {
        game(2);
        listen(1,1);
        menu();
    }
    if (input == 4)
    {
        //all zeros means that we are simply printing the scoreboard
        addToScoreboard(0, 0, 0);
        listen(1, 1);
        menu();
    }
    else
    {
        exit(0);
    }
}

int main(int argc, string argv[])
{
    //we start the game in the menu
    menu();
}