#include "stdafx.h"

using namespace std;

MTRand* TreeNode::random	= NULL;
int		TreeNode::nActions	= 0;
double	TreeNode::epsilon	= 0.0;

TreeNode::TreeNode(){
	random=new MTRand();
	nVisits=0;
	epsilon=1e-6;
	totValue=0.0;
	
}

TreeNode::TreeNode(GameState* g){
	random=new MTRand();
	nActions=5;
	nVisits=0;
	epsilon=1e-6;
	totValue=0.0;
	nodeGameState=g;
}

void TreeNode::selectAction(){
	list<TreeNode*> visited;
	TreeNode* cur = this;
	visited.push_back(this);
	while (!cur->isLeaf()) {
		cur = cur->select();
		visited.push_back(cur);
	}
	cur->expand();
	TreeNode* newNode = cur->select();
	visited.push_back(newNode);
	double value = rollOut(newNode);

	int turn=1;
	for (auto it = visited.begin(); it != visited.end(); ++it) {
		// would need extra logic for n-player game
		value*=turn;
		(*it)->updateStats(value);
		turn=1-turn;
	}
}

void TreeNode::expand(){
	children.resize(nActions);
	for (int i=0; i<nActions; i++) {
		children[i] = new TreeNode();
	}
}

TreeNode* TreeNode::select() {
	TreeNode* selected = NULL;
	double bestValue = 2.2e-308;


	for (auto it = children.begin(); it != children.end(); ++it){
		TreeNode* c = *it;
		double uctValue = c->totValue / (c->nVisits + epsilon) +
			sqrt(log(nVisits+1) / (c->nVisits + epsilon)) +
			rand()/(double)RAND_MAX * epsilon;
		// small random number to break ties randomly in unexpanded nodes
		if (uctValue > bestValue) {
			selected = c;
			bestValue = uctValue;
		}
	}
	return selected;
}

bool TreeNode::isLeaf(){
	return children.empty();
}

double TreeNode::rollOut(TreeNode* tn){
	return rand()/(double)RAND_MAX;
}

void TreeNode::updateStats(double value){
	nVisits++;
	totValue+=value;
}

int TreeNode::arity(){
	return children.empty()?0:children.size();
}