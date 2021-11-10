#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList myList = LinkedList();

void fulfilling(int numberOfElements)
{
	for (int i = 0; i < numberOfElements; i++)
	{
		int element;
		cin >> element;
		myList.pushBack(element);
	}
}

int main()
{
	int numberOfElements;
	cout << "Enter the number of elements: ";
	cin >> numberOfElements;
	fulfilling(numberOfElements);
	cout << "Our list: ";
	myList.print();

	cout << "We have swapped the first element with the last one" << endl;
	myList.swapFirstAndLastElements();
	myList.print();

	int n;
	cout << "Enter the position from the end of element that you want to find ";
	cin >> n;
	cout << "Your element: " << myList.findElementThatStandsOnNPositionFromTheEndInTheList(n) << endl;
/*
	int position1;
	int position2;
	string answer;
	cout << "Do you want to make a loop?(yes/no)";
	cin >> answer;
	if (answer == "yes")
	{
		//Making a loop:
		cout << "Enter 2 positions between what you want to make a loop: ";
		cin >> position1 >> position2;
		myList.makeALoop(position1, position2);
	}
	if (myList.doesHaveALoop())
		cout << "Your list does have a loop";
	else
		cout << "Your list doesn't have a loop";
	if(answer == "yes")
		myList.destroyTheLoop(position2);*/
	return 0;
}