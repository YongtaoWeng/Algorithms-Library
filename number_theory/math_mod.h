// Created by Yongtao Weng on 2025/7/8.
#ifndef MATH_MOD_H
#define MATH_MOD_H

#include <stdexcept>
#include <type_traits> // 用于 std::is_integral

/**
 * @brief Computes the modular reduction of a with respect to b, ensuring a non-negative result.
 * Should satisfy a = qb +r, 0<=r<|b|
 * @tparam Int Integer type.
 * @param a The dividend.
 * @param b The modulus (divisor).
 * @return Int The value a mod b, in the range [0, |b|).
 * @throws std::invalid_argument If b is zero.
 *
 * @note Uses static_assert to ensure Int is an integral type.
 */
template<typename Int>
Int math_mod (const Int a, Int b) {
    static_assert(std::is_integral_v<Int>,
                  "math_mod: Int must be integer!");
    if (b == 0)
        throw std::invalid_argument
                ("math_mod: Modulus cannot be zero!");
    if (b < 0)
        b = -b;
    const Int remainder = a % b;
    // 确保余数非负，调整为 [0, |b|) 范围
    return remainder >= 0 ? remainder : remainder + b;
}

#endif // MATH_MOD_H
