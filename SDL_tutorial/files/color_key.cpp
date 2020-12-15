//
//  color_key.cpp
//  SDL_tutorial
//
//  Created by Shilpi Roy on 11/12/20.
//  Copyright © 2020 Shilpi Roy. All rights reserved.
//

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
//#include <SDL2/SDL_image.h>
#include <string>

//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//SDL_Window* window = NULL;
//
////The window renderer
//SDL_Renderer* renderer = NULL;
//
////Scene textures
//
//
////Texture wrapper class
//class LTexture
//{
//    public:
//        //Initializes variables
//        LTexture();
//
//        //Deallocates memory
//        ~LTexture();
//
//        //Loads image at specified path
//        bool loadFromFile( std::string path );
//
//        //Deallocates texture
//        void free();
//
//        //Renders texture at given point
//        void render( int x, int y );
//
//        //Gets image dimensions
//        int getWidth();
//        int getHeight();
//
//    private:
//        //The actual hardware texture
//        SDL_Texture* mTexture;
//
//        //Image dimensions
//        int mWidth;
//        int mHeight;
//};
//
//LTexture gFooTexture;
//LTexture gBackgroundTexture;
//
//LTexture::LTexture()
//{
//    //Initialize
//    mTexture = NULL;
//    mWidth = 0;
//    mHeight = 0;
//}
//
//LTexture::~LTexture()
//{
//    //Deallocate
//    free();
//}
//
//int LTexture::getWidth()
//{
//    return mWidth;
//}
//
//int LTexture::getHeight()
//{
//    return mHeight;
//}
//
//bool LTexture::loadFromFile(std::string path) {
//    free();
//    SDL_Surface* loaded_surface = IMG_Load(path.c_str());
//    if(loaded_surface == NULL) return false;
//    SDL_SetColorKey(loaded_surface, SDL_TRUE, SDL_MapRGB(loaded_surface->format, 0, 0xFF, 0xFF));
//    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
//    if(texture == NULL) return false;
//    mWidth = loaded_surface->w;
//    mHeight = loaded_surface->h;
//    SDL_FreeSurface(loaded_surface);
//    mTexture = texture;
//    return mTexture != NULL;
//    
//}
//
//void LTexture::free() {
//    if(mTexture != NULL) {
//        SDL_DestroyTexture(mTexture);
//        mTexture = NULL;
//        mWidth = 0;
//        mHeight = 0;
//    }
//}
//
//bool loadMedia() {
//    if(!gFooTexture.loadFromFile("/Users/shroy/Desktop/foo.png")) {
//        return false;
//    }
//    if(!gBackgroundTexture.loadFromFile("/Users/shroy/Desktop/background.png")) {
//        return false;
//    }
//    return true;
//}
//
//void LTexture::render(int x, int y) {
//    SDL_Rect rect = {x, y, mWidth, mHeight};
//    SDL_RenderCopy(renderer, mTexture, NULL, &rect);
//}
//
//int main(int argc, char* args[]) {
//    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
//        return 0;
//    }
//    window = SDL_CreateWindow("Shilz game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//    if(window == NULL) {
//        return 0;
//    }
//    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//    
//    int imgFlags = IMG_INIT_PNG;
//    if(!(IMG_Init(imgFlags) & imgFlags)) {
//        printf("SDL Png flags can't be initialised, %s\n", SDL_GetError());
//        return 0;
//    }
//    if(!loadMedia()) {
//        return 0;
//    }
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
//        
//        gBackgroundTexture.render(0, 0);
//        gFooTexture.render(240, 190);
//        SDL_RenderPresent(renderer);
//    }
//    gFooTexture.free();
//    gBackgroundTexture.free();
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    renderer = NULL;
//    window = NULL;
//    IMG_Quit();
//    SDL_Quit();
//
//}
