#pragma once
#include "BaseGame.h"

class Game : public BaseGame
{
public:
  static const unsigned int TILE_SIZE = 63;
	static const unsigned int TILE_HORIZONTAL_COUNT = 16;
	static const unsigned int TILE_VERTICAL_COUNT = 16;
	typedef class Level01 InitialScene;
public:
	Game(std::string windowName);
	~Game();
	void update() override;
	void draw() const override;

	protected:
    Scene* getNextScene(SceneType type) const override;
private:
	void init() override;
	void handleEvents() override;	

	void uninit() override;




};

