#include <stdio.h>

#include <toonz_plugin.h>
#include <toonz_hostif.h>

#include <utils/rect.hpp>
#include <utils/interf_holder.hpp>
#include <utils/param_traits.hpp>
#include <utils/affine.hpp>


#ifdef __cplusplus
extern "C" {
#endif


#include <mruby/value.h>
#include <mruby.h>
#include <mruby/data.h>
#include <mruby/compile.h>
#include <mruby/object.h>
#include <mruby/numeric.h>
#include <mruby/class.h>
#include <mruby/string.h>
#include <mruby/variable.h>
#include <mruby/proc.h>
    /*
mrb_int mrb_get_args(mrb_state*, mrb_args_format , ...);
struct RClass* mrb_class_get(mrb_state*, const char*);
struct RClass* mrb_define_class(mrb_state*, const char*, struct RClass*);
struct RClass* mrb_define_class_under(mrb_state*, struct RClass*, const char*, struct RClass*);
*/


#ifdef __cplusplus
}
#endif

toonz::host_interface_t *ifactory_ = NULL;
mrb_state *default_state = NULL;

void mrb_toonz_init(mrb_state *mrb);

int toonz_mruby_init(toonz::host_interface_t *hostif)
{
    mrb_state *mrb = mrb_open();
    ifactory_ = hostif;
    return TOONZ_OK;
}

void toonz_mruby_finish()
{
    mrb_state *mrb;
    mrb_close(mrb);
    return;
}


void affine_delete(mrb_state *mrb, void *p)
{
    delete((ToonzAffine*)p);
}

mrb_value mrb_toonz_release_interf(mrb_state *mrb, mrb_value self)
{
    mrb_value v;
    mrb_get_args(mrb, "o", &v);
    return mrb_nil_value();
}

mrb_value mrb_toonz_grab_interf(mrb_state *mrb, mrb_value self)
{
    mrb_value v;
    mrb_get_args(mrb, "o", &v);
    return mrb_nil_value();
}

static const mrb_data_type mrb_toonz_utils_affine_data = {
    "mrb_toonz_utils_affine_data", affine_delete
};

mrb_value mrb_toonz_utils_affine_init(mrb_state *mrb, mrb_value self)
{
    auto *affine =  (ToonzAffine*)DATA_PTR(self);
    struct RClass *class_toonz, *class_affine;
    class_toonz = mrb_class_get(mrb, "Toonz");
    class_affine = mrb_class_get_under(mrb, class_toonz, "Affine");

    mrb_value u,v,w,x,y,z;
    if(affine) {
        delete(affine);
    }
    mrb_data_init(self, NULL, &mrb_toonz_utils_affine_data);
    mrb_get_args(mrb, "|oooooo", &u, &v, &w, &x, &y, &z);
    if(mrb_nil_p(u)){
        affine = new ToonzAffine();
    }else if( true == mrb_obj_is_kind_of(mrb, u, class_affine)) {
        affine = new ToonzAffine(*(const ToonzAffine*)DATA_PTR(u));
    }else{
    affine = new ToonzAffine();

    }

    if(affine == NULL) {
        mrb_raise(mrb, E_RUNTIME_ERROR, "fail to new ToonzAffine");
    }
    mrb_data_init(self, affine, &mrb_toonz_utils_affine_data);
    return self;
}

mrb_value mrb_toonz_utils_affine_det(mrb_state *mrb, mrb_value self)
{
    auto *affine =  (ToonzAffine*)DATA_PTR(self);
    return mrb_float_value(mrb, (mrb_float)affine->det());

}
mrb_value mrb_toonz_utils_affine_inv(mrb_state *mrb, mrb_value self)
{
    auto *affine =  (ToonzAffine*)DATA_PTR(self);
    auto retv = affine->inv();
    return self;
}

mrb_value mrb_toonz_utils_affine_isIdentify(mrb_state *mrb, mrb_value self)
{
    auto *affine =  (ToonzAffine*)DATA_PTR(self);
    mrb_float v;

    mrb_get_args(mrb, "f", &v);
    if(affine->isIdentity(v)) {
        return mrb_true_value();
    }else{
        return mrb_false_value();
    }

    return mrb_false_value();
}

mrb_value  mrb_toonz_utils_affine_isIsotropic(mrb_state *mrb, mrb_value self)
{
    auto *affine =  (ToonzAffine*)DATA_PTR(self);
    mrb_float v;
    mrb_get_args(mrb,"f",&v);
    return mrb_float_value(mrb, (mrb_float)affine->isIsotropic((double)v));
}

mrb_value mrb_toonz_utils_affine_plus(mrb_state *mrb, mrb_value self)
{
    auto *affine =  (ToonzAffine*)DATA_PTR(self);
    mrb_value v;
    mrb_get_args(mrb,"o",&v);
    return self;
}

mrb_value mrb_toonz_utils_affine_subtract(mrb_state *mrb, mrb_value self)
{
    auto *affine =  (ToonzAffine*)DATA_PTR(self);
    mrb_value v;
    mrb_get_args(mrb,"o",&v);
    return self;
}

mrb_value mrb_toonz_utils_affine_multi(mrb_state *mrb, mrb_value self)
{
    auto *affine =  (ToonzAffine*)DATA_PTR(self);

    mrb_value v;
    mrb_get_args(mrb,"o",&v);
    return self;
}

mrb_value mrb_toonz_utils_affine_div(mrb_state *mrb, mrb_value self)
{
    auto *affine =  (ToonzAffine*)DATA_PTR(self);
    mrb_value v;
    mrb_get_args(mrb,"o",&v);
    return self;
}

mrb_value mrb_toonz_utils_affine_mutil_and_assign(mrb_state *mrb, mrb_value self)
{
    auto *affine = (ToonzAffine*)DATA_PTR(self);
    mrb_value v;
    mrb_get_args(mrb, "o", &v);
    return self;
}

mrb_value mrb_toonz_utils_affine_assing(mrb_state *mrb, mrb_value self)
{
    auto *affine = (ToonzAffine*)DATA_PTR(self);
    mrb_value v;
    mrb_get_args(mrb, "o", &v);
    return self;
}

mrb_value mrb_toonz_utils_affine_eq(mrb_state *mrb, mrb_value self)
{
    auto *affine = (ToonzAffine*)DATA_PTR(self);
    mrb_value v;
    mrb_get_args(mrb, "o", &v);
    return self;
}

mrb_value mrb_toonz_utils_affine_not_eq(mrb_state *mrb, mrb_value self)
{
    auto *affine = (ToonzAffine*)DATA_PTR(self);
    mrb_value v;
    mrb_get_args(mrb, "o", &v);
    return self;
}

mrb_value mrb_toonz_utils_affine_place(mrb_state *mrb, mrb_value self)
{
    auto *affine = (ToonzAffine*)DATA_PTR(self);
    mrb_value v;
    mrb_get_args(mrb, "o", &v);
    return self;
}

void mrb_toonz_utils_affine_point_delete(mrb_state *mrb, void *p)
{
    delete((ToonzPoint*)p);
}

static const mrb_data_type mrb_toonz_utils_affine_point_data_type = {
    "mrb_toonz_utils_affine_point_data_type", mrb_toonz_utils_affine_point_delete
};

mrb_value mrb_toonz_utils_affine_point_init(mrb_state *mrb, mrb_value self)
{
   auto *point = (ToonzPoint*)DATA_PTR(self);
   mrb_value x ,y ;
    if(point) {
        delete(point);
    }

    x = mrb_float_value(mrb, 0) , y = mrb_float_value(mrb,0);
    mrb_get_args(mrb, "|oo",&x, &y);
    if( true == mrb_float_p(x) && true == mrb_float_p(x))
    {
        point = new ToonzPoint(mrb_to_flo(mrb,x), mrb_to_flo(mrb,y));
    }else {
        point = new ToonzPoint;
    }
    mrb_data_init(self, point, &mrb_toonz_utils_affine_point_data_type);
    return self;
}

void mrb_toonz_utils_rect_rect_delete(mrb_state *mrb, void *p)
{
    delete( (ToonzRect*)p );
    return;
}

mrb_data_type mrb_toonz_utils_rect_type = {
    "mrb_toonz_utils_rect_rect_data_type", mrb_toonz_utils_rect_rect_delete
};

mrb_value mrb_toonz_utils_rect_rect_init(mrb_state *mrb, mrb_value self)
{
    mrb_value v;
    mrb_get_args(mrb,"o",&v);
    return self;
}

mrb_value mrb_toonz_utils_rect_rect_equals(mrb_state *mrb, mrb_value self)
{
    mrb_value v;
    mrb_get_args(mrb,"o",&v);
    return self;
}

mrb_value mrb_toonz_utils_rect_rect_add(mrb_state *mrb, mrb_value self)
{
    mrb_value v;
    mrb_get_args(mrb,"o",&v);
    return self;
}

mrb_value mrb_toonz_utils_rect_rect_subtract(mrb_state *mrb, mrb_value self)
{
    mrb_value v;
    mrb_get_args(mrb,"o",&v);
    return self;
}

mrb_value mrb_toonz_utils_rect_rect_multi(mrb_state *mrb, mrb_value self)
{
    mrb_value v;
    mrb_get_args(mrb,"o",&v);
    return self;
}

mrb_value mrb_toonz_utils_rect_rect_add_and_assign(mrb_state *mrb, mrb_value self)
{
    mrb_value v;
    mrb_get_args(mrb,"o",&v);
    return self;
}

mrb_value mrb_toonz_utils_rect_rect_multi_and_assign(mrb_state *mrb, mrb_value self)
{
    mrb_value v;
    mrb_get_args(mrb,"o",&v);
    return self;
}

mrb_value mrb_toonz_utils_rect_rect_isEmpty(mrb_state *mrb, mrb_value self)
{
    mrb_value v;
    mrb_get_args(mrb,"o",&v);
    return self;
}

mrb_value mrb_toonz_utils_rect_rect_isContained(mrb_state *mrb, mrb_value self)
{
    mrb_value v;
    mrb_get_args(mrb,"o",&v);
    return self;
}

mrb_value mrb_toonz_utils_rect_rect_isOverlapped(mrb_state *mrb, mrb_value self)
{
    mrb_value v;
    mrb_get_args(mrb,"o",&v);
    return self;
}

mrb_value mrb_toonz_utils_rect_rect_enlarge(mrb_state *mrb, mrb_value self)
{
    mrb_value v;
    mrb_get_args(mrb,"o",&v);
    return self;
}

void mrb_toonz_init(mrb_state *mrb) 
{
    struct RClass *toonz, 
                  *utils, 
                  *affine, *point,
                  *rect, *utils_param,
                  *core, 
                  *hostif, *core_params, *core_plugin;

    toonz           = mrb_define_class(mrb,  "Toonz",       mrb->object_class);

    utils           = mrb_define_class_under(mrb,   toonz, "Utils",         mrb->object_class);

    affine          = mrb_define_class_under(mrb,   utils, "Affine",        mrb->object_class);
    rect            = mrb_define_class_under(mrb,   utils, "Rect",          mrb->object_class);
    utils_param     = mrb_define_class_under(mrb,   utils, "Param",         mrb->object_class);
    point           = mrb_define_class_under(mrb,   affine, "Point",        mrb->object_class);

    core            = mrb_define_class_under(mrb,   toonz,  "Core",         mrb->object_class);
    hostif          = mrb_define_class_under(mrb,   core,   "Hostif",       mrb->object_class);
    core_params     = mrb_define_class_under(mrb,   core,   "Param",        mrb->object_class);
    core_plugin     = mrb_define_class_under(mrb,   core,   "Plugin",       mrb->object_class);

    mrb_define_class_method(mrb,    toonz,      "relase_interf",  mrb_toonz_release_interf,   MRB_ARGS_REQ(1));
    mrb_define_class_method(mrb,    toonz,      "grub_interf",  mrb_toonz_grab_interf,   MRB_ARGS_REQ(1));

    mrb_define_method(mrb,      affine,         "initialize",   mrb_toonz_utils_affine_init,      MRB_ARGS_OPT(6));

    mrb_define_method(mrb,      point,          "initialize",   mrb_toonz_utils_affine_point_init,    MRB_ARGS_OPT(2));
}
