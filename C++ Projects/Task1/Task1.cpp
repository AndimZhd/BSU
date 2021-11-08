#include <iostream>
#include <vector>
using namespace std;
void count9LastFactorialFigures(int x)
{
    cout << "9 last numbers of " << x << " = ";
    long long factorial=1;
    for (int i = 2; i <= x; i++)
    {
        factorial *= i;
            factorial %= 1000000000;
            if (factorial == 0)
            {
                cout << "00000000";
                return;
            }
    }
    while (factorial < 100000000)
    {
         cout << "0";
         factorial *= 10;
    }
    cout << factorial;
    return;
}
int countXthFibonacciNumber(int x)
{
    if (x == 1)
        return 0;
    int result = 1;
    int previous = 0;
    int current = 1;
    for (int i = 3; i <= x; i++)
    {
        result = previous + current;
        previous = current;
        current = result;
    }
    return result;
}
bool isPrime(int x)
{
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return false;

    }
    return true;
}
void printAllDeviders(int x)
{
    vector <int> Deviders;
    vector <int> PrimeDeviders;
    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0)
        {
            Deviders.push_back(i);
            if (isPrime(i))

#include <iostream>
#include <vector>
using namespace std;
void count9LastFactorialFigures(int x)
{
    cout << "9 last numbers of " << x << " = ";
    long long factorial=1;
    for (int i = 2; i <= x; i++)
    {
        factorial *= i;
            factorial %= 1000000000;
            if (factorial == 0)
            {
                cout << "00000000";
                return;
            }
    }
    while (factorial < 100000000)
    {
         cout << "0";
         factorial *= 10;
    }
    cout << factorial;
    return;
}
int countXthFibonacciNumber(int x)
{
    if (x == 1)
        return 0;
    int result = 1;
    int previous = 0;
    int current = 1;
    for (int i = 3; i <= x; i++)
    {
        result = previous + current;
        previous = current;
        current = result;
    }
    return result;
}
bool isPrime(int x)
{
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return false;

    }
    return true;
}
void printAllDeviders(int x)
{
    vector <int> Deviders;
    vector <int> PrimeDeviders;
    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0)
        {
            Deviders.push_back(i);
            if (isPrime(i))
                PrimeDeviders.push_back(i);
        }
    }
    cout << "All deviders of the number " << x << ": " << endl;
    for (int i = 0; i < Deviders.size(); i++)
        cout << Deviders[i] << " ";
    cout << endl;
    return;
}
void printPrimeDeviders(int x)
{
   int i = 2;
   cout << "All prime deviders of the number " << x << ": " << endl;
   vector<int> a;
   while (i <= x)
   {
       if (x % i == 0)
       {
           a.push_back(i);
           while (x % i == 0)
           {
               x /= i;
           }
       }
       i++;
   }
   for (int i = 0; i < a.size(); i++)
       cout << a[i] << " ";
   cout << endl;
   return;
}
int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;
    printAllDeviders(number);
    cout<<number<<"th "<<"Fibonacci number = "<<countXthFibonacciNumber(number)<<endl;
    ///cout<<"Nine last figures of the factoriral of the number "<<number<<"= "<<countFactorial(number)%1000000000;
    printPrimeDeviders(number);
    count9LastFactorialFigures(number);
    return 0;
}
