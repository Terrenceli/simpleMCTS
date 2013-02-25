#pragma  once
#include "Game.h"
#include "GameState.h"
#include <vector>
#include "StringGameState.h"


class ConnectFour: public Game
{
public:
	ConnectFour();
	~ConnectFour();
	vector<StringGameStatePtr>& getPossibleMoves(GameStatePtr state);
	status gameStatus(GameStatePtr state);
	StringGameStatePtr getStartingState();
	void printState(GameStatePtr state);

	static Game* g;
	static Player* p1;
	static Player* p2;

private:

};