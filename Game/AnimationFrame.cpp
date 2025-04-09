#include "stdafx.h"
#include "AnimationFrame.h"

//AnimationFrame::AnimationFrame(const AnimationFrame& src)
//  : texture(src.texture)
//  , rectangle(src.rectangle)
//{
//
//}

//AnimationFrame& AnimationFrame::operator=(const AnimationFrame& rhs)
//{
//  if (this != &rhs)
//  {
//    sf::Texture* text = const_cast<sf::Texture*>(&rhs.texture);
//    sf::Texture* curText = const_cast<sf::Texture*>(&texture);
//    *curText = *text;
//    rectangle = rhs.rectangle;
//  }
//  return *this;
//}

AnimationFrame::AnimationFrame(const sf::Texture& text, sf::IntRect rect)
  : texture(text)
  , rectangle(rect)
{
}

const sf::Texture& AnimationFrame::getTexture() const
{
  return texture;
}

const sf::IntRect& AnimationFrame::getRectangle() const
{
  return rectangle;
}