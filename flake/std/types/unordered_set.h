#pragma once

#include <unordered_set>

namespace fl {
    template <class V, class... A>
    using uset_t = std::unordered_set<V, A...>;
}