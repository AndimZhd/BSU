#include <iostream>
#include "LinkedList.h"
#include <cassert>
#include <set>

using namespace std;

void LinkedList::pushBack(int value)
{
	if (!_head)
		_head = new Node(value, nullptr);
	else
	{
		auto current = _head;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new Node(value, nullptr);
	}
}

void LinkedList::pushFront(int value)
{
	_head = new Node(value, _head);
}

void LinkedList::print() const
{
	auto current = _head;
	while (current)
	{
		cout << current->value << ' ';
		current = current->next;
	}
	cout << endl;
}
 
// Task 16(easy task list) :
void LinkedList::swapFirstAndLastElements()
{
	if (!_head)
		return;
	auto current = _head;
	while (current->next)
	{
		current = current->next;
	}
	swap(current->value, _head->value);
}

// Task 2(hard task list):
int LinkedList::findElementThatStandsOnNPositionFromTheEndInTheList(int n)
{
	assert(_head && "Your list is empty!");
	assert(n > 0 && "Invalid number");
	int i = 1;
	auto current = _head;
	auto ourElement = _head;
	while (current->next && i < n)
	{
		current = current->next;
		i++;
	}
	assert(!(i < n) && "There are less than n elements in the list");
	while (current->next)
	{
		current = current->next;
		ourElement = ourElement->next;
	}
	return ourElement->value;
}

//  Task 3(hard task list):
void LinkedList::makeALoop(int position1, int position2)
{
	if (position1 > position2)
		swap(position1, position2);
	auto current = _head;
	int i = 1;
	auto element1 = _head;
	auto element2 = _head;
	while (current)
	{
		if (i == position1)
			element1 = current;
		if (i == position2)
			element2 = current;
		i++;
		current = current->next;
	}
	assert(i > position1 && i > position2 && "There are no such positions in your list!!");
	element2->next = element1;
}

void LinkedList::destroyTheLoop(int position2)
{
	auto current = _head;
	for (int i = 1; i < position2; i++)
		current = current->next;
	current->next = nullptr;
}

bool LinkedList::doesHaveALoop()
{
	set<Node*> loopChecker;
	auto current = _head;
	int previousSize = loopChecker.size();
	while (current)
	{
		loopChecker.insert(current);
		if (loopChecker.size() == previousSize)
			return true;
		current = current->next;
		previousSize++;
	}
	return false;
}

LinkedList::LinkedList(int value) : _head(nullptr)
{
	pushFront(value);
}

LinkedList::LinkedList() : _head(nullptr){}

LinkedList::LinkedList(const LinkedList& list)
{
	auto current = list._head;
	while (current)
	{
		pushBack(current->value);
		current = current->next;
	}
}

LinkedList::LinkedList(LinkedList&& list) : _head(list._head)
{
	list._head = nullptr;
}

LinkedList::~LinkedList()
{
	while (_head)
	{
		auto tempNode = _head->next;
		delete _head;
		_head = tempNode;
	}
}