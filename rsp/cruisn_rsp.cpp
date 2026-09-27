#include "rsp_contract.hpp"

#include "ultramodern/ultra64.h"

extern RspUcodeFunc aspMain;

extern "C" RspUcodeFunc* cruisn_get_rsp_microcode(const OSTask* task) {
    if (task != nullptr && task->t.type == M_AUDTASK) {
        return &aspMain;
    }
    return nullptr;
}
