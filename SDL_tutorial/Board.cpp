//
//  Board.cpp
//  SDL_tutorial
//
//  Created by Shilpi Roy on 15/12/20.
//  Copyright © 2020 Shilpi Roy. All rights reserved.
//

#include "Board.hpp"

bool Board::mWon = false;

Board::Board(SDL_Renderer* renderer) {
    mWon = false;
    last_x = -1;
    last_y = -1;
    for(int i = 0; i < BOARD_WIDTH; i += DotTexture::SPRITE_SIZE) {
        for(int j = 0; j < BOARD_HEIGHT; j += DotTexture::SPRITE_SIZE) {
            m_dots[i/DotTexture::SPRITE_SIZE][j/DotTexture::SPRITE_SIZE] = new DotTexture(i, j);
            m_dots[i/DotTexture::SPRITE_SIZE][j/DotTexture::SPRITE_SIZE]->initialize(renderer);
        }
    }
}
int Board::getBoardWidth() {
    return BOARD_WIDTH;
}
int Board::getBoardHeight() {
    return BOARD_HEIGHT;
}

void Board::display(SDL_Renderer* renderer, int turn) {
    for(int i = 0; i < BOARD_WIDTH; i += DotTexture::SPRITE_SIZE) {
        for(int j = 0; j < BOARD_HEIGHT; j += DotTexture::SPRITE_SIZE) {
            m_dots[i/DotTexture::SPRITE_SIZE][j/DotTexture::SPRITE_SIZE]->render(renderer, turn);
        }
    }
}

bool Board::handleClickEvent(SDL_Renderer* renderer, int x, int y, int turn) {
    int column_num = x/DotTexture::SPRITE_SIZE;
    int last_uncolored_idx = BOARD_HEIGHT + 1;
    for(int i = 0; i < BOARD_HEIGHT/DotTexture::SPRITE_SIZE; i++) {
        if(!m_dots[column_num][i]->isColored()) {
            last_uncolored_idx = i;
        }
    }
    
    if(last_uncolored_idx == BOARD_HEIGHT + 1) return false;
    m_dots[column_num][last_uncolored_idx]->setColor(renderer, 210, 16, 155, turn);
    last_x = column_num;
    last_y = last_uncolored_idx;
//    checkWinState(renderer, column_num, last_uncolored_idx, turn);
    
    return true;
}

bool Board::handleHoverEvent(SDL_Renderer *renderer, int x, int y, int turn) {
    int col_id = x/DotTexture::SPRITE_SIZE;
    DotTexture::setHoverIndex(col_id);
    return true;
}

bool Board::checkIfWon() {
    return mWon;
}

bool Board::checkRowWin(int turn, std::vector<std::pair<int, int> > &v) {
       int cidx = last_x;
       int cnt = 0;
       while(cidx >= 0) {
           if(m_dots[cidx][last_y]->getColor() == turn) {
               cnt++;
               v.push_back(std::make_pair(cidx, last_y));
               //if(cnt >= 4) return mWon = true;
           }
           else {
               break;
           }
           cidx--;
       }
       cidx = last_x + 1;
       while(cidx < BOARD_WIDTH/DotTexture::SPRITE_SIZE + 1) {
           if(m_dots[cidx][last_y]->getColor() == turn) {
               cnt++;
               v.push_back(std::make_pair(cidx, last_y));
               //if(cnt >= 4) return mWon = true;
           }
           else {
               break;
           }
           cidx++;
       }
       if(cnt >= 4) return mWon = true;
     return false;
}

bool Board::checkColumnWin(int turn, std::vector<std::pair<int, int> > &v) {
    int ridx = last_y;
    int cnt = 0;
    while(ridx >= 0) {
        if(m_dots[last_x][ridx]->getColor() == turn) {
            cnt++;
            v.push_back(std::make_pair(last_x, ridx));
            //if(cnt >= 4) return mWon = true;
        }
        else {
            break;
        }
        ridx--;
    }
    ridx = last_y + 1;
    while(ridx < BOARD_HEIGHT/DotTexture::SPRITE_SIZE) {
        if(m_dots[last_x][ridx]->getColor() == turn) {
            cnt++;
            v.push_back(std::make_pair(last_x, ridx));
            //if(cnt >= 4) return mWon = true;
        }
        else {
            break;
        }
        ridx++;
    }
    if(cnt >= 4) return mWon = true;
    v.clear();
     return false;
}

bool Board::checkLeftDiagonalWin(int turn, std::vector<std::pair<int, int> > &v) {
    int ridx = last_y;
    int cidx = last_x;
    int cnt = 0;
    while(ridx >= 0 && cidx < BOARD_WIDTH/DotTexture::SPRITE_SIZE) {
        if(m_dots[cidx][ridx]->getColor() == turn) {
            cnt++;
            v.push_back(std::make_pair(cidx, ridx));
//            if(cnt >= 4) return mWon = true;
        }
        else {
            break;
        }
        ridx--;
        cidx++;
    }
//    if(cnt >= 4) return mWon = true;
    ridx = last_y + 1;
    cidx = last_x - 1;
    while(ridx < BOARD_HEIGHT/DotTexture::SPRITE_SIZE && cidx >= 0) {
        if(m_dots[cidx][ridx]->getColor() == turn) {
            cnt++;
            v.push_back(std::make_pair(cidx, ridx));
//            if(cnt >= 4) return mWon = true;
        }
        else {
            break;
        }
        ridx++;
        cidx--;
    }
    if(cnt >= 4) return mWon = true;
        v.clear();
     return false;
}

bool Board::checkRightDiagonalWin(int turn, std::vector<std::pair<int, int> > &v) {
    int ridx = last_y;
    int cidx = last_x;
    int cnt = 0;
    while(ridx >= 0 && cidx >= 0) {
        if(m_dots[cidx][ridx]->getColor() == turn) {
            cnt++;
            v.push_back(std::make_pair(cidx, ridx));
//             if(cnt >= 4) return mWon = true;
        }
        else {
            break;
        }
        ridx--;
        cidx--;
    }
//    if(cnt >= 4) return mWon = true;
    ridx = last_y + 1;
    cidx = last_x + 1;
    while(ridx < BOARD_HEIGHT/DotTexture::SPRITE_SIZE && cidx < BOARD_WIDTH/DotTexture::SPRITE_SIZE) {
        if(m_dots[cidx][ridx]->getColor() == turn) {
            cnt++;
            v.push_back(std::make_pair(cidx, ridx));
        }
        else {
//            if(cnt >= 4) return mWon = true;
            break;
        }
        ridx++;
        cidx++;
    }
    if(cnt >= 4) return mWon = true;
        v.clear();
    return false;
}

void Board::highlightWinIndexes(SDL_Renderer* renderer, std::vector<std::pair<int, int> > win_indexes, int turn) {
    for(int i = 0; i < win_indexes.size(); i++) {
        m_dots[win_indexes[i].first][win_indexes[i].second]->highlight(renderer, turn);
    }
}

bool Board::checkWinState(SDL_Renderer* renderer, int turn) {
    if(last_x == -1 || last_y == -1) return false;
    std::vector<std::pair<int, int> > win_indexes;
    if(
            checkRowWin(turn, win_indexes) ||
            checkColumnWin(turn, win_indexes) ||
            checkLeftDiagonalWin(turn, win_indexes) ||
            checkRightDiagonalWin(turn, win_indexes)
       ) {
        highlightWinIndexes(renderer, win_indexes, turn);
        return true;
    }
    return false;
}
