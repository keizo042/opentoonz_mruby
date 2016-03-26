#include <stdio.h>
#include <toonz_plugin.h>
#include <toonz_hostif.h>

#include <utils/rect.hpp>
#include <utils/interf_holder.hpp>


toonz::host_interface_t *ifactory_ = NULL;

int toonz_mruby_init(toonz::host_interface_t *hostif)
{
    ifactory_ = hostif;
    return TOONZ_OK;
}
