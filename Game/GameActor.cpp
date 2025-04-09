#include "stdafx.h"
#include "GameActor.h"

GameActor::GameActor()
{
}

GameActor::~GameActor()
{
}

bool GameActor::collidesWith(const GameObject& other) const
{
  return isActive() && other.isActive() && getBoundingRectangle().intersects(other.getBoundingRectangle());
}

bool GameActor::collidesWith(const sf::Vector2f& other) const
{
  return isActive() && getBoundingRectangle().contains(other);
}

void GameActor::onCollision(GameObject& other)
{
}
