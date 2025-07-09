// Created by Yongtao Weng on 2025/7/7.

#ifndef NUMBER_THEORY_H
#define NUMBER_THEORY_H
#include <cstdint>
#include "gcd_lcm.h"
#include "math_mod.h"

uint64_t fast_modular_pow (uint64_t a, uint64_t b, uint64_t m);

int euler_sieve (int n);

int euler_sieve_enhanced (int n);

#endif //NUMBER_THEORY_H
