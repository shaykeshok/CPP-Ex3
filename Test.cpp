#include "doctest.h"
#include "solver.hpp"
using namespace std;

TEST_CASE("Complex")
{

    solver::ComplexVariable c, x, y, z;
    CHECK(solve(2 * y + 5i == 23) == (11.5, -2.5));
    // CHECK(solve(y + 5i == x + 3i));
    // CHECK(solve(x - x + x == y));
    CHECK(solve(2 * y + 5i == 23) == (11.5, -2.5));
    CHECK(solve(4 * y + 8i == 4i + 12.0 + y * 2) == (6.0, -2.0));
    CHECK(solve(2 * y + 5i == 3 * y + 5i) == (0.0, 0.0));
    // CHECK(solve(y - x + 12i == 0));
    // CHECK(solve(2 + z * x + 7 * x + 5i - 12 == -8 * x + 3));
    // CHECK(solve((x / 3) == y / 3));
    // CHECK(solve(x / z == -8));
    // CHECK(solve(x + 5i + x + 5i == x / 10 + 5i));
    // CHECK(solve(2 * x + 9i == 1));
    // CHECK(solve(4 - x == 0));
    CHECK_THROWS(solve(x + 2i == 0));
    CHECK_THROWS(solve(x / x + 1i == 2));
    CHECK_THROWS(solve(8 + x / (8 - 8) == 1));
    CHECK_THROWS(solve((z ^ 5)));
    CHECK_THROWS(solve((z ^ 4)));
    CHECK_THROWS(solve((z ^ 3)));
    CHECK_THROWS(solve((z ^ 2)));
    CHECK_THROWS(solve((z ^ 1)));
    CHECK_THROWS(solve((z ^ 0)));
    CHECK_THROWS(solve(x + 2i == 5));

    // 17
    CHECK(solve(x + 2 == 4) == std::complex<double>(2, 0));
    CHECK(solve(x * 2 + x * 5 == 7) == std::complex<double>(1, 0));

    CHECK((solve((c ^ 2) == 4) == complex<double>(2.0, 0.0) || solve((c ^ 2) == 16) == complex<double>(-2.0, 0.0)));
    CHECK((solve((c ^ 2) == -25) == complex<double>(0.0, 5.0) || solve((c ^ 2) == -16) == complex<double>(0.0, -5.0)));

    CHECK_FALSE(solve(2 * c + 4 == 3 * c + 2i) == complex<double>(4.0, 2.0));
    CHECK_FALSE(solve(c + 3i == 2i) == complex<double>(3.0, -1.0));
    CHECK(solve(4 * c - c + c == 0) == complex<double>(0.0, 0.0));
    CHECK((solve(c * c + 4i == 5i) == complex<double>(0.0, 1.0) || solve(c * c + 4i == 5i) == complex<double>(0.0, -1.0)));
    CHECK(solve(c + 3i == 2i) == complex<double>(0.0, -1.0));
    CHECK((solve(c * c + 4i == 20i) == complex<double>(0.0, 4.0) || solve(c * c + 4i == 5i) == complex<double>(0.0, -4.0)));
    CHECK(solve(2 * c + 2i == 4 * c - 6) == complex<double>(3.0, 1.0));
    CHECK(solve(2 * c + 4i == 3 * c + 2i) == complex<double>(0.0, 2.0));
    // //10

    CHECK(solve(-3.5i + x == 2) == complex<double>(2, 3.5));
    CHECK(solve(3 == x - 1i) == complex<double>(3, 1));
    CHECK(solve(4i + 2.0 - x == 0) == 4i + 2.0);
    CHECK((solve(2 * (x ^ 2) + 2 * x + 13 == 0) == complex<double>(1 / 2, -5 / 2) || solve(2 * (x ^ 2) + 2 * x + 13 == 0) == complex<double>(-1 / 2, -5 / 2)));
    CHECK(solve(x * 2 - 2 == 2i) == complex<double>(1, 1));
    CHECK((solve(-1 * (x ^ 2) + 6 * x - 10 == 0) == complex<double>(-3, 1) || solve(-1 * (x ^ 2) + 6 * x - 10 == 0) == complex<double>(3, 1)));
    CHECK_THROWS(solve(0 * x == 1));
    CHECK_THROWS(solve(x * 0 == 1));
    CHECK_THROWS(solve(x * 0 + 0 == 1));
    CHECK_THROWS(solve(x + x + x + (x ^ -3) == 3));
    CHECK(solve(x * 3 - 2 + x * 5 + 4 == 3i - 2i + 5i) == complex<double>(-1 / 4, 3 / 4));
    CHECK(solve(x + 3i == 1) == complex<double>(1, -3));

    // //10

    CHECK((solve((x ^ 2) + 14 * x + 49 == 0) == double(-7)));
    CHECK((solve((x ^ 2) == -64) == complex<double>(0, 8) || solve((x ^ 2) == -64) == complex<double>(0, -8)));
    CHECK((solve(x + x - x - 4 == 10) == double(14)));
}
TEST_CASE("Real")
{

    solver::RealVariable x;
    CHECK(solve(x + 5 == 9) == 4);
    CHECK(solve(x - 5 == 10) == 15);
    CHECK(solve(3 * x - 3 * -7 == 8 * x));
    CHECK(solve((1 / 3) * x + (1 / 4) * x == 1));
    CHECK(solve((1 / 2) * x + (1 / 2) * x == x));
    CHECK(solve(2 * x == -10));
    CHECK(solve(10 * x == -60));
    CHECK(solve(5 * x + x == 45 - 3));
    CHECK(solve(-13 * x + 16 * x + x == -4 - 8 + 44));
    CHECK(solve(-2 * x + 7 * x - 5 * x == 24 - 7));
    CHECK(solve((x ^ 2) == 16));
    CHECK(solve((x ^ 2) / 4 + (2 / x) == 0));

    CHECK_THROWS(solve((x ^ 3)));
    CHECK_THROWS(solve((x ^ 2) / (x ^ 2) == -1));
    CHECK_THROWS(solve((x ^ 3) + (x ^ 4) + (x ^ 5)));

    //15

    CHECK_THROWS(solve(x / 0));
    CHECK_THROWS(solve((x ^ 2) == -16));
    CHECK(solve(10 + 10 - x == 20) == 0);
    CHECK(solve((x + x) / 5 == 1) == 2.5);
    CHECK((solve(((x + x) ^ 2) == 25) == 2.5 || solve(((x + x) ^ 2) == 25) == -2.5));
    CHECK(solve(x + x == 4) == solve(2 * x == 4));
    // CHECK_FALSE(solve(20 * x == 20) == solve(20 * x == -20));
    CHECK(solve(x / x == 1) == 1);
    CHECK(solve(2 * x + 2 == 18) == 8);
    CHECK(solve(3 * x + 2 + 6 == 20) == 4);
    CHECK(solve(2 * x + 2 == 18) == 8);
    CHECK((solve((x ^ 2) + 2 == 18) == 4 || solve((x ^ 2) + 2 == 18) == -4));
    CHECK(solve(10 * x == 100) == 10);
    CHECK(solve(2 * x / 2 == 29) == 29);
    CHECK(solve(8 * x + 8 == 9) == 1);
    CHECK(solve(8 * x + 8 == 9) == 1);
    CHECK(solve(10 * x + 2 == 102) == 10);
    CHECK(solve(10 * x == 100) == 10);
    CHECK(solve(2 * x / 2 == 29) == 29);
    CHECK(solve(8 * x + 8 == 9) == 1);
    CHECK(solve(10 * x + 2 == 102) == 10);
    CHECK(solve(10 * x == 100) == 10);
    CHECK(solve(2 * x / 2 == 29) == 29);
    CHECK(solve(8 * x + 8 == 9) == 1);

    CHECK(solve(10 * x == 100) == 10);
    CHECK(solve(8 * x + 8 == 9) == 1);
    CHECK(solve(10 * x + 2 == 102) == 10);

    CHECK(solve(10 * x == 100) == 10);
    CHECK(solve(2 * x / 2 == 29) == 29);
    CHECK(solve(10 * x + 2 == 102) == 10);

    CHECK(solve(2 * x / 2 == 29) == 29);
    CHECK(solve(8 * x + 8 == 9) == 1);
    CHECK(solve(2 * x / 2 == 29) == 29);

    //33

    CHECK(solve(7 * x + 11 - x == 10 + 7) == 1);
    CHECK(solve(49 * x == 343) == 7);
    CHECK(solve((x ^ 2) == 81) == 9);
    CHECK((solve((x ^ 2) - 9 * x + 8 == 0) == 8 || solve((x ^ 2) - 9 * x + 8 == 0) == 1));
    CHECK_THROWS(solve(0 * x == 17778915));
    CHECK(solve((x ^ 2) == 196) == 14);
    CHECK((solve((x ^ 2) == 64) == 8 || solve((x ^ 2) == 64) == -8));
    CHECK(solve((x ^ 2) == 196) == 14);
    CHECK(solve((x ^ 2) == 196) != 13);
    CHECK(solve((x ^ 2) == 196) != 12);
    CHECK(solve((x ^ 2) == 196) != 1115);
    CHECK(solve((x ^ 2) == 1) != 0);
    //12
};