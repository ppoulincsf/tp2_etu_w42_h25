#include "stdafx.h"
#include "GameObject.h"
constexpr auto RADIANS_TO_DEGREE = 57.295779513f;

GameObject::GameObject()
  : Sprite()
  , active(false)
{
}

GameObject::GameObject(const GameObject& src)
  : Sprite(src)
  , active(src.active)
{
  if (nullptr != src.getTexture())
  {
    setTextureRect(src.getTextureRect());
    // Super important pour �viter le bogue du carr� blanc
    // Attention au fait qu'on appelle une m�thode virtuelle dans un 
    // constructeur: seule la m�thode de la classe parent (GameObject)
    // sera appel�e.
    initialize(*src.getTexture(), src.getPosition());
  }
}

float GameObject::getAngleWith(const GameObject& other) const
{
  return atan2f(other.getPosition().y - getPosition().y, other.getPosition().x - getPosition().x);
}

void GameObject::draw(sf::RenderWindow& window) const
{
  if (isActive())
    window.draw(*this);
}

void GameObject::activate(bool _active)
{
  active = _active;
}

bool GameObject::isActive() const
{
  return active;
}

sf::FloatRect GameObject::getBoundingRectangle() const
{
  return getGlobalBounds();
}


float GameObject::getRotationAngleInRadians() const
{
  return getRotation() / RADIANS_TO_DEGREE;
}


void GameObject::setRotationAngleRadians(const float angle)
{
  setRotation(angle * RADIANS_TO_DEGREE);
}

void GameObject::rotateInRadians(const float angle)
{
  rotate(angle * RADIANS_TO_DEGREE);
}

void GameObject::initialize(const sf::Texture& texture, const sf::Vector2f& initialPosition)
{
  setTexture(texture);
  const sf::IntRect& rect = getTextureRect();
  setOrigin(sf::Vector2f(rect.width / 2.0f, rect.height / 2.0f));
  setPosition(initialPosition);
}

void GameObject::initializeContent(const ContentManager& /*manager*/)
{
}
