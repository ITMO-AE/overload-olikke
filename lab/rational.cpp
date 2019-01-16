#include "rational.h"

Rational::Rational(int Numerator, int Denominator): numerator(Numerator), denominator(Denominator)
{
    CheckInputData(numerator,denominator);
    int NOD=EvklidBinNOD(abs(numerator),denominator);
    numerator/=NOD;
    denominator/=NOD;
}

void Rational::CheckInputData(int & num, int &den)
{
    if (num==0)
    {
        den=1;
        return;
    }
    else if (num>0 && den>0)
    {}
    else if (num<0 && den<0)
    {
        num=abs(num);
        den=abs(den);
    }
    else if (den<0)
    {
        num=-num;
        den=abs(den);
    }
}

Rational operator+(const Rational &val1, const Rational &val2)
{
    int numerator=val1.numerator*val2.denominator+val2.numerator*val1.denominator;
    int denominator=val1.denominator*val2.denominator;
    return Rational (numerator,denominator);
}

Rational operator-(const Rational &val1, const Rational &val2)
{
    int numerator=val1.numerator*val2.denominator-val2.numerator*val1.denominator;
    int denominator=val1.denominator*val2.denominator;
    return Rational (numerator,denominator);
}

Rational operator*(const Rational &val1, const Rational &val2)
{
    int numerator=val1.numerator*val2.numerator;
    int denominator=val1.denominator*val2.denominator;
    return Rational (numerator,denominator);
}

Rational operator/(const Rational &val1, const Rational &val2)
{
    int numerator=val1.numerator*val2.denominator;
    int denominator=val1.denominator*val2.numerator;
    return Rational (numerator,denominator);
}

bool Rational::operator==(const Rational &k) const
{
    return (numerator==k.numerator && denominator==k.denominator);
}

std::ostream& operator<<(std::ostream& os,  const Rational &val)
{
    os<<val.numerator<<"/"<<val.denominator;
    return os;
}

std::istream& operator>>(std::istream& os,  Rational &val)
{
    char d;
    os>>val.numerator>>d>>val.denominator;
    Rational::CheckInputData(val.numerator,val.denominator);
    int NOD=Rational::EvklidBinNOD(abs(val.numerator),val.denominator);
    val.numerator/=NOD;
    val.denominator/=NOD;
    return os;
}

int Rational::EvklidBinNOD(int a, int b)
{
    if (a==b) {return a;}
    if (b==0) {return a;}
    if (a==1 || b==1) {return 1;}
    int nod=1;
    int tmp;
    while (a!=0 && b!=0)
    {
        if (((a & 1) | (b & 1)) == 0)
        {
            nod<<=1;
            a>>=1;
            b>>=1;
            continue;
        }
        if (((a & 1) == 0) && (b & 1))
        {
            a >>= 1;
            continue;
        }
        if ((a & 1) && ((b & 1) == 0))
        {
            b >>= 1;
            continue;
        }
        if (a > b)
        {
            tmp = a;
            a = b;
            b = tmp;
         }
         tmp = a;
         a = (b - a) >> 1;
         b = tmp;

    }
    if (a == 0)
        return nod * b;
    else
        return nod * a;
}
