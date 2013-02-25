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
	vector<StringGameState*>& getPossibleMoves(GameState* state);
	status gameStatus(GameState* state);
	StringGameState* getStartingState();
	void printState(GameState* state);

	static Game* g;
	static Player* p1;
	static Player* p2;

private:

};