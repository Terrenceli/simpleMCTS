#pragma once
#include <string>
#include "boost/shared_ptr.hpp"

using namespace std;

class GameState;
typedef boost::shared_ptr<GameState> GameStatePtr;

class GameState
{
public:
	virtual ~GameState(){};
	virtual bool equal(GameStatePtr g)=0;
	virtual string& toString()=0;
};

