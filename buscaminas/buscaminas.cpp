// buscaminas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Window.h"
#include "Image.h"
#include "Player.h"
#include <vector>
#include "Bullet.h"

int main(int argc, char* args[])
{
    int DirX;
    int DirY;
    bool click;
    std::vector<Bullet> bullets;
    Window* window = Window::GetPtr();
    window->Init();
    Player p;
    p.Init();
    while (true)
    {
        window->Clear();
        window->Input(DirX, DirY, click);
        if (DirY > 0) 
        {
            p.y-=0.1;
        }
        else if (DirY < 0) 
        {
            p.y+=0.1;
        }
        if (DirX > 0)
        {
            p.x -= 0.1;
        }
        else if (DirX < 0)
        {
            p.x += 0.1;
        }

        if (click)
        {
            Bullet newBullet;
            newBullet.Init(p.x, p.y);
            bullets.push_back(newBullet);
        }
        for (int i = 0; i < bullets.size(); i++)
        {
            bullets[i].Draw();
        }
        p.Draw();
        window->Render();
    }

    std::cout << "Hello World!\n";
    return 0;
}


