#ifndef GTSSYNTAXHIGHLIGHTER_H
#define GTSSYNTAXHIGHLIGHTER_H

#include <tree_sitter/api.h>

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/syntax_highlighter.hpp>

#include "gts_parser.h"

namespace godot {

class GTSSyntaxHighlighter : public SyntaxHighlighter {
	GDCLASS(GTSSyntaxHighlighter, SyntaxHighlighter)

private:
	TSParser *parser;
    TSTree *tree;
    TSQuery *query;
    TSQueryCursor *cursor;

    TypedArray<Dictionary> data;

    Dictionary colors;

    Color color_by_name(const char *name);

protected:
	static void _bind_methods();

public:
    GTSSyntaxHighlighter();
    ~GTSSyntaxHighlighter();

	Dictionary _get_line_syntax_highlighting(int32_t p_line);
    void set_colors(Dictionary colors);
    bool set_language(String language, String query);
    void update(String code);
};

}

#endif