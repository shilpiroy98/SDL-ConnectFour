//
//  set_color.cpp
//  SDL_tutorial
//
//  Created by Shilpi Roy on 11/12/20.
//  Copyright © 2020 Shilpi Roy. All rights reserved.
//
//
//#include <stdio.h>
//#include <SDL.h>
//#include <SDL_image.h>
//#include <string>
//
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
//        void render( int x, int y, SDL_Rect* clip );
//    
//        void setColor(Uint8 r, Uint8 g, Uint8 b);
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
//LTexture gSpritesheetTexture;
//void LTexture::setColor(Uint8 r, Uint8 g, Uint8 b) {
//    SDL_SetTextureColorMod(mTexture, r, g, b);
//}
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
//bool LTexture::loadFromFile(std::string path) {
//    SDL_Surface* loaded_surface = IMG_Load(path.c_str());
//    if(loaded_surface == NULL) {
//        printf("null surface, %s", SDL_GetError());
//        return 0;
//    }
//    SDL_SetColorKey(loaded_surface, SDL_TRUE, SDL_MapRGB(loaded_surface->format, 0x00, 0xFF, 0xFF));
//    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
//    if(texture == NULL) {
//        printf("null texture, %s", SDL_GetError());
//        return 0;
//    }
//    mWidth = loaded_surface->w;
//    mHeight = loaded_surface->h;
//    SDL_FreeSurface(loaded_surface);
//    mTexture = texture;
//    return mTexture != NULL;
//}
//
//void LTexture::render(int x, int y, SDL_Rect *clip) {
//    SDL_Rect curRect {x, y, mWidth, mHeight};
//    if(clip != NULL) {
//        curRect.w = clip->w;
//        curRect.h = clip->h;
//    }
//    SDL_RenderCopy(renderer, mTexture, clip, &curRect);
//}
//
//void LTexture::free() {
//    if(mTexture != NULL) {
//        SDL_DestroyTexture(mTexture);
//        mTexture = NULL;
//        mWidth = mHeight = 0;
//    }
//}
//
//bool loadMedia() {
//    if(!gSpritesheetTexture.loadFromFile("/Users/shroy/Desktop/SDL_tutorial/SDL_tutorial/colors.png")) {
//        printf("couldn't load sprite, %s", SDL_GetError());
//        return false;
//    }
//    return true;
//}
//
//void close() {
//    gSpritesheetTexture.free();
//    SDL_DestroyRenderer(renderer);
//    SDL_DestroyWindow(window);
//    renderer = NULL;
//    window = NULL;
//    IMG_Quit();
//    SDL_Quit();
//}
//
//int main(int argc, char* args[]) {
//    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
//        printf("failed to initialize SDL, %s", SDL_GetError());
//        return 0;
//    }
//    window = SDL_CreateWindow("my game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//    if(window == NULL) {
//        printf("failed to initialise window, %s", SDL_GetError());
//        return 0;
//    }
//    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//    if(renderer == NULL) {
//        printf("failed to create renderer, %s", SDL_GetError());
//        return 0;
//    }
//    if(!loadMedia()) {
//        printf("couldn't load media!!");
//        return 0;
//    }
//    
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
//        gSpritesheetTexture.setColor(222, 12, 156);
//        gSpritesheetTexture.render(0, 0, NULL);
//        SDL_RenderPresent(renderer);
//    }
//    
//    close();
//    
//}
