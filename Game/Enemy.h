#pragma once
#include "GameCharacter.h"


class Enemy :
  public GameCharacter
{
public:

  Enemy();
  Enemy(const Enemy& src);
  ~Enemy();
  
  // Héritées via GameCharacter 
  virtual void initializeContent(const ContentManager& contentManager) override;

private:
};

