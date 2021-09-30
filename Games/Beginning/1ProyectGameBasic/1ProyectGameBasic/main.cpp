#include "main.h"
#include "SDL/SDL.h"
#include <iostream>
//Tamaño de la Pantalla

#define WIDTH 1280;
#define HEIGHT 720;

bool running, fullscreen;


SDL_Renderer* render;
SDL_Window* window;

void Update(){}
void input(){}
void draw(){}

int main()
{
	running = 1;
	while (running)
	{
		update();
		input();
		draw();
	}
}
