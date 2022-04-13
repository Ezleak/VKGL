#ifndef EGL_EGLCONFIG_H
#define EGL_EGLCONFIG_H

#include <stdint.h>

#include "EGL/egl.h"

namespace EGL
{

namespace Config
{

extern int* get_start_config_ptr (void);
extern int* get_end_config_ptr (void);
extern bool check_is_config_type (int* in_config_ptr);
extern bool check_is_config (int* in_config_ptr);
extern int get_max_config_num (void);
extern int* get_next_config_ptr (int* in_config_ptr);

extern int get_config_value_from_attrib (int* in_config_ptr, int in_attrib);
extern bool compare_config_attribs (int* in_config_ptr, int* in_attribs_ptr);
extern void get_configs_for_attribs (int** out_configs_ptr, int in_config_num, int* out_config_num_ptr, int* in_attribs_ptr);


}//namespace Config

}//namespace EGL

#endif //EGL_EGLCONFIG_H