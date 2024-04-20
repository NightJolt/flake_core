#pragma once

#include <cstddef>
#include <array>

namespace fl {
    template <class T, size_t U>
    using arr_t = std::array<T, U>;

    template <class T>
    using arr2_t = std::array<T, 2>;

    template <class T>
    using arr3_t = std::array<T, 3>;

    template <class T>
    using arr4_t = std::array<T, 4>;
}