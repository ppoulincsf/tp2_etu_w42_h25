#pragma once
#include "AnimationFrame.h"
struct Inputs;
class ContentManager;
class Animation
{
public:
  //Animation& operator=(const Animation& src);
  void reset();
  virtual void update(float deltaT);
  virtual unsigned int getNextFrame() const = 0;
  virtual bool init(const ContentManager& contentManager);
  float getTimeInCurrentState() const;
  virtual bool isOver() const;
  virtual float getPercentage() const = 0;
  virtual Animation* clone() const=0;
protected:

  Animation(sf::Sprite& s, float length);
  Animation(const Animation& src);
  
  std::vector<AnimationFrame> frames;
  float lengthInSeconds;
  float timeInCurrentState;

private:
  sf::Sprite& sprite;
  
};

