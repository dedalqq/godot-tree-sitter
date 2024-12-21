#include "gts_query_cursor.h"

#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void GTSQueryCursor::_bind_methods() {
    ClassDB::bind_method(D_METHOD("exec", "query", "node"), &GTSQueryCursor::exec);
    ClassDB::bind_method(D_METHOD("next_match"), &GTSQueryCursor::next_match);
}

GTSQueryCursor::GTSQueryCursor() {
    this->cursor = ts_query_cursor_new();
    this->qm = TSQueryMatch{};
}

GTSQueryCursor::~GTSQueryCursor() {
    ts_query_cursor_delete(this->cursor);
}

void GTSQueryCursor::exec(GTSQuery *query, GTSNode *node) {
    ts_query_cursor_exec(this->cursor, query->get_query(), node->get_node());
}

GTSQueryMatch *GTSQueryCursor::next_match() {
    bool v = ts_query_cursor_next_match(this->cursor, &this->qm);
    if (!v) {
        return NULL;
    }
    
    GTSQueryMatch *res = memnew(GTSQueryMatch);

    if (this->qm.capture_count > 0) {
        TSPoint s = ts_node_start_point(this->qm.captures->node);
        TSPoint e = ts_node_end_point(this->qm.captures->node);

        res->type = String(ts_node_type(this->qm.captures->node));

        res->r_start = s.row;
        res->c_start = s.column;
        res->r_end = e.row;
        res->c_end = e.column;
    }

    return res;
}