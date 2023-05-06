#pragma once
#ifndef GUARD_util
#define GUARD_util
#include <fstream>
#include <string>
#include<SDL_mixer.h>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <SDL.h>

using std::string;
using std::vector;

void updateEnteredChars(const char ch, string& correctChars, SDL_Renderer* grenderer);
void updateIncorrectGuess(int& incorrectGuess);

string chooseWordFromList(const vector<string>& wordList, int index);
string generateHiddenCharacters(string word);
char getInputCharacter(SDL_Renderer*& grenderer);
void updateSecretWord(string& secretWord, const char ch, const string& word);
void processData(const char ch, const string& word,
    string& secretWord,
    string& correctChars,
    int& incorrectGuess, string& incorrectChars, SDL_Renderer* grenderer);

int generateRandomNumber(const int min, const int max);
bool isCharInWord(const char ch, const string& word, const string& answereWord);
vector<string> readWordListFromFile(const string& filePath);

#endif