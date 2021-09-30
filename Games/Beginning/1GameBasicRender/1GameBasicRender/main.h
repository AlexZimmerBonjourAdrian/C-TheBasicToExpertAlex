#pragma once

#include <SDL.h>;
#include <iostream>

#define WIDTH 1280
#define HEIGHT 720

bool running, fullscreen;

//Inicialisa Y trae el SDL  para renderizar y dibujar la ventana
SDL_Renderer* renderer;
SDL_Window* Window;

//Inicializo las variables de control de frame el tiempo frame el siguiente frame y los fps esto es para controlar el tiempo
int frameCount, timerFPS, lastFrame, fps,lastTime;

/*
void update(){
	if (fullscreen) SDL_SetWindowFullscreen(Window, SDL_WINDOW_FULLSCREEN);
	if (!fullscreen) SDL_SetWindowFullscreen(Window, 0);

}
*/
/*
void input(){
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT) running = false;

	}
	const Uint8 *keystates = SDL_GetKeyboardState(NULL);
	if (keystates[SDL_SCANCODE_ESCAPE]) running = false;
	if (keystates[SDL_SCANCODE_F11]) fullscreen=!fullscreen;

}
*/

void draw(){
	SDL_SetRenderDrawColor(renderer, 40, 43, 200, 255);
	SDL_Rect rect;
	rect.x = rect.y = 0;
	rect.w = WIDTH;
	rect.h = HEIGHT;
	SDL_RenderFillRect(renderer, &rect);

	frameCount++;
	int timerFPS = SDL_GetTicks() - lastFrame;
	if (timerFPS < (1000 / 60)) {
		SDL_Delay((1000 / 60) - timerFPS);

	}


		SDL_RenderPresent(renderer);
}


int main()
{
	//Es una variable de control del while
	running = 1;
	//SDL esto inicia la  ventana inicializando La ventana SDL en la tarjeta
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed at SDL_Init()" << std::endl;
	//Crea ua ventana y la renderiza pasandole el alto y ancho de la misma se le puede pasar una tecla, , un puntero al window y indicarle para renderizarlo
	if (SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0,&Window, &renderer) < 0) std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;
	//Simplemente me dibuja un titulo en la ventana renderizada
	SDL_SetWindowTitle(Window, "SDL2 Window");
	//1 para poder ver el cursor
	SDL_ShowCursor(1);
	//Renderiza el toque de los SQL
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
	
	//Ejecuta el gameLoop las tres funciones para poder hacerlo funcionar
	while (running)
		{
		lastFrame = SDL_GetTicks();
		if (lastFrame >= (lastFrame + 1000))
		{
			lastTime = lastFrame;
			fps = frameCount;
			frameCount = 0;
		}

		std::cout << fps << std::endl;
			//update();
			//input();
			draw();
		}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(Window);
	SDL_Quit();
	return 1;
}
