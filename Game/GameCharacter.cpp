#include "stdafx.h"
#include "GameCharacter.h"
#include "Animation.h"
const std::string GameCharacter::PLAYER_STATE_NAMES[] = { "idle", "run", "jump", "climb", "walk", "die", "shoot" };
const unsigned int GameCharacter::PLAYER_STATE_FRAME_COUNTS[] = { 1, 12, 3, 6, 8, 5, 5 };
const unsigned int GameCharacter::MAX_TEXTURE_PER_STATE;

GameCharacter::GameCharacter(CharacterType type)
  : GameActor()
  , currentState(CharacterState::IDLE)
  , characterType(type)
  , contentManager(nullptr)
{
  for (int i = 0; i < (int)(CharacterState::NB_CHARACTER_STATES); i++)
  {
    animations[i] = nullptr;
  }
}

GameCharacter::GameCharacter(const GameCharacter& src)
  : GameActor(src)
  , currentState(src.currentState)
  , contentManager(src.contentManager)
{
  for (int i = 0; i < (int)(CharacterState::NB_CHARACTER_STATES); i++)
  {
    animations[i] = nullptr;
  }
  // Ne pas copier les animations.
  // Elles seront créées par la classe enfant.
}



GameCharacter::~GameCharacter()
{
  for (int i = 0; i < (int)(CharacterState::NB_CHARACTER_STATES); i++)
  {
    if (animations[i])
      delete animations[i];
    animations[i] = nullptr;
  }
}



CharacterType GameCharacter::getType() const
{
  return characterType;
}
