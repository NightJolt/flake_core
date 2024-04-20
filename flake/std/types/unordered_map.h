#pragma once

#include <unordered_map>

namespace fl {
    template <class K, class V, class... A>
    using umap_t = std::unordered_map<K, V, A...>;
}