#ifndef GTSPARSER_H
#define GTSPARSER_H

#include <tree_sitter/api.h>

#include <godot_cpp/classes/ref.hpp>

#include "gts_tree.h"

namespace godot {

class GTSParser : public RefCounted {
	GDCLASS(GTSParser, RefCounted)

private:
	TSParser *parser;

protected:
	static void _bind_methods();

public:
	GTSParser();
	~GTSParser();

	void set_language(String name);
	GTSTree* parse_string(String code, GTSTree *tree);
};

}

#endif
