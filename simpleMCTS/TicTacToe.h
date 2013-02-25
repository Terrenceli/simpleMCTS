#pragma  once
#include "Game.h"
#include "GameState.h"
#include <vector>
#include "StringGameState.h"

class TicTacToe: public Game
{
public:
	TicTacToe();
	~TicTacToe();
	vector<StringGameState*>& getPossibleMoves(GameState* state);
	status gameStatus(GameState* state);
	StringGameState* getStartingState();
	void printState(GameState* state);
private:

};

