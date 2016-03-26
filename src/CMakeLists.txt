project(opentoonz_mruby)
set(PLUGINSDK_ROOT ../plugin_sdk/core)
set(PLUGINSDK_UTILS_PATH ../plugin_sdk)


set(HEADERS
    ${PLUGINSDK_ROOT}/toonz_plugin.h
    ${PLUGINSDK_ROOT}/toonz_hostif.h)

set(SOURCES
    mrb_opentoonz_core.c)

if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
endif(APPLE)

add_library(opentoonz_mruby SHARED ${HEADERS} ${SOURCES})

set_target_properties(opentoonz_mruby PROPATIES
    PREFIX ""
    SUFFIX ".plugin")

include_directories(${PLUGINSDK_ROOT} ${PLUGINSDK_UTILS_PATH})
