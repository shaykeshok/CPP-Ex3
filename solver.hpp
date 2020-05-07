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
    int x;


    //constructors:
    RealVariable(): coef_2(0), coef_1(1), coef_0(0) {}; //default constructor                          
    RealVariable(double c2, double c1, double c0): coef_2(c2), coef_1(c1), coef_0(c0) {}
    double getA(){
        return coef_2;
    }
     double getB(){
        return coef_1;
    }
     double getC(){
        return coef_0;
    }
    //overloads operators:

    //operator '*'
    // const RealVariable operator*(double x) const;
    friend RealVariable &operator*(double x, RealVariable &real);
    // friend RealVariable &operator*(RealVariable &real1, RealVariable &real2)
    // friend const RealVariable operator*(const RealVariable &real1, const RealVariable &real2);

    //operator '=='
    // const RealVariable operator==(double x) const;
    friend RealVariable &operator==(RealVariable &real, double x);
    friend RealVariable &operator==(RealVariable &real1, RealVariable &real2);
    // friend const RealVariable operator==(const RealVariable &real1, const RealVariable &real2);

        //operator '^'
    // const RealVariable operator^(double x) const;
    friend RealVariable &operator^(double x, RealVariable &real);
    friend RealVariable &operator^(RealVariable &real1, double x);
    // friend const RealVariable operator^(const RealVariable &real1, const RealVariable &real2);

    //operator '-'
    // const RealVariable operator-(double x) const;
    friend RealVariable &operator-(RealVariable &real, double x);
    friend RealVariable &operator-(RealVariable &real1, RealVariable &real2);


    //operator '+'
    // const RealVariable operator+(double x) const;
    friend RealVariable &operator+(RealVariable &real1,double x);
    friend RealVariable &operator+(double x, RealVariable &real);
    friend RealVariable &operator+(RealVariable &real1, RealVariable &real2);

    //operator '/'
    // const RealVariable operator/(double x) const;
    friend RealVariable &operator/(RealVariable &real, double x);
    // friend const RealVariable operator/(const RealVariable &real1, const RealVariable &real2);
    void toString();
    void copy(RealVariable &r1);
};
double solve(RealVariable &r1);

}; // namespace solver