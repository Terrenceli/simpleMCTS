
#pragma once

#include "mtrand.h"
#include <vector>

class TreeNode{
private:
	static MTRand* random;
	static int nActions;
	static double epsilon;
	vector<TreeNode*> children;
	double totValue;
	double nVisits;
	TreeNode* select();
	GameStatePtr nodeGameState;
public:
	TreeNode();
	TreeNode(GameStatePtr g);
	void selectAction();
	void expand();
	bool isLeaf();
	double rollOut(TreeNode* tn);
	void updateStats(double value);
	int arity();
};