#ifndef GTSQUERY_H
#define GTSQUERY_H

#include <tree_sitter/api.h>

#include <tree_sitter/api.h>

#include <godot_cpp/classes/ref.hpp>

namespace godot {

class GTSQueryError : public RefCounted {
    GDCLASS(GTSQueryError, RefCounted)

protected:
	static void _bind_methods() {};

public:
    uint32_t error_offset;
    TSQueryError error_type;

    GTSQueryError() {};
	~GTSQueryError() {};
};

class GTSQuery : public RefCounted {
    GDCLASS(GTSQuery, RefCounted)

private:
    TSQuery *query;

    GTSQueryError *error;

protected:
	static void _bind_methods();

public:
    GTSQueryError *load(String code);

	GTSQuery();
	~GTSQuery();

    TSQuery *get_query();
};

}

#endif