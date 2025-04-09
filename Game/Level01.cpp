#include "stdafx.h"
#include "Level01.h"
#include "game.h"
#include "ContentManager.h"
#include "Publisher.h"

Level01::Level01()
  : LevelBase(SceneType::LEVEL01)
{
}

Level01::~Level01()
{
}
void Level01::update(float _deltaT)
{
  LevelBase::update(_deltaT);
  // A COMPLETER
}

void Level01::draw(sf::RenderWindow& window) const
{
  LevelBase::draw(window);
  // A COMPLETER
}

void Level01::uninit()
{
}

void Level01::init(SceneInfo* _previousSceneInfo)
{
  LevelBase::init(_previousSceneInfo);
  
  // A COMPLETER
}
void Level01::generateLevel()
{
  LevelBase::generateLevel();
  // A COMPLETER  
}
