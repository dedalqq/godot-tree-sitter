#ifndef GTSNODE_H
#define GTSNODE_H

#include <tree_sitter/api.h>

#include <godot_cpp/classes/ref.hpp>

namespace godot {

class GTSNode : public RefCounted {
	GDCLASS(GTSNode, RefCounted)

private:
	TSNode node;

protected:
	static void _bind_methods();

public:
	static GTSNode *byTSNode(TSNode node);
	
	GTSNode();
	~GTSNode();

	TSNode get_node();
};
}

#endif