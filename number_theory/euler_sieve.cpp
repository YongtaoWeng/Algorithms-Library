// Created by Yongtao Weng on 2025/7/9.
#include "number_theory.h"
#include <cmath>

/**
 * @brief Calculates the number of prime numbers up to n using the Euler Sieve algorithm.
 *
 * This function identifies all prime numbers from 2 to n and returns their count.
 *
 * @param n The upper bound for finding prime numbers (inclusive).
 * @return The count of prime numbers found up to n.
 * @note
 * Core principle: Each composite number is sieved exactly once by its smallest prime factor.
 * n=1E9 need 9.1 seconds
 */
int euler_sieve (const int n) {
    if (n <= 1) return 0;
    bool *const is_compound = new bool[n + 1]();

    //Estimate prime count using n/ln(n) with a 1.2 factor for safety
    int *const primes = new int[static_cast<int>(n / std::log(n) * 1.2)];
    int primes_index = 0;
    for (int i = 2; i <= n; ++i) {
        if (!is_compound[i]) {
            primes[primes_index++] = i;
        }
        for (int j = 0; j != primes_index; ++j) {
            const int compound = primes[j] * i;
            if (compound > n) break;
            is_compound[compound] = true;
            // Ensures each composite is sieved by its smallest prime factor
            if (i % primes[j] == 0) break;
        }
    }
    delete[] is_compound;
    delete[] primes;
    return primes_index;
}

/**
 * @brief Calculates the number of prime numbers up to n using the Euler Sieve algorithm.
 *
 * This function identifies all prime numbers from 2 to n and returns their count.
 *
 * @param n The upper bound for finding prime numbers (inclusive).
 * @return The count of prime numbers found up to n.
 * @note
 * Core principle: Each composite number is sieved exactly once by its smallest prime factor.
 * n=1E9 need 5.3 seconds
 * This algorithm only sieves odd numbers to improve efficiency.
 */
int euler_sieve_enhanced (const int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;

    bool *const is_compound = new bool[n + 1]();

    //Estimate prime count using n/ln(n) with a 1.2 factor for safety
    int *const primes = new int[static_cast<int>(1.2 * n / 3 / std::log(n / 3 + 1))];
    int primes_index = 0;
    int i;
    for (i = 3; i <= n / 3; i += 2) {
        if (!is_compound[i]) {
            primes[primes_index++] = i;
        }
        for (int j = 0; j != primes_index; ++j) {
            const int compound = primes[j] * i;
            if (compound > n) break;
            is_compound[compound] = true;
            // Ensures each composite is sieved by its smallest prime factor
            if (i % primes[j] == 0) break;
        }
    }
    for (; i <= n; i += 2) {
        if (!is_compound[i]) {
            ++primes_index;
        }
    }
    delete[] is_compound;
    delete[] primes;

    // add number 2 to the count
    return primes_index + 1;
}

/*
    assert(euler_sieve(1) == 0);
    assert(euler_sieve(2) == 1);
    assert(euler_sieve(3) == 2);
    assert(euler_sieve(4) == 2);
    assert(euler_sieve(5) == 3);
    assert(euler_sieve(6) == 3);
    assert(euler_sieve(7) == 4);
    assert(euler_sieve(8) == 4);
    assert(euler_sieve(9) == 4);
    assert(euler_sieve(10) == 4);

    assert(euler_sieve(1E3) == 168);
    assert(euler_sieve(1E4) == 1229);
    assert(euler_sieve(1E5) == 9592);
    assert(euler_sieve(1E6) == 78498);
    assert(euler_sieve(1E7) == 664579);
    assert(euler_sieve(1E8) == 5761455);
    assert(euler_sieve(1E9) == 50847534);
    //assert(euler_sieve(1E10) == 455052512);
 */
