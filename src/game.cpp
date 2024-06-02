#include <SDL2/SDL.h>
#include <iostream>
#include "game.hpp"

SDL_Window* g_pWindow {0};
SDL_Renderer* g_pRenderer {0};
bool m_bRunning;

using namespace std;



bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;

  if(fullscreen)
  {
    flags = SDL_WINDOW_FULLSCREEN;
  }


  // attempt to initialize SDL
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
	cout << "SDL init success\n";

    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if(m_pWindow != 0) // window init success
    {
	  cout << "window creation success\n";
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if(m_pRenderer != 0) // renderer init success
      {
        cout << "renderer creation success\n";
        SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
      }
      else
      {
        cout << "renderer init fail\n";
        return false; // renderer init fail
      }
    }
    else
    {
      cout << "window init fail\n";
      return false; // window init fail
    }
  }
  else
  {
    cout << "SDL init fail\n";
    return false; // SDL init fail
  }

  cout << "init success\n";
  m_bRunning = true; // everything inited successfully, start the main loop

  return true;
}
void Game::render()
{
  SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color

  SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::handleEvents()
{
  SDL_Event event;
  if(SDL_PollEvent(&event))
  {
    switch (event.type)
    {
		case SDL_QUIT:
        m_bRunning = false;
      break;

      default:
      break;
    }
  }
}

void Game::clean()
{
  cout << "cleaning game\n";
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}

void Game::update()
{

}

