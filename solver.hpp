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
    RealVariable(): coef_2(0), coef_1(1), coef_0(0) {}; //default constructor                          
    RealVariable(double c2, double c1, double c0): coef_2(c2), coef_1(c1), coef_0(c0) {}
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
    friend RealVariable &operator+(RealVariable &real1,double x);
    friend RealVariable &operator+(double x, RealVariable &real);
    friend RealVariable &operator+(RealVariable &real1, RealVariable &real2);

    //operator '/'
    friend RealVariable &operator/(RealVariable &real, double x);
    void toString();
    void copy(RealVariable &r1);
};
double solve(RealVariable &r1);

}; // namespace solver