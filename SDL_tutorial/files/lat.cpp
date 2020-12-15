//
//  lat.cpp
//  SDL_tutorial
//
//  Created by Shilpi Roy on 10/12/20.
//  Copyright © 2020 Shilpi Roy. All rights reserved.
//

#include "lat.hpp"
//#include <SDL.h>
//#include <SDL_image.h>
////#include <SDL2/SDL_image.h>
//#include <string>
//#include <stdio.h>
//
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//
//int main(int argc, char* args[]) {
//    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
//        return 0;
//    }
//    SDL_Window* window = SDL_CreateWindow("Shilz game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//    if(window == NULL) {
//        return 0;
//    }
//    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//    
//    int imgFlags = IMG_INIT_PNG;
//    if(!(IMG_Init(imgFlags) & imgFlags)) {
//        printf("SDL Png flags can't be initialised, %s\n", SDL_GetError());
//        return 0;
//    }
//    std::string path = "/Users/shroy/Desktop/SDL_tutorial/../SDL_Tuts/board.png";
//    SDL_Surface* loaded_surface = IMG_Load(path.c_str());
//    if(loaded_surface == NULL) {
//        printf("here!!! %s", SDL_GetError());
//        return 0;
//    }
//    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
//    SDL_FreeSurface(loaded_surface);
//    bool quit = false;
//    SDL_Event e;
//    while(!quit) {
//        while(SDL_PollEvent(&e) != 0) {
//            if(e.type == SDL_QUIT) {
//                quit = true;
//                break;
//            }
//        }
//        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
//                SDL_RenderClear(renderer);
//        SDL_Rect topLeftViewport;
//        topLeftViewport.x = 0;
//        topLeftViewport.y = 0;
//        topLeftViewport.w = SCREEN_WIDTH/2;
//        topLeftViewport.h = SCREEN_HEIGHT/2;
//        SDL_RenderSetViewport(renderer, &topLeftViewport);
//        SDL_RenderCopy(renderer, texture, NULL, NULL);
//        
//        SDL_Rect topRightViewport;
//        topRightViewport.x = SCREEN_WIDTH/2;
//        topRightViewport.y = 0;
//        topRightViewport.w = SCREEN_WIDTH/2;
//        topRightViewport.h = SCREEN_HEIGHT/2;
//        SDL_RenderSetViewport(renderer, &topRightViewport);
//        SDL_RenderCopy(renderer, texture, NULL, NULL);
//        
//        SDL_Rect bottomViewport;
//        bottomViewport.x = 0;
//        bottomViewport.y = SCREEN_HEIGHT/2;
//        bottomViewport.w = SCREEN_WIDTH;
//        bottomViewport.h = SCREEN_HEIGHT/2;
//        SDL_RenderSetViewport(renderer, &bottomViewport);
//        SDL_RenderCopy(renderer, texture, NULL, NULL);
//        
//        SDL_RenderPresent(renderer);
//    }
//    SDL_DestroyTexture(texture);
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    renderer = NULL;
//    window = NULL;
//    IMG_Quit();
//    SDL_Quit();
//
//}
