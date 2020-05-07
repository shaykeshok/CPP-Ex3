#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "solver.hpp"
#include <stdio.h>
using namespace std;

namespace solver
{

//-----------shared-------------//
double solve(RealVariable &r1)
{
    // cout<<"\nsolve: " << endl;
    // r1.toString();
    double a = r1.coef_2;
    double b = r1.coef_1;
    double c = r1.coef_0;
    double ans;

    if (a != 0) // if coef_2 of x^2 is 0 the division by 0 in the roots furmula is invalid
    {

        ans = pow(b, 2) - 4 * a * c; //b^2-4ac
        if (ans < 0)
        {
            throw runtime_error("There is no real solution!");
        }
        ans = sqrt(ans);                    //sqrt(b^2-4ac)
        if (((b * -1) - ans > 0) / (2 * a)) //(-b - sqrt(b^2-4ac))/2a
            ans = ((b * -1) - ans) / (2 * a);
        else if (((b * -1) + ans > 0) / (2 * a)) //(-b + sqrt(b^2-4ac))/2a
            ans = ((b * -1) + ans) / (2 * a);
        else
            throw runtime_error("There is no real solution to this function");
    }
    else if (b != 0)
    {
        ans = (c * -1) / b;
    }
    else
    {
        throw runtime_error("Error!");
    }
    return ans;
};

void RealVariable::toString()
{
    cout << "a: " << this->coef_2 << endl;
    cout << "b: " << this->coef_1 << endl;
    cout << "c: " << this->coef_0 << endl;
}

void RealVariable::copy(RealVariable &real1)
{
    this->coef_2 = real1.coef_2;
    this->coef_1 = real1.coef_1;
    this->coef_0 = real1.coef_0;
}
RealVariable &operator-(RealVariable &real1, double x)
{

    /*   real1.coef_0 -= x;
    return real1; */
    // cout << "\noperator-" << endl;
    // real1.toString();
    double c = real1.coef_0;
    double b = real1.coef_1;
    double a = real1.coef_2;
    RealVariable *temp = new RealVariable(a, b, c);
    temp->coef_0 -= x;
    return *temp;
};
RealVariable &operator-(RealVariable &real1, RealVariable &real2)
{
    // cout << "\noperator-" << endl;
    // real1.toString();
    double c = real1.coef_0;
    double b = real1.coef_1;
    double a = real1.coef_2;
    RealVariable *temp = new RealVariable(a, b, c);
    temp->coef_0 -= real2.coef_0;
    temp->coef_1 -= real2.coef_1;
    temp->coef_2 -= real2.coef_2;
    return *temp;
};
//-------------------------------------------------------------------------------------operator '*'
// const RealVariable RealVariable::operator*(double x) const
// {
//     return RealVariable();
// };
// const RealVariable operator*(const RealVariable &real1, const RealVariable &real2)
// {
//     return real1;
// };
RealVariable &operator*(double x, RealVariable &real1)
{
    /*  real1.coef_2 *= x;
    real1.coef_1 *= x;
    real1.coef_0 *= x;
    return real1; */
    //RealVariable temp;
    // cout << "\noperator*" << endl;
    // real1.toString();
    RealVariable *temp = new RealVariable();

    temp->copy(real1);
    temp->coef_2 *= x;
    temp->coef_1 *= x;
    temp->coef_0 *= x;
    // cout << "\noperator*     After:" << endl;
    // temp->toString();
    return *temp;
};

RealVariable &operator/(RealVariable &real1, double x)
{
    /*  real1.coef_2 /= x;
    real1.coef_1 /= x;
    real1.coef_0 /= x;
    return real1; */
    //RealVariable temp;
    // cout << "\noperator/" << endl;
    // real1.toString();
    RealVariable *temp = new RealVariable();
    temp->copy(real1);
    temp->coef_2 /= x;
    temp->coef_1 /= x;
    temp->coef_0 /= x;
    // cout << "\noperator/     After:" << endl;
    // temp->toString();
    return *temp;
};

RealVariable &operator==(RealVariable &real1, double x)
{
    /*  real1.coef_0 -= x;
    return real1; */
    // cout << "\noperator==" << endl;
    // real1.toString();
    double c = real1.coef_0;
    double b = real1.coef_1;
    double a = real1.coef_2;

    RealVariable *temp = new RealVariable(a, b, c);
    //RealVariable temp(a, b, c);
    temp->coef_0 -= x;
    return *temp;
};

RealVariable &operator==(RealVariable &real1, RealVariable &real2)
{
    // cout << "\noperator==" << endl;
    // cout << "real1:" << endl;
    // real1.toString();
    // cout << "real2:" << endl;
    // real2.toString();
    double c = real1.coef_0;
    double b = real1.coef_1;
    double a = real1.coef_2;

    RealVariable *temp = new RealVariable(a, b, c);
    temp->coef_0 -= real2.coef_0;
    temp->coef_1 -= real2.coef_1;
    temp->coef_2 -= real2.coef_2;
    return *temp;
}

RealVariable &operator^(double x, RealVariable &real1)
{
    return real1;
};

RealVariable &operator^(RealVariable &real1, double x)
{
    // cout << "\noperator^" << endl;
    // real1.toString();
    if (x > 2)
    {
        throw runtime_error("ERROR: Not Second-degree equation");
    }
    // cout << "operator^" << endl;
    double a = real1.coef_2;
    double b = real1.coef_1;
    double c = real1.coef_0;

    RealVariable *temp = new RealVariable(a, b, c);

    if (temp->coef_2 != 0)
    {
        throw runtime_error("ERROR: Not Second-degree equation");
    }
    else
    {
        temp->coef_2 = pow(b, 2);
        temp->coef_1 = 2 * b * c;
        temp->coef_0 = pow(c, 2);
    }
    // cout << "\noperator^    After:" << endl;
    // temp->toString();
    return *temp;
};

RealVariable &operator+(double x, RealVariable &real1)
{
    // cout << "\noperator+" << endl;
    // real1.toString();
    double c = real1.coef_0;
    double b = real1.coef_1;
    double a = real1.coef_2;
    RealVariable *temp = new RealVariable(a, b, c);
    temp->coef_0 += x;
    // cout << "\noperator+    After:" << endl;
    // temp->toString();
    return *temp;
}

RealVariable &operator+(RealVariable &real1, double x)
{
    // cout << "\noperator+" << endl;
    // cout << "RealVariable &real1, double x" << endl;
    // real1.toString();
    // double c = real1.coef_0;
    // double b = real1.coef_1;
    // double a = real1.coef_2;
    // RealVariable *temp = new RealVariable(a, b, c);
    // temp->coef_0 += x;
    // return *temp;
    return x + real1;
}

RealVariable &operator+(RealVariable &real1, RealVariable &real2)
{
    // cout << "\noperator+" << endl;
    // cout << "real1:" << endl;
    // real1.toString();
    // cout << "real2:" << endl;
    // real2.toString();
    double c = real1.coef_0;
    double b = real1.coef_1;
    double a = real1.coef_2;
    RealVariable *temp = new RealVariable(a, b, c);
    temp->coef_0 += real2.coef_0;
    temp->coef_1 += real2.coef_1;
    temp->coef_2 += real2.coef_2;
    // cout << "\noperator+     After:" << endl;
    // temp->toString();
    return *temp;
}

}; // namespace solver
