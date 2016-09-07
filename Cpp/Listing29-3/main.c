#include <cassert>
#include <cstdlib>
#include <iostream>

/// Represent a rational number.
struct rational
{
    int numerator; ///< numerator gets the sign of the rational value
    int denominator; ///< denominator is always positive

    /// Reduce the numerator and denominator by their GCD.
    void reduce() {
        assert(denominator != 0);
        int div {gcd(numerator, denominator)};
        numerator = numerator / div;
        denominator = denominator / div;
    }
};

/// Compute the greatest common divisor of two integers, using Euclid’s algorithm.
int gcd(int n, int m)
{
    n = std::abs(n);
    while (m != 0) {
        int tmp{n % m};
        n = m;
        m = tmp;
    }
    return n;
}

int main()
{
    rational pi{};
    pi.numerator = 1420;
    pi.denominator = 452;
    pi.reduce();
    std::cout << "pi is approximately " << pi.numerator << "/" << pi.denominator << '\n';
}
