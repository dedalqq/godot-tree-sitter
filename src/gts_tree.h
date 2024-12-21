#ifndef GTSTREE_H
#define GTSTREE_H

#include <tree_sitter/api.h>

#include <godot_cpp/classes/ref.hpp>

#include "gts_node.h"

namespace godot {

class GTSTree : public RefCounted {
	GDCLASS(GTSTree, RefCounted)

private:
	TSTree *tree;

protected:
	static void _bind_methods();

public:
	static GTSTree *byTSTree(TSTree *tree);

	GTSTree();
	~GTSTree();

	GTSNode *getRootNode();

	TSTree *get_tree();
};
}

#endif