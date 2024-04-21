#pragma once

#include <flake/types.h>
#include <flake/std/types/unordered_map.h>

namespace fl {
    template <class T>
    struct vec2_t {
        T x, y;

        vec2_t();
        vec2_t(T);
        vec2_t(T, T);

        template <class U>
        vec2_t(const vec2_t<U>&);

        static const vec2_t<T> zero;
    };

    template <class T>
    const vec2_t<T> vec2_t<T>::zero = vec2_t<T>(0, 0);

    typedef vec2_t<int32_t> vec2i_t;
    typedef vec2_t<uint32_t> vec2u_t;
    typedef vec2_t<float32_t> vec2f_t;

    typedef vec2_t<int8_t> vec2i8_t;
    typedef vec2_t<int16_t> vec2i16_t;
    typedef vec2_t<int32_t> vec2i32_t;
    typedef vec2_t<int64_t> vec2i64_t;

    typedef vec2_t<uint8_t> vec2u8_t;
    typedef vec2_t<uint16_t> vec2u16_t;
    typedef vec2_t<uint32_t> vec2u32_t;
    typedef vec2_t<uint64_t> vec2u64_t;
}

namespace fl {
    template <class T>
    size_t hash(vec2_t<T> v) {
        return ((v.x + v.y) * (v.x + v.y + 1) >> 1) + v.x;
    };

    template <class K>
    struct vec2_hasher_t {
        size_t operator()(vec2_t<K> v) const {
            return hash(v);
        }
    };

    template <class K>
    struct vec2_comparer_t {
        bool operator()(vec2_t<K> a, vec2_t<K> b) const {
            return a.x == b.x && a.y == b.y;
        }
    };

    template <class K, class V>
    using umap_vec2_t = umap_t<
            vec2_t<K>,
            V,
            vec2_hasher_t<K>,
            vec2_comparer_t<K>
        >;
}

template <class T>
fl::vec2_t<T>::vec2_t() : x(0), y(0) {}

template <class T>
fl::vec2_t<T>::vec2_t(T x) : x(x), y(x) {}

template <class T>
fl::vec2_t<T>::vec2_t(T x, T y) : x(x), y(y) {}

template <class T>
template <class U>
fl::vec2_t<T>::vec2_t(const vec2_t<U>& vec2) : x((T)vec2.x), y((T)vec2.y) {}


template <typename T>
inline bool operator ==(const fl::vec2_t<T>& a, const fl::vec2_t<T>& b) {
    return a.x == b.x && a.y == b.y;
}

template <typename T>
inline bool operator !=(const fl::vec2_t<T>& a, const fl::vec2_t<T>& b) {
    return a.x != b.x || a.y != b.y;
}

template <typename T>
inline fl::vec2_t<T> operator *(const fl::vec2_t<T>& a, const fl::vec2_t<T>& b) {
    return vec2_t<T>(a.x * b.x, a.y * b.y);
}

template <typename T>
inline void operator *=(fl::vec2_t<T>& a, const fl::vec2_t<T>& b) {
    a = a * b;
}

template <typename T>
inline fl::vec2_t<T> operator *(const fl::vec2_t<T>& a, const T& b) {
    return fl::vec2_t<T>(a.x * b, a.y * b);
}

template <typename T>
inline void operator *=(fl::vec2_t<T>& a, const T& b) {
    a = a * b;
}

template <typename T>
inline fl::vec2_t<T> operator /(const fl::vec2_t<T>& a, const fl::vec2_t<T>& b) {
    return fl::vec2_t<T>(a.x / b.x, a.y / b.y);
}

template <typename T>
inline void operator /=(fl::vec2_t<T>& a, const fl::vec2_t<T>& b) {
    a = a / b;
}

template <typename T>
inline fl::vec2_t<T> operator /(const fl::vec2_t<T>& a, const T& b) {
    return fl::vec2_t <T> (a.x / b, a.y / b);
}

template <typename T>
inline void operator /=(fl::vec2_t<T>& a, const T& b) {
    a = a / b;
}

template <typename T>
inline fl::vec2_t<T> operator %(const fl::vec2_t<T>& a, const T& b) {
    return fl::vec2_t<T>(a.x % b, a.y % b);
}

template <typename T>
inline void operator %=(fl::vec2_t<T>& a, const T& b) {
    a = a % b;
}

template <typename T>
inline fl::vec2_t<T> operator +(const fl::vec2_t<T>& a, const fl::vec2_t<T>& b) {
    return fl::vec2_t<T>(a.x + b.x, a.y + b.y);
}

template <typename T>
inline void operator +=(fl::vec2_t<T>& a, const fl::vec2_t<T>& b) {
    a = a + b;
}

template <typename T>
inline fl::vec2_t<T> operator +(const fl::vec2_t<T>& a, const T& b) {
    return fl::vec2_t<T>(a.x + b, a.y + b);
}

template <typename T>
inline void operator +=(fl::vec2_t<T>& a, const T& b) {
    a = a + b;
}

template <typename T>
inline fl::vec2_t<T> operator -(const fl::vec2_t<T>& a, const fl::vec2_t<T>& b) {
    return fl::vec2_t<T>(a.x - b.x, a.y - b.y);
}

template <typename T>
inline void operator -=(fl::vec2_t<T>& a, const fl::vec2_t<T>& b) {
    a = a - b;
}

template <typename T>
inline fl::vec2_t<T> operator -(const fl::vec2_t<T>& a, const T& b) {
    return fl::vec2_t<T>(a.x - b, a.y - b);
}

template <typename T>
inline void operator -=(fl::vec2_t<T>& a, const T& b) {
    a = a - b;
}
