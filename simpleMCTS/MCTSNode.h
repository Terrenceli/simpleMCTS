#pragma once
#include <vector>
#include "GameState.h"
#include "mtrand.h"
#include "StringGameState.h"
using namespace std;

class MCTSNode;
//typedef boost::shared_ptr<MCTSNode> MCTSNodePtr;

class MCTSNode
{
public:
	MCTSNode(GameState* nodeGameState);
	~MCTSNode();
	void expand(vector<StringGameState*>& possibleMoves);
	MCTSNode* bestSelection(bool myTurn);
	int getTimesVisited();
	MCTSNode* bestMove();
	vector<MCTSNode*> getNextMoves();
	GameState* getState();
	string toString();
	void setScore(float score);
	void visit();
	float getScore();
	MCTSNode* findChildNode(GameState* s);
	bool isLeaf();
	MCTSNode* getRandomChild();

private:
	vector<MCTSNode*> nextMoves;
	GameState* nodeGameState;
	float score;
	int timesVisited;
	MTRand r;
};

