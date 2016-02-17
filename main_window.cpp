class main_window{
	public:
		SDL_Window* content;
		SDL_Renderer* render;
		SDL_Surface* surface;
		SDL_Texture* texture;
		int width;
		int height;
		int posx;
		int posy;
		int sdl_value;
		int init_window( int, int, char* );
		int refresh_render( SDL_Surface* );
};
