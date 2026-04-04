cmake_minimum_required(VERSION 3.15)

# Fallbacks for direct CMake invocation outside scikit-build.
if(NOT DEFINED SKBUILD_PROJECT_NAME)
  set(SKBUILD_PROJECT_NAME phys)
endif()

if(NOT DEFINED SKBUILD_PROJECT_VERSION)
  set(SKBUILD_PROJECT_VERSION 0.0.0)
endif()

project(
  ${SKBUILD_PROJECT_NAME}
  VERSION ${SKBUILD_PROJECT_VERSION}
  LANGUAGES CXX)

option(PHYS_ENABLE_CLANG_TIDY "Enable clang-tidy during C++ compilation" OFF)
if(PHYS_ENABLE_CLANG_TIDY)
  find_program(CLANG_TIDY_EXE NAMES clang-tidy)
  if(CLANG_TIDY_EXE)
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
  else()
    message(WARNING "PHYS_ENABLE_CLANG_TIDY is ON, but clang-tidy was not found.")
  endif()
endif()
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# NOTE: nix requires extra steps because include folders are in the nix store
# https://mzhang.io/posts/2022-03-03-clangd-in-nix/
#
# though, this is not good practice according to cmake docs
if(CMAKE_EXPORT_COMPILE_COMMANDS)
  set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES
      ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
endif()

# add the modules
add_subdirectory(python)
add_subdirectory(src)
add_subdirectory(tests)
