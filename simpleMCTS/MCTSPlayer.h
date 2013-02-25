#pragma once
#include "Player.h"
#include "Game.h"
#include "MCTSNode.h"
class MCTSPlayer:public Player
{
public:
	MCTSPlayer(Game* g, bool player1, int thinkTime);
	~MCTSPlayer();
	GameState* getCurState();
	void updateGameState(GameState* s);
	void MakeMove();
private:
	MCTSNode* gameTree;
	MCTSNode* curNode;
	int thinkTime;
	Game::status runTrial(MCTSNode* node, bool myTurn);

protected:
	Game* g;
	bool player1;
	GameState* curState;
	bool IWin(Game::status s);
	bool ILose(Game::status s);
	virtual Game::status simulateFrom(GameState* state)=0;
};
