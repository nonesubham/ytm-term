cmake_minimum_required(VERSION 3.16)
project(ytm-term LANGUAGES CXX)

# --- Options -----------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# --- Directories -------------------------------------------------------------
set(INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/includes")
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

# --- Collect sources ---------------------------------------------------------
file(GLOB_RECURSE HEADERS "${INC_DIR}/*.hh" "${INC_DIR}/*.hpp")
file(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp")

# --- Create executable -------------------------------------------------------
add_executable(ytm-term ${SOURCES} ${HEADERS})

# --- Include directories -----------------------------------------------------
target_include_directories(ytm-term PUBLIC ${INC_DIR})

# --- Compiler-specific flags -------------------------------------------------
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(ytm-term PRIVATE -Wall -Wextra -Wpedantic)
endif()

# --- Installation (optional) -------------------------------------------------
install(TARGETS ytm-term DESTINATION bin)