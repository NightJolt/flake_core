#pragma once

#include <flake/types.h>
#include <flake/vec2.h>

namespace fl::data {
    typedef int32_t grid_int_t;
    typedef int32_t chunk_int_t;
    typedef uint8_t tile_int_t;

    typedef uint32_t chunk_volume_t;
    typedef chunk_volume_t tile_index_t;

    typedef vec2_t<grid_int_t> grid_pos_t;
    typedef vec2_t<chunk_int_t> chunk_pos_t;
    typedef vec2_t<tile_int_t> tile_pos_t;

    typedef tile_int_t chunk_size_t;
    typedef uint32_t tile_size_t;

    typedef vec2_t <chunk_size_t> chunk_size2d_t;
    typedef vec2_t <tile_size_t> tile_size2d_t;
}