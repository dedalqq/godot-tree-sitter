#include "register_types.h"

#include "gts_parser.h"
#include "gts_tree.h"
#include "gts_node.h"
#include "gts_query.h"
#include "gts_query_cursor.h"
#include "gts_query_match.h"
#include "gts_syntax_highlighter.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_gts_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	GDREGISTER_CLASS(GTSParser);
	GDREGISTER_CLASS(GTSTree);
	GDREGISTER_CLASS(GTSNode);
	GDREGISTER_CLASS(GTSQuery);
	GDREGISTER_CLASS(GTSQueryError);
	GDREGISTER_CLASS(GTSQueryCursor);
	GDREGISTER_CLASS(GTSQueryMatch);
	GDREGISTER_CLASS(GTSSyntaxHighlighter);
}

void uninitialize_gts_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
// Initialization.
GDExtensionBool GDE_EXPORT gts_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
	godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

	init_obj.register_initializer(initialize_gts_module);
	init_obj.register_terminator(uninitialize_gts_module);
	init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

	return init_obj.init();
}
}
