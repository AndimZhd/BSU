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
    friend long long findCurrentResult(const BigInteger&, const BigInteger&);

public:
    BigInteger(long long number);
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
    friend std::ostream& operator<< (std::ostream&, const BigInteger&);
    friend std::istream& operator>> (std::istream&, BigInteger&);
};

#endif //TASK9_BIGINTEGER_H
