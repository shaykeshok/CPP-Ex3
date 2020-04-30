#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "solver.hpp"
#include <stdio.h>

using namespace std;

namespace solver
{

//-----------shared-------------//
double solve(const RealVariable &r1) { return 0; };

std::complex<double> solve(const ComplexVariable& c1)
{
    std::complex<double> s = 0;
    return s;
};


//--------------RealVariable------------//
//operator '*'
const RealVariable RealVariable::operator*(double x) const
{
    return RealVariable();
};
const RealVariable operator*(const RealVariable &real1, const RealVariable &real2)
{
    return real1;
};
const RealVariable operator*(double x, const RealVariable &real1)
{
    return real1;
};

//operator '=='
const RealVariable RealVariable::operator==(double x) const
{
    return RealVariable();
};
const RealVariable operator==(const RealVariable &real1, const RealVariable &real2)
{
    return real1;
};
const RealVariable operator==(double x, const RealVariable &real1)
{
    return real1;
};

//operator '^'
const RealVariable RealVariable::operator^(double x) const
{
    return RealVariable();
};
const RealVariable operator^(const RealVariable &real1, const RealVariable &real2)
{
    return real1;
};
const RealVariable operator^(double x, const RealVariable &real1)
{
    return real1;
};

//operator '+'
const RealVariable RealVariable::operator+(double x) const
{
    return RealVariable();
};
const RealVariable operator+(const RealVariable &real1, const RealVariable &real2)
{
    return real1;
};
const RealVariable operator+(double x, const RealVariable &real1)
{
    return real1;
};

//operator '-'
const RealVariable RealVariable::operator-(double x) const
{
    return RealVariable();
};
const RealVariable operator-(const RealVariable &real1, const RealVariable &real2)
{
    return real1;
};
const RealVariable operator-(double x, const RealVariable &real1)
{
    return real1;
};

//operator '/'
const RealVariable RealVariable::operator/(double x) const
{
    return RealVariable();
};
const RealVariable operator/(const RealVariable &real1, const RealVariable &real2)
{
    return real1;
};
const RealVariable operator/(double x, const RealVariable &real1)
{
    return real1;
};



//------------Complex--------------//
//operator '*'
const ComplexVariable ComplexVariable::operator*(double x) const
{
    return ComplexVariable();
};
const ComplexVariable operator*(const ComplexVariable &real1, const ComplexVariable &real2)
{
    return real1;
};
const ComplexVariable operator*(double x, const ComplexVariable &real1)
{
    return real1;
};

//operator '=='
const ComplexVariable ComplexVariable::operator==(double x) const
{
    return ComplexVariable();
};
const ComplexVariable operator==(const ComplexVariable &real1, const ComplexVariable &real2)
{
    return real1;
};
const ComplexVariable operator==(double x, const ComplexVariable &real1)
{
    return real1;
};

//operator '^'
const ComplexVariable ComplexVariable::operator^(double x) const
{
    return ComplexVariable();
};
const ComplexVariable operator^(const ComplexVariable &real1, const ComplexVariable &real2)
{
    return real1;
};
const ComplexVariable operator^(double x, const ComplexVariable &real1)
{
    return real1;
};

//operator '+'
const ComplexVariable ComplexVariable::operator+(double x) const
{
    return ComplexVariable();
};
const ComplexVariable operator+(const ComplexVariable &real1, const ComplexVariable &real2)
{
    return real1;
};
const ComplexVariable operator+(double x, const ComplexVariable &real1)
{
    return real1;
};

//operator '-'
const ComplexVariable ComplexVariable::operator-(double x) const
{
    return ComplexVariable();
};
const ComplexVariable operator-(const ComplexVariable &real1, const ComplexVariable &real2)
{
    return real1;
};
const ComplexVariable operator-(double x, const ComplexVariable &real1)
{
    return real1;
};

//operator '/'
const ComplexVariable ComplexVariable::operator/(double x) const
{
    return ComplexVariable();
};
const ComplexVariable operator/(const ComplexVariable &real1, const ComplexVariable &real2)
{
    return real1;
};
const ComplexVariable operator/(double x, const ComplexVariable &real1)
{
    return real1;
};



}; // namespace solver
