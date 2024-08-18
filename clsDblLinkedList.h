#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
{
protected:

	int _Size = 0;

public:

	class Node
	{
	public:
		T data;
		Node* next;
		Node* prev;
	};

	Node* head = NULL;


	void Print()
	{
		Node* temp = head;
		cout << "\nNULL <--> ";
		while (temp != NULL) {
			cout << temp->data << " <--> ";
			temp = temp->next;
		}
		cout << "NULL\n";
		delete temp;
	}

	void PrintList()
	{
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		delete temp;
	}

	Node* Find(T data)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->data == data)
				return temp;

			temp = temp->next;
		}
		return NULL;
	}

	void InsertAtTheBeginning(T data)
	{
		Node* new_node = new Node();

		new_node->data = data;
		new_node->prev = NULL;
		new_node->next = head;

		if (head != NULL)
			head->prev = new_node;

		head = new_node;
		_Size++;
	}

	void InsertAfter(Node* prev_node, T data)
	{
		if (prev_node == NULL)
		{
			cout << "\nThe given previous node cannot be NULL\n";
			return;
		}

		Node* new_node = new Node();
		new_node->data = data;
		new_node->prev = prev_node;
		new_node->next = prev_node->next;

		prev_node->next = new_node;

		if (new_node->next != NULL)
			new_node->next->prev = new_node;

		_Size++;
	}

	bool InsertAfter(int index, T data)
	{
		if (head == NULL) return false;
		InsertAfter(GetNode(index), data);
		return true;
	}

	void InsertAtEnd(T data)
	{
		Node* new_node = new Node();
		
		new_node->data = data;
		new_node->next = NULL;

		if (head == NULL)
		{
			new_node->prev = NULL;
			head = new_node;
		}
		else
		{
			Node* LastNode = head;
			while (LastNode->next != NULL)
			{
				LastNode = LastNode->next;
			}

			new_node->prev = LastNode;
			LastNode->next = new_node;
		}
		
		_Size++;
	}

	void Delete(Node*& NodeToDelete)
	{
		if (head == NULL || NodeToDelete == NULL)
			return;

		if (head == NodeToDelete)
			head = NodeToDelete->next;

		if (NodeToDelete->next != NULL)
			NodeToDelete->next->prev = NodeToDelete->prev;

		if (NodeToDelete->prev != NULL)
			NodeToDelete->prev->next = NodeToDelete->next;

		delete NodeToDelete;
		_Size--;
	}

	void DeleteFirstNode()
	{
		if (head == NULL) return;

		Node* Current = head;
		head = head->next;

		if (head != NULL)
			head->prev = NULL;

		delete Current;
		_Size--;
	}

	void DeleteLastNode()
	{
		if (head == NULL) return;

		if (head->next == NULL)
		{
			delete head;
			head = NULL;
		}
		else
		{
			Node* Current = head;

			while (Current->next->next != NULL)
			{
				Current = Current->next;
			}

			Node* LastNode = Current->next;
			Current->next = NULL;
			delete LastNode;
		}

		_Size--;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (head == NULL);
	}

	void Clear()
	{
		while (head != NULL)
		{
			DeleteLastNode();
		}
	}
	
	void Reverse()
	{
		Node* Current = head;
		Node* temp = nullptr;

		while (Current != nullptr)
		{
			//swap prev & next of a node
			temp = Current->prev;
			Current->prev = Current->next;
			Current->next = temp;

			Current = Current->prev; //go to the next node
		}

		if (temp != nullptr)
			head = temp->prev;
	}

	Node* GetNode(int index)
	{
		if (index >= _Size || index < 0) return NULL;
		if (index == 0) return head;

		Node* Current = head;
		
		for (int i = 0; i < index; i++)
		{
			Current = Current->next;
		}
		return Current;
	}

	T GetItem(int index)
	{
		if (head == NULL) return NULL;
		return GetNode(index)->data;
	}

	bool UpdateItem(int index, T NewValue)
	{
		if (head == NULL) return false;
		GetNode(index)->data = NewValue;
		return true;
	}

};

