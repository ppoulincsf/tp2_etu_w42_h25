
#pragma once
#include "LevelBase.h"
#include "Game.h"
#include "Inputs.h"
#include "ContentManager.h"
#include <list>
#include "GameActor.h"
enum class Event;


class Level02 :
  public LevelBase
{
public:
public:
  // Héritées via Scene
  Level02();
  ~Level02();
  // Héritées via Scene
  virtual void draw(sf::RenderWindow& window) const override;
  virtual void init(SceneInfo* _previousSceneInfo = nullptr) override;
  virtual void uninit() override;
  virtual void update(float _deltaT) override;

private:
  void generateLevel() override;

};

