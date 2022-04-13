#ifndef EGL_EGLSURFACE_H
#define EGL_EGLSURFACE_H


#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <android/rect.h>


namespace EGL {

class eglSurface_t {
private:
	
	void * window;
	
	uint32_t width;
	uint32_t height;
	
	void * egl_context_p;

public:
	
	/* Public functions */
    
    eglSurface_t();
    ~eglSurface_t();
    
    inline void* 	get_window (void) 					{return window;}
	inline void 	set_window (void* in_window) 	{window = in_window;}
	
	inline void* 	get_egl_context_p (void) 					{return egl_context_p;}
	inline void 	set_egl_context_p (void* in_egl_context_p) 	{egl_context_p = in_egl_context_p;}
	
	uint32_t 		get_width (void);
	uint32_t		get_height (void);
	
};

}//namespace EGL

#endif //EGL_EGLSURFACE_H