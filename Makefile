.PHONY: xcc
xcc:
	@xmake project -k compile_commands -y

.PHONY: test
test:
	@xmake run test

.PHONY: fmt
fmt:
	@./scripts/fmt.sh

.PHONY: lint
lint:
	@./scripts/lint.sh