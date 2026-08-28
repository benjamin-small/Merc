# Merc

Merc is a preserved and security-focused working copy of the Merc 2.2 Diku MUD server, including its C game engine, world-area data, player and log directories, MOB programs, and IMC2 integration. It descends from the November 24, 1993 Merc release identified in the legacy [provenance README](README).

## Requirements

The supported build environment is a POSIX-like system with `make`, a Clang 17.0 or GCC-compatible C compiler, and the platform crypt library. The historical `src/startup` supervisor additionally requires `csh`, `nohup`, and standard networking tools.

## Build and usage

Build the server from the repository root:

```sh
make build
```

The resulting executable is `src/merc`. The historical startup script changes to `area/`, listens on port `9500` by default, writes numbered files under `log/`, and restarts the server unless `area/shutdown.txt` exists:

```sh
cd src
./startup 9500
```

Review [configuration documentation](docs/configuration.md) and the historical documents under `doc/` before operating a server. Do not expose an unreviewed 1993 codebase to an untrusted network.

## Testing

Run the portable SHA-256 regression vectors with `make test`. See [testing documentation](docs/testing.md) for exact scope, coverage, and the distinction between tested hashing behavior and compile-only legacy server validation.

## Licensing

Merc/Diku and bundled IMC/SHA components carry multiple historical terms. See [licensing documentation](docs/licensing.md) and retain the original notices.
