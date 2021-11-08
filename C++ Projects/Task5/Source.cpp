#include "BigInteger.h"

int main()
{
	BigInteger<int> bigInteger1;
	BigInteger<int> bigInteger2;
	std::cin >> bigInteger1;
	std::cin >> bigInteger2;
	std::cout << "Sum: " << bigInteger2 + bigInteger1;
	std::cout << "Multiplication : " << bigInteger1 * bigInteger2;
	std::cout<< "Difference: " << bigInteger1 - bigInteger2;
	std::cout<< "Division: " << bigInteger1 / bigInteger2 << "Leftover from division: " << bigInteger1 % bigInteger2;
	return 0;
}