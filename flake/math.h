#pragma once

#include <flake/types.h>
#include <flake/vec2.h>

namespace fl::math {
    namespace constants {
        const constexpr float32_t e = 2.71828182846f;

        const constexpr float32_t pi = 3.14159265359f;
        const constexpr float32_t half_pi = pi * .5f;
        const constexpr float32_t double_pi = pi * 2.f;
        
        const constexpr float32_t sqrt_2 = 1.41421356237f;
        const constexpr float32_t half_sqrt_2 = sqrt_2 * .5f;
        const constexpr float32_t inv_sqrt_2 = half_sqrt_2;

        const constexpr float32_t sqrt_3 = 1.73205080757f;
    }

    int32_t random_i32(int32_t, int32_t);
    int64_t random_i64(int64_t, int64_t);
    float32_t random_f32(float32_t, float32_t);
    bool_t random_chance(float32_t);

    int32_t mod(int32_t, int32_t);
    float32_t map_value(float32_t, float32_t, float32_t, float32_t, float32_t);
    vec2f_t normalize(const vec2f_t&);
    float32_t q_rsqrt(float32_t);
    float32_t radians(float32_t);
    float32_t degrees(float32_t);
    
    vec2f_t gravitational_acceleration(vec2f_t, vec2f_t, float32_t);
    vec2f_t gravitational_pull(vec2f_t, float32_t, vec2f_t, float32_t);

    template <class T>
    T min(const vec2_t<T>& a) {
        return a.x < a.y ? a.x : a.y;
    }

    template <class T>
    T max(const vec2_t<T>& a) {
        return a.x > a.y ? a.x : a.y;
    }

    template <class T>
    T scalar(const vec2_t<T>& a, const vec2_t<T>& b) {
        return a.x * b.x + a.y * b.y;
    }

    template <class T>
    float32_t manhattan(const vec2_t<T>& v) {
        const auto abs_v = abs(v);

        return abs_v.x + abs_v.y;
    }

    template <class T>
    float32_t magnitude(const vec2_t<T>& v) {
        return sqrt(scalar(v, v));
    }

    template <class T>
    float32_t distance(const vec2_t<T>& a, const vec2_t<T>& b) {
        return magnitude(b - a);
    }

    template <class T>
    vec2f_t direction(const vec2_t<T>& a, const vec2_t<T>& b) {
        return normalize((vec2f_t)(b - a));
    }

    template <class T>
    T lerp(T a, T b, float32_t v) {
        return a + (b - a) * v;
    }

    template <class T>
    vec2_t<T> lerp(const vec2_t<T>& a, const vec2_t<T>& b, float32_t v) {
        return vec2_t <T> (lerp(a.x, b.x, v), lerp(a.y, b.y, v));
    }

    template <class T>
    vec2_t<T> sqrt(const vec2_t<T>& a) {
        return vec2_t <T> (sqrt(a.x), sqrt(a.y));
    }

    template <class T>
    vec2_t<T> swap(const vec2_t<T>& a) {
        return vec2_t <T> (a.y, a.x);
    }

    template <class T>
    vec2_t<T> rot_90(const vec2_t<T>& a) {
        return vec2_t <T> (-a.y, a.x);
    }

    template <class T>
    vec2_t<T> rot_180(const vec2_t<T>& a) {
        return vec2_t <T> (-a.x, -a.y);
    }

    template <class T>
    vec2_t<T> rot_270(const vec2_t<T>& a) {
        return vec2_t <T> (a.y, -a.x);
    }

    template <class T>
    vec2_t<T> rotate(const vec2_t<T>& a, float32_t angle) {
        const auto c = cos(angle);
        const auto s = sin(angle);

        return vec2_t <T> (a.x * c - a.y * s, a.x * s + a.y * c);
    }

    template <class T>
    vec2_t<T> bisector(const vec2_t<T>& a, const vec2_t<T>& b) {
        return normalize(a + b);
    }

    template <class T>
    T dot(const vec2_t<T>& a, const vec2_t<T>& b) {
        return a.x * b.x + a.y * b.y;
    }

    template <class T>
    vec2_t<T> abs(const vec2_t<T>& a) {
        return vec2_t <T> (std::abs(a.x), std::abs(a.y));
    }

    template <class T>
    vec2_t<T> signs(const vec2_t<T>& a) {
        return vec2_t <T> (a.x > 0 ? 1 : -1, a.y > 0 ? 1 : -1);
    }

    template <class T>
    T clamp(T v, T a, T b) {
        return v < a ? a : v > b ? b : v;
    }

    template <class T>
    bool_t in_bounds(T a, const vec2_t<T>& b) {
        return a >= b.x && a <= b.y;
    }
}
