#include "stdafx.h"

// Constructor that takes 2 arguments 
// first argument is of string type that to be tokenized.
// second argument is of string type that is used as token seperator
// and default seperator is space
StringTokenizer::StringTokenizer(CString str,CString sep=" ")
{
	index=0;
	count=0;
	CString str1="";
	for(int i=0;i<str.GetLength() && sep.GetLength()==1;i++)
	{
		if(str.GetAt(i)==sep.GetAt(0))
		{
			elements.Add(str1);
			
			str1="";
		}
		else
		{
			str1+=str.GetAt(i); 
		}
	}
	elements.Add(str1);
	count=elements.GetSize ();

}

// Method is used to fetch the tokens.
CString StringTokenizer::getNextElement()
{
	index++;
	if(index==count)
	{
		throw CString("Index out of Bounds");
	}
	return elements.GetAt(index-1);	
}
//method used to fetch the count of tokens from the string
int StringTokenizer::countElements()
{
	return count;
}

//fetch the elements at given position 
CString StringTokenizer::elementAt(int index)
{
	if(index>=count ||index<0)
	{
		throw CString("Index out of Bounds");
	}
	else
		return elements.GetAt(index);	
}