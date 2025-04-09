#include "stdafx.h"
#include "Animation.h"

Animation::Animation(sf::Sprite& s, float length)
  : sprite(s)
  , lengthInSeconds(length)
  , timeInCurrentState(0)
{

}

Animation::Animation(const Animation& src)
  : sprite(src.sprite)
  , lengthInSeconds(src.lengthInSeconds)
  , timeInCurrentState(src.timeInCurrentState)
{
  for (auto& frame : src.frames)
  {
    frames.push_back(frame);
  }
}
//Animation& Animation::operator=(const Animation& src)
//{
//  if (this != &src)
//  {
//   // sprite = src.sprite;
//    lengthInSeconds = src.lengthInSeconds;
//    timeInCurrentState = src.timeInCurrentState;
//    frames.clear();
//    for (auto& frame : src.frames)
//    {
//      frames.push_back(frame);
//    }
//  }
//  return *this;
//
//}

void Animation::reset()
  {
  timeInCurrentState = 0;
}

bool Animation::isOver() const
{
  return getTimeInCurrentState() >= lengthInSeconds;
}

Animation* Animation::clone() const
{
  return nullptr;
}
void Animation::update(float /*deltaT*/)
{
  unsigned int nf = getNextFrame();
  sprite.setTexture(frames[nf].getTexture());
  const sf::IntRect& rect = frames[nf].getRectangle();
  sprite.setTextureRect(rect);
  sf::Vector2f origin((float)rect.width * 0.5f, (float)rect.height * 0.5f);
  sprite.setOrigin(sf::Vector2f(origin));
}

bool Animation::init(const ContentManager& contentManager)
{
  return true;
}

float Animation::getTimeInCurrentState() const
{
  return timeInCurrentState;
}