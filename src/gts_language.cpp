#include "gts_language.h"

#include <tree-sitter-json.h>
#include <tree-sitter-javascript.h>
#include <tree-sitter-go.h>
#include <tree-sitter-lua.h>
#include <tree-sitter-python.h>

// using namespace godot;

const TSLanguage *language_by_name(godot::String lg_name) {
    if (lg_name == "json") {
        return tree_sitter_json();
    }

    if (lg_name == "java-script") {
        return tree_sitter_javascript();
    }

    if (lg_name == "golang") {
        return tree_sitter_go();
    }

    if (lg_name == "lua") {
        return tree_sitter_lua();
    }

    if (lg_name == "python") {
        return tree_sitter_python();
    }

    return NULL;
};
