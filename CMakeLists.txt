cmake_minimum_required(VERSION 3.5)

project(mcpelauncher-cheatlesstweaks)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

FetchContent_Declare(libhat
    GIT_REPOSITORY https://github.com/BasedInc/libhat.git
    EXCLUDE_FROM_ALL
)

FetchContent_Declare(safetyhook
    GIT_REPOSITORY https://github.com/cursey/safetyhook.git
    GIT_TAG origin/main)

FetchContent_Declare(zydis
    GIT_REPOSITORY https://github.com/zyantific/zydis.git)

FetchContent_MakeAvailable(libhat)
FetchContent_MakeAvailable(safetyhook)
FetchContent_MakeAvailable(zydis)

add_library(mcpelauncher-cheatlesstweaks SHARED
    src/main.cpp
)

target_include_directories(mcpelauncher-cheatlesstweaks PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_options(mcpelauncher-cheatlesstweaks PRIVATE
    -static-libstdc++
)

target_link_libraries(mcpelauncher-cheatlesstweaks PUBLIC
    libhat::libhat
    safetyhook::safetyhook
    Zydis::Zydis
)

set_target_properties(mcpelauncher-cheatlesstweaks PROPERTIES
    OUTPUT_NAME "mcpelauncher-cheatlesstweaks"
)

install(TARGETS mcpelauncher-cheatlesstweaks LIBRARY DESTINATION mods)
