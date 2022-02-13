#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
class Rational
{
public:
	Rational(int a, int b ): numerator(a), divisor(b)
	{
        int diver = gcd(numerator, divisor);
        diver = (divisor >= 0) ? diver : -diver;
        numerator /= diver;
        divisor /= diver;
	}

    int getnumerator() {
        return numerator;
    }

    int getdivisor() {
        return divisor;
    }

    int gcd(int a, int b) {
        while (true) {
            if (a == 0) {
                return (b >= 0) ? b : -b;
            }
            b %= a;
            if (b == 0) {
                return (a >= 0) ? a : -a;
            }
            a %= b;
        }
    }

    unsigned int hash() const {
        return static_cast<unsigned int>(numerator) + 429496751 * static_cast<unsigned int>(divisor);
    }

    void Create();

    friend std::ostream& operator << (std::ostream&, Rational const&);
    friend std::istream& operator>> (std::istream&, Rational&);
    friend Rational const operator+ (Rational const&, Rational const&);
    friend Rational const operator- (Rational const&, Rational const&);
    friend Rational const operator* (Rational const&, Rational const&);
    friend Rational const operator/ (Rational const&, Rational const&);
    friend bool operator< (Rational const&, Rational const&);
    friend bool operator== (Rational const&, Rational const&);
    friend bool operator> (Rational const&, Rational const&);
    friend bool operator<= (Rational const&, Rational const&);
    friend bool operator>= (Rational const&, Rational const&);
private:
    int numerator=0;
    int divisor=1;
};

#endif // RATIONAL_H
