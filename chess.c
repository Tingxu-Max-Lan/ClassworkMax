#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <time.h>
int state = 0;
bool white = true;
enum Type{
    Empty = 0,
    Pawn,
    Bishop,
    Knight,
    Rook,
    King,
    Queen
};

enum Color{
    Blank = 0,
    Black,
    White,
};
struct Piece {
    enum Type type;
    enum Color color;
};
//create board
struct Piece board[8][8];

//waits for the user to input a number in the specified range and outputs that integer.
//good for selecting a menu option and returning from the menu
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
int check(int *moves){
    int y = moves[0];
    int x = moves[1];
    int z = moves[2];
    int a = moves[3];
    int piece = board[y][x].type;
    //checks whether a move is valid or not. the parameter signifies the place where the piece is.
    //returns 0 if it is valid, and 1 if it is not valid, and 2 if it has no moves, and -1 if there is no piece.
    return 0;
}
void boardstate(void){
    for(int j = 0; j < 8; j++)
    {
        for(int i = 0; i < 8; i++)
        {
            switch(board[j][i].type){
                case Pawn:
                if(board[j][i].color == Black){
                    for(int x = 0; x<2;x++){
                        if(!(abs(i+x > 8)>8)){
                        if(board[j-1][i+(1-2*(x%2))].type == King && board[j-1][i+(1-2*(x%2))].color == White){
                            state = 1;
                        }
                        }
                    }
                }else{
                    for(int x = 0; x<2;x++){
                        if(!(abs(i+x > 8)>8)){
                        if(board[j+1][i+(1-2*(x%2))].type == King && board[j+1][i+(1-2*(x%2))].color == Black){
                            state = 2;
                        }
                        }
                    }
                }
                    break;
                case Knight:
                if(board[j][i].color == Black){
                    for(int x = 0; x<4;x++){
                        int row = ((1-2*(x%2))*2-(1-2*(x%2)));
                        int col = (2*(-1+(2*ceil((double)(x%3)/((x%3)+1)))));

                        if(!(abs(row) > 8 || abs(col) > 8)){
                            if(board[row][col].type == King && board[row][col].color == White){
                                state = 1;
                            }
                        }
                        col = (2*(-1+(2*ceil((double)(x%3)/((x%3)+1))))-(-1+(2*ceil((double)(x%3)/((x%3)+1)))));
                        row = ((1-2*(x%2))*2);
                        if(!(abs(row) > 8 || abs(col) > 8)){
                            if(board[row][col].type == King && board[row][col].color == White){
                                state = 1;
                            }
                        }
                    }
                }else{
                    for(int x = 0; x<4;x++){

                    }
                }
                case Bishop:
                    break;
                case Rook:
                    break;
                case Queen:
                    break;
                default:
                    break;

            }
        }
    }
}
int *ask(void){
    static int move[4];
    /*repeatedly asks for a three letter string until the user enters a valid move and returns that string
    It does this with a for loop checking if its the correct type and length and then using check()
    to make sure that it is a legal move.
    */
    return move;
}
int update(int *update){
    int y = update[0];
    int x = update[1];
    int a = update[2];
    int z = update[3];
    board[z][a].type = board[x][y].type;
    board[z][a].color = board[x][y].color;
    board[x][y].type = Empty;
    board[x][y].color = Blank;
    //interprets the string passed by the ask function to update the board struct array
    //checks to see if there is a check or checkmate or staleate
    //returns 0 for no check, 1 for check, 2 for white stalemate, 3 for black stalemate, 4 for white win, 5 for black win
    //prints out the array along with other UI info like previous moves and pieces captured
    return 0;
}
void initialize(void){
    //empties the board
    for(int j = 0; j < 8; j++)
{
    for(int i = 0; i < 8; i++)
    {
        board[i][j].type = Empty;
        board[i][j].color = Blank;
    }
}

    //uses a for loop to randomly assign piece positions based on the random numbers
    int r = (rand() % 5)+1;

    //updates the board after asking the user for a move
    //a is the state of the game specified on line 79
    int a = 0;
    while(a == 1 || a == 0){
        a = update(ask());
    }

    //if statement printing out results

}
void menu(void){
    system("clear");
    printf("------------------------------------------\n");
    printf("|1. Instructions                         |\n");
    printf("|2. Play Chess                           |\n");
    printf("|3. Exit Game                            |\n");
    printf("------------------------------------------\n");
    int input = listen(1,3);
    if(input == 1){
        printf("Instructions");
        listen(1,1);
        menu();
    }else if(input == 2){
        initialize();
        listen(1,1);
        menu();
    }else{
        exit(0);
    }
}

int main(int argc, string argv[])
{
    srand(time(NULL)); //we set our random number list to the amount of seconds passed since 1970.
    //since each game will have a different amount of seconds passed, our numbers will always be random

    //we start the game in the menu
    menu();
}
