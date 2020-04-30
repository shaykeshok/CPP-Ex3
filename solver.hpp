#include <iostream>
#include <stdexcept>
#include <complex>

using namespace std;

namespace solver
{

class RealVariable
{
private:
    double a;
    // double b;
    // double c;

public:
    RealVariable() = default; //{} //default constructor
                              // RealVariable(double a,double b,double c)
                              // {
                              //     this->a = a;
                              //     this->b = b;
                              //     this->c = c;
                              // }
    RealVariable(double a)
    {
        this->a = a;
    }
    // ~RealVariable()
    // {
    //     delete (this);
    // }

    //overloads operators:

    //operator '*'
    const RealVariable operator*(double x) const;
    friend const RealVariable operator*(double x, const RealVariable &real);
    friend const RealVariable operator*(const RealVariable &real1, const RealVariable &real2);

    //operator '=='
    const RealVariable operator==(double x) const;
    friend const RealVariable operator==(double x, const RealVariable &real);
    friend const RealVariable operator==(const RealVariable &real1, const RealVariable &real2);

    //operator '^'
    const RealVariable operator^(double x) const;
    friend const RealVariable operator^(double x, const RealVariable &real);
    friend const RealVariable operator^(const RealVariable &real1, const RealVariable &real2);

    //operator '-'
    const RealVariable operator-(double x) const;
    friend const RealVariable operator-(double x, const RealVariable &real);
    friend const RealVariable operator-(const RealVariable &real1, const RealVariable &real2);

    //operator '+'
    const RealVariable operator+(double x) const;
    friend const RealVariable operator+(double x, const RealVariable &real);
    friend const RealVariable operator+(const RealVariable &real1, const RealVariable &real2);

    //operator '/'
    const RealVariable operator/(double x) const;
    friend const RealVariable operator/(double x, const RealVariable &real);
    friend const RealVariable operator/(const RealVariable &real1, const RealVariable &real2);
};

class ComplexVariable
{

private:
    complex<double> num;

public:
    ComplexVariable() = default; //default constructor

    ComplexVariable(complex<double> x)
    {
        this->num = x;
    }
    // ~RealVariable()
    // {
    //     delete (this);
    // }

    //overloads operators:

    //operator '*'
    const ComplexVariable operator*(double x) const;
    friend const ComplexVariable operator*(double x, const ComplexVariable &real);
    friend const ComplexVariable operator*(const ComplexVariable &real1, const ComplexVariable &real2);

    //operator '=='
    const ComplexVariable operator==(double x) const;
    friend const ComplexVariable operator==(double x, const ComplexVariable &real);
    friend const ComplexVariable operator==(const ComplexVariable &real1, const ComplexVariable &real2);

    //operator '^'
    const ComplexVariable operator^(double x) const;
    friend const ComplexVariable operator^(double x, const ComplexVariable &real);
    friend const ComplexVariable operator^(const ComplexVariable &real1, const ComplexVariable &real2);

    //operator '-'
    const ComplexVariable operator-(double x) const;
    friend const ComplexVariable operator-(double x, const ComplexVariable &real);
    friend const ComplexVariable operator-(const ComplexVariable &real1, const ComplexVariable &real2);

    //operator '+'
    const ComplexVariable operator+(double x) const;
    friend const ComplexVariable operator+(double x, const ComplexVariable &real);
    friend const ComplexVariable operator+(const ComplexVariable &real1, const ComplexVariable &real2);

    //operator '/'
    const ComplexVariable operator/(double x) const;
    friend const ComplexVariable operator/(double x, const ComplexVariable &real);
    friend const ComplexVariable operator/(const ComplexVariable &real1, const ComplexVariable &real2);
};

double solve(const RealVariable &r1);
std::complex<double> solve(const ComplexVariable &c1);

}; // namespace solver