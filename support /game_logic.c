#include "game_logic.h"

int checkWinner(char board[3][3]) {

    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {
            return (board[i][0] == 'X') ? 1 : 2;
            }
    }

    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j]) {
            return (board[0][j] == 'X') ? 1 : 2;
            }
    }

    if (board[1][1] != ' ' &&
       ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0]))) {
        return (board[1][1] == 'X') ? 1 : 2;
        }
    return 0;
}

bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}
