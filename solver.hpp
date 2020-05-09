#include <iostream>
#include <stdexcept>
#include <complex>

using namespace std;

namespace solver
{

class RealVariable
{
public:
    double coef_2; //x^2
    double coef_1; //x^1
    double coef_0; //x^0

    //constructors:
    RealVariable() : coef_2(0), coef_1(1), coef_0(0){}; //default constructor
    RealVariable(double c2, double c1, double c0) : coef_2(c2), coef_1(c1), coef_0(c0) {}
    //overloads operators:

    //operator '*'
    friend RealVariable &operator*(double x, RealVariable &real);

    //operator '=='
    friend RealVariable &operator==(RealVariable &real, double x);
    friend RealVariable &operator==(RealVariable &real1, RealVariable &real2);

    //operator '^'
    friend RealVariable &operator^(double x, RealVariable &real);
    friend RealVariable &operator^(RealVariable &real1, double x);

    //operator '-'
    friend RealVariable &operator-(RealVariable &real, double x);
    friend RealVariable &operator-(RealVariable &real1, RealVariable &real2);

    //operator '+'
    friend RealVariable &operator+(RealVariable &real1, double x);
    friend RealVariable &operator+(double x, RealVariable &real);
    friend RealVariable &operator+(RealVariable &real1, RealVariable &real2);

    //operator '/'
    friend RealVariable &operator/(RealVariable &real, double x);
    void toString();
    void copy(RealVariable &r1);
};
double solve(RealVariable &r1);

class ComplexVariable
{

public:
    // complex<double> num;
    //a+bi
    double coef_1; //y^1
    double coef_2; //y^2
    complex<double> comp = 0. + 0i;

    ComplexVariable() : coef_2(0), coef_1(1){}; //default constructor
    ComplexVariable(double c2, double c1) : coef_2(c2), coef_1(c1) {}
    ComplexVariable(double c2, double c1, complex<double> c0) : coef_2(c2), coef_1(c1), comp(c0) {}

    //overloads operators:

    //operator '*'
    friend ComplexVariable &operator*(double num, ComplexVariable &x);

    //operator '=='
    friend ComplexVariable &operator==(ComplexVariable &x, double num);
    // friend ComplexVariable &operator==(double num, ComplexVariable &x);
    friend ComplexVariable &operator==(ComplexVariable &x, ComplexVariable &y);
    // friend ComplexVariable &operator==(ComplexVariable &x, complex<double> comp);
    // friend ComplexVariable &operator==(complex<double> comp, ComplexVariable &x);

    //operator '^'
    friend ComplexVariable &operator^(ComplexVariable &x, double num);

    //operator '-'
    friend ComplexVariable &operator-(ComplexVariable &x, double num);
    // friend ComplexVariable &operator-(double num, ComplexVariable &x);
    friend ComplexVariable &operator-(ComplexVariable &x, ComplexVariable &y);
    // friend ComplexVariable &operator-(complex<double> comp, ComplexVariable &x);
    // friend ComplexVariable &operator-(ComplexVariable &x, complex<double> comp);

    //operator '+'
    friend ComplexVariable &operator+(ComplexVariable &x, double num);
    friend ComplexVariable &operator+(double num, ComplexVariable &x);
    friend ComplexVariable &operator+(ComplexVariable &x, int num);
    friend ComplexVariable &operator+(int num, ComplexVariable &x);

    friend ComplexVariable &operator+(ComplexVariable &x, ComplexVariable &y);
    friend ComplexVariable &operator+(ComplexVariable &x, complex<double> comp);
    // friend ComplexVariable &operator+(complex<double> comp, ComplexVariable &x);

    //operator '/'
    friend ComplexVariable &operator/(ComplexVariable &x, double num);
    void toString(string msg);
};

std::complex<double> solve(ComplexVariable &c1);

}; // namespace solver