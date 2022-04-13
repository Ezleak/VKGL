
#include "EGL/egl.h"

#include "EGL/eglDisplay.h"


EGL::eglDisplay_t::eglDisplay_t ()
		:old_tls_ptr					(nullptr),
		current_bind_egl_context_p	(nullptr)
{

}

EGL::eglDisplay_t::~eglDisplay_t ()
{

}
	


