/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "EGL/globals.h"

VKGL_THREADLOCAL EGL::eglDisplay_t* EGL::g_current_egl_display_ptr = nullptr;
VKGL_THREADLOCAL EGLint 			EGL::g_current_egl_error 	= EGL_SUCCESS;

__attribute__((constructor))
static void load_egl_library_func(void)
{
	vkgl_printf("%s", __func__);
}