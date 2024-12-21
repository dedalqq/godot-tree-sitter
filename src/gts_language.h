#ifndef GTSLANGUAGE_H
#define GTSLANGUAGE_H

#include <tree_sitter/api.h>
#include <godot_cpp/classes/ref.hpp>

const TSLanguage *language_by_name(godot::String lg_name);

#endif