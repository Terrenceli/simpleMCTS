#pragma once
#include "Player.h"
#include "Game.h"
#include "MCTSNode.h"
class RandomPlayer:public Player
{
public:
	RandomPlayer(Game* g, bool player1);
	~RandomPlayer();
	GameStatePtr curState;
	GameStatePtr getCurState();
	void updateGameState(GameStatePtr s);
	void MakeMove();

private:
	Game* g;
	bool player1;
	GameStatePtr getFinishingMoveFrom(GameStatePtr gameState);
	GameStatePtr getRandomMoveFrom(GameStatePtr gameState);
};
