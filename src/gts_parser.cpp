#include "gts_parser.h"

#include "gts_language.h"

using namespace godot;

void GTSParser::_bind_methods() {
    ClassDB::bind_method(D_METHOD("parse_string", "String", "tree"), &GTSParser::parse_string);
    ClassDB::bind_method(D_METHOD("set_language", "String"), &GTSParser::set_language);
}

GTSParser::GTSParser() {
    this->parser = ts_parser_new();
}

GTSParser::~GTSParser() {
    ts_parser_delete(this->parser);
}

void GTSParser::set_language(String name) {
    ts_parser_set_language(this->parser, language_by_name(name));
}

GTSTree* GTSParser::parse_string(String code, GTSTree *tree) {
    CharString data = code.utf8();

    TSTree *ts_tree = NULL;
    if (tree != NULL) {
        ts_tree = tree->get_tree();
    }

    TSTree *new_ts_tree = ts_parser_parse_string(
        this->parser,
        ts_tree,
        data.get_data(),
        data.size()-1
    );

    return GTSTree::byTSTree(new_ts_tree);
}
