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
std::complex<double> solve(ComplexVariable &c1)
{
    //c1.toString("solve");
    double a = c1.coef_2;
    double b = c1.coef_1;
    std::complex<double> c = c1.comp;
    std::complex<double> ans;

    if (a != 0) // if coef_2 of y^2 is 0 the division by 0 in the roots furmula is invalid
    {

        ans = pow(b, 2) - 4 * a * c; //b^2-4ac
        if (c.imag() != 0)
        {
            throw runtime_error("Can't perform sqrt to imaginary variable!");
        }
        ans = sqrt(ans); //sqrt(b^2-4ac)
        ans = (ans - b) / (2 * a);
    }
    else if (b != 0)
    {
        ans = (c * -1.0) / b;
    }
    else
    {
        throw runtime_error("Error!");
    }
    if (ans.imag() == 0)
    {
        ans.imag(0);
    }
    if (ans.real() == 0)
    {
        ans.real(0);
    }
    return ans;
};

//----------------------------------------------------------RealVariable--------------------------------------------------//

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
    double c = real1.coef_0;
    double b = real1.coef_1;
    double a = real1.coef_2;
    RealVariable *temp = new RealVariable(a, b, c);
    temp->coef_0 -= x;
    return *temp;
};

RealVariable &operator-(RealVariable &real1, RealVariable &real2)
{
    double c = real1.coef_0;
    double b = real1.coef_1;
    double a = real1.coef_2;
    RealVariable *temp = new RealVariable(a, b, c);
    temp->coef_0 -= real2.coef_0;
    temp->coef_1 -= real2.coef_1;
    temp->coef_2 -= real2.coef_2;
    return *temp;
};

RealVariable &operator*(double x, RealVariable &real1)
{

    RealVariable *temp = new RealVariable();

    temp->copy(real1);
    temp->coef_2 *= x;
    temp->coef_1 *= x;
    temp->coef_0 *= x;

    return *temp;
};

RealVariable &operator/(RealVariable &real1, double x)
{

    RealVariable *temp = new RealVariable();
    temp->copy(real1);
    temp->coef_2 /= x;
    temp->coef_1 /= x;
    temp->coef_0 /= x;

    return *temp;
};

RealVariable &operator==(RealVariable &real1, double x)
{
    double c = real1.coef_0;
    double b = real1.coef_1;
    double a = real1.coef_2;

    RealVariable *temp = new RealVariable(a, b, c);
    temp->coef_0 -= x;
    return *temp;
};

RealVariable &operator==(RealVariable &real1, RealVariable &real2)
{
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
    if (x > 2)
    {
        throw runtime_error("ERROR: Not Second-degree equation");
    }
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

    return *temp;
};

RealVariable &operator+(double x, RealVariable &real1)
{

    double c = real1.coef_0;
    double b = real1.coef_1;
    double a = real1.coef_2;
    RealVariable *temp = new RealVariable(a, b, c);
    temp->coef_0 += x;
    return *temp;
}

RealVariable &operator+(RealVariable &real1, double x)
{
    return x + real1;
}

RealVariable &operator+(RealVariable &real1, RealVariable &real2)
{
    double c = real1.coef_0;
    double b = real1.coef_1;
    double a = real1.coef_2;
    RealVariable *temp = new RealVariable(a, b, c);
    temp->coef_0 += real2.coef_0;
    temp->coef_1 += real2.coef_1;
    temp->coef_2 += real2.coef_2;
    return *temp;
}

//----------------------------------------------------------ComplexVariable--------------------------------------------------//
ComplexVariable &operator*(double x, ComplexVariable &complex)
{
    //complex.toString("operator*");
    double b = complex.coef_1;
    double a = complex.coef_2;
    std::complex<double> c = complex.comp;

    ComplexVariable *temp = new ComplexVariable(a, b);
    temp->coef_1 *= x;
    temp->coef_2 *= x;
    temp->comp *= x;
    //temp->toString("operator*    After:");

    return *temp;
}
ComplexVariable &operator*(ComplexVariable &complex, double x)
{

    //complex.toString("operator*");
    return x * complex;
}

ComplexVariable &operator/(ComplexVariable &complex, double num)
{
    double b = complex.coef_1;
    double a = complex.coef_2;
    std::complex<double> c = complex.comp;
    ComplexVariable *temp = new ComplexVariable(a, b, c);

    temp->coef_2 /= num;
    temp->coef_1 /= num;
    temp->comp /= num;

    return *temp;
}

ComplexVariable &operator-(ComplexVariable &comp, double x)
{
    // double b = comp.coef_1;
    // double a = comp.coef_2;
    // ComplexVariable *temp = new ComplexVariable(a, b);
    // temp->coef_0 -= x;
    // return *temp;
    //comp.toString("operator-");
    return comp + (-1) * x;
}

ComplexVariable &operator-(ComplexVariable &x, ComplexVariable &y)
{
    double b = x.coef_1;
    double a = x.coef_2;
    std::complex<double> c = x.comp;
    ComplexVariable *temp = new ComplexVariable(a, b, c);
    temp->coef_1 -= y.coef_1;
    temp->coef_2 -= y.coef_2;
    temp->comp -= y.comp;
    return *temp;
}
ComplexVariable &operator+(ComplexVariable &complex, double y)
{
    //complex.toString("operator+");

    double b = complex.coef_1;
    double a = complex.coef_2;
    std::complex<double> c = complex.comp;
    ComplexVariable *temp = new ComplexVariable(a, b, c);
    temp->comp += y;
    //temp->toString("operator+     After:");
    return *temp;
}
ComplexVariable &operator+(double y, ComplexVariable &complex)
{
    //complex.toString("operator+");
    return complex + y;
}
ComplexVariable &operator+(ComplexVariable &x, ComplexVariable &y)
{
    //x.toString("operator+");
    //y.toString("operator+");

    double b = x.coef_1;
    double a = x.coef_2;
    std::complex<double> c = x.comp;
    ComplexVariable *temp = new ComplexVariable(a, b, c);
    temp->coef_1 += y.coef_1;
    temp->coef_2 += y.coef_2;
    temp->comp += y.comp;
    //temp->toString("operator+     After:");
    return *temp;
}
ComplexVariable &operator+(ComplexVariable &x, complex<double> comp)
{
    double b = x.coef_1;
    double a = x.coef_2;
    std::complex<double> c = x.comp;
    ComplexVariable *temp = new ComplexVariable(a, b, c);
    temp->comp += comp;
    return *temp;
}
ComplexVariable &operator==(ComplexVariable &comp, double x)
{
    //comp.toString("operator==");

    return comp + (-1) * x;
}
ComplexVariable &operator==(ComplexVariable &x, ComplexVariable &y)
{
    double b = x.coef_1;
    double a = x.coef_2;
    std::complex<double> c = x.comp;
    ComplexVariable *temp = new ComplexVariable(a, b, c);
    temp->coef_1 -= y.coef_1;
    temp->coef_2 -= y.coef_2;
    temp->comp -= y.comp;
    return *temp;
}
ComplexVariable &operator^(ComplexVariable &complex, double x)
{
    if (x > 2)
    {
        throw runtime_error("ERROR: Not Second-degree equation");
    }

    double b = complex.coef_1;
    double a = complex.coef_2;
    std::complex<double> c = complex.comp;
    ComplexVariable *temp = new ComplexVariable(a, b, c);

    if (temp->coef_2 != 0)
    {
        throw runtime_error("ERROR: Not Second-degree equation");
    }
    else
    {
        temp->coef_2 = pow(b, 2);
        temp->coef_1 = 0;
        temp->comp *= temp->comp;
    }

    return *temp;
}
void ComplexVariable::toString(string msg)
{
    cout << "\n"
         << msg << endl;
    cout << "a: " << this->coef_2 << endl;
    cout << "b: " << this->coef_1 << endl;
    cout << "c: " << this->comp << endl;
}

}; // namespace solver
