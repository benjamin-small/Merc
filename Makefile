CC ?= cc
TEST_CFLAGS ?= -std=c99 -Wall -Wextra -Werror -O2
BUILD_DIR := .build
TEST_BINARY := $(BUILD_DIR)/test_sha256

.PHONY: test build clean

test: $(TEST_BINARY)
	$(TEST_BINARY)

$(TEST_BINARY): tests/test_sha256.c src/sha256.c src/sha256.h
	mkdir -p $(BUILD_DIR)
	$(CC) $(TEST_CFLAGS) -Isrc tests/test_sha256.c src/sha256.c -o $(TEST_BINARY)

build:
	$(MAKE) -C src

clean:
	rm -rf $(BUILD_DIR)
	$(MAKE) -C src clean
