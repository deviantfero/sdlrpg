class main_window{
	public:
		SDL_Window* content;
		SDL_Renderer* render;
		SDL_Texture* texture;
		SDL_Surface* surface;
		int width;
		int height;
		int posx;
		int posy;
		int sdl_value;
		int init_window( int, int, char* );
		int load_in_render( SDL_Surface*, SDL_Rect*, SDL_Rect* );
};
