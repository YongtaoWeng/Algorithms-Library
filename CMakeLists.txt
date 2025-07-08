cmake_minimum_required(VERSION 3.21)
project(Algorithms_Library CXX)   # 指定为C++项目
set(CMAKE_CXX_STANDARD 17)           # 全局启用 C++14
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # 强制要求支持 C++14
set(CMAKE_CXX_EXTENSIONS OFF)  #禁用编译器特定的非标准扩展（如 GNU 扩展）
add_library(number_theory
        number_theory/number_theory.h
        number_theory/fast_exponentiation.cpp
        number_theory/gcd_lcm.h
        number_theory/math_mod.h
)
add_executable(draft draft.cpp)
target_link_libraries(draft PRIVATE number_theory)
