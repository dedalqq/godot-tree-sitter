#ifndef GTSQUERYMATCH_H
#define GTSQUERYMATCH_H

#include <tree_sitter/api.h>
#include <godot_cpp/classes/ref.hpp>

namespace godot {

class GTSQueryMatch : public RefCounted {
    GDCLASS(GTSQueryMatch, RefCounted)

protected:
	static void _bind_methods();

public:
    String type;
    
    uint32_t r_start;
    uint32_t c_start;
    uint32_t r_end;
    uint32_t c_end;

    GTSQueryMatch();
    ~GTSQueryMatch();

    String get_type() { return this->type; };

    uint32_t get_r_start() { return this->r_start; };
    uint32_t get_c_start() { return this->c_start; };
    uint32_t get_r_end() { return this->r_end; };
    uint32_t get_c_end() { return this->c_end; };
};

}

#endif