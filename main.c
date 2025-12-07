#include <stdio.h>
#include <stdbool.h>
#include "support/board.h"
#include "support/game_logic.h"
#include "support/input.h"

int main(void) {

    printf("Console-Based Tic-Tac-Toe Game\n");
    printf("--------------------------------\n");
    printf("GitHub: https://github.com/gh0st-spritx/cse115-tictactoe\n");
    printf("Project Number: 02");
    printf("\n");
    printf("\n");
    printf("Team:\n");
    printf("  Lead Developer: Soumik Halder (ID: 2531413042)\n");
    printf("  Board & Display: Mostafia Al Jannati (ID: 2532532642)\n");
    printf("  Player Input: Shreyosi Mohanta (ID: 2532176042)\n");
    printf("  Game Logic: Md. Kaif Khan (ID: 2532389642)\n");
    printf("  Documentation: Sarah Tabassum (ID: 2531479042)\n");
    printf("\nLet's start the game!\n");

    char board[3][3];
    bool exitProgram = false;

    while (!exitProgram) {
        initBoard(board);
        char currentPlayer = 'X';
        bool gameOver = false;


        while (!gameOver) {
            printBoard(board);
            printf("Player %c, enter your move (1-9), 'r' to restart, or 'e' to exit: ", currentPlayer);
            int choice = getUserInput();


            if (choice == -1) {
                exitProgram = true;
                break;
            }
            if (choice == -2) {
                printf("Restarting the game...\n\n");
                break;
            }
            if (choice < 1 || choice > 9) {
                printf("Invalid input. Please enter 1-9, 'r', or 'e'.\n");
                continue;
            }
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;
            if (board[row][col] != ' ') {
                printf("Cell already taken. Choose another.\n");
                continue;
            }

            board[row][col] = currentPlayer;

            int winner = checkWinner(board);
            if (winner != 0) {
                printBoard(board);
                if (winner == 1)
                    printf("Player X wins!\n");
                else
                    printf("Player O wins!\n");
                gameOver = true;
            }
            else if (isBoardFull(board)) {
                printBoard(board);
                printf("It's a draw!\n");
                gameOver = true;
            }
            else {

                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        if (exitProgram) {
            printf("Exiting the game. Goodbye!\n");
            break;
        }

        if (!gameOver) {
            continue;
        }

        printf("Game over. Enter 'r' to play again or 'e' to exit: ");
        int next = getUserInput();
        if (next == -2) {
            printf("\n");
            continue;
        }
        printf("Exiting the game. Goodbye!\n");
        break;
    }

    return 0;
}
