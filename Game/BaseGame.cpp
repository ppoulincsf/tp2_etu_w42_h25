#include "stdafx.h"
#include "BaseGame.h"
#include <windows.h>
#include "ContentManager.h"
#include "game.h"

const unsigned int BaseGame::FRAME_RATE = 60;
const float BaseGame::TIME_PER_FRAME = 1.0f / (float)BaseGame::FRAME_RATE;
const unsigned int BaseGame::GAME_WIDTH = Game::TILE_SIZE * Game::TILE_HORIZONTAL_COUNT;
const unsigned int BaseGame::GAME_HEIGHT = Game::TILE_SIZE * Game::TILE_VERTICAL_COUNT;

BaseGame::BaseGame(std::string windowName)
  : gameName(windowName)
  
{
}


void BaseGame::run()
{
  init();
  
  if (!scenes.top()->isGameInitialized())
  {
    MessageBox(
      NULL,                         // Pas de fen�tre parente
      L"Une erreur est survenue lors du chargement des ressources",  // Texte du message
      L"Erreur de chargement",                 // Titre de la bo�te
      MB_OK | MB_ICONINFORMATION    // Boutons et ic�ne
    );
    return;
  }

  while (window.isOpen())
  {
    handleEvents();
    // Si fin de partie atteinte,
    update();
    if (scenes.top()->isGameOver())
    {
      // On termine "normalement" l'application
      break;
    }
    else
    {
      window.clear();
      draw();
      window.display();
    }
  }
}


void BaseGame::init()
{
  window.create(sf::VideoMode(BaseGame::GAME_WIDTH, BaseGame::GAME_HEIGHT, 32), gameName);
  window.setFramerateLimit(BaseGame::FRAME_RATE);

  }

void BaseGame::uninit()
{
}


void BaseGame::popScene(bool initNextScene)
{
  if (!scenes.empty())
  {
    Scene* top = scenes.top();
    top->uninit();
    delete top;
    scenes.pop();

    if (!scenes.empty())
    {
      if (initNextScene)
        scenes.top()->init();
      else
        scenes.top()->unPause();
    }
  }
}

void BaseGame::pushScene(Scene* newScene, SceneInfo* nextSceneInfo)
{
  newScene->init(nextSceneInfo);
  if (newScene->isGameInitialized())
  {
    if (!scenes.empty())
      scenes.top()->pause();
    scenes.push(newScene);
  }

}