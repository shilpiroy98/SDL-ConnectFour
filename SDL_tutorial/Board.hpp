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
    static bool mWon;
    int last_x, last_y;
    
public:
    Board(SDL_Renderer* renderer);
    ~Board();
    void placeDotAt(int player, int colNum);
    DotTexture* getDotAt(int x, int y);
    void colorBoard(Uint8 r, Uint8 g, Uint8 b, Uint8 a, SDL_Renderer* renderer);
    static int getBoardWidth();
    static int getBoardHeight();
    void display(SDL_Renderer* renderer, int turn);
    bool handleClickEvent(SDL_Renderer* renderer, int x, int y, int turn);
    bool handleHoverEvent(SDL_Renderer* renderer, int x, int y, int turn);
    bool checkWinState(SDL_Renderer* renderer, int turn);
    static bool checkIfWon();
    bool checkColumnWin(int turn, std::vector<std::pair<int, int> > &v);
    bool checkRowWin(int turn, std::vector<std::pair<int, int> > &v);
    bool checkLeftDiagonalWin(int turn, std::vector<std::pair<int, int> > &v);
    bool checkRightDiagonalWin(int turn, std::vector<std::pair<int, int> > &v);
    void highlightWinIndexes(SDL_Renderer* renderer, std::vector<std::pair<int, int> > win_indexes, int turn);
    
};
#endif /* Board_hpp */
