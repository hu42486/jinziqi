#pragma once

class GameModel {
private:
    char board[3][3];
    char currentPlayer;

public:
    GameModel();
    void reset();
    bool makeMove(int r, int c);
    bool checkWin();
    bool isFull();
    char getCell(int r, int c);
    char getCurrentPlayer();
    void switchPlayer();
};