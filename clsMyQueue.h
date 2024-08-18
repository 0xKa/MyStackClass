#pragma once
#include <iostream>
#include "clsDblLinkedList.h";
using namespace std;

template <class T>
class clsMyQueue
{
protected:
	clsDblLinkedList <T> _LinkedList;

public:

	void Print()
	{
		_LinkedList.PrintList();
	}

	bool IsEmpty()
	{
		return _LinkedList.IsEmpty();
	}

	void push(T data)
	{
		_LinkedList.InsertAtEnd(data);
	}
	void pop()
	{
		_LinkedList.DeleteFirstNode();
	}

	int Size()
	{
		return _LinkedList.Size();
	}

	T front()
	{
		return _LinkedList.GetItem(0);
	}
	T back()
	{
		return _LinkedList.GetItem(Size() - 1);
	}

	T GetItem(int index)
	{
		return _LinkedList.GetItem(index);
	}

	void Reverse()
	{
		_LinkedList.Reverse();
	}

	void UpdateItem(int index, T NewValue)
	{
		_LinkedList.UpdateItem(index,NewValue);
	}

	void InsertAfter(int index, T NewValue)
	{
		_LinkedList.InsertAfter(index, NewValue); 
	}
	void InsertAtFront(T NewValue)
	{
		_LinkedList.InsertAtTheBeginning(NewValue); 
	}
	void InsertAtBack(T NewValue)
	{
		_LinkedList.InsertAtEnd(NewValue); //another solution: *this.push(Value);
	}

	void Clear()
	{
		_LinkedList.Clear();
	}

};

