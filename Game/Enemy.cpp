#include "stdafx.h"
#include "Enemy.h"
#include "game.h"
#include "Inputs.h"
#include "game.h"
#include "LevelBase.h"

Enemy::Enemy()
  :GameCharacter(CharacterType::ENEMY)
{

}

Enemy::Enemy(const Enemy& src)
  : GameCharacter(src)
{
  initializeContent(*contentManager);
}

Enemy::~Enemy()
{

}

void Enemy::initializeContent(const ContentManager& _contentManager)
{
  contentManager = &_contentManager;

    // A COMPLETER
}


