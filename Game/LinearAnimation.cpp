
#include "stdafx.h"
#include "LinearAnimation.h"


LinearAnimation::LinearAnimation(sf::Sprite& s, float length, bool repeated)
  : Animation(s, length)
{
  this->repeated = repeated;
}

LinearAnimation::LinearAnimation(const LinearAnimation& src)
  : Animation(src), repeated(src.repeated)
{
}

//LinearAnimation& LinearAnimation::operator=(const LinearAnimation& src)
//{
//  if (this != &src)
//  {
//    Animation::operator=(src);
//    repeated = src.repeated;
//  }
//  return *this;
//}

void LinearAnimation::update(float deltaT)
{
  timeInCurrentState += deltaT;
  if (timeInCurrentState >= lengthInSeconds)
    if (repeated)
      timeInCurrentState = 0;
  Animation::update(deltaT);
}

unsigned int LinearAnimation::getNextFrame() const
{
  if (isOver())
    return frames.size() - 1;
  float retval = (float)frames.size() * timeInCurrentState / lengthInSeconds;
  return (unsigned int)(retval);
}

float LinearAnimation::getPercentage() const
{
  return (float)getNextFrame() / (float)frames.size();
}

Animation* LinearAnimation::clone() const
{
 return new LinearAnimation(*this);;
}
