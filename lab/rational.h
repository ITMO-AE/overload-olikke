#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>


class Rational
{
public:    
    Rational(): numerator (0), denominator (1) {}

    int Numerator() const {return numerator;}
    int Denominator()const {return denominator;}

    Rational(int Numerator, int Denominator);

    bool operator == (const Rational  &k)const;

    friend std::ostream& operator<<(std::ostream& os,  const Rational &val);

    friend std::istream& operator>>(std::istream& os,  Rational &val);

    friend Rational operator + (const Rational &val1, const Rational &val2);

    friend Rational operator - (const Rational &val1, const Rational &val2);

    friend Rational operator * (const Rational &val1, const Rational &val2);

    friend Rational operator / (const Rational &val1, const Rational &val2);

private:
    int numerator;
    int denominator;
    static int EvklidBinNOD(int a, int b);
    static void CheckInputData(int &num, int & den);
};

#endif // RATIONAL_H
