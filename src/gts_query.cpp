#include <tree-sitter-json.h>

#include "gts_query.h"

#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void GTSQuery::_bind_methods() {
    ClassDB::bind_method(D_METHOD("load", "code"), &GTSQuery::load);
}

GTSQueryError *GTSQuery::load(String code) {
    this->error = NULL;

    uint32_t error_offset = 0;
    TSQueryError error_type = TSQueryErrorNone;

    CharString data = code.ascii();
    
    this->query = ts_query_new(
        tree_sitter_json(),
        data.get_data(),
        data.size()-1,
        &error_offset,
        &error_type
    );

    if (error_type != TSQueryErrorNone || error_offset != 0) {
        error = memnew(GTSQueryError);
        error->error_offset = error_offset;
        error->error_type = error_type;
        
        return error;
    }

    return NULL;
}

GTSQuery::GTSQuery() {
    this->query = NULL;
}

GTSQuery::~GTSQuery() {
    ts_query_delete(this->query);
}

TSQuery *GTSQuery::get_query() {
    return this->query;
}