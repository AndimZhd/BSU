//
// Created by a3057 on 12/2/2020.
//

#include "BigInteger.h"
#include <cassert>
#include <string>
#include <ostream>

const long long NOTATION = 10000;

template <typename T>
BigInteger<T>::BigInteger(long long number)
{

    if (number < 0)
        _sign = -1;
    else
        _sign = 1;
    if (number == 0)
    {
        _value.push_back(0);
        return;
    }
    while (number != 0)
    {
        _value.push_back(abs(number % NOTATION));
        number /= NOTATION;
    }
}

template <typename T>
BigInteger<T>::BigInteger()
{
    _value = {};
    _sign = 1;
}

template <typename T>
BigInteger<T>::BigInteger(const BigInteger& bigInteger1)
{
    _sign = bigInteger1._sign;
    _value = bigInteger1._value;
}

template <typename T>
BigInteger<T>::BigInteger(BigInteger&& bigInteger1)
{
    _value = std::move(bigInteger1._value);
    _sign = bigInteger1._sign;
}

template <typename T>
BigInteger<T>& BigInteger<T>::operator=(const BigInteger& bigInteger1)
{
    if (this == &bigInteger1)
        return *this;
    _value = bigInteger1._value;
    _sign = bigInteger1._sign;
    return *this;
}

template <typename T>
BigInteger<T>& BigInteger<T>::operator=(BigInteger&& bigInteger1)
{
    if (this == &bigInteger1)
        return *this;
    _value = std::move(bigInteger1._value);
    _sign = bigInteger1._sign;
    return *this;
}

template <typename T>
bool BigInteger<T>::operator== (const BigInteger& bigInteger2) const
{
    if (_value.size() == bigInteger2._value.size() && _value.size() != 0)
    {
        for (int i = _value.size() - 1; i >= 0; i--)
        {
            if (_value[i] != bigInteger2._value[i])
                return false;
        }
        return true;
    }
    return false;
}

template <typename T>
bool BigInteger<T>::operator> (const BigInteger& bigInteger2) const
{
    if (_value.size() == bigInteger2._value.size() && _value.size() != 0)
    {
        for (int i = _value.size() - 1; i >= 0; i--)
        {
            if (_value[i] > bigInteger2._value[i])
                return true;
            if (_value[i] < bigInteger2._value[i])
                return false;
        }
        return false;
    }
    return (_value.size() > bigInteger2._value.size());
}

template <typename T>
bool BigInteger<T>::operator>= (const BigInteger& bigInteger2)const
{
    return (*this > bigInteger2 || *this == bigInteger2);
}

template <typename T>
bool BigInteger<T>::operator<= (const BigInteger& bigInteger2)const
{
    return !(*this > bigInteger2);
}

template <typename T>
bool BigInteger<T>::operator<(const BigInteger& bigInteger2) const
{
    return !(*this > bigInteger2 || *this == bigInteger2);
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const BigInteger<T>& bigInteger1)
{
    if (bigInteger1._value.size() == 0)
    {
        out << std::to_string(0) << std::endl;
        return out;
    }
    if (bigInteger1._sign == -1 && bigInteger1._value[bigInteger1._value.size() - 1] != 0)
        out << "-";
    for (int i = bigInteger1._value.size() - 1; i >= 0; i--)
    {
        if (bigInteger1._value[i] < NOTATION / 10 && i != bigInteger1._value.size() - 1)
        {
            for (int j = 0; j < std::to_string(NOTATION).size() - std::to_string(bigInteger1._value[i]).size() - 1; j++)
            {
                out << std::to_string(0);
            }
        }
        out << std::to_string(bigInteger1._value[i]);
    }
    out << std::endl;
    return out;
}

template <typename T>
std::istream& operator>> (std::istream& in, BigInteger<T>& bigInteger1)
{
    std::string number;
    in >> number;
    if (number[0] == '-')
    {
        bigInteger1._sign = -1;
        number.erase(0, 1);
    }
    else
        bigInteger1._sign = 1;
    int sizeOfElement = std::to_string(NOTATION).length() - 1;
    int i = 1;
    int value = number.length() - i * sizeOfElement;
    while (number.length() >= i * sizeOfElement)
    {
        std::string element = number.substr(number.length() - sizeOfElement * i, sizeOfElement);
        bigInteger1._value.push_back(std::stoi(element));
        i++;
    }
    if ((i - 1) * sizeOfElement != number.length())
        bigInteger1._value.push_back(std::stoi(number.substr(0, number.length() - (i - 1) * sizeOfElement)));
    return in;
}

template <typename T>
BigInteger<T>& BigInteger<T>::summ(const BigInteger& bigInteger2)
{
    int additive = 0;
    int i = 0;
    while (true)
    {
        if (i == bigInteger2._value.size())
        {
            while (additive > 0 && _value.size() > i)
            {
                _value[i] = (_value[i] + additive) % NOTATION;
                additive = (_value[i] + additive) / NOTATION;
                i++;
            }
            if (i == _value.size())
            {
                if (additive > 0)
                    _value.push_back(additive);
            }
            return *this;
        }
        int currentSum = _value[i] + bigInteger2._value[i];
        _value[i] = (currentSum + additive) % NOTATION;
        additive = (currentSum + additive) / NOTATION;
        i++;
    }
    return *this;
}

template <typename T>
BigInteger<T>& BigInteger<T>::analizeSignForSumm(const BigInteger& bigInteger2)
{
    if (bigInteger2._sign != this->_sign)
        this->difference(bigInteger2);
    else
        this->summ(bigInteger2);
    return *this;
}

template <typename T>
BigInteger<T>& BigInteger<T>::operator+=(const BigInteger& bigInteger2)
{
    if (*this >= bigInteger2)
        analizeSignForSumm(bigInteger2);
    else
    {
        BigInteger bigInt2Copy = bigInteger2;
        bigInt2Copy.analizeSignForSumm(*this);
        *this = bigInt2Copy;
    }
    return *this;
}

template <typename T>
BigInteger<T> BigInteger<T>::operator+(const BigInteger& bigInteger2) const
{
    return (BigInteger(*this) += bigInteger2);
}

template <typename T>
BigInteger<T>& BigInteger<T>::operator*= (const BigInteger& bigInteger2)
{
    std::vector<BigInteger> vectorOfSums;
    for (int i = 0; i < bigInteger2._value.size(); i++)
    {
        int additive = 0;
        vectorOfSums.push_back(BigInteger());
        int currentMultiplier = bigInteger2._value[i];
        for (int j = 0; j < _value.size(); j++)
        {
            long long currentMultiplication = currentMultiplier * _value[j];
            vectorOfSums[i]._value.push_back((currentMultiplication + additive) % NOTATION);
            additive = (currentMultiplication + additive) / NOTATION;
        }
        if (additive > 0)
            vectorOfSums[i]._value.push_back(additive);
        for (int j = 0; j < i; j++)
            vectorOfSums[i]._value.insert(vectorOfSums[i]._value.begin(), 0);
    }
    *this = BigInteger();
    for (auto& element : vectorOfSums)
    {
        *this += element;
    }
    _sign *= bigInteger2._sign;
    return *this;
}

template <typename T>
BigInteger<T> BigInteger<T>::operator*(const BigInteger& bigInteger2) const
{
    return (BigInteger(*this) *= bigInteger2);
}

template <typename T>
BigInteger<T>& BigInteger<T>::difference(const BigInteger& bigInteger2)
{
    int i = 0;
    int decreaser = 0;
    for (i; i != bigInteger2._value.size(); i++)
    {
        int difference = _value[i] - decreaser - bigInteger2._value[i];
        if (difference < 0)
        {
            _value[i] = (NOTATION + difference);
            decreaser = 1;
        }
        else
        {
            _value[i] = difference;
            decreaser = 0;
        }
    }
    while (decreaser == 1)
    {
        if (_value[i] == 0)
            _value[i] = (NOTATION - 1);
        else
        {
            _value[i] -= decreaser;
            decreaser = 0;
        }
        i++;
    }
    while (_value[_value.size() - 1] == 0 && _value.size() > 1)
        _value.pop_back();
    return *this;
}

template <typename T>
BigInteger<T>& BigInteger<T>::analizeSignForDifference(const BigInteger& bigInteger2)
{
    if (_sign != bigInteger2._sign)
        this->summ(bigInteger2);
    else
        this->difference(bigInteger2);
    return *this;
}

template <typename T>
BigInteger<T>& BigInteger<T>::operator-=(const BigInteger& bigInteger2)
{
    if (*this >= bigInteger2)
        this->analizeSignForDifference(bigInteger2);
    else
    {
        BigInteger result = bigInteger2;
        result.analizeSignForDifference(*this);
        *this = result;
        _sign *= -1;
    }
    return *this;
}

template <typename T>
BigInteger<T> BigInteger<T>::operator-(const BigInteger& bigInteger2) const
{
    return (BigInteger(*this) -= bigInteger2);
}

template <typename T>
long long findCurrentResult(const BigInteger<T>& currentReducedBigInteger, const BigInteger<T>& bigInteger2)
{
    long long endOfRange = NOTATION;
    long long beginOfRange = 0;
    long long mid = 0;
    while (currentReducedBigInteger - bigInteger2 * BigInteger<T>(mid) >= bigInteger2)
    {
        mid = (endOfRange - beginOfRange) / 2 + beginOfRange;
        if (bigInteger2 * BigInteger<T>(mid) == currentReducedBigInteger)
            return mid;
        if (bigInteger2 * BigInteger<T>(mid) > currentReducedBigInteger)
            endOfRange = mid;
        else
            beginOfRange = mid + 1;
    }
    if (currentReducedBigInteger > bigInteger2 * BigInteger<T>(mid))
        return mid;
    return mid - 1;
}

template <typename T>
std::pair<BigInteger<T>, BigInteger<T>> BigInteger<T>::division(const BigInteger& bigInteger2)
{
    BigInteger resultBigInteger = BigInteger();
    BigInteger currentReducedBigInteger = BigInteger();
    bool isDividerANull = true;
    if (bigInteger2._value == BigInteger(0)._value)
        isDividerANull = false;
    assert(isDividerANull && "Null division!!!");
    if (_sign != bigInteger2._sign)
        resultBigInteger._sign = -1;
    while (true)
    {
        int calculator = 1;
        for (int i = 0; i < _value.size(); i++)
        {
            if (_value[_value.size() - 1 - i] != 0 || currentReducedBigInteger._value.size() != 0)
                currentReducedBigInteger._value.insert(currentReducedBigInteger._value.begin(), _value[_value.size() - 1 - i]);
            if (currentReducedBigInteger >= bigInteger2)
                break;
            if (calculator > 1 && resultBigInteger._value.size() > 0)
                resultBigInteger._value.insert(resultBigInteger._value.begin(), 0);
            calculator++;
        }
        if (currentReducedBigInteger < bigInteger2)
        {
            if (calculator > 1)
                resultBigInteger._value.insert(resultBigInteger._value.begin(), 0);
            std::pair<BigInteger, BigInteger> result{ resultBigInteger, currentReducedBigInteger };
            return result;
        }
        _value.erase(_value.end() - calculator, _value.end());
        BigInteger currentBigIntegerMaxDeductible = BigInteger();
        BigInteger currentDifference = BigInteger();
        long long nextNumberInResultBigInteger = findCurrentResult(currentReducedBigInteger, bigInteger2);
        currentBigIntegerMaxDeductible = BigInteger(nextNumberInResultBigInteger) * bigInteger2;
        currentDifference = currentReducedBigInteger - currentBigIntegerMaxDeductible;
        resultBigInteger._value.insert(resultBigInteger._value.begin(), nextNumberInResultBigInteger);
        if (currentDifference > BigInteger(0))
            currentReducedBigInteger = currentDifference;
        else
            currentReducedBigInteger = BigInteger();
    }
}

template <typename T>
BigInteger<T>& BigInteger<T>::operator/=(const BigInteger& bigInteger2)
{
    *this = this->division(bigInteger2).first;
    return *this;
}

template <typename T>
BigInteger<T>& BigInteger<T>::operator%=(const BigInteger& bigInteger2)
{
    *this = this->division(bigInteger2).second;
    return *this;
}

template <typename T>
BigInteger<T> BigInteger<T>::operator/ (const BigInteger& bigInteger2) const
{
    return (BigInteger(*this) /= bigInteger2);
}

template <typename T>
BigInteger<T> BigInteger<T>::operator% (const BigInteger& bigInteger2) const
{
    return (BigInteger(*this) %= bigInteger2);
}
