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
	virtual vector<StringGameState*>& getPossibleMoves(GameState* state)=0;
	virtual status gameStatus(GameState* state)=0;
	virtual StringGameState* getStartingState()=0;
	virtual void printState(GameState* state)=0;
private:

};