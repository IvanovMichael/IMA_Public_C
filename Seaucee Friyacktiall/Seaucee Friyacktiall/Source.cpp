#include <SDL.h>
#undef main

struct point
{
	double x, y;
	point(double x, double y) : x(x), y(y) {};
};

point sqr(point p)
{
	return point(p.x*p.x - p.y*p.y, 2 * p.x*p.y);
}

point pow(point p, Uint16 n)
{
	if (n == 0)
		return point(1., 0.);
	point z = sqr(pow(p, n / 2));
	if (n & 1)
		return point(p.x*z.x - p.y*z.y, p.x*z.y + p.y*z.x);
	else
		return z;
}

point sum(point p1, point p2)
{
	return point(p1.x + p2.x, p1.y + p2.y);
}

int main()
{
	const uint16_t	WIDTH = 920,
					HEIGHT = 980;
	const point C(-0.777807810193171, 0.131645108003206);				//Центр изображения
	const long double l = 3.2E-10;				//Размер изображения
	const Uint16 N = 2;					//Степень многОчлена
	const Uint16 K = 10000;				//Кол-во итераций


	const double d = l / HEIGHT;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *win = SDL_CreateWindow("Lokheed", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer *rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	SDL_RenderClear(rend);

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			point P(C.x + d*(i - WIDTH / 2), C.y - d*(j - HEIGHT / 2));
			point Z = P;
			for (int k = 0; k < K; k++)
			{
				Z = sum(pow(Z, N), P); // P{Мандельштамм} <=> point(x, y){Жюльен}
				if (Z.x*Z.x + Z.y*Z.y > 4)
				{
					Uint8 r, g, b;

					switch ((k / 64) % 2)
					{
					case 0: {r = 255; g = 4 * (k % 64); b = 0; break; }
					//case 1: {r = 255 - 4 * (k % 64); g = 255; b = 0; break; }
					//case 2: {r = 0; g = 255; b = 4 * (k % 64); break; }
					//case 3: {r = 0; g = 255 - 4 * (k % 64); b = 255; break; }
					//case 4: {r = 4 * (k % 64); g = 0; b = 255; break; }
					case 1: {r = 255; g = 0; b = 255 - 4 * (k % 64); break; }
					}

					SDL_SetRenderDrawColor(rend, r, g, b, 0);
					SDL_RenderDrawPoint(rend, i, j);
					break;
				}
			}
		}
		SDL_RenderPresent(rend);
	}

	SDL_Surface* pScreenShot = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0x00000000);

	if (pScreenShot)
	{
		// Read the pixels from the current render target and save them onto the surface 
		SDL_RenderReadPixels(rend, NULL, SDL_GetWindowPixelFormat(win), pScreenShot->pixels, pScreenShot->pitch);

		// Create the bmp screenshot file 
		SDL_SaveBMP(pScreenShot, "Fractal.bmp");

		// Destroy the screenshot surface 
		SDL_FreeSurface(pScreenShot);
	}

	SDL_Delay(5000);
	
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}