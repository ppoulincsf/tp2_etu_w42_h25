#include "stdafx.h"
#include "game.h"
#include "scenetype.h" 
#include "Level01.h"
#include "Publisher.h"
const unsigned int Game::TILE_SIZE;
const unsigned int Game::TILE_HORIZONTAL_COUNT;
const unsigned int Game::TILE_VERTICAL_COUNT;

Game::Game(std::string windowName)
  : BaseGame(windowName)
{
}

Game::~Game()
{
  uninit();
}

void Game::handleEvents()
{
  if (!scenes.empty())
    scenes.top()->handleEvents(window);
}


void Game::update()
{
  bool gameMustEnd = scenes.empty();
  if (!gameMustEnd)
  {
    scenes.top()->update(TIME_PER_FRAME);
    SceneInfo nextSceneInfo = scenes.top()->getSceneInfo();
    // Si la nouvelle scène attendue est différente de l'ancienne...
    if (nextSceneInfo.nextSceneType != nextSceneInfo.currentSceneType)
    {
      Scene* nextScene = nullptr;
      // ... soit on veut retirer la scène courant de la pile
      if (SceneType::NONE == nextSceneInfo.nextSceneType)
      {
        popScene(true);
      }
      else
      {
        if (nextSceneInfo.discardActiveScene)
          popScene(false);
        // ... soit on veut en ajouter une nouvelle
        nextScene = getNextScene(nextSceneInfo.nextSceneType);
      }
      if (nextScene != nullptr)
        pushScene(nextScene, &nextSceneInfo);
    }
  }

}


void Game::draw()  const
{
  if (!scenes.empty())
  {
    scenes.top()->draw(window);
  }
}

void Game::init()
{
  BaseGame::init();

  pushScene(new InitialScene(), nullptr);
  
}

void Game::uninit()
{
  while (!scenes.empty())
  {
    popScene(false);
  }
}



Scene* Game::getNextScene(SceneType type) const
{
  Scene* scene = nullptr;
  switch (type)
  {
  case SceneType::LEVEL01:
  {
    scene = new Level01();
    break;
  }

  default:
  {
    scene = nullptr;
    break;
  }
  }
  return scene;
}