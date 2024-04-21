#pragma once

#include <flake/std/types/array.h>
#include <flake/std/types/string.h>
#include <flake/types.h>

namespace fl {
    struct rgb_t;
    struct rgba_t;

    struct rgb_t {
        rgb_t();
        constexpr rgb_t(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b) {}
        rgb_t(const rgba_t&);

        rgb_t invert() const;

        uint8_t r;
        uint8_t g;
        uint8_t b;

        bool operator ==(const rgb_t&) const;

        static rgb_t from_f32(float32_t, float32_t, float32_t);
        arr3_t<float32_t> to_f32() const;

        static rgb_t rand();
        static rgb_t rand_grayscale();
    };

	namespace rgb {
		inline constexpr rgb_t black = { 0, 0, 0 };
		inline constexpr rgb_t white = { 255, 255, 255 };
		inline constexpr rgb_t red = { 255, 0, 0 };
		inline constexpr rgb_t green = { 0, 255, 0 };
		inline constexpr rgb_t blue = { 0, 0, 255 };
	}

    struct rgba_t {
        rgba_t();
        constexpr rgba_t(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r(r), g(g), b(b), a(a) {};
        rgba_t(const rgb_t&);
        rgba_t(const rgb_t&, uint8_t);

        rgba_t invert() const;

        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;

        bool operator ==(const rgba_t&) const;

        static rgba_t from_f32(float32_t, float32_t, float32_t, float32_t);
        arr4_t<float32_t> to_f32() const;
    };

	namespace rgba {
		inline constexpr rgba_t black = { 0, 0, 0, 255 };
		inline constexpr rgba_t white = { 255, 255, 255, 255 };
		inline constexpr rgba_t red = { 255, 0, 0, 255 };
		inline constexpr rgba_t green = { 0, 255, 0, 255 };
		inline constexpr rgba_t blue = { 0, 0, 255, 255 };
		inline constexpr rgba_t transparent = { 0, 0, 0, 0 };
	}
}