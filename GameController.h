#pragma once
#include "GameModel.h"
#include "GameView.h"

class GameController {
private:
    GameModel model;
    GameView view;

public:
    void run();
};