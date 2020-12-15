//
//  GameManager.hpp
//  SDL_tutorial
//
//  Created by Shilpi Roy on 15/12/20.
//  Copyright © 2020 Shilpi Roy. All rights reserved.
//

#ifndef GameManager_hpp
#define GameManager_hpp

#include <stdio.h>
#include "Board.hpp"

class GameManager {
    Board* board;
public:
    GameManager(SDL_Renderer* renderer);
    ~GameManager();
    void displayBoard(SDL_Renderer* renderer);
    bool handleBoardClickEvent(SDL_Renderer* renderer, int x, int y, int turn);
    bool checkWinState();
};
#endif /* GameManager_hpp */
