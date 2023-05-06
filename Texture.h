#pragma once
#include<SDL.h>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include<SDL_mixer.h>
#include <stdio.h>
void init(SDL_Window* &gWindow, SDL_Renderer* &gRenderer);
SDL_Texture* loadTexture(std::string path, SDL_Renderer* &renderer);
void waitUntilKeyPressed();
SDL_Texture* LoadFontTexture(SDL_Renderer* grenderer, std::string fontFilePath, int fontSize, const char* text, SDL_Color color);
void pressAnyKeyToContinue();
void renderTextCentered(SDL_Renderer* grenderer, TTF_Font* font, const char* text, SDL_Window* gwindow);
void handleButtonClick(SDL_Rect playButtonRect);
bool waitForButtonClick(SDL_Rect buttonRect);
void pressEnterToContinue();
void playSound(bool correct);
void playMusic(const char* filePath, int loops);
void intro(SDL_Renderer*& renderer);