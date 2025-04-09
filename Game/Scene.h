#pragma once
#include "scenetype.h"
#include "SceneInfo.h"
#include "ContentManager.h"
class Scene
{
public:
  Scene(SceneType type);
  virtual ~Scene();
  virtual void update(float _deltaT) = 0;
  virtual void draw(sf::RenderWindow& window) const = 0;
  virtual void pause();
  virtual void unPause();
  virtual void init(SceneInfo* _previousSceneInfo = nullptr);
  virtual void uninit();
  virtual void handleEvents(sf::RenderWindow& window);
  SceneInfo getSceneInfo() const;
  virtual bool isGameOver() const;
  virtual bool isGameInitialized() const;
protected:
  
  sf::Event event;
  ContentManager contentManager;
  bool gameIsOver;
  bool gameIsInitialized;
  SceneInfo sceneInfo;
private:
  

};

