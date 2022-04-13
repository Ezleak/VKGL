
#include "EGL/eglSurface.h"


//android native_window for some aux functions
#include <sys/types.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>


EGL::eglSurface_t::eglSurface_t()
     :window				(nullptr),
     width					(0),
     height					(0)
{
    /* Stub */
}

EGL::eglSurface_t::~eglSurface_t()
{
	/* Stub */
}

uint32_t EGL::eglSurface_t::get_width(void)
{
	width = (uint32_t)ANativeWindow_getWidth((ANativeWindow*)get_window());
	
	return width;
}

uint32_t EGL::eglSurface_t::get_height(void)
{
	height = (uint32_t)ANativeWindow_getHeight((ANativeWindow*)get_window());
	
	return height;
}