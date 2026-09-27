cmake_minimum_required(VERSION 3.20)
project(cruisn_world LANGUAGES C CXX OBJC OBJCXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CRUISN_COMMON_ROOT "" CACHE PATH "Shared Cruis'n workspace root")
if (NOT CRUISN_COMMON_ROOT)
    get_filename_component(CRUISN_COMMON_ROOT
        "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)
endif()
include("${CRUISN_COMMON_ROOT}/native/CruisnNative.cmake")
cruisn_add_native_app(
    GAME_ID cruisn_world
    ROM_HASH 25719e5d267c09d0
    INTERNAL_NAME "CRUIS'N WORLD"
    DISPLAY_NAME "Cruis'n World"
    WINDOW_TITLE "Cruis'n World: Recompiled"
    PROGRAM_ID CruisnWorldRecompiled
    PROGRAM_NAME "Cruis'n World: Recompiled"
    SAVE_TYPE Eep16k)
