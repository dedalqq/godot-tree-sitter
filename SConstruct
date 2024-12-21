#!/usr/bin/env python
import os
import sys

env = SConscript("godot-cpp/SConstruct")

env.Append(CPPPATH=["tree-sitter/lib/include"])

env.Append(CPPPATH=["tree-sitter-go/bindings/c"])
env.Append(CPPPATH=["tree-sitter-javascript/bindings/c"])
env.Append(CPPPATH=["tree-sitter-json/bindings/c"])
env.Append(CPPPATH=["tree-sitter-lua/bindings/c"])
env.Append(CPPPATH=["tree-sitter-python/bindings/c"])

sources = Glob("src/*.cpp")
sources.append(Glob('tree-sitter/lib/src/lib.c'))

sources.append(Glob('tree-sitter-go/src/*.c'))
sources.append(Glob('tree-sitter-javascript/src/*.c'))
sources.append(Glob('tree-sitter-json/src/*.c'))
sources.append(Glob('tree-sitter-lua/src/*.c'))
sources.append(Glob('tree-sitter-python/src/*.c'))

library = env.SharedLibrary(
    "gts/bin/gts{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
    source=sources,
)

Default(library)