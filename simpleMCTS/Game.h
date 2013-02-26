#pragma once
#include <vector>
#include "StringGameState.h"
class Game
{
public:
	virtual ~Game(){}
	enum status
	{
		PLAYER1WIN,
		PLAYER2WIN,
		ONGOING,
		DRAW
	};
	virtual vector<StringGameStatePtr>& getPossibleMoves(GameStatePtr state)=0;
	virtual status gameStatus(GameStatePtr state)=0;
	virtual StringGameStatePtr getStartingState()=0;
	virtual void printState(GameStatePtr state)=0;
	virtual long getNumOfStateCount()=0;
private:

};