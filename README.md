# godot-tree-sitter

Godot bindings for tree-sitter

It project contains godot bindings and SyntaxHighlighter realisation for TestEdit

**Notic**: This is a preliminary version, far from complete and imperfect =)

### build

Via docker
```bash
make docker-build
```

### Example with SyntaxHighlighter

```gosot
// content of tree-sitter-json/queries/highlights.scm
const query = """
// ...
"""

// add more colors
var colors = {
    // ...
    "keyword": Color.RED,
    // ...
}

var ce: CodeEdit = CodeEdit.new()

var gts_sh = GTSSyntaxHighlighter.new()

gts_sh.set_colors(colors)
if !gts_sh.set_language("json", query): // alsow available: java-script, golang, lua, python
    print("Error")
    return

ce.set_syntax_highlighter(gts_sh)
ce.connect("lines_edited_from", func(from_line: int, to_line: int):
	gts_sh.update(ce.get_text()))
```