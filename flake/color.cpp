#include <flake/color.h>
#include <flake/math.h>



fl::rgb_t::rgb_t() : r(0), g(0), b(0) {}
fl::rgb_t::rgb_t(const rgba_t& rgba) : r(rgba.r), g(rgba.g), b(rgba.b) {}

fl::rgb_t fl::rgb_t::invert() const {
    return { uint8_t(255u - r), (uint8_t)(255u - g), (uint8_t)(255u - b) };
}

bool fl::rgb_t::operator ==(const rgb_t& other) const {
    return r == other.r && g == other.g && b == other.b;
}

fl::rgb_t fl::rgb_t::from_f32(float32_t r, float32_t g, float32_t b) {
    return { (uint8_t)(r * 255), (uint8_t)(g * 255), (uint8_t)(b * 255) };
}

fl::arr3_t<fl::float32_t> fl::rgb_t::to_f32() const {
    return { (float32_t)r / 255.f, (float32_t)g / 255.f, (float32_t)b / 255.f };
}

fl::rgb_t fl::rgb_t::rand() {
    uint32_t val = math::random_i32(0, 255 * 255 * 255);

    return { (uint8_t)(val >> 16), (uint8_t)(val >> 8), (uint8_t)val };
}

fl::rgb_t fl::rgb_t::rand_grayscale() {
    uint8_t val = math::random_i32(0, 255);

    return { val, val, val };
}



fl::rgba_t::rgba_t() : r(0), g(0), b(0), a(255) {}
fl::rgba_t::rgba_t(const rgb_t& rgb) : r(rgb.r), g(rgb.g), b(rgb.b), a(255) {}
fl::rgba_t::rgba_t(const rgb_t& rgb, uint8_t a) : r(rgb.r), g(rgb.g), b(rgb.b), a(a) {}

fl::rgba_t fl::rgba_t::invert() const {
    return { uint8_t(255u - r), uint8_t(255u - g), uint8_t(255u - b), a };
}

bool fl::rgba_t::operator ==(const rgba_t& other) const {
    return r == other.r && g == other.g && b == other.b && a == other.a;
}

fl::rgba_t fl::rgba_t::from_f32(float32_t r, float32_t g, float32_t b, float32_t a) {
    return { (uint8_t)(r * 255), (uint8_t)(g * 255), (uint8_t)(b * 255), (uint8_t)(a * 255) };
}

fl::arr4_t<fl::float32_t> fl::rgba_t::to_f32() const {
    return { (float32_t)r / 255.f, (float32_t)g / 255.f, (float32_t)b / 255.f, (float32_t)a / 255.f };
}
