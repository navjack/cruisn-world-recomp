// Cruis'n World's copy protection compares hardware state that the CIC-6106
// boot process leaves behind: words in low RDRAM, the first words of SP DMEM
// and IMEM, the word at 0x80000310, and IPL3 bytes read straight from the
// cartridge. Any mismatch makes func_802E0A90 halt the boot thread, and copies
// of the RDRAM checks also run during play. The runtime starts the game
// without running IPL3, so main seeds that state first.
#include <cstdint>
#include <cstdio>

#include "librecomp/addresses.hpp"
#include "librecomp/game.hpp"
#include "recomp.h"

namespace {

struct BootWord {
    uint32_t address;
    uint32_t value;
};

// Each value is the one a check in the game compares against.
constexpr BootWord kBootWords[] = {
    {0x80000164, 0x01EC6021}, // func_802CA4D0, func_802B2E70
    {0x800001BC, 0x8FBF001C}, // func_802BDF88, func_802FA130
    {0x80000234, 0xAD130004}, // func_802FE5D0
    {0x8000028C, 0xAD0AFFFC}, // func_802CD960
    {0x800002B8, 0x8941680C}, // func_80050400, func_8030EC30
    {0x80000310, 0x000017D8}, // func_802E83A0
    {0xA4000000, 0xFFFFFFFF}, // SP DMEM, func_802AD898
    {0xA4001000, 0x000017D8}, // SP IMEM, func_802AD870
};

constexpr uint32_t kIpl3Size = 0x1000;
// Guest loads from 0xB0000000 reach physical 0x10000000 in the runtime's
// address space; 0x90000000 is the same physical address through KSEG0.
constexpr int32_t kCartridgeWindow = static_cast<int32_t>(0x90000000u);

}

extern "C" void cruisn_world_seed_boot_state(uint8_t* rdram, recomp_context* ctx) {
    for (const BootWord& word : kBootWords) {
        MEM_W(0, static_cast<int32_t>(word.address)) = static_cast<int32_t>(word.value);
    }
    recomp::do_rom_read(rdram, kCartridgeWindow, recomp::rom_base, kIpl3Size);
}

// Reports the self-test's error mask once; zero means every check passed.
extern "C" void cruisn_world_report_self_test(uint8_t* rdram, recomp_context* ctx) {
    std::fprintf(stderr, "[boot] copy-protection mask=%08X\n",
                 static_cast<uint32_t>(MEM_W(0, static_cast<int32_t>(0x803BDE2Cu))));
}
