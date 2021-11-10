#pragma once

class LinkedList
{
private:
	struct Node
	{
		Node(int value, Node* next) : value(value), next(next) {}
		int value;
		Node* next;
	};

	Node* _head;

public:
	LinkedList(int);
	LinkedList();
	LinkedList(const LinkedList&);
	LinkedList(LinkedList&&);
	~LinkedList();
	void pushBack(int);
	void pushFront(int);
	void print() const;
	void swapFirstAndLastElements();
	int findElementThatStandsOnNPositionFromTheEndInTheList(int);
	void makeALoop(int, int);
	bool doesHaveALoop();
	void destroyTheLoop(int);
};
