#pragma once

#include <functional>

namespace fl {
    template <class T>
    using fn_t = std::function<T>;
}