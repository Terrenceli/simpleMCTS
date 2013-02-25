#pragma once
#include "Player.h"
#include "Game.h"
#include "MCTSNode.h"
class RandomPlayer:public Player
{
public:
	RandomPlayer(Game* g, bool player1);
	~RandomPlayer();
	GameState* curState;
	GameState* getCurState();
	void updateGameState(GameState* s);
	void MakeMove();

private:
	Game* g;
	bool player1;
	GameState* getFinishingMoveFrom(GameState* gameState);
	GameState* getRandomMoveFrom(GameState* gameState);
};
