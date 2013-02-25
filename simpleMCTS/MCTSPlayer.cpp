#include "stdafx.h"
#include "time.h"
MCTSPlayer::MCTSPlayer(Game* g, bool player1, int thinkTime)
{
	this->g=g;
	this->player1=player1;
	curState=g->getStartingState();
	gameTree=MCTSNodePtr(new MCTSNode(curState));
	curNode=gameTree;
	curNode->expand(g->getPossibleMoves(curNode->getState()));
	this->thinkTime=thinkTime;

}

MCTSPlayer::~MCTSPlayer()
{
}

GameStatePtr MCTSPlayer::getCurState()
{
	return curState;

}

void MCTSPlayer::updateGameState( GameStatePtr s )
{
	curState=s;
	if(curNode->isLeaf())
	{
		curNode->expand(g->getPossibleMoves(curNode->getState()));
	}
	curNode=curNode->findChildNode(s);
}

void MCTSPlayer::MakeMove()
{
	clock_t time = clock();
	clock_t endTime = time+thinkTime;
	while (clock() < endTime)
	{
		runTrial(curNode,true);
	}
	if (g->gameStatus(curState)==Game::status::ONGOING)
	{
		MCTSNodePtr best=curNode->bestMove();
		curState = best->getState();
		curNode = best;
	}
	
	/*
	clock_t time = clock();
	clock_t endTime = time+thinkTime;
	int i=0;
	while (++i<30)
	{
		runTrial(curNode,true);
	}
	if (g->gameStatus(curState)==Game::status::ONGOING)
	{
		MCTSNodePtr best=curNode->bestMove();
		curState = best->getState();
		curNode = best;
	}
	*/
}

Game::status MCTSPlayer::runTrial( MCTSNodePtr node, bool myTurn )
{
	Game::status returnStatus;
	node->visit();
	if (!node->isLeaf())
	{
		//selection
		returnStatus=runTrial(node->bestSelection(myTurn), !myTurn);
	}
	else
	{
		//expansion
		vector<StringGameStatePtr>& a = g->getPossibleMoves(node->getState());
		
		node->expand(a);
		
		if (!node->isLeaf())
		{
			node=node->getRandomChild();
			node->visit();
		}
		//simulation
		returnStatus=simulateFrom(node->getState());
	}

	//back prorogation
	if (IWin(returnStatus))
	{
		node->setScore(node->getScore()+1);
	}
	if (ILose(returnStatus))
	{
		node->setScore(node->getScore()-1);
	}
	return returnStatus;
}

bool MCTSPlayer::IWin( Game::status s )
{
	return (s == Game::status::PLAYER1WIN && player1) || (s == Game::status::PLAYER2WIN && !player1);
}

bool MCTSPlayer::ILose( Game::status s )
{
	return (s == Game::status::PLAYER1WIN && !player1) || (s == Game::status::PLAYER2WIN && player1);
}

