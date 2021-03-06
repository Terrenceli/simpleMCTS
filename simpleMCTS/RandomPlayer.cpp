#include "stdafx.h"

RandomPlayer::RandomPlayer( Game* g, bool player1 )
{
	this->g=g;
	this->player1=player1;
	curState=g->getStartingState();
}

RandomPlayer::~RandomPlayer()
{

}

GameStatePtr RandomPlayer::getCurState()
{
	return curState;
}

void RandomPlayer::updateGameState( GameStatePtr s )
{
	curState=s;
}

void RandomPlayer::MakeMove()
{
	if (g->gameStatus(curState)==Game::status::ONGOING)
	{
		GameStatePtr finisher=getFinishingMoveFrom(curState);
		if (finisher==NULL)
		{
			curState=getRandomMoveFrom(curState);
		}
		else
		{
			curState=finisher;
		}
	}
	if (!player1)
	{
//		cout<<"Player1 :"<<endl;
	}
	else
	{
//		cout<<"Player2 :"<<endl;
	}
//	cout<<g->gameStatus(curState)<<endl;
//	g->printState(curState);
}

GameStatePtr RandomPlayer::getFinishingMoveFrom( GameStatePtr gameState )
{
	vector<StringGameStatePtr >& moves=g->getPossibleMoves(gameState);
	for(auto it=moves.begin();it!=moves.end();++it)
	{
		if ((g->gameStatus((*it))==Game::status::PLAYER1WIN)||
			(g->gameStatus((*it))==Game::status::PLAYER2WIN))
		{
			return (*it);
		}
	}
	return NULL;
}

GameStatePtr RandomPlayer::getRandomMoveFrom( GameStatePtr gameState )
{
	vector<StringGameStatePtr >& moves=g->getPossibleMoves(gameState);
	int random=rand()%moves.size();
	return moves[random];
}










