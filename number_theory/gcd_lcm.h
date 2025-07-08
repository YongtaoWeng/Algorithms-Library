// Created by Yongtao Weng on 2025/7/8.
#ifndef GCD_LCM_H
#define GCD_LCM_H

#include <stdexcept>
#include <type_traits> // 用于 std::is_integral
#include <cstdlib> // 用于 std::abs, std::div

/**
 * @brief Computes the Greatest Common Divisor (GCD) of two integers using the Euclidean algorithm.
 *
 * @tparam Int Integer type.
 * @param a First integer.
 * @param b Second integer.
 * @return Int The GCD of a and b (non-negative).
 * @throws std::invalid_argument If both a and b are zero.
 *
 * @note The function handles negative inputs by taking absolute values.
 * @note Uses static_assert to ensure Int is an integral type.
 */
template<typename Int>
Int gcd (Int a, Int b) {
    static_assert(std::is_integral_v<Int>,
                  "gcd: Int must be integer!");
    if (a == 0 && b == 0)
        throw std::invalid_argument
                ("gcd: a and b should not be both zeros!");
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        const Int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

/**
 * @brief Computes the GCD of two integers using the Extended Euclidean algorithm and finds coefficients s, t such that a*s + b*t = gcd(a,b).
 *
 * @tparam Int Signed integer type.
 * @param a First non-negative integer.
 * @param b Second non-negative integer.
 * @param s Reference to store coefficient s.
 * @param t Reference to store coefficient t.
 * @return Int The GCD of a and b (non-negative).
 * @throws std::invalid_argument
 * If both a and b are zero.
 * If a or b are negative.
 *
 * @note Uses static_assert to ensure Int is a signed integral type.
 * a*s + b*t = gcd(a,b)
 */
template<typename Int>
Int gcd_extended (Int a, Int b, Int &s, Int &t) {
    static_assert(std::is_signed_v<Int> && std::is_integral_v<Int>,
                  "gcd_extended: Int must be signed integer!");
    if (a == 0 && b == 0)
        throw std::invalid_argument
                ("gcd_extended: a and b should not be both zeros!");
    if (a < 0 || b < 0)
        throw std::invalid_argument
                ("gcd_extended: a and b should be non-negative!");

    // Initialize coefficients for Extended Euclidean algorithm
    Int s0 = 1, s1 = 0, t0 = 0, t1 = 1;
    while (b != 0) {
        // Compute quotient and remainder
        const auto [quotient, remainder] = std::div(a, b);
        a = b;
        b = remainder;

        // Update coefficients s and t
        const Int s2 = s0 - quotient * s1;
        s0 = s1;
        s1 = s2;
        const Int t2 = t0 - quotient * t1;
        t0 = t1;
        t1 = t2;
    }
    s = s0;
    t = t0;
    return a;
}

#endif // GCD_LCM_H
