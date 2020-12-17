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
    Board(SDL_Renderer* const renderer);
    ~Board();
    static int getBoardWidth();
    static int getBoardHeight();
    void display(SDL_Renderer* const renderer, int const* turn) const;
    bool handleClickEvent(SDL_Renderer* const renderer, int const * x, int const * y, int const* turn);
    bool handleHoverEvent(SDL_Renderer* const renderer, int const * x, int const * y, int const* turn) const;
    bool checkWinState(SDL_Renderer* const renderer, int const* turn) const;
    bool checkColumnWin(int const* turn, std::vector<std::pair<int, int> > &v) const;
    bool checkRowWin(int const* turn, std::vector<std::pair<int, int> > &v) const;
    bool checkLeftDiagonalWin(int const* turn, std::vector<std::pair<int, int> > &v) const;
    bool checkRightDiagonalWin(int const* turn, std::vector<std::pair<int, int> > &v) const;
    void highlightWinIndexes(SDL_Renderer* const renderer, const std::vector<std::pair<int, int> > &win_indexes, int const* turn) const;
    
};
#endif /* Board_hpp */
