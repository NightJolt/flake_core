#include <flake/math.h>

#include <random>

namespace {
    std::random_device random_device;
    std::mt19937 engine32(random_device());
    std::mt19937_64 engine64(random_device());
    std::uniform_int_distribution <int32_t> uniform_int32_distribution;
    std::uniform_int_distribution <int64_t> uniform_int64_distribution;
    std::uniform_real_distribution <fl::float32_t> uniform_float32_distribution;
}

int32_t fl::math::random_i32(int32_t a, int32_t b) {
    return uniform_int32_distribution(engine32, std::uniform_int_distribution<int32_t>::param_type(a, b));
}

int64_t fl::math::random_i64(int64_t a, int64_t b) {
    return uniform_int64_distribution(engine64, std::uniform_int_distribution<int64_t>::param_type(a, b));
}

fl::float32_t fl::math::random_f32(float32_t a, float32_t b) {
    return uniform_float32_distribution(engine32, std::uniform_real_distribution<float32_t>::param_type(a, b));
}

fl::bool_t fl::math::random_chance(float32_t chance) {
    return random_f32(0, 1) < chance;
}

int32_t fl::math::mod(int32_t a, int32_t m) {
    const int32_t r = a % m;

    return r >= 0 ? r : m + r;
}

fl::float32_t fl::math::map_value(float32_t n, float32_t a, float32_t b, float32_t c, float32_t d) {
    return (d - c) / (b - a) * (n - a) + c;
}

fl::vec2f_t fl::math::normalize(const vec2f_t& v) {
    const float32_t l = magnitude(v);

    return l ? v / l : v;
}

fl::float32_t fl::math::q_rsqrt(float32_t v) {
    float32_t y = v;
    long i = 0x5f3759df - ((*(long*)&y) >> 1);

    y = *(float32_t*)&i;

    return y * (1.5f - (y * y * v * .5f));
}

fl::float32_t fl::math::radians(float32_t degrees) {
    return degrees * 0.0174532f;
}

fl::float32_t fl::math::degrees(float32_t radians) {
    return radians * 57.295779f;
}

fl::vec2f_t fl::math::gravitational_acceleration(vec2f_t p1, vec2f_t p2, float32_t m2) {
    fl::vec2f_t segment = p2 - p1;

    return normalize(segment) * m2 / scalar(segment, segment);
}

fl::vec2f_t fl::math::gravitational_pull(vec2f_t p1, float32_t m1, vec2f_t p2, float32_t m2) {
    return gravitational_acceleration(p1, p2, m2) * m1;
}
