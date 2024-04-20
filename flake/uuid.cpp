#include <flake/uuid.h>
#include <flake/math.h>
#include <flake/limits.h>

uint64_t fl::uuid::generate() {
    return math::random_i64(limits::u64_min, limits::u64_max);
}