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
    ~RealVariable()
    {
        delete (this);
    }


    //overloads operators:

    //operator '*'
    const RealVariable operator*(double x) const;                            //in the class: 'this' is exist
    friend const RealVariable operator*(double x, const RealVariable &real); //out the class: 'this' is not exist
    friend const RealVariable operator*(const RealVariable &real1,const RealVariable &real2); //out the class: 'this' is not exist


    //operator '=='
    const RealVariable operator==(double x) const;
    friend const RealVariable operator==(double x, const RealVariable &real);
    friend const RealVariable operator==(const RealVariable &real1,const RealVariable &real2);

    //operator '^'
    const RealVariable operator^(double x) const;
    friend const RealVariable operator^(double x, const RealVariable &real);
    friend const RealVariable operator^(const RealVariable &real1,const RealVariable &real2);

    //operator '-'
    const RealVariable operator-(double x) const;
    friend const RealVariable operator-(double x, const RealVariable &real);
    friend const RealVariable operator-(const RealVariable &real1,const RealVariable &real2);


    //operator '+'
    const RealVariable operator+(double x) const;
    friend const RealVariable operator+(double x, const RealVariable &real);
    friend const RealVariable operator+(const RealVariable &real1,const RealVariable &real2);

};

class ComplexVariable
{
};


double solve(RealVariable);
std::complex<double> solve(ComplexVariable);

}; // namespace solver