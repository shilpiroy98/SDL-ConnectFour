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
        bool loadFromFile(std::string path, std::string path2, SDL_Renderer* renderer);

        //Deallocates texture
        void free();

        //Renders texture at given point
        void render(SDL_Renderer* renderer, int turn = -1);
    
        void setColor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, int turn);
    
        bool loadMedia(SDL_Renderer* renderer);
        void initialize(SDL_Renderer* renderer);
        static void setHoverIndex(int x);
        void highlight(SDL_Renderer* renderer, int turn);

        //Gets image dimensions
        int getWidth();
        int getHeight();
        
        bool isColored();
        int getColor();
        const static int SPRITE_SIZE = 32;
        static const std::string FILE_PATH;

    private:
        //The actual hardware texture
        static SDL_Texture* mTexture;
        static SDL_Texture* mTexture2;
        static int hoverIndex;
        SDL_Texture* currentTexture;
        bool m_isColored;
        int m_color;
        int posX, posY;
        SDL_Rect spriteRect;
        static SDL_Surface* mloadedSurfaceOne, *mloadedSurfaceTwo;
        //Image dimensions
        int mWidth;
        int mHeight;
};


#endif /* DotTexture_hpp */
