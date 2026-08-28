# Configuration

Merc uses files and compile-time settings rather than environment variables:

- `src/startup` selects port `9500` by default; pass another port as its first argument.
- `area/area.lst` selects the world-area files loaded by the server.
- `src/Makefile` enables IMC2 through `IMC = 1`; comment that assignment to build without IMC2.
- `imc/imc.config` and the other files under `imc/` hold IMC2 runtime data.
- `player/` stores player files and `log/` receives numbered server logs; both must be writable by the server account.
- creating `area/shutdown.txt` tells the historical supervisor not to restart after the server exits.

There are no documented environment-variable secrets. Treat any live IMC credentials, player data, and logs as private operational data and do not commit them.
