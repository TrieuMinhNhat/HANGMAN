
#include <SDL.h>
#include<iostream>
#include <SDL_image.h>
#include <string>
#include <SDL_ttf.h>
#include<SDL_mixer.h>
#include "Texture.h"
#include "Draw.h"
#define window_width 1536
#define window_height 960

void init (SDL_Window* &gWindow, SDL_Renderer* &gRenderer)
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("HANGMAN2D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
		if (TTF_Init() == -1)
		{
			printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
			success = false;
		}
		if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) != 0) {
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == 0) {
				// Mixer is initialized successfully
			}
			else {
				// Failed to open audio
				std::cout << SDL_GetError();
			}
		}
		else {
			// Failed to initialize mixer
		}
	}

}
SDL_Texture* loadTexture(std::string path, SDL_Renderer* &gRenderer)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
void pressAnyKeyToContinue() {
	SDL_Event ev;
	while (SDL_WaitEvent(&ev)) {
		if (ev.type == SDL_KEYDOWN) {
			break;
		}
		else if (ev.type == SDL_QUIT) {
			exit(1);
		}
	}
}
SDL_Texture* LoadFontTexture(SDL_Renderer* grenderer, std::string fontFilePath, int fontSize, const char* text, SDL_Color color) {
	// load the font
	TTF_Font* font = TTF_OpenFont(fontFilePath.c_str(), fontSize);
	if (font == NULL) {
		printf("Failed to load font: %s\n", TTF_GetError());
		return NULL;
	}

	// create a surface from the font and text
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);
	if (textSurface == NULL) {
		printf("Failed to render text: %s\n", TTF_GetError());
		TTF_CloseFont(font);
		return NULL;
	}

	// create a texture from the surface
	SDL_Texture* texture = SDL_CreateTextureFromSurface(grenderer, textSurface);
	if (texture == NULL) {
		printf("Failed to create texture: %s\n", SDL_GetError());
		SDL_FreeSurface(textSurface);
		TTF_CloseFont(font);
		return NULL;
	}

	// free the surface and font
	SDL_FreeSurface(textSurface);
	TTF_CloseFont(font);

	// return the texture
	return texture;
}
void renderTextCentered(SDL_Renderer* grenderer, TTF_Font* font, const char* text, SDL_Window*& gwindow) {
	// create a surface from the font and text
	SDL_Color color = { 0, 0, 0 }; // black color
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);

	// create a texture from the surface
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(grenderer, textSurface);

	// get the dimensions of the texture
	int textureWidth, textureHeight;
	SDL_QueryTexture(textTexture, NULL, NULL, &textureWidth, &textureHeight);

	// get the dimensions of the window
	int windowWidth, windowHeight;
	SDL_GetWindowSize(gwindow, &windowWidth, &windowHeight);

	// calculate the x and y positions to center the texture
	int xPos = (windowWidth - textureWidth) / 2;
	int yPos = (windowHeight - textureHeight) / 2;

	// render the texture to the screen
	SDL_Rect destRect = { xPos, yPos, textureWidth, textureHeight };
	SDL_RenderCopy(grenderer, textTexture, NULL, &destRect);

	// free the surface and texture
	SDL_FreeSurface(textSurface);
	SDL_DestroyTexture(textTexture);
}
void handleButtonClick(SDL_Rect buttonRect) {
	SDL_Event event;
	bool quit = false;
	memset(&event, 0, sizeof(SDL_Event));
	//SDL_Event event;
	while ( !quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN) {
				int mouseX, mouseY;
				SDL_GetMouseState(&mouseX, &mouseY);
				if (mouseX >= buttonRect.x && mouseX < buttonRect.x + buttonRect.w &&
					mouseY >= buttonRect.y && mouseY < buttonRect.y + buttonRect.h) {
					quit = true;
				}
			}
		}
	}
}

bool waitForButtonClick(SDL_Rect buttonRect) {
	SDL_Event event;
	bool quit = false;
	memset(&event, 0, sizeof(SDL_Event));
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN) {
				int mouseX, mouseY;
				SDL_GetMouseState(&mouseX, &mouseY);
				if (mouseX >= buttonRect.x && mouseX < buttonRect.x + buttonRect.w &&
					mouseY >= buttonRect.y && mouseY < buttonRect.y + buttonRect.h) {
					return true;
				}
			}
		}
	}
	return false;
}
void pressEnterToContinue() {
	std::cout << "Press Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}
void playSound(bool correct) {
	// Initialize SDL_mixer
	Mix_Init(MIX_INIT_MP3);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	// Load the sound effect
	Mix_Chunk* sound_effect;
	if (correct) {
		sound_effect = Mix_LoadWAV("correct.wav");
	}
	else {
		sound_effect = Mix_LoadWAV("wrong.wav");
	}

	// Play the sound effect
	Mix_PlayChannel(-1, sound_effect, 0);
	SDL_Delay(500);
	// Clean up resources
	Mix_FreeChunk(sound_effect);
	Mix_CloseAudio();
	Mix_Quit();
}

/*void scrollText(SDL_Renderer*& renderer, const std::string& fontPath, int fontSize, const std::string& text, int scrollSpeed, int startX, int startY) {
	// Load the font texture
	SDL_Texture* fontTexture = loadTexture(fontPath, renderer);

	// Set the font size and color
	TTF_Font* font = TTF_OpenFont(fontPath.c_str(), fontSize);
	SDL_Color color = { 255, 255, 255, 255 };

	// Calculate the total width of the text
	int textWidth, textHeight;
	TTF_SizeText(font, text.c_str(), &textWidth, &textHeight);

	// Calculate the number of frames needed to fully scroll the text
	int numFrames = textWidth / scrollSpeed;
	if (textWidth % scrollSpeed > 0) {
		numFrames++;
	}

	// Create a timer to update the animation
	int currentFrame = 0;
	SDL_TimerCallback timerCallback = [](Uint32 interval, void* param) -> Uint32 {
		SDL_Renderer* renderer = static_cast<SDL_Renderer*>(param);

		// Display the current frame
		int x = startX - currentFrame * scrollSpeed;
		int y = startY;
		SDL_Rect sourceRect = { currentFrame * scrollSpeed, 0, textWidth - currentFrame * scrollSpeed, textHeight };
		SDL_Rect destRect = { x, y, textWidth - currentFrame * scrollSpeed, textHeight };
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, fontTexture, &sourceRect, &destRect);
		SDL_RenderPresent(renderer);

		// Move to the next frame
		currentFrame++;
		if (currentFrame >= numFrames) {
			currentFrame = 0;
		}

		return interval;
	};
	SDL_TimerID timerID = SDL_AddTimer(16, reinterpret_cast<SDL_TimerCallback>(timerCallback), renderer);

	// Wait for the user to quit
	bool quit = false;
	SDL_Event event;
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
		SDL_Delay(10);
	}

	// Clean up resources
	SDL_RemoveTimer(timerID);
	TTF_CloseFont(font);
	SDL_DestroyTexture(fontTexture);
}*/

void intro(SDL_Renderer*& renderer) {
	SDL_Texture* intro = loadTexture("hangman.jpg", renderer);
	SDL_Texture* playbutton = loadTexture("play.png", renderer);
	SDL_Texture* tex = LoadFontTexture(renderer, "intro.ttf", 30, "Click the button above to play!", { 0, 0, 255,255 });
	int textWidth, textHeight;
	SDL_QueryTexture(tex, NULL, NULL, &textWidth, &textHeight);
	SDL_Rect texrect = getSDLRect(window_width / 2 + 0, window_height / 2 + 85, textWidth, textHeight);

	SDL_QueryTexture(playbutton, NULL, NULL, &textWidth, &textHeight);
	SDL_Rect playbuttonrect = getSDLRect(window_width / 2 + 90, window_height / 2 - 40, textWidth / 5, textHeight / 5);
	SDL_RenderCopy(renderer, intro, NULL, NULL);
	SDL_RenderCopy(renderer, playbutton, NULL, &playbuttonrect);
	SDL_RenderCopy(renderer, tex, NULL, &texrect);
	SDL_RenderPresent(renderer);
	handleButtonClick(playbuttonrect);
}


void playMusic(const char* filePath, int loops) {
	// Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return;
	}

	// Load music file
	Mix_Music* music = Mix_LoadMUS(filePath);
	if (music == NULL) {
		printf("Failed to load music file! SDL_mixer Error: %s\n", Mix_GetError());
		return;
	}

	// Play music
	if (Mix_PlayMusic(music, loops) < 0) {
		printf("Failed to play music! SDL_mixer Error: %s\n", Mix_GetError());
		return;
	}

	// Wait for music to finish playing
	while (Mix_PlayingMusic()) {
		SDL_Delay(0);
	}

	// Free resources
	Mix_FreeMusic(music);
	Mix_CloseAudio();
}
