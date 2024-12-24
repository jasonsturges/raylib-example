
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(RaylibExample VERSION 1.0)

# Find Raylib (installed via Homebrew)
find_package(raylib REQUIRED CONFIG)

# Set the executable
add_executable(${PROJECT_NAME} main.c)

# Link Raylib and required macOS frameworks
target_link_libraries(${PROJECT_NAME}
    raylib
    "-framework OpenGL"
    "-framework Cocoa"
    "-framework IOKit"
)

# Suppress terminal window on Windows 
# set(CMAKE_EXE_LINKER_FLAGS "-Wl,-subsystem,windows")
# Suppres terminal window on macOS
set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE TRUE)

# Create the web target (for Emscripten)
if(EMSCRIPTEN)
    add_executable(RaylibWeb main.c)
    target_compile_options(RaylibWeb PRIVATE
        "-sUSE_GLFW=3"
        "-sUSE_WEBGL2=1"
        "-sASSERTIONS=1"
    )
    target_link_options(RaylibWeb PRIVATE
        "-sUSE_GLFW=3"
        "-sUSE_WEBGL2=1"
        "-sASSERTIONS=1"
        "-sTOTAL_MEMORY=64MB"
        "--shell-file ${CMAKE_SOURCE_DIR}/shell_minimal.html"
    )
endif()
