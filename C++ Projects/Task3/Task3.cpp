#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
std::vector<char> letters = { 'A', 'B', 'C', 'D', 'E', 'F' };
std::string str = "";
std::string num = "";
///task 5:
void changeSimilarLetters()
{
	std::cout << "Enter a string to change something : ";
	std::cin >> str;
	char lastletter = ' ';
	int quantity = 1;
	for (int i = 0; i < size(str); i++)
	{
		if (str[i] == lastletter)
			quantity += 1;
		if (str[i] != lastletter || i==size(str)-1)
		{
			if (quantity > 1)
			{
				if(i==size(str)-1 && str[i]==lastletter)
					str.replace(i - quantity+1, quantity - 1, std::to_string(quantity));
				else
					str.replace(i-quantity, quantity - 1, std::to_string(quantity));
				i -= (quantity - 2);
				quantity = 1;
			}
			lastletter = str[i];
			
		}	
	}
	std::cout << "We have replaced something, have a look : " << str;

}
std::string transfer10To16(long long & x)
{
	std::string number;
	std::string swapnumber;
	std::cout << x << " ";
	while (x > 0)
	{
		if (x % 16 > 9)
			number += letters[x % 16 - 10];
		else
			number += std::to_string(x % 16);
		x /= 16;
	}
	for (int i = size(number) - 1; i >= 0; i--)
		swapnumber += number[i];
	swapnumber = "0x" + swapnumber;
	num += swapnumber;
	std::cout << swapnumber << " " << std::endl;
	return swapnumber;
}
void replace10Into16()
{
	std::cout << std::endl <<"Enter a string to convert constants : ";
	std::cin >> str;
	std::string number;
	for (int i = 0; i < std::size(str); i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			while (str[i] >= 48 && str[i] <= 57)
			{
				number += str[i];
				i++;
			}
			long long n = std::stoll(number);
			str.replace(i-size(number), size(number), transfer10To16(n));
			i -= (size(number) - size(num));
			number.clear();
			num.clear();
		}
	}
	std::cout << "Look at it : " << str<<std::endl;
    return;
}
int main()
{
	int m, n;
	changeSimilarLetters();
	//std::cout << std::endl<<"Enter 2 numbers : ";
	//std::cin >> m >> n;
	//std::cout << "Result = " << count(m, n) << std::endl;
	replace10Into16();

}
