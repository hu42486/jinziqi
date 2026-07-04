#pragma once
#include "GameModel.h"

class GameView {
public:
    void showBoard(GameModel& model);
    void showResult(char winner, bool isDraw);
    void getMove(int& r, int& c);
};