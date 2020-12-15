//
//  Main.cpp
//  SDL_tutorial
//
//  Created by Shilpi Roy on 15/12/20.
//  Copyright © 2020 Shilpi Roy. All rights reserved.
//

#include "Main.hpp"
#include "GameManager.hpp"

#include <iostream>
#include <SDL.h>

int main(int argc, char * argv[]) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
            printf("failed to initialize SDL, %s", SDL_GetError());
            return 0;
    }
    
    SDL_Window* window = SDL_CreateWindow("my game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Board::getBoardWidth(), Board::getBoardWidth(), SDL_WINDOW_SHOWN);
        if(window == NULL) {
            printf("failed to initialise window, %s", SDL_GetError());
            return 0;
        }
        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if(renderer == NULL) {
            printf("failed to create renderer, %s", SDL_GetError());
            return 0;
        }
        
        bool quit = false;
        SDL_Event e;
        GameManager* gameMgr = new GameManager(renderer);
        int turn = 0;
        while(!quit) {
            if(gameMgr->checkWinState()) {
                           SDL_Delay(2000);
                           SDL_RenderClear(renderer);
                           SDL_RenderPresent(renderer);
                           SDL_Delay(4000);
                           break;
                       }
            while(SDL_PollEvent(&e) != 0) {
                if(e.type == SDL_QUIT) {
                    quit = true;
                    break;
                }
                if(e.type == SDL_MOUSEBUTTONDOWN) {
                    int x, y;
                    SDL_GetMouseState( &x, &y );
                    if(gameMgr->handleBoardClickEvent(renderer, x, y, turn)) {
                        turn = (turn + 1)%2;
                    }
                    break;
                }
            }
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(renderer);
            gameMgr->displayBoard(renderer);
            SDL_RenderPresent(renderer);
        }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;
    IMG_Quit();
    SDL_Quit();
}
