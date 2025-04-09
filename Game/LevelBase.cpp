#include "stdafx.h"
#include "LevelBase.h"
#include "game.h"
#include "ContentManager.h"
#include "SceneInfo.h"

const float LevelBase::TIME_PER_FRAME = 1.0f / (float)Game::FRAME_RATE;
const float LevelBase::GAMEPAD_SPEEDRATIO = 1000.0f;
const float LevelBase::KEYBOARD_SPEED = 0.2f;
const float LevelBase::TIME_BETWEEN_FIRE = 0.5f;
const unsigned int LevelBase::SPACE_BETWEEN_STAIRS ;

LevelBase::LevelBase(SceneType type)
  : Scene(type)
{
}

LevelBase::~LevelBase()
{
}
void LevelBase::update(float _deltaT)
{
 
}

void LevelBase::draw(sf::RenderWindow& window) const
{
  for (unsigned int i = 0; i < Game::TILE_VERTICAL_COUNT; i++)
  {
    for (unsigned int j = 0; j < Game::TILE_HORIZONTAL_COUNT; j++)
    {
      background[i][j].draw(window);
    }
  }
}

void LevelBase::uninit()
{
  
}

void LevelBase::init(SceneInfo* _previousSceneInfo)
{
  Scene::init(_previousSceneInfo);
  
  generateLevel();
}

void LevelBase::generateLevel()
{
  for (unsigned int i = 0; i < Game::TILE_VERTICAL_COUNT; i += SPACE_BETWEEN_STAIRS)
  {
    for (unsigned int j = 0; j < Game::TILE_HORIZONTAL_COUNT; j++) 
    {
      background[Game::TILE_VERTICAL_COUNT - 1 - i][j].setTexture(contentManager.getTileset());
      background[Game::TILE_VERTICAL_COUNT - 1 - i][j].setPosition(sf::Vector2f((float)j * Game::TILE_SIZE, (float)(Game::TILE_VERTICAL_COUNT - 1 - i) * Game::TILE_SIZE));
      background[Game::TILE_VERTICAL_COUNT - 1 - i][j].activate(true);
    }
  }
}

void LevelBase::handleEvents(sf::RenderWindow& window)
{
  gameIsOver = false;
  inputs.reset();
  sf::Event event;
  while (window.pollEvent(event))
  {
    //x sur la fenêtre
    if (event.type == sf::Event::Closed)
    {
      window.close();
      gameIsOver = true;
    }
    if (event.type == sf::Event::KeyPressed)
    {
      if (event.key.code == sf::Keyboard::Escape)
      {
        window.close();
        gameIsOver = true;
      }
      if (event.key.code == sf::Keyboard::Space)
      {
        inputs.jump = true;
      }
      if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down)
      {
        inputs.usePortal = true;
      }
    }
  }
}