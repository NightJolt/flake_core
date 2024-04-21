#pragma once

#include <flake/std/types/string.h>
#include <flake/std/types/vector.h>
#include <flake/std/types/unordered_map.h>
#include <flake/std/types/unordered_set.h>

namespace fl {

    // cmd arg0 [ar g3] -flag0 -[fl ag1] key0:val0 [ke y1]:[va l1] ...

    class command_t {
    public:
        command_t() = default;
        explicit command_t(const str_t&);

        const str_t& get_command() const;
        const str_t& get_arg(uint32_t) const;
        const vec_t<str_t>& get_args() const;
        bool has_flag(const str_t&) const;
        bool has_key(const str_t&) const;
        const str_t& get_val(const str_t&) const;
        const vec_t<str_t>& get_vals(const str_t&) const;

        void set_command(const str_t&);
        void add_arg(const str_t&);
        void add_flag(const str_t&);
        void add_key_val(const str_t&, const str_t&);

        str_t build() const;

    private:
        str_t format(const str_t&) const;

        umap_t<str_t, vec_t<str_t>> m_key_vals;
        uset_t<str_t> m_flags;
        vec_t <str_t> m_args;
        str_t m_command;
    };
}
