//
//  GameManager.cpp
//  SDL_tutorial
//
//  Created by Shilpi Roy on 15/12/20.
//  Copyright © 2020 Shilpi Roy. All rights reserved.
//

#include "GameManager.hpp"

GameManager::GameManager(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
    board = new Board(renderer);
}

void GameManager::displayBoard(SDL_Renderer* renderer, int turn) const {
    board->display(renderer, turn);
}

bool GameManager::handleBoardClickEvent(SDL_Renderer *renderer, int x, int y, int turn) const {
    return board->handleClickEvent(renderer, x, y, turn);
}

bool GameManager::handleHoverEvent(SDL_Renderer *renderer, int x, int y, int turn) const {
    return board->handleHoverEvent(renderer, x, y, turn);
}

bool GameManager::checkWinState(SDL_Renderer* renderer, int turn) const {
    return board->checkWinState(renderer, turn);
}
