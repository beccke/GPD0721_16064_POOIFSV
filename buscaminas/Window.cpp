#include "Window.h"
#include <iostream>

 Window *Window::ptr = nullptr;

 Window::Window()
 {
 }

Window *Window::GetPtr()
{
     if (ptr == nullptr)
     {
         ptr = new Window();
     }
     return ptr;
}

void Window::Init()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("buscaminas", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 480, 640, SDL_WINDOW_SHOWN);
    canvas = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}
void Window::Clear()
{
    SDL_SetRenderDrawColor(canvas, 255, 0, 0, 255);
    SDL_RenderClear(canvas);
}
void Window::Render() 
{
    SDL_RenderPresent(canvas);
}
void Window::Input(int &DirectionX, int &DirectionY, bool &isClick)
{
    const Uint8 *keys = SDL_GetKeyboardState(NULL);
    DirectionX = 0;
    DirectionY = 0;
    if (keys[SDL_SCANCODE_UP])
    {
        std::cout << "se preciono arriba";
        DirectionY = 1;
    }
    else if (keys[SDL_SCANCODE_DOWN])
    {
        DirectionY = -1;
    }    
    if (keys[SDL_SCANCODE_LEFT])
    {
        std::cout << "se preciono DERECHA";
        DirectionX = 1;
    }
    else if (keys[SDL_SCANCODE_RIGHT])
    {
        DirectionX = -1;
    }

    //Input
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        if (e.button.type == SDL_MOUSEBUTTONDOWN) 
        {
            isClick = true;
            std::cout << "click";
            std::cout << e.button.x << std::endl;
            std::cout << e.button.y << std::endl;
        }
        else
        {
            isClick = false;
        }
    }
}

SDL_Renderer* Window::GetCanvas()
{
    return canvas;
}

void Window::RenderTexture(Image *image,int x, int y)
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.w = image->GetWidth();
    dest.h = image->GetHeight();
    SDL_RenderCopy(canvas, image->GetTexture(), NULL, &dest);
}