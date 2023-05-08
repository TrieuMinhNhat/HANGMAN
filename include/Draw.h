#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include <vector>
#include <string>
#include "Texture.h"
std::string Draw(int incorr);
void printStats(const std::string& word, const std::string& secretWord, const std::string& correctChars, const int incorrectGuess, const std::string& incorrectChars, SDL_Renderer*& grenderer);

void printScreen(const std::string& word, const std::string& secretWord, const std::string& correctChars, const int incorrectGuess, const std::string& incorrectChars, SDL_Renderer*& grenderer, std::string Enterchars);

SDL_Rect getSDLRect(int x, int y, int width, int height);

void createWinAnimation(SDL_Renderer*& renderer);

void outro(SDL_Renderer* renderer, std::string word, std::string secrectWord, bool& iscontinue);