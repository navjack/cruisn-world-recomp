cmake_minimum_required(VERSION 3.20)
project(cruisn_world LANGUAGES C CXX OBJC OBJCXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
include("${CMAKE_CURRENT_SOURCE_DIR}/../../native/CruisnNative.cmake")
cruisn_add_native_app(
    GAME_ID cruisn_world
    ROM_HASH 975bc0b0840d1020
    INTERNAL_NAME "CRUIS'N WORLD"
    DISPLAY_NAME "Cruis'n World"
    WINDOW_TITLE "Cruis'n World - Recompiled")
