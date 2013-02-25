#include "stdafx.h"

RandomRolloutPlayer::RandomRolloutPlayer(Game* g, bool player1, int thinkTime):MCTSPlayer(g, player1, thinkTime)
{
}

RandomRolloutPlayer::~RandomRolloutPlayer()
{
}

Game::status RandomRolloutPlayer::simulateFrom( GameState* state )
{
	Game::status s=g->gameStatus(state);
	if (s!=Game::status::ONGOING)
	{
		return s;
	}
	else
	{
		return simulateFrom(getRandomMoveFrom(state));
	}
}

StringGameState* RandomRolloutPlayer::getRandomMoveFrom( GameState* gameState )
{
	vector<StringGameState*>& moves = g->getPossibleMoves(gameState);
	int r = rand() % moves.size();
	return moves[r];
}
