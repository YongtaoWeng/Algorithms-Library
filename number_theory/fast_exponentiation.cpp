#include <stdexcept>
#include <cstdint> // 用于 uint64_t

/**
 * @brief 使用快速幂算法计算 (a^b) % m
 *
 * 该函数基于平方-乘法方法实现高效的模幂运算，时间复杂度为 O(log b)。
 *
 * @param a 底数（非负）
 * @param b 指数（非负）
 * @param m 模数（正数）
 * @return uint64_t 计算结果 (a^b) % m
 *
 * @note
 * 核心原理：
 * 1. (a * b) mod m = ((a mod m) * (b mod m)) mod m
 * 2. a^(2k) mod m = (a^k mod m)^2 mod m
 *
 * @warning
 * - 当 a 和 m 非常大时，中间乘法可能溢出。
 * - 确保 m 不接近 2^64 以避免中间计算溢出。
 *
 * @example
 * @code
 *   std::cout << fast_modular_pow(2, 10, 1000); // 输出 24
 * @endcode
 */
uint64_t fast_modular_pow(uint64_t a, uint64_t b, const uint64_t m) {
    // 输入验证
    if (m == 0) {
        throw std::invalid_argument("fast_modular_pow: m should be positive!");
    }
    if (a == 0 && b == 0) {
        throw std::invalid_argument("fast_modular_pow: 0^0 is undefined!");
    }

    // 先对 a 取模，减少中间结果的大小
    a %= m;
    if (a <= 1) {
        return a;
    }

    uint64_t result = 1;
    while (b > 0) {
        // 检查指数的最低位是否为 1
        if (b & 1) {
            result = (result * a) % m;
        }
        // 平方底数并取模
        a = (a * a) % m;
        // 右移指数，处理下一位
        b >>= 1;
    }

    return result;
}