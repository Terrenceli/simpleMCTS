#include "stdafx.h"

TicTacToe::TicTacToe()
{

}

TicTacToe::~TicTacToe()
{

}

bool strMatch( const char *str1, const char *str2);


const string replaceAll(const string& source, const string& replaceWhat, const string& replaceWithWhat)
{
	string result = source;
	string::size_type pos = 0;
	while(1)
	{
		pos = result.find(replaceWhat,pos);
		if (pos == string::npos) break;
		result.replace(pos,replaceWhat.size(),replaceWithWhat);
		pos += replaceWithWhat.size();
	}
	return result;
}

vector<StringGameStatePtr>& TicTacToe::getPossibleMoves(GameStatePtr state)
{
	static vector<StringGameStatePtr> posMoves;
// 	for(int i = 0; i < posMoves.size(); i++) {
// 		delete posMoves[i];
// 		posMoves[i] = NULL;
// 	}
	posMoves.clear();
	posMoves.reserve(100);
	/*
	if(gameStatus(state)==Game::status::ONGOING)
	{
		string& str = state->toString();
		char activePlayer = str.back();
		//char activePlayer = state.toString().charAt(state.toString().length() - 1);
		for(int i = 0; i < str.length() - 1; i++)
		{
			if(str.at(i) == '_')
			{
				string temp = str.substr(0,i);
				temp += activePlayer;
				temp += str.substr(i+1, str.length() - i);
				if(activePlayer == 'X')
				{
					temp += 'O';
				}
				else
				{
					temp += 'X';
				}
				posMoves.push_back(new StringGameState(temp));
			}
		}
		//cout<<"possible moves: "<<posMoves.size()<<endl;
	}
	*/
	if(gameStatus(state)==Game::status::ONGOING)
	{
		char activePlayer = state->toString().at(state->toString().length()-1);
		//char activePlayer = state.toString().charAt(state.toString().length() - 1);
		for(int i = 0; i < state -> toString().length() - 1; i++)
		{
			if(state->toString().at(i) == '_')
			{
				string temp = state->toString().substr(0,i);
				temp += activePlayer;
				temp += state->toString().substr(i+1, state->toString().length() - (i+1)-1);
				if(activePlayer == 'X')
				{
					temp += 'O';
				}
				else
				{
					temp += 'X';
				}
				posMoves.push_back(StringGameStatePtr(new StringGameState(temp)));
			}
		}
		//cout<<"possible moves: "<<posMoves.size()<<endl;
	}

	return posMoves;
}

Game::status TicTacToe::gameStatus(GameStatePtr state)
{
	string s = state->toString();
	s[9]='.';
	//string sX= replaceAll(state->toString(),"O",".");
// 	string sX= replaceAll(s,"O",".");
// 	sX=replaceAll(sX,"_",".");
// 
// 	string sO= replaceAll(s,"X",".");
// 	sO=replaceAll(sO,"_",".");

	/*if (sX=="XXX......."
		|| sX=="...XXX...."         
		|| sX=="......XXX."
		|| sX=="X..X..X..."
		|| sX==".X..X..X.."
		|| sX=="..X..X..X."
		|| sX=="X...X...X."
		|| sX=="..X.X.X...") 
		*/
	if (strMatch(s.c_str(), "XXX???????")
		|| strMatch(s.c_str(), "???XXX????")        
		|| strMatch(s.c_str(), "??????XXX?")
		|| strMatch(s.c_str(), "X??X??X???")
		|| strMatch(s.c_str(), "?X??X??X??")
		|| strMatch(s.c_str(), "??X??X??X?")
		|| strMatch(s.c_str(), "X???X???X?")
		|| strMatch(s.c_str(), "??X?X?X???"))
	{
		return Game::status::PLAYER1WIN;
	} 
	/*else if (s=="OOO......."
		|| s=="...OOO...."
		|| s=="......OOO."
		|| s=="O..O..O..."
		|| s==".O..O..O.."
		|| s=="..O..O..O."
		|| s=="O...O...O."
		|| s=="..O.O.O...")*/
	else if (strMatch(s.c_str(), "OOO???????")
		|| strMatch(s.c_str(), "???OOO????")        
		|| strMatch(s.c_str(), "??????OOO?")
		|| strMatch(s.c_str(), "O??O??O???")
		|| strMatch(s.c_str(), "?O??O??O??")
		|| strMatch(s.c_str(), "??O??O??O?")
		|| strMatch(s.c_str(), "O???O???O?")
		|| strMatch(s.c_str(), "??O?O?O???"))
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

StringGameStatePtr TicTacToe::getStartingState()
{
    return StringGameStatePtr(new StringGameState("_________X"));
}

void TicTacToe::printState(GameStatePtr state)
{
	cout<<state->toString().substr(0, 3)<<endl;
	cout<<state->toString().substr(3, 3)<<endl;
	cout<<state->toString().substr(6, 3)<<endl;
}

bool strMatch( const char *str1, const char *str2)  
{  
	int slen1 = strlen(str1);  
	int slen2 = strlen(str2);

	//实际使用时根据strl的长度来动态分配表的内存
	char matchmap[12][12];
	memset(matchmap, 0, 12*12); 
	matchmap[0][0] = 1;  
	int i, j, k;  
	//遍历目标字符串符串
	for(i = 1; i<= slen1; ++i)  
	{  
		//遍历通配符串
		for(j = 1; j<=slen2; ++j)
		{
			//当前字符之前的字符是否已经得到匹配
			if(matchmap[i-1][j-1])
			{
				//匹配当前字符
				if(str1[i-1] == str2[j-1] || str2[j-1] == '?')
				{ 
					matchmap[i][j] = 1; 
					//考虑星号在末尾的情况
					if( i  == slen1 && j < slen2)
					{
						for ( k = j+1 ; k <= slen2 ; ++k )
						{
							if( '*' == str2[k-1])
							{
								matchmap[i][k] = 1;
							}else{
								break;
							}
						}
					}
				}else if(str2[j-1] == '*')
				{
					//遇到星号，目标字符串到末尾都能得到匹配
					for(k = i-1; k<=slen1; ++k)
					{
						matchmap[k][j] = 1;  
					}
				}
			}
		}
		//如果当前字符得到了匹配则继续循环，否则匹配失败
		for(k = 1; k<=slen2; ++k)  
		{
			if(matchmap[i][k])
			{
				break; 
			}
		}
		if(k>slen2)
		{
			return false;  
		}
	}
	return true;  
}  