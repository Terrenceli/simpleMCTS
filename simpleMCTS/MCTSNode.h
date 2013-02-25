#pragma once
#include <vector>
#include "GameState.h"
#include "mtrand.h"
#include "StringGameState.h"
using namespace std;

class MCTSNode;
typedef boost::shared_ptr<MCTSNode> MCTSNodePtr;

class MCTSNode
{
public:
	MCTSNode(GameStatePtr nodeGameState);
	~MCTSNode();
	void expand(vector<StringGameStatePtr>& possibleMoves);
	MCTSNodePtr bestSelection(bool myTurn);
	int getTimesVisited();
	MCTSNodePtr bestMove();
	vector<MCTSNodePtr> getNextMoves();
	GameStatePtr getState();
	string toString();
	void setScore(float score);
	void visit();
	float getScore();
	MCTSNodePtr findChildNode(GameStatePtr s);
	bool isLeaf();
	MCTSNodePtr getRandomChild();

private:
	vector<MCTSNodePtr> nextMoves;
	GameStatePtr nodeGameState;
	float score;
	int timesVisited;
	MTRand r;
};

