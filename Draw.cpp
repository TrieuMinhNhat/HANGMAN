#include<SDL.h>
#include<SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include<iostream>
#include <vector>
#include <string>
#include "Draw.h"
#include "Texture.h"
#define window_width 1536
#define window_height 960
const int MAX_MISTAKES = 8;
std::string Draw(int incorr) {

		std::string s;
		switch (incorr) {
		case 1:
			s = "1.png";
			break;
		case 8:
			s = "8.png";
			break;
		case 2:
			s = "2.png";
			break;
		case 3:
			s = "3.png";
			break;
		case 4:
			s = "4.png";
			break;
		case 5:
			s = "5.png";
			break;
		case 6:
			s = "6.png";
			break;
		case 7:
			s = "7.png";
			break;

		}
		return s;
}





void printStats(const std::string& word, const std::string& secretWord,
	const std::string& correctChars,
	const int incorrectGuess, const std::string& incorrectChars, SDL_Renderer*& grenderer) {
	/*SDL_RenderClear(grenderer);
	 cout << "Current word: " << secretWord;
	cout << endl << "Correct guesses: " << correctChars;
	cout << "    " << "Incorrect guesses: " << incorrectChars;

	if (secretWord == word) {
		cout << endl << "Well done :D   The word is: " << word << endl;
	}
	else if (incorrectGuess == MAX_MISTAKES - 1) {
		cout << endl << "You lose :(   The word is: " << word << endl;
	}
	else {
		cout << endl << "Choose a character: ";
	}
	SDL_Rect dest_rect = { 0, 80, window_width / 3, window_height / 1.2 };*/
	std::string secretword = "CURRENT WORD: " + secretWord;
	std::string correctguesses = "CORRECT GUESSES " + correctChars;
	std::string incorrectguesses = "INCORRECT GUESSES: " + incorrectChars;
	std::string status;
	if (secretWord == word) {
		//cout << endl << "Well done :D   The word is: " << word << endl;
		//status = "Well done :D   The word is: " + word;
		SDL_Texture* statusTexture = LoadFontTexture(grenderer, "intro.ttf", 30, status.c_str(), { 255,255,255,255 });
		SDL_Texture* secrectwordTexture = LoadFontTexture(grenderer, "intro.ttf", 30, secretword.c_str(), { 255, 255, 255, 255 });
		SDL_Texture* incorrectGuessesTexture = LoadFontTexture(grenderer, "intro.ttf", 30, incorrectguesses.c_str(), { 255, 255, 255, 255 });
		int textWidth, textHeight;
		SDL_QueryTexture(statusTexture, NULL, NULL, &textWidth, &textHeight);
		SDL_Rect statusrect = getSDLRect(100, 400, textWidth, textHeight);
		SDL_RenderCopy(grenderer, statusTexture, NULL, &statusrect);
		SDL_QueryTexture(secrectwordTexture, NULL, NULL, &textWidth, &textHeight);
		SDL_Rect secretwordrect = getSDLRect(150, 870, textWidth, textHeight);
		SDL_RenderCopy(grenderer, secrectwordTexture, NULL, &secretwordrect);
		SDL_QueryTexture(incorrectGuessesTexture, NULL, NULL, &textWidth, &textHeight);
		SDL_Rect incorrectGuessrect = getSDLRect(150, 900, textWidth, textHeight);
		SDL_RenderCopy(grenderer, incorrectGuessesTexture, NULL, &incorrectGuessrect);
		SDL_RenderPresent(grenderer);
		//pressAnyKeyToContinue();
	}
	else if (incorrectGuess == MAX_MISTAKES - 1) {
		//cout << endl << "You lose :(   The word is: " << word << endl;
		//status = "You lose :(   The word is: " + word;
		SDL_Texture* statusTexture = LoadFontTexture(grenderer, "intro.ttf", 30, status.c_str(), { 255,255,255,255 });
		SDL_Texture* secrectwordTexture = LoadFontTexture(grenderer, "intro.ttf", 30, secretword.c_str(), { 255, 255, 255, 255 });
		SDL_Texture* incorrectGuessesTexture = LoadFontTexture(grenderer, "intro.ttf", 30, incorrectguesses.c_str(), { 255, 255, 255, 255 });
		int textWidth, textHeight;
		SDL_QueryTexture(statusTexture, NULL, NULL, &textWidth, &textHeight);
		SDL_Rect statusrect = getSDLRect(100, 400, textWidth, textHeight);
		SDL_RenderCopy(grenderer, statusTexture, NULL, &statusrect);
		SDL_QueryTexture(secrectwordTexture, NULL, NULL, &textWidth, &textHeight);
		SDL_Rect secretwordrect = getSDLRect(150, 870, textWidth, textHeight);
		SDL_RenderCopy(grenderer, secrectwordTexture, NULL, &secretwordrect);
		SDL_QueryTexture(incorrectGuessesTexture, NULL, NULL, &textWidth, &textHeight);
		SDL_Rect incorrectGuessrect = getSDLRect(150, 900, textWidth, textHeight);
		SDL_RenderCopy(grenderer, incorrectGuessesTexture, NULL, &incorrectGuessrect);
		SDL_RenderPresent(grenderer);
		//pressAnyKeyToContinue();
	}
	else {
		//cout << endl << "Choose a character: ";
		//status = "Choose a character: ";
		status = incorrectguesses;

		SDL_Texture* textTexture = LoadFontTexture(grenderer, "intro.ttf", 50, "PLEASE ENTER YOUR GUESS!", { 255, 165, 0, 255 });
		int textureWidth, textureHeight;
		SDL_QueryTexture(textTexture, NULL, NULL, &textureWidth, &textureHeight);
		SDL_Rect textRect = { (window_width - textureWidth) / 2+100, (window_height - textureHeight) / 2, textureWidth, textureHeight };
		SDL_RenderCopy(grenderer, textTexture, NULL, &textRect);
		//SDL_RenderPresent(grenderer);
		SDL_Texture* statusTexture = LoadFontTexture(grenderer, "intro.ttf", 30, status.c_str(), { 255, 174, 174,255 });
		SDL_Texture* secrectwordTexture = LoadFontTexture(grenderer, "intro.ttf",30 , secretword.c_str(), { 255, 255, 255, 255 });
		SDL_Texture* correctGuessesTexture = LoadFontTexture(grenderer, "intro.ttf", 30, correctguesses.c_str(), { 255, 255, 255, 255 });
		int textWidth, textHeight;
		SDL_QueryTexture(statusTexture, NULL, NULL, &textWidth, &textHeight);
		SDL_Rect statusrect = getSDLRect(10,window_height-( window_height-textHeight-20), textWidth, textHeight);
		SDL_RenderCopy(grenderer, statusTexture, NULL, &statusrect);
		SDL_QueryTexture(secrectwordTexture, NULL, NULL, &textWidth, &textHeight);
		SDL_Rect secretwordrect = getSDLRect(150, 870, textWidth, textHeight);
		SDL_RenderCopy(grenderer, secrectwordTexture, NULL, &secretwordrect);
		SDL_QueryTexture(correctGuessesTexture, NULL, NULL, &textWidth, &textHeight);
		SDL_Rect incorrectGuessrect = getSDLRect(150, 900, textWidth, textHeight);
		SDL_RenderCopy(grenderer, correctGuessesTexture, NULL, &incorrectGuessrect);
	}
}

SDL_Rect getSDLRect(int x, int y, int width, int height) {
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
	return rect;
}

void printScreen(const std::string& word, const std::string& secretWord,
	const std::string& correctChars,
	const int incorrectGuess, const std::string& incorrectChars, SDL_Renderer*& grenderer, std::string Enterchars)
{
	/*for (int i = 0; i < 30; ++i) cout << endl;

	cout << getDrawing(incorrectGuess);
	printStats(word, secretWord, correctChars, incorrectGuess, incorrectChars);*/
	//SDL_RenderClear(grenderer);
	SDL_Texture* guess[8] = { NULL };
	for (int i = 0; i < 8; i++) {
		guess[i] = loadTexture(Draw(i + 1), grenderer);
	}
	SDL_Rect dest_rect = { 0, 80, window_width / 3, window_height / 1.2 };
	SDL_Texture* bg = loadTexture("background.bmp", grenderer);
	std::string S = " ENTERED CHARs:" + Enterchars;
	SDL_Texture* Enterchar = LoadFontTexture(grenderer, "Sigmar.ttf", 40, S.c_str(), { 0, 255, 0, 255});
	int charwidth, charheight;
	SDL_QueryTexture(Enterchar, NULL, NULL, &charwidth, &charheight);
	SDL_Rect charsrect = getSDLRect(window_width-charwidth-5,window_height-charheight-6, charwidth, charheight);
	SDL_RenderCopy(grenderer, bg, NULL, NULL);
	SDL_RenderCopy(grenderer, guess[incorrectGuess], NULL, &dest_rect);
	SDL_RenderCopy(grenderer, Enterchar, NULL, &charsrect);
	printStats(word, secretWord, correctChars, incorrectGuess, incorrectChars,grenderer);
	SDL_RenderPresent(grenderer);
}

/*void createWinAnimation(SDL_Renderer*& renderer) {
	int frameRate=1; int startX=0; int startY=0; int frameWidth; int frameHeight;
	std::vector<SDL_Texture*> frames;
	frames.push_back(loadTexture("youwin1.png", renderer));
	frames.push_back(loadTexture("youwin2.png", renderer));

	int numFrames = frames.size();
	int currentFrame = 0;
	int frameDelay = 1000 / frameRate;
	SDL_QueryTexture(frames[0], NULL, NULL, &frameWidth, &frameHeight);
	SDL_Rect srcRect = { 0, 0, frameWidth, frameHeight };
	SDL_Rect destRect = { startX, startY, frameWidth*4, frameHeight*4 };

	Uint32 lastFrameTime = SDL_GetTicks();
	bool quit = false;

	while (!quit) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}

		Uint32 currentTime = SDL_GetTicks();
		if (currentTime - lastFrameTime >= frameDelay) {
			lastFrameTime = currentTime;

			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, frames[currentFrame], &srcRect, &destRect);
			SDL_RenderPresent(renderer);

			currentFrame = (currentFrame + 1) % numFrames;
		}
	}
}*/

/*void createLoseAnimation(SDL_Renderer*& renderer) {
	int frameRate = 1; int startX = 0; int startY = 0; int frameWidth; int frameHeight;
	std::vector<SDL_Texture*> frames;
	frames.push_back(loadTexture("l1.png", renderer));
	frames.push_back(loadTexture("l2.png", renderer));
	frames.push_back(loadTexture("l3.png", renderer));
	frames.push_back(loadTexture("l4.png", renderer));
	/*frames.push_back(loadTexture("l5.png", renderer));
	frames.push_back(loadTexture("l6.png", renderer));
	frames.push_back(loadTexture("l7.png", renderer));

	int numFrames = frames.size();
	int currentFrame = 0;
	int frameDelay = 1000 / frameRate;
	SDL_QueryTexture(frames[0], NULL, NULL, &frameWidth, &frameHeight);
	SDL_Rect srcRect = { 0, 0, frameWidth, frameHeight };
	SDL_Rect destRect = { startX, startY, frameWidth, frameHeight*2 };

	Uint32 lastFrameTime = SDL_GetTicks();
	bool quit = false;

	while (!quit) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}

		Uint32 currentTime = SDL_GetTicks();
		if (currentTime - lastFrameTime >= frameDelay) {
			lastFrameTime = currentTime;

			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, frames[currentFrame], NULL, &destRect);
			SDL_RenderPresent(renderer);

			currentFrame = (currentFrame + 1) % numFrames;
		}
	}
}*/

void outro(SDL_Renderer* renderer,std::string word, std::string secrectWord, bool& iscontinue) {
	std::string s;
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	if (word!=secrectWord) {
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		 
		 s = "Sorry! you lose, the word is " + word;
		 SDL_Texture* textTexture = LoadFontTexture(renderer, "intro.ttf", 55, s.c_str(), { 255, 165, 0, 255 });
		 int textureWidth, textureHeight;
		 SDL_QueryTexture(textTexture, NULL, NULL, &textureWidth, &textureHeight);
		 SDL_Rect textRect = { (window_width - textureWidth) / 2 + 100, (window_height - textureHeight) / 2 - 150, textureWidth, textureHeight };
		 SDL_Texture* text = LoadFontTexture(renderer, "intro.ttf", 50, "Do you want to replay?", { 255, 165, 0, 255 });
		 SDL_QueryTexture(text, NULL, NULL, &textureWidth, &textureHeight);
		 SDL_Rect textR = { (window_width - textureWidth) / 2 + 50, (window_height - textureHeight) / 2 + 50 , textureWidth, textureHeight };
		 SDL_Texture* yes = loadTexture("yes.jpg", renderer);
		 SDL_QueryTexture(yes, NULL, NULL, &textureWidth, &textureHeight);
		 SDL_Rect yesRect = getSDLRect(window_width / 2 + 30, window_height / 2 + 90, textureWidth / 2, textureHeight / 2);
		 SDL_Texture* no = loadTexture("no.png", renderer);
		 SDL_QueryTexture(no, NULL, NULL, &textureWidth, &textureHeight);
		 SDL_Rect noRect = getSDLRect(window_width / 2 - 190, window_height / 2 + 90, textureWidth, textureHeight);
		 int frameRate = 2; int startX = 0; int startY = 0; int frameWidth; int frameHeight;
		 std::vector<SDL_Texture*> frames;
		 frames.push_back(loadTexture("l1.png", renderer));
		 frames.push_back(loadTexture("l2.png", renderer));
		 frames.push_back(loadTexture("l3.png", renderer));
		 frames.push_back(loadTexture("l4.png", renderer));	
		 int numFrames = frames.size();
		 int currentFrame = 0;
		 int frameDelay = 1000 / frameRate;
		 SDL_QueryTexture(frames[0], NULL, NULL, &frameWidth, &frameHeight);
		 SDL_Rect srcRect = { 0, 0, frameWidth, frameHeight };
		 SDL_Rect destRect = { startX, startY, frameWidth-10, frameHeight * 2 };
		 playMusic("losesound.wav", 0);
		 Uint32 lastFrameTime = SDL_GetTicks();
		 bool quit = false;
		 while (!quit) {
			 SDL_Event event;
			 while (SDL_PollEvent(&event)) {
				 if (event.type == SDL_QUIT) {
					 quit = true;
				 }
				 if (event.type == SDL_MOUSEBUTTONDOWN) {
					 int mouseX, mouseY;
					 SDL_GetMouseState(&mouseX, &mouseY);
					 if (mouseX >= noRect.x && mouseX < noRect.x + noRect.w &&
						 mouseY >= noRect.y && mouseY < noRect.y + noRect.h) {
						 quit = true;
						 iscontinue = false;
					 }
					 if (mouseX >= yesRect.x && mouseX < yesRect.x + yesRect.w &&
						 mouseY >= yesRect.y && mouseY < yesRect.y + yesRect.h) {
						 quit = true;
						 iscontinue = true;
					 }
				 }
			 }
			 Uint32 currentTime = SDL_GetTicks();
			 if (currentTime - lastFrameTime >= frameDelay) {
				 lastFrameTime = currentTime;
				 SDL_RenderClear(renderer);
				 
				 SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
				 SDL_RenderCopy(renderer, text, NULL, &textR);
				 SDL_RenderCopy(renderer, frames[currentFrame], NULL, &destRect);
				 SDL_RenderCopy(renderer, yes, NULL, &yesRect);
				 SDL_RenderCopy(renderer, no, NULL, &noRect);
				 SDL_RenderPresent(renderer);
				 currentFrame = (currentFrame + 1) % numFrames;
			 }
			 
		 }
		 /*SDL_Texture* textTexture = LoadFontTexture(renderer, "intro.ttf", 50, s.c_str(), { 255, 165, 0, 255 });
		 int textureWidth, textureHeight;
		 SDL_QueryTexture(textTexture, NULL, NULL, &textureWidth, &textureHeight);
		 SDL_Rect textRect = { (window_width - textureWidth) / 2 + 100, (window_height - textureHeight) / 2, textureWidth, textureHeight };
		 SDL_Texture* text = LoadFontTexture(renderer, "intro.ttf", 50, "Do you want to replay?", { 255, 165, 0, 255 });
		 SDL_QueryTexture(text, NULL, NULL, &textureWidth, &textureHeight);
		 SDL_Rect textR = { (window_width - textureWidth) / 2 + 50, (window_height - textureHeight) / 2 + 50, textureWidth, textureHeight };
		 SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
		 SDL_RenderCopy(renderer, text, NULL, &textR);*/
		
		 //createLoseAnimation(renderer);
	}
	else {
		playMusic("winsound.wav", 0);
		s = "Congratulations! you win, the word is " + word;
		SDL_Texture* textTexture = LoadFontTexture(renderer, "intro.ttf", 50, s.c_str(), { 255, 165, 0, 255 });
		int textureWidth, textureHeight;
		SDL_QueryTexture(textTexture, NULL, NULL, &textureWidth, &textureHeight);
		SDL_Rect textRect = { (window_width - textureWidth) / 2 + 100, (window_height - textureHeight) / 2, textureWidth, textureHeight };
		SDL_Texture* text = LoadFontTexture(renderer, "intro.ttf", 50, "Do you want to replay?", { 255, 165, 0, 255 });
		SDL_QueryTexture(text, NULL, NULL, &textureWidth, &textureHeight);
		SDL_Rect textR = { (window_width - textureWidth) / 2 + 50, (window_height - textureHeight) / 2 + 50, textureWidth, textureHeight };
		SDL_Texture* yes = loadTexture("yes.jpg", renderer);
		SDL_QueryTexture(yes, NULL, NULL, &textureWidth, &textureHeight);
		SDL_Rect yesRect = getSDLRect(window_width/2+30, window_height/2+90, textureWidth/2, textureHeight/2);
		SDL_Texture* no = loadTexture("no.png", renderer);
		SDL_QueryTexture(no, NULL, NULL, &textureWidth, &textureHeight);
		SDL_Rect noRect = getSDLRect(window_width/2-190, window_height/2 + 90, textureWidth, textureHeight);
		int frameRate = 3; int startX = 0; int startY = 0; int frameWidth; int frameHeight;
		std::vector<SDL_Texture*> frames;
		frames.push_back(loadTexture("youwin1.png", renderer));
		frames.push_back(loadTexture("youwin2.png", renderer));
		int numFrames = frames.size();
		int currentFrame = 0;
		int frameDelay = 1000 / frameRate;
		SDL_QueryTexture(frames[0], NULL, NULL, &frameWidth, &frameHeight);
		SDL_Rect srcRect = { 0, 0, frameWidth, frameHeight };
		SDL_Rect destRect = { startX, startY, frameWidth * 4, frameHeight * 4 };
		Uint32 lastFrameTime = SDL_GetTicks();
		bool quit = false;

		while (!quit) {
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) {
					quit = true;
				}

				if (event.type == SDL_MOUSEBUTTONDOWN) {
					int mouseX, mouseY;
					SDL_GetMouseState(&mouseX, &mouseY);
					if (mouseX >= noRect.x && mouseX < noRect.x + noRect.w &&
						mouseY >= noRect.y && mouseY < noRect.y + noRect.h) {
						quit = true;
						iscontinue = false;
					}
					if (mouseX >= yesRect.x && mouseX < yesRect.x + yesRect.w &&
						mouseY >= yesRect.y && mouseY < yesRect.y + yesRect.h) {
						quit = true;
						iscontinue = true;
					}
				}
			}
			Uint32 currentTime = SDL_GetTicks();
			if (currentTime - lastFrameTime >= frameDelay) {
				lastFrameTime = currentTime;

				SDL_RenderClear(renderer);
				SDL_RenderCopy(renderer, frames[currentFrame], &srcRect, &destRect);
				SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
				SDL_RenderCopy(renderer, text, NULL, &textR);
				SDL_RenderCopy(renderer, yes, NULL, &yesRect);
				SDL_RenderCopy(renderer, no, NULL, &noRect);
				SDL_RenderPresent(renderer);
				currentFrame = (currentFrame + 1) % numFrames;
			}
			
		}
	}
	//pressAnyKeyToContinue();
	std::cout << iscontinue;
}
/*void scrollTextures(SDL_Renderer* renderer, const std::vector<std::string>& imagePaths, int scrollSpeed) {
	// Load the textures
	std::vector<SDL_Texture*> textures;
	for (const auto& path : imagePaths) {
		textures.push_back(loadTexture(path, renderer));
	}

	// Get the dimensions of the textures
	int textureWidth, textureHeight;
	SDL_QueryTexture(textures[0], NULL, NULL, &textureWidth, &textureHeight);

	// Initialize the scroll position
	int scrollPosition = 0;

	// Scroll the textures until the user quits
	bool quit = false;
	while (!quit) {
		// Handle events
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}

		// Scroll the textures
		scrollPosition += scrollSpeed;
		if (scrollPosition >= textureWidth) {
			scrollPosition -= window_width;
		}

		// Clear the renderer
		SDL_RenderClear(renderer);

		// Render the textures at the same position with different offsets
		for (int i = 0; i < textures.size(); i++) {
			int x = i * textureWidth - scrollPosition;
			SDL_Rect destRect = { x, 0, textureWidth, textureHeight };
			SDL_RenderCopy(renderer, textures[i], NULL, &destRect);
		}

		// Update the screen
		SDL_RenderPresent(renderer);

		// Delay to control the frame rate
		SDL_Delay(10);
	}

	// Free the textures
	for (auto texture : textures) {
		SDL_DestroyTexture(texture);
	}
}*/
