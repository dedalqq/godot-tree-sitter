#include "gts_query_match.h"

using namespace godot;

void GTSQueryMatch::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_type"), &GTSQueryMatch::get_type);

    ClassDB::bind_method(D_METHOD("get_r_start"), &GTSQueryMatch::get_r_start);
    ClassDB::bind_method(D_METHOD("get_c_start"), &GTSQueryMatch::get_c_start);
    ClassDB::bind_method(D_METHOD("get_r_end"), &GTSQueryMatch::get_r_end);
    ClassDB::bind_method(D_METHOD("get_c_end"), &GTSQueryMatch::get_c_end);
}

GTSQueryMatch::GTSQueryMatch() {

}

GTSQueryMatch::~GTSQueryMatch() {

}
