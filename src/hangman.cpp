#include <iostream>
#include "hangman.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include<SDL_mixer.h>
#include "Texture.h"
#include "Draw.h"

#define window_width 1536
#define window_height 960
using std::string;
using std::vector;
using std::ifstream;
using std::domain_error;
using std::cin;

/***
    Args:
        min (int): left margin of a range
        max (int): right margin of a range
    Returns:
        number (int) : random number in range [min; max]
***/
int generateRandomNumber(const int min, const int max)
{
    // TODO: Return a random integer number between min and max
    return min + (rand() % (max - min + 1));

}

vector<string> readWordListFromFile(const string& filePath)
{
    vector<string> wordList;
    string word;
    ifstream wordFile(filePath);
    /*if (!wordFile.is_open()) {
        throw domain_error("Unable to open file");
    }*/

    //while ( getline (wordFile, word) ){  // Thong thuong doc tung line. 
                                           // Chuong trinh nay cung chay.
    while (wordFile >> word) {  // Nhung voi chuong trinh nay, doc tung word cung duoc
        // Tuc ca 2 cach doc deu chay.
        wordList.push_back(word);
        //cout << word << '\n';
    }
    wordFile.close();

    return wordList;
}

/***
    Args:
        ch (char): A character
        word (string): a word
    Returns:
        result (bool) : the character ch is in the word or not.
***/
bool isCharInWord(const char ch, const string& word, const string& correctChars)
{
    bool check = false;
    bool check2 = true;
    int len = word.length();
    for (int i = 0; i < len; i++) {
        if (word[i] == ch) {
            for (int j = 0; j<int(correctChars.length()); j++) {
                if (ch == correctChars[j]) {
                    check2 = false;
                    break;
                }
            }
            check = true;
            break;
            
        }
    }
    // TODO: return true if ch is in word else return false
    return check and check2;
}

/***
    Args:
        wordList (vector<string>): A list of words
        index (int): an integer number
    Returns:
        answer (string) : the lowercase word is in the position index of wordList
***/
string chooseWordFromList(const vector<string>& wordList, int index)
{
    // TODO: Return a lowercase word in the index position of the vector wordList.
    string answer = wordList.at(index);
    int len = answer.length();
    for (int i = 0; i < len; i++) {
        answer[i] = tolower(answer[i]);
    }
    return answer;
}

/***
    Args:
        answerWord (string): a word that player needs to guess
    Returns:
        secretWord (string): answerWord in hidden form (form of ---)
***/
string generateHiddenCharacters(string answerWord) {
    // TODO: Based on answerWord's length, generate hidden characters in form of "---"
    string secretWord;
    int len = answerWord.length();
    secretWord = string(len, '-');
    return secretWord;
}
char getInputCharacter(SDL_Renderer*& grenderer) {
    SDL_Event event;

    //while (true) {
   /* SDL_Texture* textTexture = LoadFontTexture(grenderer, "intro.ttf", 80, "Please enter your guess! ", { 255, 165, 0, 255 });
    int textureWidth, textureHeight;
    SDL_QueryTexture(textTexture, NULL, NULL, &textureWidth, &textureHeight);
    SDL_Rect textRect = { (window_width - textureWidth) / 2, (window_height - textureHeight) / 2, textureWidth, textureHeight };
    SDL_RenderCopy(grenderer, textTexture, NULL, &textRect);
    SDL_RenderPresent(grenderer);*/
    //SDL_RenderClear(grenderer);
     string input = " ";
    char text = ' ';
    SDL_StartTextInput();
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                // User closed the window, exit the loop
                quit=true;
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_RETURN and text!=' ') {
                    // User pressed Enter, exit the loop
                    quit = true;
                }
                else if (event.key.keysym.sym >= SDLK_a && event.key.keysym.sym <= SDLK_z) {
                    // Convert the key symbol to a character and append to input
                    //SDL_Texture* bg = loadTexture("background.bmp", grenderer);
                    //SDL_RenderCopy(grenderer, bg, NULL, NULL);
                    SDL_SetRenderDrawColor(grenderer, 112, 100, 252,255);
                    SDL_Rect clearRect = { ((window_width) / 2) - 55, ((window_height) / 2) + 47, 110, 100 };
                    SDL_RenderFillRect(grenderer, &clearRect);
                    // Render new text
                     text = event.key.keysym.sym;
                    string word_str = string(1, text);
                    SDL_Texture* textT = LoadFontTexture(grenderer, "intro.ttf", 100, word_str.c_str(), { 0, 0, 0, 0 });
                    int textWidth, textHeight;
                    SDL_QueryTexture(textT, NULL, NULL, &textWidth, &textHeight);
                    SDL_Rect textrect = { ((window_width) / 2) - (textWidth / 2), ((window_height) / 2) + 25, textWidth, textHeight };
                    SDL_RenderCopy(grenderer, textT, NULL, &textrect);
                    SDL_RenderPresent(grenderer);
                    SDL_DestroyTexture(textT);

                    // Append new character to input text
                    input += text;
                }
            }
        }
        //}
       //std::cout << text;
       /* string word_str = string(1, text);
        SDL_Texture* textT = LoadFontTexture(grenderer, "intro.ttf", 100, word_str.c_str(), { 0, 0, 0, 0 });
        int textWidth, textHeight;
        SDL_QueryTexture(textT, NULL, NULL, &textWidth, &textHeight);
        SDL_Rect textrect = { ((window_width) / 2) - 58, ((window_height) / 2) + 10, textWidth, textHeight };
        SDL_RenderCopy(grenderer, textT, NULL, &textrect);
        SDL_RenderPresent(grenderer);*/
        //pressAnyKeyToContinue();
        //SDL_DestroyTexture(textT);
        //SDL_RenderPresent(grenderer);
        

    }
   std::cout << text;
    return tolower(text);
}

/***
    Args:
        secretWord (string): secret word in hidden form
        ch (char): a charater
        word (string): the answer word
    Returns:
        void
***/
void updateSecretWord(string& secretWord, const char ch, const string& word)
{
    // TODO: Update the secret word if the character ch is in the answer word.
    int len = word.length();
    for (int i = 0; i < len; i++) {
        if (word[i] == ch and secretWord[i]!=ch) {
            secretWord[i] = ch;
        }
    }

}

/***
    Args:
        ch (char): a character
        chars (string): an array of characters
    Returns:
        void
***/
void updateEnteredChars(const char ch, string& charsE, SDL_Renderer* grenderer) {
    // TODO: append the character ch is in end of the text chars
    charsE = charsE  + ch + ' ';
    //string chars = " Enteredchars: " + charsE;
    //SDL_Texture* Enterchars = LoadFontTexture(grenderer, "intro.ttf", 50, chars.c_str(), { 255, 255, 255, 255 });
    //int charwidth, charheight;
    //SDL_QueryTexture(Enterchars, NULL, NULL, & charwidth, & charheight);
    //SDL_Rect charsrect = getSDLRect(window_width - charwidth, window_height - charheight, charwidth, charheight);//{ ((window_width) / 2) - 58, ((window_height) / 2) + 10, charwidth, charheight };
    //SDL_RenderCopy(grenderer, Enterchars, NULL, &charsrect);
    //SDL_RenderPresent(grenderer);
   // pressAnyKeyToContinue();
}

/***
    Args:
        incorrectGuess (int): a number that store the number of player's wrong guess
    Returns:
        void
***/
void updateIncorrectGuess(int& incorrectGuess) {
    // TODO: increase the value of incorrectGuess by 1
    incorrectGuess++;

}

/***
    Args:
        ch (char): a character that player enter to console
        word (string): answer word that play needs to guess
        secretWord (string): answer word in hidden form
        correctChars (string): a string that stores correct inputs of player
        incorrectGuess (int): a number that stores the number of player's wrong guess
        incorrectChars (string): a string that stores incorrect inputs of player
    Returns:
        void
***/
void processData(const char ch, const string& word, string& secretWord, string& correctChars, int& incorrectGuess, string& incorrectChars, SDL_Renderer* grenderer)
{   
    if (isCharInWord(ch, word, correctChars)) {
        playSound(true);
        updateSecretWord(secretWord, ch, word);
        updateEnteredChars(ch, correctChars,grenderer);
    }
    else {
        playSound(false);
        updateIncorrectGuess(incorrectGuess);
        updateEnteredChars(ch, incorrectChars,grenderer);
    }
   // SDL_RenderPresent(grenderer);
}
/*** TODO
    If ch in word:
        update secretWord: call updateSecretWord() function
        update correctChars: call updateEnteredChars() function
    else:
        update incorrectGuess: call updateIncorrectGuess() function
        update incorrectChars: call updateEnteredChars() function
***/
