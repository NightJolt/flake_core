#pragma once

#include <flake/data/gridmap/utils.h>

namespace fl::data {
    template <chunk_size_t S, class T>
    class gridchunk_t {
    public:
        static constexpr chunk_size_t chunk_size = S;
        static constexpr chunk_volume_t chunk_volume = S * S;
        typedef T tile_data_t;

    public:
        tile_data_t& get_data(tile_pos_t tile_pos) {
            return data[tile_pos.x][tile_pos.y];
        }

        tile_data_t* get_data_array() {
            return &data[0][0];
        }

    private:
        tile_data_t data[chunk_size][chunk_size];
    };
}