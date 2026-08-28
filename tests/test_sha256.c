#include <stdio.h>
#include <string.h>

#include "sha256.h"

struct vector {
    const char *input;
    const char *expected;
};

int main(void) {
    const struct vector vectors[] = {
        {"", "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"},
        {"abc", "ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad"},
        {"The quick brown fox jumps over the lazy dog", "d7a8fbb307d7809469ca9abcb0082e4f8d5651e46d3cdb762d02d0bf37c9e592"},
        {"The quick brown fox jumps over the lazy dog.", "ef537f25c895bfa782526529a9b63d97aa631564d5d789c2b765448c8635fb6c"}
    };
    size_t index;

    for (index = 0; index < sizeof(vectors) / sizeof(vectors[0]); index++) {
        const char *actual = sha256_crypt(vectors[index].input);
        if (strcmp(actual, vectors[index].expected) != 0) {
            fprintf(stderr, "SHA-256 vector %zu failed: expected %s, got %s\n", index, vectors[index].expected, actual);
            return 1;
        }
    }

    printf("PASS: %zu SHA-256 standard vectors\n", sizeof(vectors) / sizeof(vectors[0]));
    return 0;
}
