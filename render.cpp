#include "SDL2/SDL_render.h"
#include <SDL2/SDL.h>
#include <iostream>

const int WIDTH=800, HEIGHT=600;



// WARN: These Here are function declarations
//
bool init();
void shutdown();
SDL_Texture* loadTexture(std::string path);



// WARN: These here are Global Variables
//
SDL_Window* main_window = NULL;





