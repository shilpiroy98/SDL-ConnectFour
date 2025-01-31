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
        std::unique_ptr<GameManager> gameMgr = std::make_unique<GameManager>(renderer);
        int turn = 0;
        while(!quit) {
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(renderer);
            gameMgr->displayBoard(renderer, &turn);
            bool click = false;
            while(SDL_PollEvent(&e) != 0) {
                if(e.type == SDL_QUIT) {
                    quit = true;
                    break;
                }
                if(e.type == SDL_MOUSEBUTTONDOWN) {
                    int x, y;
                    SDL_GetMouseState( &x, &y );
                    if(gameMgr->handleBoardClickEvent(renderer, &x, &y, &turn)) {
                        click = true;
                        break;
                    }
                }
                else if(e.type == SDL_MOUSEMOTION) {
                    int x, y;
                    SDL_GetMouseState( &x, &y );
                    gameMgr->handleHoverEvent(renderer, &x, &y, &turn);
                    break;
                }
            }
            
            if(click && gameMgr->checkWinState(renderer, &turn)) {
                SDL_RenderPresent(renderer);
                SDL_Delay(2000);
                break;
            }
            if(click) turn = (turn + 1)%2;
            
            SDL_RenderPresent(renderer);
        }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = NULL;
    window = NULL;
    IMG_Quit();
    SDL_Quit();
}
