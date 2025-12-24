VCPKG_ROOT ?= $(shell vcpkg root 2>/dev/null || echo "")
VCPKG_TOOLCHAIN ?= $(if $(VCPKG_ROOT),$(VCPKG_ROOT)/scripts/buildsystems/vcpkg.cmake,)

.PHONY: build
build:
	@mkdir -p build
	@if [ -n "$(VCPKG_TOOLCHAIN)" ] && [ -f "$(VCPKG_TOOLCHAIN)" ]; then \
		cd build && cmake .. -DCMAKE_TOOLCHAIN_FILE=$(VCPKG_TOOLCHAIN); \
	else \
		echo "Warning: vcpkg toolchain not found. Trying without it..."; \
		cd build && cmake ..; \
	fi
	@cmake --build build

.PHONY: test
test: build
	@cd build && ctest --output-on-failure

.PHONY: test-verbose
test-verbose: build
	@cd build && ctest --verbose

.PHONY: compile_commands
compile_commands: build
	@ln -sf build/compile_commands.json .

.PHONY: fmt
fmt:
	@./scripts/fmt.sh

.PHONY: lint
lint:
	@./scripts/lint.sh