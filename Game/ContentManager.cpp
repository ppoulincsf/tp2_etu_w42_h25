#include "stdafx.h"
#include "ContentManager.h"
#include "GameCharacter.h"
ContentManager::ContentManager()
{
}

bool ContentManager::loadContent()
{
  std::string filename = "Assets/Sprites/tileset/tileset.png";
  if (!tileset.loadFromFile(filename))
  {
    //std::cerr << "Failed to load " << filename << std::endl;
    return false;
  }
  for (int i = 1; i <= 5; i++)
  {
    std::string filename = "Assets/Sprites/characters/bullet/muzzle (" + std::to_string(i) + ").png";
    if (!fireBulletTexture[i - 1].loadFromFile(filename))
    {
      //std::cerr << "Failed to load " << filename << std::endl;
      return false;
    }
  }
  for (int i = 0; i < (int)(CharacterState::NB_CHARACTER_STATES); i++)
  {

    for (unsigned int j = 1; j <= GameCharacter::PLAYER_STATE_FRAME_COUNTS[i]; j++)
    {
      std::string filename = "Assets/Sprites/characters/hero1/" + GameCharacter::PLAYER_STATE_NAMES[i] + " (" + std::to_string(j) + ").png";
      if (!playerTextures[i][j - 1].loadFromFile(filename))
      {
        //std::cerr << "Failed to load " << filename << std::endl;
        return false;
      }

      filename = "Assets/Sprites/characters/enemy/" + GameCharacter::PLAYER_STATE_NAMES[i] + " (" + std::to_string(j) + ").png";
      if (!enemyTextures[i][j - 1].loadFromFile(filename))
      {
        //std::cerr << "Failed to load " << filename << std::endl;
        return false;
      }
    }
  }
  if (!doorTexture.loadFromFile("Assets/Sprites/items/door1.png"))
  {
    //std::cerr << "Failed to load " << filename << std::endl;
    return false;
  }
  if (!bigLadder.loadFromFile("Assets/Sprites/items/BigLadder.png"))
  {
    //std::cerr << "Failed to load " << filename << std::endl;
    return false;
  }
  if (!barrel_front.loadFromFile("Assets/Sprites/items/barrel_front.png"))
  {
    //std::cerr << "Failed to load " << filename << std::endl;
    return false;
  }
  if (!bulletTexture.loadFromFile("Assets/Sprites/characters/bullet/Bullet1 (1).png"))
  {
    //std::cerr << "Failed to load " << filename << std::endl;
    return false;
  }
  if (!bonusTexture.loadFromFile("Assets/Sprites/items/crystal1.png"))
  {
    //std::cerr << "Failed to load " << filename << std::endl;
    return false;
  }
  if (!font.loadFromFile("Assets/Fonts/segoepr.ttf"))
  {
    //std::cerr << "Failed to load " << filename << std::endl;
    return false;
  }
  return true;
}

const sf::Texture& ContentManager::getTileset() const
{
  // TODO: insérer une instruction return ici
  return tileset;
}

const sf::Texture& ContentManager::getPlayerTexture(CharacterState state, int index) const
{
  // TODO: insérer une instruction return ici
  return playerTextures[(int)state][index];
}

const sf::Texture& ContentManager::getEnemyTexture(CharacterState state, int index) const
{
  // TODO: insérer une instruction return ici
  return enemyTextures[(int)state][index];
}

const sf::Texture& ContentManager::getDoorTexture() const
{
  // TODO: insérer une instruction return ici
  return doorTexture;
}

const sf::Texture& ContentManager::getBigLadderTexture() const
{
  // TODO: insérer une instruction return ici
  return bigLadder;
}

const sf::Texture& ContentManager::getBarrelTexture() const
{
  // TODO: insérer une instruction return ici
  return barrel_front;
}

const sf::Texture& ContentManager::getBulletTexture() const
{
  // TODO: insérer une instruction return ici
  return bulletTexture;
}

const sf::Texture& ContentManager::getFireBulletTexture(int index) const
{
  // TODO: insérer une instruction return ici
  return fireBulletTexture[index];
}

const sf::Font& ContentManager::getMainFont() const
{
  // TODO: insérer une instruction return ici
  return font;
}

const sf::Texture& ContentManager::getBonusTexture() const
{
  // TODO: insérer une instruction return ici
  return bonusTexture;
}
