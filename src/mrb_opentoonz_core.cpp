#include <stdio.h>

#include <toonz_plugin.h>
#include <toonz_hostif.h>

#include <utils/rect.hpp>
#include <utils/interf_holder.hpp>

#include <mruby.h>
#include <mruby/compile.h>
#include <mruby/object.h>
#include <mruby/class.h>
#include <mruby/string.h>


toonz::host_interface_t *ifactory_ = NULL;

int toonz_mruby_init(toonz::host_interface_t *hostif)
{
    ifactory_ = hostif;
    return TOONZ_OK;
}
