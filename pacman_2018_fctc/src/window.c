#include "window.h"
#include <SDL/SDL_rotozoom.h>

#define SCREEN_WID 448
#define SCREEN_HEI 640

bool init_window(const char* title, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}

	screen = SDL_SetVideoMode(SCREEN_WID, SCREEN_HEI, 32, SDL_SWSURFACE | SDL_RESIZABLE);

	if (screen == NULL)
	{
		return false;
	}

	SDL_WM_SetCaption(title, NULL);

	return true;
}

void dispose_window(void)
{
	SDL_FreeSurface(screen);
}

SDL_Surface *get_screen(void)
{
	return screen;
}

void clear_screen(int r, int g, int b, int a)
{
	Uint32 col = SDL_MapRGBA(screen->format, r, g, b, a);

	SDL_FillRect(screen, NULL, col);
}

void apply_surface(int x, int y, SDL_Surface* source)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	
	SDL_BlitSurface(source, NULL, screen, &offset);
}

void flip_screen(void)
{
	SDL_Surface * temp;

	double zoom_w = (double) scr_temp_rec.w /SCREEN_WID;
	double zoom_h = (double) scr_temp_rec.h /SCREEN_HEI;
	
	temp = zoomSurface(screen, zoom_w, zoom_h, 0);

	SDL_BlitSurface(temp, NULL, screen, &scr_temp_rec);

	SDL_FreeSurface(temp);
	
	SDL_Flip(screen);
}
