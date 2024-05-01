#pragma once

#include <queue>

namespace fl {
    template <class V, class... A>
    using queue_t = std::queue<V, A...>;
}