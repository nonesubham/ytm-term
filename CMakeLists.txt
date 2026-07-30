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
  PATHS "client.h"
  PATH_SUFFIXES mpv
)

find_library(MPV_LIBRARY
  NAMES mpv libmpv
  PATHS "${CMAKE_CURRENT_SOURCE_DIR}"
)

if(NOT MPV_INCLUDE_DIR OR NOT MPV_LIBRARY)
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(MPV REQUIRED mpv)
  set(MPV_INCLUDE_DIR "${MPV_INCLUDE_DIRS}")
  set(MPV_LIBRARY "${MPV_LIBRARIES}")
endif()

# ── Sources ───────────────────────────────────────────────────────────────────

set(SOURCES
  src/main.cc
)

# ── Executable ────────────────────────────────────────────────────────────────

add_executable(ytm-term ${SOURCES})

target_include_directories(ytm-term PRIVATE
  ${MPV_INCLUDE_DIR}
  src
)

target_link_libraries(ytm-term PRIVATE
  ${MPV_LIBRARY}
  ftxui::component
  ftxui::dom
  ftxui::screen
  stdc++exp
)

# ── Install ───────────────────────────────────────────────────────────────────

install(TARGETS ytm-term RUNTIME DESTINATION bin)