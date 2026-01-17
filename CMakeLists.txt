cmake_minimum_required(VERSION 3.15)
project(
  ${SKBUILD_PROJECT_NAME}
  VERSION ${SKBUILD_PROJECT_VERSION}
  LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS
    ON
    CACHE INTERNAL "")

# NOTE: Nix workaround for clang-tidy and clangd
# In Nix environments, C++ standard library headers are in the Nix store
# (e.g., /nix/store/.../include), not in standard system locations.
# This workaround explicitly adds these paths to compile_commands.json so that
# clang-tidy and clangd can find them.
#
# Reference: https://mzhang.io/posts/2022-03-03-clangd-in-nix/
#
# Alternative: Use a CMake toolchain file to properly configure the compiler.
# However, this simple workaround is sufficient for development tools.
if(CMAKE_EXPORT_COMPILE_COMMANDS)
  set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES
      ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
  
  # Create symlink to compile_commands.json in project root for clang-tidy
  # This allows clang-tidy to find the compilation database without -p flag
  add_custom_target(
    symlink_compile_commands ALL
    COMMAND ${CMAKE_COMMAND} -E remove -f ${CMAKE_SOURCE_DIR}/compile_commands.json
    COMMAND ${CMAKE_COMMAND} -E create_symlink
            build/compile_commands.json
            ${CMAKE_SOURCE_DIR}/compile_commands.json
    COMMENT "Creating symlink to compile_commands.json in project root")
endif()

# add the modules
add_subdirectory(python)
add_subdirectory(src)
add_subdirectory(tests)
