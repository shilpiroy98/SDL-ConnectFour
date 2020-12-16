//
//  DotTexture.cpp
//  SDL_tutorial
//
//  Created by Shilpi Roy on 15/12/20.
//  Copyright © 2020 Shilpi Roy. All rights reserved.
//

#include "DotTexture.hpp"

SDL_Surface* DotTexture::mloadedSurfaceOne = NULL;
SDL_Surface* DotTexture::mloadedSurfaceTwo = NULL;

SDL_Texture* DotTexture::mTexture = NULL;
SDL_Texture* DotTexture::mTexture2 = NULL;

const std::string DotTexture::FILE_PATH = "/Users/shroy/Desktop/SDL_tutorial/SDL_tutorial/";

DotTexture::DotTexture()
{
    //Initialize
    mTexture = NULL;
    m_isColored = false;
    m_color = -1;
    mWidth = 0;
    mHeight = 0;
}

DotTexture::DotTexture(int x, int y)
{
    //Initialize
    m_color = -1;
    mTexture = NULL;
    m_isColored = false;
    mWidth = 0;
    mHeight = 0;
    posX = x;
    posY = y;
}

DotTexture::~DotTexture()
{
    //Deallocate
    free();
}

void DotTexture::initialize(SDL_Renderer* renderer) {
    if(loadMedia(renderer)) {
        //render(posX, posY, &spriteRect, renderer);
    }
}

bool DotTexture::loadFromFile(std::string path, std::string path2, SDL_Renderer* renderer) {
    if(mTexture != NULL && mTexture2 != NULL) return true;
    if(mloadedSurfaceOne == NULL) {
        mloadedSurfaceOne = IMG_Load(path.c_str());
    }
    
    if(mloadedSurfaceOne == NULL) {
        printf("null surface, %s", SDL_GetError());
        return 0;
    }
    //SDL_SetColorKey(mloadedSurfaceOne, SDL_TRUE, SDL_MapRGB(mloadedSurfaceOne->format, 0x00, 0xFF, 0xFF));
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, mloadedSurfaceOne);
    if(texture == NULL) {
        printf("null texture, %s", SDL_GetError());
        return 0;
    }
    mWidth = mloadedSurfaceOne->w;
    mHeight = mloadedSurfaceOne->h;
    mTexture = texture;
    
    if(mloadedSurfaceTwo == NULL) {
        mloadedSurfaceTwo = IMG_Load(path2.c_str());
    }
    
    if(mloadedSurfaceTwo == NULL) {
        printf("null surface, %s", SDL_GetError());
        return 0;
    }
    //SDL_SetColorKey(mloadedSurfaceTwo, SDL_TRUE, SDL_MapRGB(mloadedSurfaceTwo->format, 0x00, 0xFF, 0xFF));
    SDL_Texture* texture2 = SDL_CreateTextureFromSurface(renderer, mloadedSurfaceTwo);
    if(texture2 == NULL) {
        printf("null texture, %s", SDL_GetError());
        return 0;
    }
    mWidth = mloadedSurfaceTwo->w;
    mHeight = mloadedSurfaceTwo->h;
    //SDL_FreeSurface(mloadedSurface);
    mTexture2 = texture2;
    currentTexture = mTexture;
    return mTexture != NULL && mTexture2 != NULL;
}

void DotTexture::render(int x, int y, SDL_Rect *clip, SDL_Renderer* renderer, int turn) {
    SDL_Rect curRect {x, y, 50, 50};
    if(clip != NULL) {
        curRect.w = clip->w/2;
        curRect.h = clip->h/2;
    }
    if(!isColored()) {
         SDL_SetTextureAlphaMod(mTexture, 45);
         SDL_RenderCopy(renderer, mTexture, &spriteRect, &curRect);
    }
    else {
        SDL_SetTextureAlphaMod(mTexture, 255);
        SDL_RenderCopy(renderer, currentTexture, &spriteRect, &curRect);
    }

}

void DotTexture::free() {
    if(mTexture != NULL) {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
    }
    
    if(mTexture2 != NULL) {
        SDL_DestroyTexture(mTexture2);
        mTexture2 = NULL;
    }
    mWidth = mHeight = 0;
    currentTexture = NULL;
    if(mloadedSurfaceOne != NULL) {
        SDL_FreeSurface(mloadedSurfaceOne);
    }
    if(mloadedSurfaceTwo != NULL) {
        SDL_FreeSurface(mloadedSurfaceTwo);
    }
    mloadedSurfaceOne = mloadedSurfaceTwo = NULL;
}

bool DotTexture::loadMedia(SDL_Renderer* renderer) {
    if(!loadFromFile(FILE_PATH + "rouge.png", FILE_PATH + "blue.png", renderer)) {
        printf("couldn't load sprite, %s", SDL_GetError());
        return false;
    }
    spriteRect.x = 0;
    spriteRect.y = 0;
    spriteRect.w = 32;
    spriteRect.h = 32;
    return true;
}

bool DotTexture::isColored() {
    return m_isColored;
}

void DotTexture::setColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, int turn) {
    m_isColored = true;
    m_color = turn;
    if(turn == 0) currentTexture = mTexture;
    else currentTexture = mTexture2;
}

int DotTexture::getColor() {
    return m_color;
}

