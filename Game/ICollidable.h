#pragma once
class GameObject;
struct ICollidable
{
  virtual bool collidesWith(const GameObject& other) const = 0;
  //virtual bool collidesWithFromLeft(const GameObject& other) const = 0;
  //virtual bool collidesWithFromRight(const GameObject& other) const = 0;
//  virtual bool collidesWithFromTop(const GameObject& other) const = 0;
  virtual bool collidesWith(const sf::Vector2f& other) const = 0;
  virtual void onCollision(GameObject& other) = 0;
};
