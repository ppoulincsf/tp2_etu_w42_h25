#pragma once
#include "GameActor.h"
#include "CharacterState.h"
#include "IUpdatable.h"
#include "CharacterType.h"
class Animation;
class Bullet;
class GameCharacter :
  public GameActor, public IUpdatable
{
public:
  static const unsigned int MAX_TEXTURE_PER_STATE = 12;
  static const std::string PLAYER_STATE_NAMES[];
  static const unsigned int PLAYER_STATE_FRAME_COUNTS[];
  

  GameCharacter(CharacterType type);
  GameCharacter(const GameCharacter& src);
  ~GameCharacter();

  
  CharacterType getType() const;
protected:
  CharacterState currentState;
  CharacterType characterType;

  Animation* animations[(int)CharacterState::NB_CHARACTER_STATES];  
  const ContentManager* contentManager;
};

