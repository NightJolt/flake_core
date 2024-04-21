#pragma once

#include <flake/std/types/string.h>
#include <flake/std/types/string_view.h>
#include <flake/std/types/vector.h>

namespace fl::strutil {
    class tokens_iterator_t {
    public:
        tokens_iterator_t(vec_t<str_view_t>&);
        ~tokens_iterator_t();
        
        tokens_iterator_t(const tokens_iterator_t&) = delete;
        tokens_iterator_t& operator=(const tokens_iterator_t&) = delete;
        
        tokens_iterator_t(tokens_iterator_t&&);
        tokens_iterator_t& operator=(tokens_iterator_t&&);

        str_view_t current();
        void advance();
        bool is_empty();
        void reset();

        str_view_t* begin();
        str_view_t* end();

        vec_t<str_view_t>& get_tokens();

    private:
        vec_t<str_view_t> tokens;
        uint32_t index = 0;
    };

    tokens_iterator_t tokenize(const std::string&, vec_t<const char*>, bool = true);
    tokens_iterator_t tokenize(std::string&&, vec_t<const char*>, bool = true) = delete;

    void filter_empty(tokens_iterator_t&);
}