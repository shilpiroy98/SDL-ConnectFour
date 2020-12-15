//
//  DotTexture.cpp
//  SDL_tutorial
//
//  Created by Shilpi Roy on 15/12/20.
//  Copyright © 2020 Shilpi Roy. All rights reserved.
//

#include "DotTexture.hpp"

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

bool DotTexture::loadFromFile(std::string path, SDL_Renderer* renderer) {
    SDL_Surface* loaded_surface = IMG_Load(path.c_str());
    if(loaded_surface == NULL) {
        printf("null surface, %s", SDL_GetError());
        return 0;
    }
    SDL_SetColorKey(loaded_surface, SDL_TRUE, SDL_MapRGB(loaded_surface->format, 0x00, 0xFF, 0xFF));
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
    if(texture == NULL) {
        printf("null texture, %s", SDL_GetError());
        return 0;
    }
    mWidth = loaded_surface->w;
    mHeight = loaded_surface->h;
    SDL_FreeSurface(loaded_surface);
    mTexture = texture;
    return mTexture != NULL;
}

void DotTexture::render(int x, int y, SDL_Rect *clip, SDL_Renderer* renderer) {
    SDL_Rect curRect {x, y, 50, 50};
    if(clip != NULL) {
        curRect.w = clip->w/2;
        curRect.h = clip->h/2;
    }
//    printf(".....");
    //if(!isColored()) SDL_SetTextureAlphaMod(mTexture, 24);
    SDL_RenderCopy(renderer, mTexture, &spriteRect, &curRect);
}

void DotTexture::free() {
    if(mTexture != NULL) {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = mHeight = 0;
    }
}

bool DotTexture::loadMedia(SDL_Renderer* renderer) {
    if(!loadFromFile("/Users/shroy/Desktop/SDL_tutorial/SDL_tutorial/rouge.png", renderer)) {
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
    SDL_SetTextureColorMod(mTexture, r, g, b);
    if(turn == 0)
    SDL_SetTextureAlphaMod(mTexture, 124);
    render(posX, posY, &spriteRect, renderer);
}

int DotTexture::getColor() {
    return m_color;
}
