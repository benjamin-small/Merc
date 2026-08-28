# Testing

Run the deterministic regression suite and full legacy build:

```sh
make test
make build
```

The tests cover four published SHA-256 vectors: empty input, `abc`, and the “quick brown fox” sentence with and without its final period. They exercise initialization, short and multi-byte updates, padding, transformation, digest encoding, and hexadecimal output. The full server is compiled as an integration check but is not started; gameplay, area loading, sockets, IMC2 networking, persistence, and the csh restart supervisor are not behaviorally tested.

Instrumenting `src/sha256.c` with compiler coverage reports **96.58% line coverage (141 of 146 lines)**. This measured percentage applies only to the SHA-256 component; no coverage percentage is claimed for the full historical MUD engine.
