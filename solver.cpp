#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "solver.hpp"
#include <stdio.h>

using namespace std;

namespace solver
{

// double solve(RealVariable) { return 0; };
// std::complex<double> solve(ComplexVariable)
// {
//     std::complex<double> s = 0;
//     return s;
// };

// //operator '*'
// const RealVariable RealVariable::operator*(double x) const
// {
//     return RealVariable();
// };
// const RealVariable &operator*(RealVariable &real1, RealVariable &real2)
// {
//     return real1;
// };
// const RealVariable &operator*(double x, RealVariable &real1)
// {
//     return real1;
// };

// //operator '=='
// const RealVariable RealVariable::operator==(double x) const
// {
//     return RealVariable();
// };
// const RealVariable &operator==(RealVariable &real1, RealVariable &real2)
// {
//     return real1;
// };
// const RealVariable &operator==(double x, RealVariable &real1)
// {
//     return real1;
// };

// //operator '^'
// const RealVariable RealVariable::operator^(double x) const
// {
//     return RealVariable();
// };
// const RealVariable &operator^(RealVariable &real1, RealVariable &real2)
// {
//     return real1;
// };
// const RealVariable &operator^(double x, RealVariable &real1)
// {
//     return real1;
// };

// //operator '+'
// const RealVariable RealVariable::operator+(double x) const
// {
//     return RealVariable();
// };
// const RealVariable &operator+(RealVariable &real1, RealVariable &real2)
// {
//     return real1;
// };
// const RealVariable &operator+(double x, RealVariable &real1)
// {
//     return real1;
// };

// //operator '-'
// const RealVariable RealVariable::operator-(double x) const
// {
//     return RealVariable();
// };
// const RealVariable &operator-(RealVariable &real1, RealVariable &real2)
// {
//     return real1;
// };
// const RealVariable &operator-(double x, RealVariable &real1)
// {
//     return real1;
// };

double solve(const RealVariable& r1) {
		return 4.0;
	}
	complex<double> solve(const ComplexVariable& c1) {
		return 2i;
	}



	const RealVariable operator*(double other, const RealVariable& real) {//(         *          )
		return RealVariable(4.4);
	}
	const RealVariable RealVariable::operator*(double other) const {
		return RealVariable(4.4);
	}
	const RealVariable operator*(const RealVariable& real, const RealVariable& real2) {
		return RealVariable(4.4);
	}

	const RealVariable operator-(double other, const RealVariable& real) {// (         -          )
		return RealVariable(4.4);
	}
	const RealVariable RealVariable::operator-(double other) const {
		return RealVariable(4.4);
	}
	const RealVariable operator-(const RealVariable& real, const RealVariable& real2) {
		return RealVariable(4.4);
	}


	const RealVariable operator+(double other, const RealVariable& real) {// (       +       )
		return RealVariable(4.4);
	}
	const RealVariable RealVariable::operator+(double other) const {
		return RealVariable(4.4);
	}
	const RealVariable operator+(const RealVariable& real, const RealVariable& real2) {
		return RealVariable(4.4);
	}

	const RealVariable operator/(double other, const RealVariable& real) {// (      /      )
		return RealVariable(4.4);
	}
	const RealVariable RealVariable::operator/(double other) const {
		return RealVariable(4.4);
	}
	const RealVariable operator/(const RealVariable& real, const RealVariable& real2) {
		return RealVariable(4.4);
	}

	const RealVariable RealVariable::operator==(double other) const {// (         ==         )
		return RealVariable(4.4);
	}
	const RealVariable RealVariable::operator==(const RealVariable& real) const {
		return RealVariable(4.4);
	}
	const RealVariable operator==(double other, const RealVariable& real2) {
		return RealVariable(4.4);
	}

	const RealVariable RealVariable::operator^(double other) const { //  (             ^             )
		return RealVariable(4.4);
	}
}; // namespace solver
