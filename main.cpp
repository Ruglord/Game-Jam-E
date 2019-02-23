#include <iostream>
#include <vector>
#include <SDL.h>

#include <render.h>


struct Circle
{
    int x, y;
    int radius = 0;
    Circle()
    {

    }
    bool collides(Circle& circ)
    {
        return sqrt(pow(x-circ.x,2) + pow(y-circ.y,2)) <= radius + circ.radius;
    }
};

struct Planet
{
    Circle c;
    Sprite* spr = nullptr;
    Planet(int X, int Y, int R, Sprite& sprite)
    {
        spr = &sprite;
        c = {X,Y,R};
    }
    void render()
    {
        spr->renderInstanced(RenderProgram::basicProgram,{{{c.x,c.y,c.radius*2,c.radius*2}}});
    }
};

struct Ball
{
    double speedX = 0, speedY = 0;
    double accelX = 0, accelY = 0;
    Circle c;
    Sprite s;
    Ball()
    {
        c = {100,100,64};
        s.init("sprites/circle.png",true);
    }
    void update(std::vector<Planet>& vec)
    {

    }
    void render()
    {
        s.renderInstanced(RenderProgram::basicProgram,{{{c.x,c.y,c.radius,c.radius}}});
    }
};
const int screenWidth = 640, screenHeight = 640;
int main(int args, char** argc)
{
    SDL_Window* window = SDL_CreateWindow("Gravity Golf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,screenWidth,screenHeight,SDL_WINDOW_SHOWN);
    SDL_Event e;
    RenderProgram::init(screenWidth,screenHeight);
    bool quit = false;
    while (!quit)
    {
        while(SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }
}
