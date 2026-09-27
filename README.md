# Cruis'n World recomp

Title repository for the native Apple Silicon macOS port of *Cruis'n World*
(N64, US). It builds inside the
[cruisn-recomp](https://github.com/navjack/cruisn-recomp) workspace, which
clones it into `games/cruisn-world`. **No game data is included; you need your
own ROM.**

**Status: boots, loads its gameplay code, and plays audio. Not yet played
through.**

## Contents

- `input/cruisn-world.syms.toml` — the CPU symbol map: entry, main, and the
  fixed overlay the game reads from ROM `0xA7040-0xC12A0` to `0x80050400`.
- `config/recomp-symbols.toml` — N64Recomp configuration: exception and TLB
  stubs, and the hooks below.
- `native/cruisn_world_boot.cpp` — the game's copy protection compares
  hardware state the CIC-6106 boot leaves behind (low-RDRAM words, SP
  DMEM/IMEM, IPL3 bytes read from the cartridge). This seeds that state before
  `main`.
- `rsp/aspMain.us.toml` — the stock `aspMain` audio microcode at ROM
  `0x86230`, recompiled with RSPRecomp at build time.
- `roms.toml`, `splat.yaml` — the supported dump's SHA-256 and the ROM
  segmentation.

Saves are EEPROM 16K.

## Build

From the workspace root, with `roms/Cruis'n World (U) [!].z64` in place:

```sh
./scripts/build_game_app.sh cruisn-world
```

This produces `Cruis'n World.app` in the workspace root.
