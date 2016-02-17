#include "./main_window.cpp"

int main_window::init_window( int w_width, int w_height, char* name ) {
	posx = SDL_WINDOWPOS_UNDEFINED; width = w_width;
	posy = SDL_WINDOWPOS_UNDEFINED; height = w_height;
	sdl_value = SDL_WINDOW_OPENGL;
	content = SDL_CreateWindow( name, posx, posy, w_width, w_height, sdl_value );
	if( content == NULL ) {
		std::cout << "Window creation ERROR: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	render = SDL_CreateRenderer( content, -1, SDL_RENDERER_ACCELERATED );
	if( render == NULL ){
		std::cout << "Render creation ERROR: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow( content );
		SDL_Quit();
		return 1;
	}
	surface = SDL_CreateRGBSurface( 0, width, height, 32, 0, 0, 0, 0 );
	SDL_FillRect( surface, NULL, SDL_MapRGB( surface->format, 255, 12, 2 ) );

	texture = SDL_CreateTextureFromSurface( render, surface );
	SDL_FreeSurface( surface );
	if( texture == NULL ){
		SDL_DestroyRenderer( render );
		SDL_DestroyWindow( content );
		std::cout << "SDL_Texture ERROR: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	SDL_RenderClear( render );
	SDL_RenderCopy( render, texture, NULL, NULL );
	SDL_RenderPresent( render );
}

int main_window::refresh_render( SDL_Surface* new_surface ) {
	if( new_surface == NULL ){
		SDL_DestroyRenderer( render );
		SDL_DestroyWindow( content );
		std::cout << "SDL_Surface ERROR: " << SDL_GetError() << std::endl;
	}
	texture = SDL_CreateTextureFromSurface( render, new_surface );
	SDL_FreeSurface( new_surface );
	if( texture == NULL ){
		SDL_DestroyRenderer( render );
		SDL_DestroyWindow( content );
		std::cout << "SDL_Texture ERROR: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	SDL_RenderClear( render );
	SDL_RenderCopy( render, texture, NULL, NULL );
	SDL_RenderPresent( render );
}
