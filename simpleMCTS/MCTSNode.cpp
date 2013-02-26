#include "stdafx.h"

MCTSNode::MCTSNode(GameStatePtr nodeGameState)
{
	score=0.0;
	timesVisited=0;
	this->nodeGameState=nodeGameState;
}

MCTSNode::~MCTSNode()
{
}

void MCTSNode::expand(vector<StringGameStatePtr>& possibleMoves)
{
	for(auto it=possibleMoves.begin(); it!=possibleMoves.end();++it)
	{
		nextMoves.push_back(MCTSNodePtr(new MCTSNode(*it)));
	}
}

MCTSNodePtr MCTSNode::bestSelection(bool myTurn)
{
	int turn;
	if(myTurn)
	{
		turn=1;
	}
	else
	{
		turn=-1;
	}
	float bias, randomizer;
	float max = -FLT_MAX * turn;
	int maxIndex = 0;
	float C = 1;
	for (unsigned i = 0; i < nextMoves.size(); i++) 
	{
		MCTSNodePtr node = nextMoves[i];
		float nodeScore = (float) node->getScore() / ((float) (node->getTimesVisited() + FLT_MIN));
		bias = 2 * C * (float) (sqrt(log((float) this->getTimesVisited()) / ((float) node->getTimesVisited() + FLT_MIN)));
		randomizer = FLT_MIN * (rand() % nextMoves.size()) * nextMoves.size();
		float biasedScore = nodeScore + randomizer + (bias * turn);
		if (biasedScore * turn > max * turn) 
		{
			max = biasedScore;
			maxIndex = i;
		}
	}
	return nextMoves[maxIndex];
}

int MCTSNode::getTimesVisited()
{
	return timesVisited;
}

MCTSNodePtr MCTSNode::bestMove()
{
	float max=-FLT_MAX;
	int maxIndex=rand()%nextMoves.size();
	float randomizer;
	for (unsigned i = 0; i < nextMoves.size(); i++)
	{
		MCTSNodePtr node=nextMoves[i];
		float nodeScore=(float) node->getScore() / (float) (node->getTimesVisited());
		randomizer=FLT_MIN* (rand()% nextMoves.size()) * nextMoves.size();

		if (nodeScore + randomizer > max) {
			max = nodeScore + randomizer;
			maxIndex = i;
		}
	}
	return nextMoves[maxIndex];
}

vector<MCTSNodePtr> MCTSNode::getNextMoves()
{
	return nextMoves;
}

GameStatePtr MCTSNode::getState()
{
	return nodeGameState;
}

string MCTSNode::toString()
{
	return nodeGameState->toString();
}

void MCTSNode::setScore(float score)
{
	this->score=score;
}

void MCTSNode::visit()
{
	this->timesVisited++;
}

float MCTSNode::getScore()
{
	return this->score;
}

MCTSNodePtr MCTSNode::findChildNode(GameStatePtr s)
{
	for(auto it=nextMoves.begin();it!=nextMoves.end();it++)
	{
		GameStatePtr st = (*it)->getState();
		if(st->equal(s))
		{
			return *it;
		}
	}
	return NULL;
}

bool MCTSNode::isLeaf()
{
	return nextMoves.empty();
}

MCTSNodePtr MCTSNode::getRandomChild()
{
	int random=rand()% nextMoves.size();
	return nextMoves[random];
}


