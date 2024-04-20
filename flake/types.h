#pragma once

#include <cstdint>
#include <array>
#include <functional>

namespace fl {
    typedef uint64_t mask64_t;
    typedef uint32_t mask32_t;
    typedef uint16_t mask16_t;
    typedef uint8_t mask8_t;

    typedef float float32_t;
    typedef double float64_t;

    typedef bool bool_t;

    typedef void* ptr_t;

    typedef void async;

    typedef std::string str_t;

    template <class T>
    using fn_t = std::function <T>;

    template <class T, size_t U>
    using arr_t = std::array<T, U>;

    template <class T>
    using arr2_t = std::array<T, 2>;

    template <class T>
    using arr3_t = std::array<T, 3>;

    template <class T>
    using arr4_t = std::array<T, 4>;
}
