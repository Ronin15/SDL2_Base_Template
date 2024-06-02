#include <SDL2/SDL.h>

#include "game.hpp"

Game* g_game = {0};

int main(int argc, char* args[]){
	
	g_game = new Game();
	
	if(g_game->init("Base_Template", 100, 100, 1920, 1080, false))

	while(g_game->running()){
	
	g_game->handleEvents();
	g_game->update();
	g_game->render();
	
	}	 
g_game->clean();

return 0;
}
