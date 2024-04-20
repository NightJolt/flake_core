#pragma once

#include <flake/data/gridmap/gridchunk.h>
#include <flake/std/types/unordered_map.h>
#include <flake/std/types/function.h>

namespace fl::data {
    template <chunk_size_t S, class T>
    class gridmap_t {
    public:
        static constexpr chunk_size_t chunk_size = S;
        typedef gridchunk_t<S, T> chunk_t;
        typedef T tile_data_t;

    private:
        typedef umap_vec2_t<chunk_int_t, chunk_t*> gridchunk_map_t;
        typedef fn_t<void(chunk_t*, chunk_pos_t)> init_chunk_fn_t;

    public:
        ~gridmap_t() {
            for (auto& [pos, chunk] : gridchunks) {
                delete chunk;
            }
        }

        tile_data_t* get_data(grid_pos_t grid_pos) {
            auto chunk = get_chunk(grid_to_chunk(grid_pos, S));

            if (!chunk) {
                return nullptr;
            }

            return &chunk->get_data(grid_to_tile(grid_pos, S));
        }

        tile_data_t* get_or_create_data(grid_pos_t grid_pos) {
            return &get_or_create_chunk(grid_to_chunk(grid_pos, S))->get_data(grid_to_tile(grid_pos, S));
        }

        tile_data_t* get_data_array(grid_pos_t grid_pos) {
            auto chunk = get_chunk(grid_to_chunk(grid_pos, S));

            if (!chunk) {
                return nullptr;
            }

            return chunk->get_data_array();
        }

        tile_data_t* get_or_create_data_array(grid_pos_t grid_pos) {
            return get_or_create_chunk(grid_to_chunk(grid_pos, S))->get_data_array();
        }

        gridchunk_map_t& get_chunks() {
            return gridchunks;
        }

        void set_init_chunk_fn(init_chunk_fn_t fn) {
            init_chunk_fn = fn;
        }

        chunk_t* get_chunk(chunk_pos_t chunk_pos) {
            if (m_gridchunks.contains(chunk_pos)) {
                return gridchunks[chunk_pos];
            }

            return nullptr;
        }

        chunk_t* get_or_create_chunk(chunk_pos_t chunk_pos) {
            if (gridchunks.contains(chunk_pos)) {
                return gridchunks[chunk_pos];
            }

            auto* chunk = new gridchunk_t<chunk_size, tile_data_t>();
            gridchunks[chunk_pos] = chunk;

            if (m_init_chunk) {
                init_chunk(chunk, chunk_pos);
            }

            return chunk;
        }

        void clear() {
            for (auto& [pos, chunk] : gridchunks) {
                delete chunk;
            }

            gridchunks.clear();
        }
        
    private:
        gridchunk_map_t gridchunks;
        init_chunk_fn_t init_chunk_fn;
    };
}