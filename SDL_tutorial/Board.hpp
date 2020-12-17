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
#include <vector>

class Board {
    const static int BOARD_WIDTH = 270;
    const static int BOARD_HEIGHT = 285;
    DotTexture* m_dots[BOARD_WIDTH + 1][BOARD_HEIGHT + 1];
    int last_x, last_y;
    
public:
    Board(SDL_Renderer* renderer);
    ~Board();
    static int getBoardWidth();
    static int getBoardHeight();
    void display(SDL_Renderer* renderer, int turn) const;
    bool handleClickEvent(SDL_Renderer* renderer, int x, int y, int turn);
    bool handleHoverEvent(SDL_Renderer* renderer, int x, int y, int turn) const;
    bool checkWinState(SDL_Renderer* renderer, int turn) const;
    bool checkColumnWin(int turn, std::vector<std::pair<int, int> > &v) const;
    bool checkRowWin(int turn, std::vector<std::pair<int, int> > &v) const;
    bool checkLeftDiagonalWin(int turn, std::vector<std::pair<int, int> > &v) const;
    bool checkRightDiagonalWin(int turn, std::vector<std::pair<int, int> > &v) const;
    void highlightWinIndexes(SDL_Renderer* renderer, std::vector<std::pair<int, int> > win_indexes, int turn) const;
    
};
#endif /* Board_hpp */
