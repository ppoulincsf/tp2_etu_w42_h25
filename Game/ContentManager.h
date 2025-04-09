#pragma once
#include "CharacterState.h"
class ContentManager
{
public:
	ContentManager();
	virtual bool loadContent();
  const sf::Texture& getTileset() const;
//  const sf::Texture& getLadders(int index) const;
  const sf::Texture& getPlayerTexture(CharacterState state, int index) const;
  const sf::Texture& getEnemyTexture(CharacterState state, int index) const;
  const sf::Texture& getDoorTexture() const;
  const sf::Texture& getBigLadderTexture() const;
  const sf::Texture& getBarrelTexture() const;
  const sf::Texture& getBulletTexture() const;
  const sf::Texture& getFireBulletTexture(int index) const;
  const sf::Font& getMainFont() const;
  const sf::Texture& getBonusTexture() const;
private:
  sf::Texture tileset;
  
  sf::Texture playerTextures[(int)CharacterState::NB_CHARACTER_STATES][12];
  sf::Texture enemyTextures[(int)CharacterState::NB_CHARACTER_STATES][12];
  sf::Texture doorTexture;
  sf::Texture bigLadder;
  sf::Texture barrel_front;
  sf::Texture bulletTexture;
  sf::Texture fireBulletTexture[5];
  sf::Font font;
  sf::Texture bonusTexture;
};



