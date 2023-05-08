#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <SDL_ttf.h>	
#include <vector>
#include <ctime>
#include<SDL_mixer.h>
#include <stdexcept>
#include <algorithm>
#include "hangman.h"
#include "Draw.h"
#include "Texture.h"
const int MAX_MISTAKES = 8;
#define window_width 1536
#define window_height 960
static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
int main(int argc, char* args[]) {
	init(window, renderer);
	
    intro(renderer);
   
    bool iscontinue = true;
    
    while (iscontinue) {
        SDL_RenderClear(renderer);
        srand((int)time(0));
        //string vocabularyFile = "Ogden_Picturable_200.txt";
        string vocabularyFile = "words.txt";
        //string vocabularyFile = "data/ErrorOpenFileTest.txt";
        //string vocabularyFile = "data/EmptyTest.txt";
        vector<string> wordList;
        wordList = readWordListFromFile(vocabularyFile);
        int index = generateRandomNumber(0, wordList.size() - 1);
        string word =chooseWordFromList(wordList, index);
        if (word.empty()) {
            std::cout << "Error: Coud not choose a random word." << std::endl;
            return 1;
        }
        //cout << "Chosen word: " << word << endl;
        // string secretWord(word.length(), '-');
        string secretWord = generateHiddenCharacters(word);
        int incorrectGuess = 0;
        string correctChars = "";
        string incorrectChars = "";
        string Enterchars = "";
        do {
            printScreen(word, secretWord, correctChars, incorrectGuess, incorrectChars, renderer, Enterchars);
            char ch = getInputCharacter(renderer);
            std::cout << ch << std::endl;
            Enterchars.push_back(ch);
            Enterchars += " ";
            std::cout << Enterchars << std::endl;
            processData(ch, word, secretWord,
                correctChars, incorrectGuess, incorrectChars, renderer);
            printScreen(word, secretWord, correctChars, incorrectGuess, incorrectChars, renderer, Enterchars);
        } while (secretWord != word && incorrectGuess != MAX_MISTAKES - 1);
        SDL_RenderClear(renderer);
        outro(renderer, word, secretWord, iscontinue);
    }
	return 0;
}  