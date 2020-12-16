//
//  Board.cpp
//  SDL_tutorial
//
//  Created by Shilpi Roy on 15/12/20.
//  Copyright © 2020 Shilpi Roy. All rights reserved.
//

#include "Board.hpp"

Board::Board(SDL_Renderer* renderer) {
    mWon = false;
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
            m_dots[i/DotTexture::SPRITE_SIZE][j/DotTexture::SPRITE_SIZE]->render(i, j, NULL, renderer, turn);
        }
    }
}

bool Board::handleClickEvent(SDL_Renderer* renderer, int x, int y, int turn) {
    int column_num = x/DotTexture::SPRITE_SIZE;
    int last_uncolored_idx = BOARD_HEIGHT + 1;
    for(int i = 0; i < BOARD_HEIGHT/DotTexture::SPRITE_SIZE + 1; i++) {
        if(!m_dots[column_num][i]->isColored()) {
            last_uncolored_idx = i;
        }
    }
    
    if(last_uncolored_idx == BOARD_HEIGHT + 1) return false;
    m_dots[column_num][last_uncolored_idx]->setColor(renderer, 210, 16, 155, turn);
    checkWinState(column_num, last_uncolored_idx, turn);
    
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

bool Board::checkWinState(int column_num, int last_colored_idx, int turn) {
    int cidx = column_num;
    int cnt = 0;
    while(cidx >= 0) {
        if(m_dots[cidx][last_colored_idx]->getColor() == turn) {
            cnt++;
            if(cnt >= 4) return mWon = true;
        }
        else {
            break;
        }
        cidx--;
    }
    cidx = column_num + 1;
    while(cidx < BOARD_WIDTH/DotTexture::SPRITE_SIZE + 1) {
        if(m_dots[cidx][last_colored_idx]->getColor() == turn) {
            cnt++;
            if(cnt >= 4) return mWon = true;
        }
        else {
            break;
        }
        cidx++;
    }
    if(cnt >= 4) return mWon = true;
    int ridx = last_colored_idx;
    cnt = 0;
    while(ridx >= 0) {
        if(m_dots[column_num][ridx]->getColor() == turn) {
            cnt++;
            if(cnt >= 4) return mWon = true;
        }
        else {
            break;
        }
        ridx--;
    }
    ridx = last_colored_idx + 1;
    while(ridx < BOARD_HEIGHT/DotTexture::SPRITE_SIZE + 1) {
        if(m_dots[column_num][ridx]->getColor() == turn) {
            cnt++;
            if(cnt >= 4) return mWon = true;
        }
        else {
            break;
        }
        ridx++;
    }
    if(cnt >= 4) return mWon = true;
    ridx = last_colored_idx;
    cidx = column_num;
    cnt = 0;
    while(ridx >= 0 && cidx < BOARD_WIDTH/DotTexture::SPRITE_SIZE + 1) {
        if(m_dots[cidx][ridx]->getColor() == turn) {
            cnt++;
            if(cnt >= 4) return mWon = true;
        }
        else {
            break;
        }
        ridx--;
        cidx++;
    }
    if(cnt >= 4) return mWon = true;
    ridx = last_colored_idx + 1;
    cidx = column_num - 1;
    while(ridx < BOARD_HEIGHT/DotTexture::SPRITE_SIZE + 1 && cidx >= 0) {
        if(m_dots[cidx][ridx]->getColor() == turn) {
            cnt++;
            if(cnt >= 4) return mWon = true;
        }
        else {
            break;
        }
        ridx++;
        cidx--;
    }
    ridx = last_colored_idx;
    cidx = column_num;
    cnt = 0;
    while(ridx >= 0 && cidx >= 0) {
        if(m_dots[cidx][ridx]->getColor() == turn) {
            cnt++;
             if(cnt >= 4) return mWon = true;
        }
        else {
            break;
        }
        ridx--;
        cidx--;
    }
    if(cnt >= 4) return mWon = true;
    ridx = last_colored_idx + 1;
    cidx = column_num + 1;
    while(ridx < BOARD_HEIGHT/DotTexture::SPRITE_SIZE + 1 && cidx < BOARD_WIDTH/DotTexture::SPRITE_SIZE + 1) {
        if(m_dots[cidx][ridx]->getColor() == turn) {
            cnt++;
        }
        else {
            if(cnt >= 4) return mWon = true;
            break;
        }
        ridx++;
        cidx++;
    }
    if(cnt >= 4) return mWon = true;
   
    return false;
}
