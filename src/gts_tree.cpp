#include <tree_sitter/api.h>

#include "gts_tree.h"

using namespace godot;

void GTSTree::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_root_node"), &GTSTree::getRootNode);
}

GTSTree::GTSTree() {
    this->tree = NULL;
}

GTSTree::~GTSTree() {
    ts_tree_delete(this->tree);
}

GTSTree *GTSTree::byTSTree(TSTree *tree) {
    auto t = memnew(GTSTree);
    t->tree = tree;
    return t;
}

GTSNode *GTSTree::getRootNode() {
    return GTSNode::byTSNode(ts_tree_root_node(this->tree));
}

TSTree *GTSTree::get_tree() {
    return this->tree;
}