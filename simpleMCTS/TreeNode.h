
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
	GameState* nodeGameState;
public:
	TreeNode();
	TreeNode(GameState* g);
	void selectAction();
	void expand();
	bool isLeaf();
	double rollOut(TreeNode* tn);
	void updateStats(double value);
	int arity();
};