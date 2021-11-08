//
// Created by a3057 on 12/2/2020.
//

#ifndef TASK9_BIGINTEGER_H
#define TASK9_BIGINTEGER_H

#include <vector>
#include <iostream>

template <class T>
class BigInteger
{
private:
    std::vector<T> _value;
    int _sign;
    BigInteger& summ(const BigInteger&);
    BigInteger& analizeSignForSumm(const BigInteger&);
    BigInteger& difference(const BigInteger&);
    BigInteger& analizeSignForDifference(const BigInteger&);
    std::pair<BigInteger, BigInteger> division(const BigInteger&);
    template<typename T>
    friend long long findCurrentResult(const BigInteger<T>&, const BigInteger<T>&);

public:
    BigInteger(T number);
    BigInteger();
    BigInteger(const BigInteger&);
    BigInteger(BigInteger&&);
    BigInteger& operator= (const BigInteger&);
    BigInteger& operator= (BigInteger&&);
    BigInteger& operator+= (const BigInteger&);
    BigInteger operator+ (const BigInteger&) const;
    BigInteger& operator*=(const BigInteger&);
    BigInteger operator* (const BigInteger&) const;
    BigInteger& operator-=(const BigInteger&);
    BigInteger operator- (const BigInteger&) const;
    BigInteger& operator/= (const BigInteger&);
    BigInteger& operator%= (const BigInteger&);
    BigInteger operator/ (const BigInteger&) const;
    BigInteger operator% (const BigInteger&) const;
    bool operator== (const BigInteger&) const;
    bool operator>= (const BigInteger&) const;
    bool operator<= (const BigInteger&) const;
    bool operator<(const BigInteger&) const;
    bool operator>(const BigInteger&) const;
    template<typename T>
    friend std::ostream& operator<< (std::ostream&, const BigInteger<T>&);
    template<typename T>
    friend std::istream& operator>> (std::istream&, BigInteger<T>&);
};

#endif //TASK9_BIGINTEGER_H
