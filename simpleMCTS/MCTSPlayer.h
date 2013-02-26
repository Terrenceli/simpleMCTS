#pragma once
#include "Player.h"
#include "Game.h"
#include "MCTSNode.h"
class MCTSPlayer:public Player
{
public:
	MCTSPlayer(Game* g, bool player1, int thinkTime);
	~MCTSPlayer();
	GameStatePtr getCurState();
	void updateGameState(GameStatePtr s);
	void MakeMove();
private:
	MCTSNodePtr gameTree;
	MCTSNodePtr curNode;
	int thinkTime;
	Game::status runTrial(MCTSNodePtr node, bool myTurn);

protected:
	Game* g;
	bool player1;
	GameStatePtr curState;
	bool IWin(Game::status s);
	bool ILose(Game::status s);
	virtual Game::status simulateFrom(GameStatePtr state)=0;
};
