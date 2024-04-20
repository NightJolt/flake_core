#pragma once

#include <flake/data/gridmap/types.h>

namespace fl::data {
    tile_pos_t index_to_tile(tile_index_t, chunk_size_t);
    tile_index_t tile_to_index(tile_pos_t, chunk_size_t);

    grid_pos_t world_to_grid(vec2f_t, tile_size_t);
    chunk_pos_t grid_to_chunk(grid_pos_t, chunk_size_t);
    grid_pos_t chunk_to_grid(chunk_pos_t, chunk_size_t);
    tile_pos_t grid_to_tile(grid_pos_t, chunk_size_t);
}