#include "stdafx.h"

RandomRolloutPlayer::RandomRolloutPlayer(Game* g, bool player1, int thinkTime):MCTSPlayer(g, player1, thinkTime)
{
}

RandomRolloutPlayer::~RandomRolloutPlayer()
{
}

Game::status RandomRolloutPlayer::simulateFrom( GameStatePtr state )
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

StringGameStatePtr RandomRolloutPlayer::getRandomMoveFrom( GameStatePtr gameState )
{
	vector<StringGameStatePtr>& moves = g->getPossibleMoves(gameState);
	int r = rand() % moves.size();
	return moves[r];
}
