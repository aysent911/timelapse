cmake_minimum_required(VERSION 3.26)
project(never_cli)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)
set(CMAKE_INSTALL_PREFIX "/usr/local")

message("When installed, executable binaries will be available in ${CMAKE_INSTALL_PREFIX}")

## DEP: pkg-config
find_package(PkgConfig REQUIRED)

## DEP: ffmpeg
pkg_check_modules(LIBAV REQUIRED IMPORTED_TARGET
        libavformat
        libavcodec
        libswscale
        libavutil
)

## Target: timelapse
add_executable(timelapse timelapse.cpp  helper.cpp helper.h)
target_link_libraries(timelapse PRIVATE PkgConfig::LIBAV -lm $<$<BOOL:${MINGW}>:ws2_32>)
install(TARGETS timelapse DESTINATION bin)

