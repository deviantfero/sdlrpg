#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <cstring>
#include <string>
// Classes and methods
#include "./src/main_window.hpp"

#define WIN_W 400
#define WIN_H 500

int main( int argc, char** argv ) {
	if( SDL_Init(SDL_INIT_EVERYTHING) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) ){
		std::cout << "SDL_Init ERROR: " << SDL_GetError() << std::endl;
		std::cout << "IMG_Init ERROR: " << IMG_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	main_window w1;
	SDL_Rect testpos = { 100, 100, 200, 200 };
	SDL_Rect testsize = { 100, 100, 200, 200 };
	w1.init_window( WIN_W, WIN_H, (char*)"RPG Battle SIM" );
	SDL_Surface* image = IMG_Load( "./img/forest2.jpg" );
	if( image == NULL ){
		std::cout << "SDL_IMG ERROR:" << IMG_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}else{
		std::cout << "SUCCESS LOADING IMAGE" << std::endl;
		SDL_RenderClear( w1.render );
		w1.load_in_render( image, NULL, NULL );
		w1.load_in_render( image, &testsize, &testpos );
		SDL_RenderPresent( w1.render );
		SDL_Delay( 3000 );
		SDL_FreeSurface( image );
	}
	SDL_Quit();
}
