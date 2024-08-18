// stack based on doubly linked list
#pragma once
#include <iostream>
#include "clsMyQueue.h";
using namespace std;

template <class T>
class clsMyStack : public clsMyQueue <T>
{

public:

	void push(T data)
	{
		clsMyQueue <T> ::_LinkedList.InsertAtTheBeginning(data);
	}

	T Top()
	{
		return clsMyQueue <T> ::_LinkedList.GetItem(0);
	}
	T Bottom()
	{
		return clsMyQueue <T> ::_LinkedList.GetItem(clsMyQueue <T> ::Size() - 1);
	}

	void InsertAtTop(T NewValue)
	{
		clsMyQueue <T> ::_LinkedList.InsertAtTheBeginning(NewValue);
	}
	void InsertAtBottom(T NewValue)
	{
		clsMyQueue <T> ::_LinkedList.InsertAtEnd(NewValue);
	}


};

