#pragma once
#include "GameObject.h"
#include "ICollidable.h"
class GameActor :
  public GameObject, public ICollidable
{
  public:
    GameActor();
    ~GameActor();
    
    // Inherited via ICollidable
    virtual bool collidesWith(const GameObject& other) const override;
    virtual bool collidesWith(const sf::Vector2f& other) const override;
    virtual void onCollision(GameObject& other) override;
};

