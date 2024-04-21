#pragma once

#include <memory>

namespace fl {
    template <class T>
    using uptr_t = std::unique_ptr<T>;

    template <class T>
    using sptr_t = std::shared_ptr<T>;

    template <class T>
    using wptr_t = std::weak_ptr<T>;
}