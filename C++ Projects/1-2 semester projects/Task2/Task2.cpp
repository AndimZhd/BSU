#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
using namespace std;
vector <int> vect1 = { 2, 3, 5, 5, 5, 5, 5, 7, 10, 14, 19, 21, 25, 30, 31, 36, 38, 46, 58, 60, 61, 62, 76, 86, 93, 99, 100 };
vector <int> period1;
int findElementsPosition(int element, int left, int right)
{
	if (left >= right)
	{
		cout << "The element isn't in the array, but if it was in it, it would stand on position number " << left + (right - left) / 2 + 1 << endl;
		return 0;
	}
	int middle = (right - left) / 2 + left;
	if (vect1[middle] == element)
		return middle+1;
	if (vect1[middle] > element)
		return findElementsPosition(element, left, middle);
	else
		return findElementsPosition(element, middle + 1, right);
}
bool fulfilling(int & unit, int n, int & degree)
{
	int i = 0;
	while (unit / n == 0)
	{
		unit *= 10;
		if ((i > 0) && (period1.size() != 0))
			period1.push_back(0);
		if (period1.size() == 0 && (i > 0))
			cout << "0";
		i++;
		if (i > degree)
			return true;
	}
	period1.push_back(unit/n);
	unit = unit%n;
	return false;
}
int checkPeriod()
{
	for (int i = 0; i < (period1.size()-1)/2; i++)
	{
		if (period1[period1.size() - 1] == period1[i])
		{
			if ((period1[(period1.size() - 1 + i) / 2] == period1[i]) && (period1.size() - 1 - i) > 2)
			{
				int period=(period1.size()-1+i)/2-i;
				for (int k = i; k < (period1.size() - 1 + i) / 2; k++)
				{
					if (period1[k] != period1[k + period])
						break;
					if (k == (period1.size() - 1 + i) / 2 - 1)
						return period;
				}

			}
		}
	}
	return 0;
}
int findPeriodsLength(int & n)
{
	cout << "Our number : ";
	int degree=1;
	int j = 1;
	while(j<n)
	{
		j *= 10;
		degree++;
	}
	cout << "0.";
	int unit = 1;
	while(true)
	{
		fulfilling(unit, n, degree);
		if (fulfilling(unit, n, degree))
		{
			for (auto element : period1)
				cout << element;
			cout << endl;
			cout <<"This number doesn't have a period" << endl;
			return 0;
		}
		if (checkPeriod() != 0)
			break;
	}
	for (auto element : period1)
		cout << element;
	cout << endl;
	cout << "Length of the period = " << checkPeriod() << endl;
	return 0;
}
int main()
{ 
	int number;
	cout << "Enter n for 1/n number : ";
	cin >> number;
	int left = 0;
	int right = vect1.size();
	int x;
	cout << "Enter a number which position you want to find in the array: ";
	cin >> x;
	int result = findElementsPosition(x, left, right);
	if (result != 0)
		cout << "Your element stays on position number " << result << " in our array" << endl;
	findPeriodsLength(number);
	return 0;
}
