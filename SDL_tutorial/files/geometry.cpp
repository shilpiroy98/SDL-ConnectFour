//
//  main.cpp
//  SDL_tutorial
//
//  Created by Shilpi Roy on 12/11/20.
//  Copyright © 2020 Shilpi Roy. All rights reserved.
//
/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
/*This source code copyrighted by Lazy Foo' Productions (2004-2020)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
//#include <SDL.h>
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
//        SDL_RenderClear(renderer);
//        SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
//        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
//        SDL_RenderFillRect(renderer, &fillRect);
//        
//        SDL_Rect drawRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 };
//        SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
//        SDL_RenderDrawRect(renderer, &drawRect);
//        
//        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
//        SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT/2);
//        
//        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, 0xFF);
//        for(int i = 0; i < SCREEN_HEIGHT; i += 6) {
//            SDL_RenderDrawPoint(renderer, SCREEN_WIDTH/2, i);
//        }
//        SDL_RenderPresent(renderer);
//    }
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    renderer = NULL;
//    window = NULL;
//    SDL_Quit();
//
//}
