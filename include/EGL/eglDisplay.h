#ifndef EGL_EGLDISPLAY_H
#define EGL_EGLDISPLAY_H


namespace EGL
{

class eglDisplay_t {
private:
	
	void* old_tls_ptr;
	
	void* current_bind_egl_context_p;
	
public:
	
	inline void* 	get_old_tls_ptr (void) 					{return old_tls_ptr;}
	inline void 	set_old_tls_ptr (void* in_old_tls_ptr) 	{old_tls_ptr = in_old_tls_ptr;}
	
	inline void* 	get_current_bind_egl_context_p (void) 					{return current_bind_egl_context_p;}
	inline void 	set_current_bind_egl_context_p (void* in_current_bind_egl_context_p) 	{current_bind_egl_context_p = in_current_bind_egl_context_p;}
	
	
	eglDisplay_t ();
	~eglDisplay_t ();
	
};

}//namespace EGL

#endif //EGL_EGLDISPLAY_H