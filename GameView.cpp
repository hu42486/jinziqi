#include "GameView.h"
#include <iostream>

void GameView::showBoard(GameModel& model) {
    system("cls"); // 清屏
    std::cout << "  0 1 2\n";
    for (int i = 0; i < 3; i++) {
        std::cout << i << " ";
        for (int j = 0; j < 3; j++) {
            std::cout << model.getCell(i, j);
            if (j < 2) std::cout << "|";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "  -----\n";
    }
    std::cout << "\n当前玩家: " << model.getCurrentPlayer() << "\n";
}

void GameView::showResult(char winner, bool isDraw) {
    if (isDraw) std::cout << "\n平局！\n";
    else std::cout << "\n玩家 " << winner << " 获胜！\n";
}

void GameView::getMove(int& r, int& c) {
    std::cout << "输入行和列(0-2, 空格分隔): ";
    std::cin >> r >> c;
}
