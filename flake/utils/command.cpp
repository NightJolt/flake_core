#include <flake/utils/command.h>
#include <flake/types.h>

fl::command_t::command_t(const str_t& cmd) {
    bool is_command = true;
    bool is_key = false;
    bool is_val = false;
    bool is_flag = false;
    bool is_arg = false;

    str_t key;
    str_t val;

    bool ignore_special_keys = false;
    bool ignore_brackets = false;

    for (uint32_t i = 0; i <= cmd.size(); i++) {
        char c = i == cmd.size() ? ' ' : cmd[i];

        if (i == 0 && c == '/') continue;

        if ((c == '[' || c == ']') && !ignore_brackets) {
            ignore_special_keys = c == '[';

            continue;
        }

        if (c == '$' && !ignore_brackets) {
            ignore_brackets = true;

            continue;
        }

        ignore_brackets = false;

        if (is_command) {
            if (c == ' ' && !ignore_special_keys) {
                is_command = false;
            } else {
                m_command.push_back(c);
            }
        } else {
            if (c == ' ' && !ignore_special_keys) {
                if (is_arg) {
                    is_arg = false;

                    m_args.emplace_back(val);
                } else if (is_flag) {
                    is_flag = false;

                    m_flags.emplace(val);
                } else if (is_val) {
                    is_val = false;

                    if (val.length()) m_key_vals[key].emplace_back(val);
                } else if (is_key) is_key = false;

                key.clear();
                val.clear();
            } else if (!is_key && !is_flag && !is_val && val.empty()) {
                if (c == '+' && !ignore_special_keys) {
                    is_key = true;
                } else if (c == '-' && !ignore_special_keys) {
                    is_flag = true;
                } else {
                    is_arg = true;

                    val += c;
                }
            } else {
                if (key.length() && !ignore_special_keys && (c == ':' || c == ',')) {
                    is_key = false;
                    is_val = true;

                    if (val.length()) m_key_vals[key].emplace_back(val);

                    val.clear();
                } else {
                    if (is_key) key += c;
                    else val += c;
                }
            }
        }
    }
}

const fl::str_t& fl::command_t::get_command() const {
    return m_command;
}

const fl::str_t& fl::command_t::get_arg(uint32_t index) const {
    return m_args[index];
}

const fl::vec_t<fl::str_t>& fl::command_t::get_args() const {
    return m_args;
}

bool fl::command_t::has_flag(const str_t& flag) const {
    return m_flags.contains(flag);
}

bool fl::command_t::has_key(const str_t& key) const {
    return m_key_vals.contains(key);
}

const fl::str_t& fl::command_t::get_val(const str_t& key) const {
    return m_key_vals.at(key)[0];
}

const fl::vec_t<fl::str_t>& fl::command_t::get_vals(const str_t& key) const {
    return m_key_vals.at(key);
}

void fl::command_t::set_command(const str_t& cmd) {
    m_command = cmd;
}

fl::str_t fl::command_t::format(const str_t& arg) const {
    str_t arg_cpy;
    arg_cpy.reserve(arg.size() * 1.2f);

    bool apply_guard = false;

    for (int i = 0; i < arg.size(); i++) {
        if (arg[i] == ' ' || arg[i] == '-' || arg[i] == '+') apply_guard = true;
        if (arg[i] == '[' || arg[i] == ']' || arg[i] == '$') arg_cpy += '$';

        arg_cpy += arg[i];
    }

    if (apply_guard) {
        arg_cpy =  '[' + arg_cpy + ']';
    }

    return arg_cpy;
}

void fl::command_t::add_arg(const str_t& arg) {
    m_args.emplace_back(arg);
}

void fl::command_t::add_flag(const str_t& flag) {
    m_flags.emplace(flag);
}

void fl::command_t::add_key_val(const str_t& key, const str_t& val) {
    m_key_vals[key].emplace_back(val);
}

fl::str_t fl::command_t::build() const {
    str_t cmd(m_command);

    for (auto& arg : m_args) {
        cmd += " " + format(arg);
    }

    for (auto& flag : m_flags) {
        cmd += " -" + format(flag);
    }

    for (auto& [key, vals] : m_key_vals) {
        cmd += " +" + format(key) + ":";

        for (int i = 0; i < vals.size(); i++) {
            cmd += format(vals[i]);

            if (i != vals.size() - 1) cmd += ",";
        }
    }

    return cmd;
}