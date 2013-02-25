#pragma once
#include "GameState.h"
class Player
{
public:
	Player(){};
	virtual ~Player(){};
	virtual void MakeMove()=0;
	virtual void updateGameState(GameStatePtr s)=0;
	virtual GameStatePtr getCurState()=0;
private:

};
