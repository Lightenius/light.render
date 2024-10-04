#define SDL_MAIN_HANDLED
#include "SDL2/SDL_error.h"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_video.h"
#include "SDL2/SDL_render.h"
#include <SDL2/SDL.h>
#include <iostream>

const int WIDTH=800, HEIGHT=600;


// WARN: These Here are the Struct Definitions
//

struct Obj {
	uint32_t vertex_c;
	SDL_Vertex* vertices;
};




// WARN: These Here are Function Declarations
//
bool init();
void shutdown();
SDL_Texture* loadTexture(std::string path);
SDL_Renderer* createRenderer();



// WARN: These here are Global Variables
//
SDL_Window* main_window = NULL;
void drawObject(Obj object);
SDL_Renderer* main_renderer = NULL;
bool running = true;
SDL_Event event;



// NOTE:
// NOTE:
int main(int argc, char* argv[]){
	
	if ( !init() ){return -1;}

	while (running) {
		while ( SDL_PollEvent( &event ) != 0 ){
			if (event.type == SDL_QUIT){
				running = false;
			}
		}
// NOTE: CORE LOOP START!









// NOTE: CORE LOOP END!
	}

	shutdown();
	return 0;
}
// WARN: MAIN END
// WARN:

bool init(){

	if ( SDL_Init( SDL_INIT_VIDEO ) < 0){
		std::cout << "An error occured when initializing SDL system! -> " << SDL_GetError() << std::endl;
		return false;
	}

	main_window = SDL_CreateWindow("light.render", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	
	if ( main_window == NULL ){
		std::cout << "An error occured when creating the window! -> " << SDL_GetError() << std::endl;
		return false;
	}
	
	main_renderer = SDL_CreateRenderer(main_window, -1, SDL_RENDERER_ACCELERATED);

	if ( main_renderer == NULL ) {
		std::cout << "An error occured when setting up SDL_Renderer*! -> " << SDL_GetError() << std::endl;
		return false;
	}
	// TODO: setup renderer here!

	return true;

}

void shutdown(){
	SDL_DestroyRenderer(main_renderer);

	SDL_DestroyWindow(main_window);

	SDL_Quit();
}
