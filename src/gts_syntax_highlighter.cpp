#include "gts_syntax_highlighter.h"

#include "gts_language.h"

#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void GTSSyntaxHighlighter::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_colors", "colors"), &GTSSyntaxHighlighter::set_colors);
    ClassDB::bind_method(D_METHOD("set_language", "language", "query"), &GTSSyntaxHighlighter::set_language);
    ClassDB::bind_method(D_METHOD("update", "code"), &GTSSyntaxHighlighter::update);
}

GTSSyntaxHighlighter::GTSSyntaxHighlighter() {
    this->tree = NULL;
    this->query = NULL;
    this->parser = NULL;
    this->cursor = NULL;

    this->data = TypedArray<Dictionary>();

    this->colors = Dictionary();
}

GTSSyntaxHighlighter::~GTSSyntaxHighlighter() {
    ts_tree_delete(this->tree);
    ts_parser_delete(this->parser);
    ts_query_delete(this->query);
    
    if (this->cursor) {
        ts_query_cursor_delete(this->cursor);
    }
}

void GTSSyntaxHighlighter::set_colors(Dictionary colors) {
    this->colors = colors;
}

bool GTSSyntaxHighlighter::set_language(String language, String query) {
    ts_parser_delete(this->parser);
    ts_query_delete(this->query);

    if (this->cursor) {
        ts_query_cursor_delete(this->cursor);
    }

    this->parser = ts_parser_new();
    this->cursor = ts_query_cursor_new();

    const TSLanguage *lang = language_by_name(language); // TODO delete
    
    ts_parser_set_language(this->parser, lang);

    uint32_t error_offset = 0;
    TSQueryError error_type = TSQueryErrorNone;

    CharString data = query.ascii();

    this->query = ts_query_new(
        lang,
        data.get_data(),
        data.size()-1,
        &error_offset,
        &error_type
    );

    return error_type == TSQueryErrorNone;
}

Dictionary getColorDict(Color c);

void GTSSyntaxHighlighter::update(String code) {
    CharString data = code.utf8();

    // TSInputEdit edit = TSInputEdit{
    //     .start_byte = 0,
    //     .old_end_byte = uint32_t(data.size()-1),
    //     .new_end_byte = uint32_t(data.size()-1),
    // };

    // ts_tree_edit(this->tree, &edit);

    this->tree = ts_parser_parse_string(
        this->parser,
        NULL, // this->tree,
        data.get_data(),
        data.size()-1
    );

    ts_query_cursor_exec(this->cursor, this->query, ts_tree_root_node(this->tree));

    TSQueryMatch match;

    for (int32_t i = 0; i < this->data.size(); i++) {
        this->data[i].clear();
        this->data[i] = Dictionary();
    }

    for (;;) {
        bool v = ts_query_cursor_next_match(this->cursor, &match);
        if (!v) {
            break;
        }

        if (!match.captures) {
            continue;
        }

        TSPoint start = ts_node_start_point(match.captures->node);
        TSPoint end = ts_node_end_point(match.captures->node);

        while (this->data.size() < end.row+1) {
            this->data.append(Dictionary());
        }

        uint32_t length;
        
        const char *name = ts_query_capture_name_for_id(this->query, match.captures->index, &length);

        Dictionary ds = this->data[start.row];
        Dictionary de = this->data[end.row];

        ds[start.column] = getColorDict(this->color_by_name(name));

        for (uint32_t i = start.row + 1; i <= end.row; i++) {
            Dictionary d = this->data[i];
            d[0] = getColorDict(this->color_by_name(name));
        }

        de[end.column] = getColorDict(this->color_by_name(""));

        if (match.capture_count != 1) {
            UtilityFunctions::print("c ", match.capture_count);
        }
    }
}

Color GTSSyntaxHighlighter::color_by_name(const char *name) {
    if (this->colors.has(name)) {
        return this->colors[name];
    }

    return Color(255, 255, 255);
}

Dictionary getColorDict(Color c) {
    Dictionary d = Dictionary();
    d["color"] = c;
    return d;
}

Dictionary GTSSyntaxHighlighter::_get_line_syntax_highlighting(int32_t p_line) {
    if (this->data.size() <= p_line) {
        return Dictionary{};
    }

    return this->data[p_line];
}