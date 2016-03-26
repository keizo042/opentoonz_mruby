cmake_minimum_required(VERSION 3.0)
project(opentoonz_mruby C CXX)
set(PLUGINSDK_ROOT ../plugin_sdk/core)
set(PLUGINSDK_UTILS_PATH ../plugin_sdk)
set(MRUBY_ROOT ../mruby)


set(HEADERS
    ${PLUGINSDK_ROOT}/toonz_plugin.h
    ${PLUGINSDK_ROOT}/toonz_hostif.h)

set(SOURCES
    mrb_opentoonz_core.cpp)


if(APPLE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
endif(APPLE)


include_directories(opentoonz_mruby mruby/include)
include_directories(opentoonz_mruby mruby)
link_directories(${MRUBY_LIBMRUBY_DIR})

add_library(opentoonz_mruby SHARED ${HEADERS} ${SOURCES})

target_include_directories(opentoonz_mruby PRIVATE "${MRUBY_ROOT}/include" )


set_target_properties(opentoonz_mruby PROPERTIES
    PREFIX ""
    SUFFIX ".plugin")

include_directories(${PLUGINSDK_ROOT} ${PLUGINSDK_UTILS_PATH})
