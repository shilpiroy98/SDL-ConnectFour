////
////  sprite_render.cpp
////  SDL_tutorial
////
////  Created by Shilpi Roy on 11/12/20.
////  Copyright © 2020 Shilpi Roy. All rights reserved.
////
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
//        void render( int x, int y, SDL_Rect* clip , int col_num);
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
//SDL_Rect rect[4];
//LTexture gSpritesheetTexture;
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
//void LTexture::render(int x, int y, SDL_Rect *clip, int col_num) {
//    SDL_Rect curRect {x, y, mWidth, mHeight};
//    if(clip != NULL) {
//        curRect.w = clip->w/2;
//        curRect.h = clip->h/2;
//    }
//    if(col_num != -1 && col_num == x/50) {
//        SDL_SetTextureColorMod(mTexture, 255, 255, 255);
//        SDL_SetTextureAlphaMod(mTexture, 255);
//    }
//    else {
//        SDL_SetTextureColorMod(mTexture, 0, 0, 255);
//        SDL_SetTextureAlphaMod(mTexture, 45);
//    }
//    
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
//    if(!gSpritesheetTexture.loadFromFile("/Users/shroy/Desktop/SDL_tutorial/SDL_tutorial/dots.png")) {
//        printf("couldn't load sprite, %s", SDL_GetError());
//        return false;
//    }
//    rect[0].x = 0;
//    rect[0].y = 0;
//    rect[0].w = 100;
//    rect[0].h = 100;
//    
//    rect[1].x = 100;
//    rect[1].y = 0;
//    rect[1].w = 100;
//    rect[1].h = 100;
//    
//    rect[2].x = 0;
//    rect[2].y = 100;
//    rect[2].w = 100;
//    rect[2].h = 100;
//    
//    rect[3].x = 100;
//    rect[3].y = 100;
//    rect[3].w = 100;
//    rect[3].h = 100;
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
//        int col_num = -1;
//        while(SDL_PollEvent(&e) != 0) {
//            if(e.type == SDL_QUIT) {
//                quit = true;
//                break;
//            }
//            if(e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
//            {
//                //Get mouse position
//                int x, y;
//                SDL_GetMouseState( &x, &y );
//                col_num = x/50;
//                printf("%d, %d \n", x, y);
//            }
//                
//        }
//        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0xFF, 0xFF);
//        SDL_RenderClear(renderer);
//        for(int i = 0; i < SCREEN_WIDTH; i += 50) {
//            for(int j = 0; j < SCREEN_HEIGHT; j += 50) {
//                gSpritesheetTexture.render(i, j, &rect[0], col_num);
//            }
//        }
//       
////        gSpritesheetTexture.render(0, 0, &rect[0]);
////        gSpritesheetTexture.render(0, 50, &rect[0]);
////        gSpritesheetTexture.render(SCREEN_WIDTH - rect[1].w, 0, &rect[1]);
////        gSpritesheetTexture.render(0, SCREEN_HEIGHT - rect[2].h, &rect[2]);
////        gSpritesheetTexture.render(SCREEN_WIDTH - rect[3].w, SCREEN_HEIGHT - rect[3].h, &rect[3]);
//        SDL_RenderPresent(renderer);
//        SDL_Delay(400);
//    }
//    
//    close();
//    
//}
