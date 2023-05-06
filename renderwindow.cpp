//#include <SDL.h>
//#include <iostream>
//#include<SDL_image.h>
//#include <string>
//#include "RenderWindow.h"
//#include "entity.h"
//using namespace std;
//RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
//	:window(NULL), renderer(NULL)
//{
//	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
//
//	if (window == NULL)
//	{
//		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
//	}
//
//	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//}
//SDL_Texture* RenderWindow::loadTexture(const char* p_filepath) {
//
//	SDL_Texture* texture = NULL;
//	texture = IMG_LoadTexture(renderer, p_filepath);
//	if (texture == NULL) {
//		cout << "Fail to load texture! " << SDL_GetError() << endl;
//	}
//	return texture;
//}
//void RenderWindow::cleanUp()
//{
//	SDL_DestroyWindow(window);
//}
//
//void RenderWindow::clear()
//{
//	SDL_RenderClear(renderer);
//}
//
//void RenderWindow::render(SDL_Texture* p_tex)
//{	
//	/*SDL_Rect src;
//	src.x =p_entity.getCurrentFrame().x;
//	src.y = p_entity.getCurrentFrame().y;
//	src.w = p_entity.getCurrentFrame().w;
//	src.h = p_entity.getCurrentFrame().h;
//	SDL_Rect dst;
//	dst.x = p_entity.getX()*4;
//	dst.y = p_entity.getY()*4;
//	dst.w = p_entity.getCurrentFrame().w*4;
//	dst.h = p_entity.getCurrentFrame().h*4;*/
//
//	SDL_RenderCopy(renderer,p_tex ,NULL, NULL);
//}
//
//void RenderWindow::display()
//{
//	SDL_RenderPresent(renderer);
//}
//void RenderWindow::loadsc() {
//	SDL_Surface* Screensurface = NULL;
//	SDL_Surface* bkgr = NULL;
//	window = NULL;
//	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
//	Screensurface = SDL_GetWindowSurface(window);
//	bkgr = SDL_LoadBMP("anh1.bmp");
//	SDL_BlitSurface(bkgr, NULL, Screensurface, NULL);
//}