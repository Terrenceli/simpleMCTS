#include "stdafx.h"
#include <boost/tokenizer.hpp>
using namespace boost;
const int COLS=7;
const int ROWS=6;


ConnectFour::ConnectFour()
{
	numOfStateCount=0;
}

ConnectFour::~ConnectFour()
{

}

const string replaceAll(const string& source, const string& replaceWhat, const string& replaceWithWhat);

vector<StringGameStatePtr>& ConnectFour::getPossibleMoves( GameStatePtr state )
{
	static vector<StringGameStatePtr> posMoves;

	posMoves.clear();
	posMoves.reserve(100);
	if (gameStatus(state)==Game::status::ONGOING)
	{
		string& str=state->toString().substr(0,state->toString().length()-1);
		char activePlayer=state->toString().back();

		for (int i=0; i<COLS;i++)
		{
			for (int j=ROWS-1;j>=0;j--)
			{
				int pos = j * (COLS + 1) + i;
				if(state->toString().at(pos) == '_')
				{
					string temp = state->toString().substr(0,pos);
					temp += activePlayer;
					temp += state->toString().substr(pos + 1, state->toString().length() - pos-2);
					if(activePlayer == '1')
					{
						temp += '2';
					}
					else
					{
						temp += '1';
					}
					posMoves.push_back(StringGameStatePtr(new StringGameState(temp)));
					j = -1;
				}
			}
			
		}
	}
	return posMoves;
}

Game::status ConnectFour::gameStatus( GameStatePtr state )
{
	numOfStateCount++;
	
	string s = state->toString().substr(0,state->toString().length()-1);
	//string sX= replaceAll(state->toString(),"O",".");
// 	string sX= replaceAll(s,"O",".");
// 	sX=replaceAll(sX,"_",".");
// 
// 	string sO= replaceAll(s,"X",".");
// 	sO=replaceAll(sO,"_",".");



	if (regex_match(s,regex(".*1111.*"))
		||regex_match(s,regex(".*(1.......){3}1.*"))
		||regex_match(s,regex(".*(1[^,].......){3}1.*"))
		||regex_match(s,regex(".*([^,]1.....){3}.1.*")))
	{
		return Game::status::PLAYER1WIN;
	} 

	else if (regex_match(s,regex(".*2222.*"))
		||regex_match(s,regex(".*(2.......){3}2.*"))
		||regex_match(s,regex(".*(2[^,].......){3}2.*"))
		||regex_match(s,regex(".*([^,]2.....){3}.2.*")))
	{
		return Game::status::PLAYER2WIN;
	} 
	else if (s.find("_") == string::npos) 
	{
		return Game::status::DRAW;
	} 
	else
	{
		return Game::status::ONGOING;
	}
}

StringGameStatePtr ConnectFour::getStartingState()
{
	return StringGameStatePtr(new StringGameState("_______,_______,_______,_______,_______,_______,1"));
}

void ConnectFour::printState( GameStatePtr state )
{
	string s = state->toString();
	s = replaceAll(s,"1","X");
	s = replaceAll(s,"2","O");
	s = replaceAll(s,"_",".");
	char_separator<char> sep(",");
	typedef tokenizer<char_separator<char> > t_tokenizer;
	t_tokenizer tok(s, sep);
	tokenizer<char_separator<char> >::iterator beg=tok.begin();
	for (int i=0;i<ROWS;++i)
	{
		cout<<*beg<<endl;
		beg++;
	}
}

long ConnectFour::getNumOfStateCount()
{
	return numOfStateCount;
}


Player* ConnectFour::p2 = 0;
Player* ConnectFour::p1 = 0;
Game* ConnectFour::g = 0;
