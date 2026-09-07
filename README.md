# Cruis'n World

Status: repository scaffolded; native game binary is waiting for game-specific
MIPS ELF/symbol data and the frontend port.

Run the real recompiler preflight from the workspace root:

```text
./scripts/build_game.sh cruisn-world
```

It verifies the ROM SHA-256 and then invokes N64Recomp. Until
`input/cruisn-world.elf` is supplied, it exits with an actionable missing-input
message. No placeholder executable is generated.

The boot address recorded from the ROM header is `0x804AD400`. It must be
matched against the supplied ELF before generated output is treated as valid.
