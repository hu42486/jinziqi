#include "GameModel.h"

GameModel::GameModel() { reset(); }

void GameModel::reset() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
    currentPlayer = 'X';
}

bool GameModel::makeMove(int r, int c) {
    if (board[r][c] == ' ') {
        board[r][c] = currentPlayer;
        return true;
    }
    return false;
}

bool GameModel::checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

bool GameModel::isFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ') return false;
    return true;
}

char GameModel::getCell(int r, int c) { return board[r][c]; }
char GameModel::getCurrentPlayer() { return currentPlayer; }
void GameModel::switchPlayer() { currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; }