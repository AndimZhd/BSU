//
// Created by a3057 on 12/2/2020.
//

#include "BigInteger.h"
#include "BigInteger.cpp"


int main()
{
    BigInteger<char> bigInteger1;
    BigInteger<char> bigInteger2;
    std::cout << bigInteger1;
    std::cin >> bigInteger1 >> bigInteger2;
    std::cout << bigInteger2;
    std::cout << "Sum: " << bigInteger2 + bigInteger1;
    std::cout << "Multiplication : " << bigInteger1 * bigInteger2;
    std::cout<< "Difference: " << bigInteger1 - bigInteger2;
    std::cout<< "Division: " << bigInteger1 / bigInteger2 << "Leftover from division: " << bigInteger1 % bigInteger2;
    return 0;
}
