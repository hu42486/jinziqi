#include "GameController.h"
#include <iostream>

void GameController::run() {
    bool playing = true;

    while (playing) {
        model.reset();
        bool gameOver = false;

        // 单局游戏循环
        while (!gameOver) {
            view.showBoard(model);
            int r, c;
            view.getMove(r, c);

            // 校验输入范围并尝试落子
            if (r >= 0 && r < 3 && c >= 0 && c < 3 && model.makeMove(r, c)) {
                if (model.checkWin()) {
                    view.showBoard(model);
                    view.showResult(model.getCurrentPlayer(), false);
                    gameOver = true;
                }
                else if (model.isFull()) {
                    view.showBoard(model);
                    view.showResult(' ', true);
                    gameOver = true;
                }
                else {
                    model.switchPlayer();
                }
            }
            else {
                std::cout << "无效输入或位置已占用，请按任意键重试...";
                system("pause >nul");
            }
        }

        // 询问是否重玩
        std::cout << "\n再来一局？(1=是, 0=否): ";
        int choice;
        std::cin >> choice;
        playing = (choice == 1);
    }
}