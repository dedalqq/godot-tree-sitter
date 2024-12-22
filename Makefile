all: docker-build

build:
	mkdir -p gts/{queries,bin}

	scons -j4 platform=linux target=template_release
	scons -j4 platform=windows target=template_release
	scons -j4 platform=linux target=template_debug
	scons -j4 platform=windows target=template_debug

	cp -r tree-sitter-go/queries/ gts/queries/go/
	cp -r tree-sitter-javascript/queries/ gts/queries/javascript/
	cp -r tree-sitter-json/queries/ gts/queries/json/
	cp -r tree-sitter-lua/queries/ gts/queries/lua/
	cp -r tree-sitter-python/queries/ gts/queries/python/

docker-build:
	docker build . -t gts-builder
	docker run -ti --rm -v .:/mnt --user $${UID}:$${GID} gts-builder make build
