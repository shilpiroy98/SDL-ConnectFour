//
//  Board.hpp
//  SDL_tutorial
//
//  Created by Shilpi Roy on 15/12/20.
//  Copyright © 2020 Shilpi Roy. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include "DotTexture.hpp"
#include <stdio.h>

class Board {
    const static int BOARD_WIDTH = 640;
    const static int BOARD_HEIGHT = 480;
    DotTexture* m_dots[BOARD_WIDTH + 1][BOARD_HEIGHT + 1];
    int m_lastRowFill[BOARD_HEIGHT + 1];
    bool mWon;
    
public:
    Board(SDL_Renderer* renderer);
    ~Board();
    void placeDotAt(int player, int colNum);
    DotTexture* getDotAt(int x, int y);
    void colorBoard(Uint8 r, Uint8 g, Uint8 b, Uint8 a, SDL_Renderer* renderer);
    static int getBoardWidth();
    static int getBoardHeight();
    void display(SDL_Renderer* renderer);
    bool handleClickEvent(SDL_Renderer* renderer, int x, int y, int turn);
    bool checkWinState(int row, int col, int turn);
    bool checkIfWon();
    
};
#endif /* Board_hpp */
