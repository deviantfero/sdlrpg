#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <cstring>
#include <string>
// Classes and methods
#include "./main_window.hpp"

int main( int argc, char** argv ) {
	if( SDL_Init( SDL_INIT_VIDEO ) != 0 ){
		std::cout << "SDL_Init ERROR: " << SDL_GetError() << std::endl;
		return 1;
	}
	main_window w1;
	w1.init_window( 300, 300, (char*)"Hello There!" );
	SDL_Delay( 3000 );
	SDL_Quit();
}
