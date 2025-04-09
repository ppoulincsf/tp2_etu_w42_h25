#include "stdafx.h"
#include "Scene.h"


Scene::Scene(SceneType type)
  : gameIsOver(false)
  , gameIsInitialized(false)
  , event(sf::Event())
{
  sceneInfo.currentSceneType = type;
  sceneInfo.nextSceneType = type;
  sceneInfo.discardActiveScene = false;

}

Scene::~Scene()
{

}

void Scene::pause()
{

}

void Scene::unPause()
{

}

void Scene::init(SceneInfo* /*_previousSceneInfo*/)
{
  gameIsInitialized = contentManager.loadContent();
  sceneInfo.nextSceneType=sceneInfo.currentSceneType;
  gameIsOver = false;
}

void Scene::uninit()
{
}

void Scene::handleEvents(sf::RenderWindow& window)
{

  while (window.pollEvent(event))
  {
    //x sur la fen?tre
    if (event.type == sf::Event::Closed)
    {
      window.close();
      gameIsOver = true;
    }
  }
}

SceneInfo Scene::getSceneInfo() const
{
  return sceneInfo;
}

//SceneResult Scene::getSceneResult() const
//{
//  return result;
//}

bool Scene::isGameOver() const
{
  return gameIsOver;
}

bool Scene::isGameInitialized() const
{
  return gameIsInitialized;
}
