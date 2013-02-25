#include "stdafx.h"

StringGameState::StringGameState(string s)
{
	state=s;
}

bool StringGameState::equal(GameState* g)
{
	StringGameState* sun = dynamic_cast<StringGameState*>(g);
	if (sun){
		return state == sun->state;
	}
	return false;
}

string& StringGameState::toString()
{
	return state;
}