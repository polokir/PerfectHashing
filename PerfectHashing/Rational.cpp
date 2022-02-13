#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string>
#include <sstream>
#include "Rational.h"

void Rational::Create() {
    if (!divisor)
        throw std::invalid_argument("denominator should not be zero");
    if (((numerator >> (sizeof(numerator) * 8 - 1)) ^ (divisor >> (sizeof(divisor) * 8 - 1))) & 1)
        numerator = -std::abs(numerator);
    else
        numerator = std::abs(numerator);
    divisor = std::abs(divisor);
}

std::ostream& operator <<(std::ostream& ost, Rational const& r)
{
    return ost << r.numerator << '/' << r.divisor;
}

std::istream& operator>>(std::istream& ist, Rational& r) // e.g. (5, -2)
{
    std::string s;
    std::getline(ist, s, ')');
    std::string::size_type ind;
    while ((ind = s.find_first_of("(,)")) != std::string::npos)
        s.replace(ind, 1, 1, ' ');
    std::istringstream iss(s);
    iss >> r.numerator >> r.divisor;
    r.Create();
    return ist;
}

Rational const operator+ (Rational const& lhs, Rational const& rhs)
{
    return Rational(lhs.numerator * rhs.divisor + rhs.numerator * lhs.divisor, lhs.divisor * rhs.divisor);
}

Rational const operator- (Rational const& lhs, Rational const& rhs)
{
    return lhs + Rational(-rhs.numerator, rhs.divisor);
}

Rational const operator* (Rational const& lhs, Rational const& rhs)
{
    return Rational(lhs.numerator * rhs.numerator, lhs.divisor * rhs.divisor);
}

Rational const operator/ (Rational const& lhs, Rational const& rhs)
{
    return lhs * Rational(rhs.divisor, rhs.numerator);
}

bool operator< (Rational const& lhs, Rational const& rhs)
{
    return double(lhs.numerator) / lhs.divisor < double(rhs.numerator) / rhs.divisor;
}

bool operator== (Rational const& lhs, Rational const& rhs)
{
    return !(lhs < rhs || rhs < lhs);
}

bool operator> (Rational const& lhs, Rational const& rhs)
{
    return rhs < lhs;
}

bool operator<= (Rational const& lhs, Rational const& rhs)
{
    return !(rhs < lhs);
}

bool operator>= (Rational const& lhs, Rational const& rhs)
{
    return !(lhs < rhs);
}