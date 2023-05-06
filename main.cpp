//#include <iostream>
//#include <SDL.h>
//#include <SDL_image.h>
//#include <vector>
//#include <string>
//#include <stdio.h>
//#include <SDL_ttf.h>	
//#include <vector>
//#include <ctime>
//#include <stdexcept>
//#include <algorithm>
//#include "hangman.h"
//#include "Draw.h"
//#include "Texture.h"
//#define window_width 1536
//#define window_height 960
//SDL_Window* window = NULL;
//SDL_Renderer* renderer = NULL;
//
//
//int main(int argc, char* args[]) {
//	init(window, renderer);
//	SDL_Texture* intro = loadTexture("hangman.bmp", renderer);
//	SDL_RenderCopy(renderer, intro, NULL, NULL);
//	SDL_RenderPresent(renderer);
//	pressAnyKeyToContinue();
//	SDL_Texture* backgound = loadTexture("background.bmp", renderer);
//	/*SDL_Texture* guess[8] = { NULL };
//	for (int i = 0; i < 8; i++) {
//		guess[i] = loadTexture(Draw(i + 1), renderer);
//	}*/
//	SDL_Rect dest_rect = { 0, 80, window_width / 3, window_height/1.2 };
//	bool quit = false;
//	int current_texture = 0;
//	SDL_Event e;
//	while (!quit) {
//		SDL_RenderPresent(renderer);
//		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//		//SDL_RenderClear(renderer);
//		while (SDL_PollEvent(&e) != 0)
//		{
//			switch (e.type) {
//			case SDL_QUIT:
//				quit = 0;
//				break;
//			case SDL_KEYDOWN:
//				// Check if the user pressed the delete key
//				if (e.key.keysym.sym == SDLK_DELETE) {
//					// Delete the current texture
//					SDL_DestroyTexture(guess[current_texture]);
//					guess[current_texture] = NULL;
//				}
//				// Increment the current texture index and wrap around
//				current_texture = (current_texture + 1) % 8;
//				break;
//			case SDL_MOUSEBUTTONDOWN:
//				// Get the mouse position
//				int x = e.button.x;
//				int y = e.button.y;
//
//				// Check if the mouse is over the current texture
//				SDL_Rect texture_rect;
//				SDL_QueryTexture(guess[current_texture], NULL, NULL, &texture_rect.w, &texture_rect.h);
//				texture_rect.x = (940 - texture_rect.w) / 2;
//				texture_rect.y = (680 - texture_rect.h) / 2;
//				if (x >= texture_rect.x && x < texture_rect.x + texture_rect.w
//					&& y >= texture_rect.y && y < texture_rect.y + texture_rect.h) {
//					// Delete the current texture
//					SDL_DestroyTexture(guess[current_texture]);
//					guess[current_texture] = NULL;
//				}
//				// Increment the current texture index and wrap around
//				current_texture = (current_texture + 1) % 8;
//				break;
//			}
//		}
//
//		// Display the current texture
//		SDL_RenderClear(renderer);
//		if (guess[current_texture]) {
//			SDL_RenderCopy(renderer, backgound, NULL, NULL);
//			SDL_RenderCopy(renderer, guess[current_texture], NULL, &dest_rect );
//		}
//		SDL_RenderPresent(renderer);
//	}
//	return 0;
//}
//		
//			
//			
//		
//
//		
//		/*SDL_Texture* opening = loadTexture("hangman.bmp", renderer);		
//		SDL_RenderCopy(renderer, opening, NULL, NULL);
//		SDL_RenderPresent(renderer);
//		SDL_DestroyTexture(opening);*/
