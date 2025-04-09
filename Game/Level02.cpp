#include "stdafx.h"
#include "Level02.h"
#include "game.h"
#include "ContentManager.h"
#include "Publisher.h"

Level02::Level02()
  : LevelBase(SceneType::LEVEL02)
{
}

Level02::~Level02()
{
}
void Level02::update(float _deltaT)
{
  LevelBase::update(_deltaT);
  // A COMPLETER
}

void Level02::draw(sf::RenderWindow& window) const
{
  LevelBase::draw(window);
  // A COMPLETER
}

void Level02::uninit()
{
}

void Level02::init(SceneInfo* _previousSceneInfo)
{
  LevelBase::init(_previousSceneInfo);
  
  // A COMPLETER
}
void Level02::generateLevel()
{
  LevelBase::generateLevel();
  // A COMPLETER  
}
