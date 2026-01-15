# 1. Define defaults so the Makefile doesn't break
BUILD_DIR ?= build
CMAKE ?= cmake
MAKE ?= make

.PHONY: fmt lint submodule build clean

fmt:
	@./scripts/fmt.sh all

lint:
	@./scripts/lint.sh all

submodule:
	@git submodule update --init --recursive

# 2. Use CMake's -B and -S flags to avoid 'cd' issues
build:
	$(CMAKE) -S . -B $(BUILD_DIR)
	$(CMAKE) --build $(BUILD_DIR)

# 3. Improved catch-all for CMake targets/tests
# Note: Added a guard to prevent this from catching common files
%:
	@if [ -d "$(BUILD_DIR)" ]; then \
		$(MAKE) -C $(BUILD_DIR) $@ || exit 1; \
		if [ -x "$(BUILD_DIR)/test/$@" ]; then \
			echo "Running test $@"; \
			$(BUILD_DIR)/test/$@ || exit 1; \
		fi \
	else \
		echo "Build directory not found. Run 'make build' first."; \
		exit 1; \
	fi

clean:
	rm -rf $(BUILD_DIR)