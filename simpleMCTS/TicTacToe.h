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
	vector<StringGameStatePtr>& getPossibleMoves(GameStatePtr state);
	status gameStatus(GameStatePtr state);
	StringGameStatePtr getStartingState();
	void printState(GameStatePtr state);
private:

};

