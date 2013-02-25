#pragma once
#include <string>
#include "GameState.h"
#include "boost/shared_ptr.hpp"

using namespace std;
class StringGameState:public GameState
{
public:
	StringGameState(string s);
	bool equal(GameStatePtr g);
	string& toString();
private:
	string state;

};

typedef boost::shared_ptr<StringGameState> StringGameStatePtr;