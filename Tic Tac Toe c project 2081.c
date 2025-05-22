#include <stdio.h> 
#include <stdlib.h> 

int checkwin(); // Prototype

// Structure for the Board
struct Board {
    char cells[3][3]; // Array of string 
} board = {{{'1','2','3'},{'4','5','6'},{'7','8','9'}}}; // Assigning value 

char turn = 'X';
int draw = 0;
int mode = 0; // 0 for player vs player, 1 for player vs computer

// Global win counters
int player1Wins = 0; // Player 1 (X)
int player2Wins = 0; // Player 2 (O) or Computer (O)

// To Save the current Board
/* 
   1 2 3
   4 5 6
   7 8 9
*/
void saveboard()
{                       
    int i, j;
    FILE *file;
    file = fopen("board.txt", "w"); 
    for(i = 0; i < 3; i++) // row
    {
        for(j = 0; j < 3; j++) // column
        {
            fprintf(file, "%c ", board.cells[i][j]); // Saving value in proper format //
        }
        fprintf(file, "\n"); // Saving value in proper format //
    }
    fprintf(file, "%c\n", turn); // Saving turn //
    fclose(file);
}

// To Load the Saved board i.e. Read saved data //
void loadboard()
{
    int i, j;
    FILE *file;
    file = fopen("board.txt", "r"); // For reading the saved board //
    if(file == NULL)
    {
        return; // Error checking //
    }
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            fscanf(file, " %c", &board.cells[i][j]); // space is made to prevent reading \n or spaces //
        }
    }
    fscanf(file, " %c", &turn);
    fclose(file);
}

// To display the Board
void displayBoard()
{
    printf("\n\n");
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", board.cells[0][0], board.cells[0][1], board.cells[0][2]);
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", board.cells[1][0], board.cells[1][1], board.cells[1][2]);
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", board.cells[2][0], board.cells[2][1], board.cells[2][2]);
    printf("+---+---+---+\n");
}

// To detect the Player Move and adjust the board
void playermove()
{
    int choice, row, column;
    printf("\nPlayer %c, please enter your position (1-9): ", turn);
    scanf("%d", &choice);
   
    while(choice < 1 || choice > 9)
    {
        printf("\nInvalid Move .. Please re-enter: ");
        scanf("%d", &choice);
    }

    if(choice >= 1 && choice <= 3)
    {
        row = 0;
        column = choice - 1;
    }

    else if(choice >= 4 && choice <= 6)
    {
        row = 1;
        column = choice - 4;
    }
    else
    {
        row = 2;
        column = choice - 7;
    }
   
    // Check if the chosen cell is available
    if(board.cells[row][column] != 'X' && board.cells[row][column] != 'O')
    {
        board.cells[row][column] = turn; // Assigning the value { Both are character } // 
    } 
    else
    {
        printf("\nCell already taken, please choose another.\n");
        playermove(); // Ask again
        return;
    }
   
    turn = (turn == 'X') ? 'O' : 'X'; // Switching Turns //    
    saveboard(); // Saving the board //
}

// Simple logic A.I. formulation for computer move //
void computermove()
{
    int i, j;

    // 1. Take the center if available //
    if (board.cells[1][1] != 'X' && board.cells[1][1] != 'O')
    {
        board.cells[1][1] = 'O';
        turn = 'X'; // Flip turns // 
        return;
    }

    // 2. Take a corner (checking each one separately) //
    if (board.cells[0][0] != 'X' && board.cells[0][0] != 'O') // Top-left //
    {
        board.cells[0][0] = 'O';
        turn = 'X';
        return;
    }
    if (board.cells[0][2] != 'X' && board.cells[0][2] != 'O') // Top-right //
    {
        board.cells[0][2] = 'O';
        turn = 'X';
        return;
    }
    if (board.cells[2][0] != 'X' && board.cells[2][0] != 'O') // Bottom-left //
    {
        board.cells[2][0] = 'O';
        turn = 'X';
        return;
    }
    if (board.cells[2][2] != 'X' && board.cells[2][2] != 'O') // Bottom-right //
    {
        board.cells[2][2] = 'O';
        turn = 'X';
        return;
    }

    // 3. Pick any available move //
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board.cells[i][j] != 'X' && board.cells[i][j] != 'O')
            {
                board.cells[i][j] = 'O'; // Computer always O
                turn = 'X';
                return;
            }
        }
    }
    /* Board is saved only for p vs p */
}

// To check win or draw condition //
int checkwin()
{
    int i, j;

    // Check for Rows and Columns    
    for(i = 0; i < 3; i++)
    {
        if(board.cells[i][0] == board.cells[i][1] && board.cells[i][1] == board.cells[i][2])
        {
            return 1; // Returns true condition // 
        }
        if(board.cells[0][i] == board.cells[1][i] && board.cells[1][i] == board.cells[2][i])
        {
            return 1; // Returns true condition //
        }
    }
   
    // Check For diagonals
    if (board.cells[0][0] == board.cells[1][1] && board.cells[1][1] == board.cells[2][2])
    {
        return 1; // Returns true condition //
    }
    if (board.cells[0][2] == board.cells[1][1] && board.cells[1][1] == board.cells[2][0])
    {
        return 1; // Returns true condition //
    }
   
    // Check for Draw Case: if any cell is not X or O, then no draw yet

    draw = 1; // Initianlly Assuming to be draw //

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(board.cells[i][j] != 'X' && board.cells[i][j] != 'O') // Still spaces available // 
            {
                draw = 0;
                return 0;
            }
        }
    }
    return 0;
}

// To Reset the Game board
void resetgame()
{
    int i, j;
    struct Board newBoard = {{{'1','2','3'},{'4','5','6'},{'7','8','9'}}}; 
    board = newBoard; 
    turn = 'X';
    draw = 0;
    saveboard(); // Saving new reset board //
}

// Function to display the Leaderboard
void leaderboard()
{
    printf("\n\n\t... Leaderboard ...\n\n");
    printf("+-----------------+-----------------+\n");
    printf("| %-15s | %-15s |\n", "Player (X)", "Player (O)");
    printf("+-----------------+-----------------+\n");
    printf("| %-15d | %-15d |\n", player1Wins, player2Wins);
    printf("+-----------------+-----------------+\n");

}

// Function to Save Leaderboard
void saveLeaderboard()
{
    FILE *file = fopen("leaderboard.txt", "w");
    if(file != NULL)
    {
        fprintf(file, "%d %d\n", player1Wins, player2Wins);
        fclose(file);
    }
}

// Function to Load Leaderboard
void loadLeaderboard()
{
    FILE *file = fopen("leaderboard.txt", "r");
    if(file != NULL)
    {
        fscanf(file, "%d %d", &player1Wins, &player2Wins);
        fclose(file);
    }
}

// Function to play one round of Tic Tac Toe based on game mode //
void playGame(int mode)
{
    loadboard();  
    while(1) // Infinite Loop until win or loss or draw // 
    {
        displayBoard();
        if(turn == 'X') // X always plays first //
        {
            playermove();
        }
        else // Turn for X //
        {
            if(mode == 0) // Player vs Player //
            {
                playermove();
            }
            else // Player vs Computer //
            {
                computermove(); 
            }
        }
       
        if(checkwin()) // If returns true or 1 //
        {
            displayBoard();
            // Since turn has already been swapped, the winner is the opposite of current turn. //
            char winner = (turn == 'X') ? 'O' : 'X';
            printf("\nCongratulations! %c wins the game!\n", winner);
            if(winner == 'X')
            {  
                player1Wins++;
                resetgame(); // After each win game is reset //
            }
            else
            {   player2Wins++;
                 resetgame();
            }
            saveLeaderboard(); // Save the leaderboard after each game //
            break;
        }
       
        if(draw) // If returns true or 1 //
        {
            displayBoard();
            printf("\nIt's a draw!\n");
            resetgame();
            saveLeaderboard(); // Save the leaderboard after each game //
            break;
        }
    }
}

int main()
{
    int mainChoice;

    printf("\n  Welcome to Tic Tac Toe ...\n\n");
    printf("Developers :\n");
    printf(" - Samrat Malla\n");
    printf(" - Suraj Bhattrai\n");
    printf(" - Tulsi P.d Shrestha\n");
    printf(" - Rozal Gurung\n");
   
    while(1) // Infinte Loop until exit(0) is done //
    {
        // Main Menu
        printf("\n\n\t... Main Menu ...\n\n");
        printf("+--------------------+----------+\n");
        printf("| %-14s  | %-8d |\n","Manual { p vs p }",1);
        printf("+--------------------+----------+\n");
        printf("| %-14s    | %-8d |\n","A.I. { p vs c }",2);
        printf("+--------------------+----------+\n");
        printf("| %-14s | %-8d |\n","Load Previous Game",3);
        printf("+--------------------+----------+\n");
        printf("| %-14s   | %-8d |\n","Show Leaderboard",4);
        printf("+--------------------+----------+\n");
        printf("|   %-14s   | %-8d |\n","--- EXIT --- ",5);
        printf("+--------------------+----------+\n\n");
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);

        switch(mainChoice)
        {
            case 1:
                mode = 0;
                resetgame();
                playGame(mode);
                break;
            case 2:
                mode = 1;
                resetgame();
                playGame(mode);
                break;
            case 3:
                // Load and continue the previous game
                loadboard();
                displayBoard();
                if(turn == 'X')
                    playGame(0); // Assuming previous game was Player vs Player
                else
                    playGame(1); // Assuming previous game was Player vs Computer
                break;
            case 4:
                loadLeaderboard(); // Read value of wins of X and O
                leaderboard();
                break;
            case 5:
                printf("Exiting the game ... Goodbye :)\n");
                saveLeaderboard(); // Save the leaderboard when exiting
                exit(0); // defined under #include<stdlib.h>
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
   
    return 0;
}

