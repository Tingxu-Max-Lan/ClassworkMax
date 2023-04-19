#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <term.h>

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
    int check[7][7];
    for(int j = 0; j < 8; j++)
    {
        for(int i = 0; i < 8; i++)
        {
            switch(board[j][i].type){
                case Pawn:
                if(board[j][i].color == Black){
                    for(int x = 0; x<2;x++){
                        if(!(abs(i+x)>7)){
                        if(board[j-1][i+(1-2*(x%2))].type == King && board[j-1][i+(1-2*(x%2))].color == White){
                            state = 1;
                        }else{
                            check[j-1][i+(1-2*(x%2))] = 1;
                        }
                        }
                    }
                }else{
                    for(int x = 0; x<2;x++){
                        if(!(abs(i+x)>7)){
                        if(board[j+1][i+(1-2*(x%2))].type == King && board[j+1][i+(1-2*(x%2))].color == Black){
                            state = 1;
                            check[j-1][i+(1-2*(x%2))] = 2;
                        }
                        }
                    }
                }
                    break;
                case Knight:

                    for(int x = 0; x<4;x++){
                         int row = ((1-2*(x%2))*2-(1-2*(x%2)));
                        int col = (2*(-1+(2*ceil((double)(x%3)/((x%3)+1)))));

                         if(!(abs(row) > 7 || abs(col) > 7)){
                            if(board[col][row].type == King && (board[col][row].color != board[j][i].color)){
                                state = 1;
                            }else{
                                check[col][row] = board[j][i].color;
                            }
                        }
                        col = (2*(-1+(2*ceil((double)(x%3)/((x%3)+1))))-(-1+(2*ceil((double)(x%3)/((x%3)+1)))));
                        row = ((1-2*(x%2))*2);
                        if(!(abs(row) > 7 || abs(col) > 7)){
                            if(board[col][row].type == King && (board[col][row].color != board[j][i].color)){
                                state = 1;
                            }else{
                                check[col][row] = board[j][i].color;
                            }
                        }
                    }

                case Bishop:
                    for(int q = 0; q<4; q++){
                       int x = ((1-2*(q%2))*q)+i;
                       int y = ((1-2*((q+1)%2))*q)+j;
                        while((abs(y) < 8) && (abs(x) < 8)){
                            if(board[y][x].color != Blank){
                                if(board[y][x].type == King && (board[y][x].color != board[j][i].color)){
                                state = 1;
                                }
                                break;
                            }else{
                                check[y][x] = board[j][i].color;
                            }

                        }
                    }
                    break;
                case Rook:
                    for(int q = 0; q<4; q++){
                        int x;
                        int y;
                        if(q > 1){
                            x = ((1-2*(q%2))*q)+i;
                            y = j;
                        }else{
                            x = i;
                            y = ((1-2*((q)%2))*q)+j;
                        }

                        while((abs(y) < 8) && (abs(x) < 8)){
                            if(board[y][x].color != Blank){
                                if(board[y][x].type == King && (board[y][x].color != board[j][i].color)){
                                state = 1;
                                }
                                break;
                            }else{
                                check[y][x] = board[j][i].color;
                            }

                        }
                    }
                    break;
                case Queen:
                    for(int q = 0; q<4; q++){
                        int x;
                        int y;
                            if(q > 1){
                                x = ((1-2*(q%2))*q)+i;
                                y = j;
                            }else{
                                x = i;
                                y = ((1-2*((q)%2))*q)+j;
                            }

                            while((abs(y) < 8) && (abs(x) < 8)){
                                if(board[y][x].color != Blank){
                                    if(board[y][x].type == King && (board[y][x].color != board[j][i].color)){
                                    state = 1;
                                    }
                                    break;
                                }else{
                                    check[y][x] = board[j][i].color;
                                }

                            }
                        }
                        for(int q = 0; q<4; q++){
                        int x = ((1-2*(q%2))*q)+i;
                        int y = ((1-2*((q+1)%2))*q)+j;
                            while((abs(y) < 8) && (abs(x) < 8)){
                                if(board[y][x].color != Blank){
                                    if(board[y][x].type == King && (board[y][x].color != board[j][i].color)){
                                    state = 1;
                                    }
                                    break;
                                }else{
                                    check[y][x] = board[j][i].color;
                                }

                            }
                        }
                        break;
                    case King:
                        {int moves = true;
                        for(int q = 0; q<9;q++){
                                int x = 1 - (q%3) + i;
                                int y = (1 - ((q+((int)(ceil(q/3)+1)))%3))+j;
                                if(check[y][x] == board[j][i].color || check[y][x] == 0){
                                    moves = false;
                                }
                        }

                        if(moves && state == 1){
                            state = 2;
                        }else{
                            state = 3;
                        }
                        }
                        break;
                default:
                    break;

            }
        }
    }
}
int *ask(void){
    static int move[4];
    int w = 0;

    while (w == 0)
    {
   char str[2];
    printf("Please enter the row of the piece you want to move: ");
   fgets(str, 1, stdin);
        if (scanf("%s", str) != 1)
        {
            //clears the scanf buffer if it doesn't. This prevents crashes.
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
        }
        if (strcmp(&str[1],"a")  || strcmp(&str[1],"b") || strcmp(&str[1],"c") || strcmp(&str[1],"d") || strcmp(&str[1],"e") || strcmp(&str[1],"f") || strcmp(&str[1],"g") || strcmp(&str[1],"h")){
            move[0] = str[1] - 96;
        }
        printf("Please enter the column of the piece you want to move: ");
        fgets(str, 1, stdin);
        if (scanf("%s", str) != 1)
        {
            //clears the scanf buffer if it doesn't. This prevents crashes.
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
        }
        if (strcmp(&str[1],"1")  || strcmp(&str[1],"2") || strcmp(&str[1],"3") || strcmp(&str[1],"4") || strcmp(&str[1],"5") || strcmp(&str[1],"6") || strcmp(&str[1],"7") || strcmp(&str[1],"8")){
            move[1] = str[1] - 48;
        }
        if(board[])
        printf("Please enter the row of the  you want to move: ");

        printf("\x1b[1F"); // Move to beginning of previous line
        printf("\x1b[2K"); // Clear entire line
    }
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
    //board[z][a].type = board[x][y].type;
    //board[z][a].color = board[x][y].color;
    //board[x][y].type = Empty;
    //board[x][y].color = Blank;
    system("clear");
    for(int j = 0; j < 8; j++)
{
    for(int i = 0; i < 8; i++)
    {
        if(board[j][i].type == Pawn){
            if(board[j][i].color == White){
                system("setterm -bold on");
                printf("♟ ");
                system("setterm -bold off");
            }else{
                system("setterm -bold on");
                printf("♙ ");
                system("setterm -bold off");
            }
        }
        else if(board[j][i].type == Knight){
            if(board[j][i].color == White){
                system("setterm -bold on");
                printf("♞ ");
                system("setterm -bold off");
            }else{
                system("setterm -bold on");
                printf("♘ ");
                system("setterm -bold off");
            }
        }
        else if(board[j][i].type == Bishop){
            if(board[j][i].color == White){
                system("setterm -bold on");
                printf("♝ ");
                system("setterm -bold off");
            }else{
                system("setterm -bold on");
                printf("♗ ");
                system("setterm -bold off");
            }
        }
        else if(board[j][i].type == Rook){
            if(board[j][i].color == White){
                system("setterm -bold on");
                printf("♜ ");
                system("setterm -bold off");
            }else{
                system("setterm -bold on");
                printf("♖ ");
                system("setterm -bold off");
            }
        }
        else if(board[j][i].type == Queen){
            if(board[j][i].color == White){
                system("setterm -bold on");
                printf("♛ ");
                system("setterm -bold off");
            }else{
                system("setterm -bold on");
                printf("♕ ");
                system("setterm -bold off");
            }
        }
        else if(board[j][i].type == King){
            if(board[j][i].color == White){
                system("setterm -bold on");
                printf("♚ ");
            }else{
                system("setterm -bold on");
                printf("♔ ");
            }
        }else{
            if((j%2)==(i%2)){
                 printf("⬜");
            }else{
            printf("⬛");}
        }
    }
    printf("\n");
}
    //interprets the string passed by the ask function to update the board struct array
    //checks to see if there is a check or checkmate or staleate
    //returns 0 for no check, 1 for check, 2 for white stalemate, 3 for black stalemate, 4 for white win, 5 for black win
    //prints out the array along with other UI info like previous moves and pieces captured
    return 0;
}
void initialize(int x){
    //empties the board
    for(int j = 0; j < 8; j++)
{
    for(int i = 0; i < 8; i++)
    {
        board[i][j].type = Empty;
        board[i][j].color = Blank;
    }
}
    if(x == 1){
        for(int i = 1; i < 3; i++){
            int y = 0;
            if(i == 2){
                y = 7;
            }
        board[y][7].type = Rook;
        board[y][7].color = i;
        board[y][6].type = Knight;
        board[y][6].color = i;
        board[y][5].type = Bishop;
        board[y][5].color = i;
        board[y][4].type = King;
        board[y][4].color = i;
        board[y][3].type = Queen;
        board[y][3].color = i;
        board[y][2].type = Bishop;
        board[y][2].color = i;
        board[y][1].type = Knight;
        board[y][1].color = i;
        board[y][0].type = Rook;
        board[y][0].color = i;
        for(int z = 0; z < 8; z++){
            int q = 1;
            if(y == 7){
                q = -1;
            }
            board[y + q][z].type = Pawn;
            board[y + q][z].color = i;
        }
        }

    }

    //uses a for loop to randomly assign piece positions based on the random numbers
    int r = (rand() % 5)+1;

    //updates the board after asking the user for a move

    //while(state == 1 || state == 0){
        update(ask());
    //}

    //if statement printing out results

}
void menu(void){
    system("clear");
    printf("------------------------------------------\n");
    printf("|1. Instructions                         |\n");
    printf("|2. Play Normal Chess                    |\n");
    printf("|3. Play Chess 960                       |\n");
    printf("|4. Play With Material Down              |\n");
    printf("|5. Exit Game                            |\n");
    printf("------------------------------------------\n");
    int input = listen(1,5);
    if(input == 1){
        printf("Instructions");
        listen(1,1);
        menu();
    }else if(input == 2){
        initialize(1);
        listen(1,1);
        menu();
    }else if(input == 3){
        initialize(2);
        listen(1,1);
        menu();
    }else if(input == 4){
        initialize(3);
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
