#include "common.hpp"
#include <SDL.h>
#include <cmath>
#include <iostream>
#include "3dPoint.hpp"
#include "cube.hpp"

float A = 0;
float B = 0;
std::pair <float, SDL_Color> screenPixels[600][400];
SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;

bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		success = false;
	}
	else
	{
		!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
		gWindow = SDL_CreateWindow("Rotating Cube", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				success = false;
			}
		}
	}
	return success;
}

void close()
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	SDL_Quit();
}

int main(int argc, char *args[])
{
	if (init())
	{
		Cube cube;
		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}
			SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 1);
			SDL_RenderClear(gRenderer);
			for(int i = 0; i < 600; i++)
			{
				for(int j = 0; j < 400; j++)
				{
					screenPixels[i][j].first = -999;
					screenPixels[i][j].second = {0, 0, 0, 1};
				}
			}
			A += 0.06;
			B += 0.04;
			cube.render();
			for(int i = 0; i < 600; i++)
			{
				for(int j = 0; j < 400; j++)
				{
					SDL_SetRenderDrawColor(gRenderer, screenPixels[i][j].second.r, screenPixels[i][j].second.g, screenPixels[i][j].second.b, screenPixels[i][j].second.a);
					SDL_RenderDrawPoint(gRenderer, i, j);
				}
			}
			SDL_RenderPresent(gRenderer);
		}
	}
	close();
	return 0;
}