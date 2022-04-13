/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef EGL_GLOBALS_H
#define EGL_GLOBALS_H

#include "EGL/egl.h"
#include "EGL/eglDisplay.h"
#include "Common/globals.h"

namespace EGL
{
    VKGL_THREADLOCAL extern eglDisplay_t* g_current_egl_display_ptr;
    VKGL_THREADLOCAL extern EGLint 		g_current_egl_error;
    
    inline eglDisplay_t* get_current_display(void)
    {
    	return g_current_egl_display_ptr;
    }
    
    inline void set_current_display(eglDisplay_t* in_display)
    {
    	g_current_egl_display_ptr = in_display;
    }
    
    inline EGLint get_current_egl_error(void)
    {
    	return g_current_egl_error;
    }
    
    inline void set_current_egl_error(EGLint in_egl_error)
    {
    	g_current_egl_error = in_egl_error;
    }
}

#endif /* EGL_GLOBALS_H */