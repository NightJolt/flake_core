#pragma once

#include <vector>

namespace fl {
    template <class V, class... A>
    using vec_t = std::vector<V, A...>;
}