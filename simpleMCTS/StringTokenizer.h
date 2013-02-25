#pragma once
#include <afxcoll.h>
class StringTokenizer 
{
private:
	CStringArray elements;
	int index;
	int count;
public:
	StringTokenizer(CString,CString);
	int countElements();
	CString elementAt(int);
	
	CString getNextElement();
};