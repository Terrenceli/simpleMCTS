#pragma once
#include "GameState.h"
class Player
{
public:
	Player(){};
	virtual ~Player(){};
	virtual void MakeMove()=0;
	virtual void updateGameState(GameState* s)=0;
	virtual GameState* getCurState()=0;
private:

};
