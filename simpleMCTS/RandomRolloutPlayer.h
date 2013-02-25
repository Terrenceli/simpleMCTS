#pragma once
#include "MCTSPlayer.h"

class RandomRolloutPlayer:public MCTSPlayer
{
public:
	RandomRolloutPlayer(Game* g, bool player1, int thinkTime);
	~RandomRolloutPlayer();
protected:
	Game::status simulateFrom(GameState* state);
private:
	StringGameState* getRandomMoveFrom(GameState* gameState);

};

