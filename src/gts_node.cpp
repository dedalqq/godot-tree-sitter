#include "gts_node.h"

using namespace godot;

void GTSNode::_bind_methods() {
    
}

GTSNode::GTSNode() {
}

GTSNode::~GTSNode() {
}

GTSNode *GTSNode::byTSNode(TSNode node) {
    auto n = memnew(GTSNode);
    n->node = node;
    return n;
}

TSNode GTSNode::get_node() {
    return this->node;
}