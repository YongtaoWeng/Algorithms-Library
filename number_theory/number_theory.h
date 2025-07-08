// Created by Yongtao Weng on 2025/7/7.

#ifndef NUMBER_THEORY_H
#define NUMBER_THEORY_H
#include <cstdint>

uint64_t fast_modular_pow (uint64_t a, uint64_t b, uint64_t m);

template<typename Int>
Int math_mod (Int a, Int b);

template<typename Int>
Int gcd (Int a, Int b);

template<typename Int>
Int gcd_extended (Int a, Int b, Int &s, Int &t);

#endif //NUMBER_THEORY_H
