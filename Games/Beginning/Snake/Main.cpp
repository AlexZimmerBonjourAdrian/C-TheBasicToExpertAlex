
#include <SDL.h>
#include <iostream>

#define WIDTH 1280
#define HEIGTHT 720
 

bool running, fullscreen;

SDL_Renderer* renderer;
SDL_Window* window;

int frameCount, timeFPS, lastFrame,fps;

void Update(){
	if (fullscreen) SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
	if (!fullscreen) SDL_SetWindowFullscreen(window, 0);
}

void input(){
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) running = false;
	}
	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	if (keystates[SDL_SCANCODE_ESCAPE])running = false;
	if (keystates[SDL_SCANCODE_F11]) fullscreen;
}
void draw(){
	SDL_SetRenderDrawColor(renderer, 40, 43, 200, 255);
	SDL_Rect rect;
	rect.x = rect.y = 0;
	rect.w = WIDTH;
	rect.h = HEIGTHT;
	SDL_RenderFillRect(renderer, &rect);
	frameCount++;
	int timerFPS = SDL_GetTicks() - lastFrame;
	if (timerFPS < (1000 / 60))
	{
		SDL_Delay((1000 / 60) - timerFPS);
	}
	SDL_RenderPresent(renderer);
}


int main()
{
	running = 1;
	fullscreen = 0;
	int lastTime = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed at SDL_init()" << std::endl;
	if (SDL_CreateWindowAndRenderer(WIDTH, HEIGTHT, 0, &window,&renderer) < 0) std::cout << "Failed at SDL_Create" << std::endl;
	SDL_SetWindowTitle(window, "SDL2 Widow");
	SDL_ShowCursor(1);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
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
			Update();
			input();
			draw();
		}
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 0;

}


/*
#include <SDL.h>

#undef main
#include <iostream>

int Width = 1024;
int heught = 768;

void drawQuad(SDL_Window& w, SDL_Color c, int x1, int y1,int w1, int x2, int y2, int w2)
{
	SDL_Rect fillRect = {x1-w1,y1,x2-w2,y2};
	SDL_SetRenderDrawColor(gRendrer, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(gRenderer, &fillRect)

}
*/