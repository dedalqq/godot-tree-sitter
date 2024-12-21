#ifndef GTSQUERYCURSOR_H
#define GTSQUERYCURSOR_H

#include <tree_sitter/api.h>
#include <godot_cpp/classes/ref.hpp>

#include "gts_query.h"
#include "gts_node.h"
#include "gts_query_match.h"

namespace godot {

class GTSQueryCursor : public RefCounted {
    GDCLASS(GTSQueryCursor, RefCounted)

private:
    TSQueryCursor *cursor;

    TSQueryMatch qm;

protected:
	static void _bind_methods();

public:
    GTSQueryCursor();
    ~GTSQueryCursor();

    void exec(GTSQuery *query,  GTSNode *node);
    GTSQueryMatch *next_match();
};

}

#endif