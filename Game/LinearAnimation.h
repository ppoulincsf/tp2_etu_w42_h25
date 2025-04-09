#pragma once
#include "Animation.h"
class LinearAnimation :
  public Animation
{
public:
  //LinearAnimation& operator=(const LinearAnimation& src);
  virtual void update(float deltaT) override;
  virtual unsigned int getNextFrame() const override;
  virtual float getPercentage() const override;
  Animation* clone() const override;
protected:
  LinearAnimation(sf::Sprite& s, float length, bool repeated = false);
  LinearAnimation(const LinearAnimation& src);
protected:
  bool repeated;

};

