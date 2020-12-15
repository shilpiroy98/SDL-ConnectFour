//
//  DotTexture.hpp
//  SDL_tutorial
//
//  Created by Shilpi Roy on 15/12/20.
//  Copyright © 2020 Shilpi Roy. All rights reserved.
//

#ifndef DotTexture_hpp
#define DotTexture_hpp

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <string>

class DotTexture
{
    public:
        //Initializes variables
        DotTexture();
    
        DotTexture(int x, int y);

        //Deallocates memory
        ~DotTexture();

        //Loads image at specified path
        bool loadFromFile( std::string path, SDL_Renderer* renderer);

        //Deallocates texture
        void free();

        //Renders texture at given point
        void render( int x, int y, SDL_Rect* clip , SDL_Renderer* renderer);
    
        void setColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, int turn);
    
        bool loadMedia(SDL_Renderer* renderer);
        void initialize(SDL_Renderer* renderer);

        //Gets image dimensions
        int getWidth();
        int getHeight();
        
        bool isColored();
        int getColor();
        const static int SPRITE_SIZE = 50;

    private:
        //The actual hardware texture
        SDL_Texture* mTexture;
        bool m_isColored;
        int m_color;
        int posX, posY;
        SDL_Rect spriteRect;
        //Image dimensions
        int mWidth;
        int mHeight;
};

#endif /* DotTexture_hpp */