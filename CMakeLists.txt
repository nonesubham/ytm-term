cmake_minimum_required(VERSION 3.20)
project(ytm-term VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ── Dependencies ──────────────────────────────────────────────────────────────

# FTXUI ships CMake config files
find_package(ftxui REQUIRED COMPONENTS component dom screen)

# mpv — MSYS2 UCRT64: mingw-w64-ucrt-x86_64-mpv
find_path(MPV_INCLUDE_DIR
  NAMES client.h
  PATH_SUFFIXES mpv
)
find_library(MPV_LIBRARY
  NAMES mpv libmpv
)

# Fallback: locate mpv via pkg-config if not in default search paths
if(NOT MPV_INCLUDE_DIR OR NOT MPV_LIBRARY)
  find_package(PkgConfig)
  if(PKG_CONFIG_FOUND)
    pkg_check_modules(MPV_PC QUIET IMPORTED_TARGET mpv)
  endif()
  if(TARGET PkgConfig::MPV_PC)
    set(MPV_INCLUDE_DIR "${MPV_PC_INCLUDE_DIRS}")
    set(MPV_LIBRARY "${MPV_PC_LIBRARIES}")
  endif()
endif()

if(NOT MPV_INCLUDE_DIR OR NOT MPV_LIBRARY)
  message(FATAL_ERROR "mpv not found: install mingw-w64-ucrt-x86_64-mpv (MSYS2 UCRT64) or set MPV_INCLUDE_DIR/MPV_LIBRARY")
endif()

# MinGW's libstdc++ keeps the terminal support for std::print in stdc++exp
if(MINGW AND CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(EXTRA_LIBS stdc++exp)
endif()

# ── Executable ────────────────────────────────────────────────────────────────

add_executable(ytm-term src/main.cc)

target_include_directories(ytm-term PRIVATE
  ${MPV_INCLUDE_DIR}
  external
  src
)

target_link_libraries(ytm-term PRIVATE
  ${MPV_LIBRARY}
  ftxui::component
  ftxui::dom
  ftxui::screen
  ${EXTRA_LIBS}
)

# ── Install ───────────────────────────────────────────────────────────────────

install(TARGETS ytm-term RUNTIME DESTINATION bin)
