#pragma once

#include <flake/types.h>

#include <limits>

namespace fl::limits {
    constexpr auto i8_min = std::numeric_limits<int8_t>::min();
    constexpr auto i8_max = std::numeric_limits<int8_t>::max();
    
    constexpr auto i16_min = std::numeric_limits<int16_t>::min();
    constexpr auto i16_max = std::numeric_limits<int16_t>::max();

    constexpr auto i32_min = std::numeric_limits<int32_t>::min();
    constexpr auto i32_max = std::numeric_limits<int32_t>::max();
    
    constexpr auto i64_min = std::numeric_limits<int64_t>::min();
    constexpr auto i64_max = std::numeric_limits<int64_t>::max();

    constexpr auto u8_min = std::numeric_limits<uint8_t>::min();
    constexpr auto u8_max = std::numeric_limits<uint8_t>::max();

    constexpr auto u16_min = std::numeric_limits<uint16_t>::min();
    constexpr auto u16_max = std::numeric_limits<uint16_t>::max();

    constexpr auto u32_min = std::numeric_limits<uint32_t>::min();
    constexpr auto u32_max = std::numeric_limits<uint32_t>::max();

    constexpr auto u64_min = std::numeric_limits<uint64_t>::min();
    constexpr auto u64_max = std::numeric_limits<uint64_t>::max();
}