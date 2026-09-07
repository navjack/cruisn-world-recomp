# Cruis'n World

Status: repository scaffolded; native game binary is waiting for game-specific
MIPS ELF or complete symbol data and the frontend port.

Run the real recompiler preflight from the workspace root:

```text
./scripts/build_game.sh cruisn-world
```

It verifies the ROM SHA-256 and then invokes N64Recomp. Supply either
`input/cruisn-world.elf` or a complete `input/cruisn-world.syms.toml`; otherwise
it exits with an actionable missing-input message. No placeholder executable is
generated.

The ROM header stores `0x804AD400`; after the CIC 6106 adjustment, the runtime
entrypoint used by the recompiler is `0x802AD400`. It must be matched against
the supplied ELF before generated output is treated as valid.

The committed [`splat.yaml`](splat.yaml) records the ROM-derived entry, main,
data, and BSS boundaries. Run `./scripts/split_game.sh cruisn-world` from the
workspace root to regenerate the ignored disassembly workspace.
