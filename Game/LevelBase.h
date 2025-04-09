#pragma once

#include "Inputs.h"
#include "GameActor.h"
#include "Scene.h"
#include "Subscriber.h"
class LevelBase :
  public Scene
{
public:
  static const float TIME_PER_FRAME;
  static const float GAMEPAD_SPEEDRATIO;
  static const float KEYBOARD_SPEED;
  static const float TIME_BETWEEN_FIRE;
  static const unsigned int SPACE_BETWEEN_STAIRS = 4;
public:
  ~LevelBase();

  // Héritées via Scene
  virtual void draw(sf::RenderWindow& window) const override;
  virtual void init(SceneInfo* _previousSceneInfo = nullptr) override;
  virtual void uninit() override;
  virtual void handleEvents(sf::RenderWindow& window) override;
  virtual void update(float _deltaT) override;
protected:
  LevelBase(SceneType type);
  Inputs inputs;
  virtual void generateLevel();
private:
  GameActor background[16][16];
  
};