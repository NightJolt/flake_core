#pragma once

#include <flake/types.h>

namespace fl::uuid {
    typedef uint64_t uuid_t;

    uuid_t generate();
}