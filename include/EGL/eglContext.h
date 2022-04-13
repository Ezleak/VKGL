#ifndef EGL_EGLCONTEXT_H
#define EGL_EGLCONTEXT_H

#include "Common/types.h"


namespace EGL {

class eglContext_t : public VKGL::IWSIContext {
public:
	
    /* Public functions */
    
    eglContext_t();
    ~eglContext_t();

    const VKGL::PixelFormatRequirements& get_pixel_format_requirements() const
    {
        return m_pixel_format_reqs;
    }

    const int& get_swap_interval() const
    {
        return m_swap_interval;
    }

    const bool& is_debug_context() const
    {
        return m_is_debug_context;
    }

    const bool& is_forward_compatible_context() const
    {
        return m_is_forward_compatible_context;
    }

    const uint32_t& get_major_version() const
    {
        return m_major_version;
    }

    const uint32_t& get_minor_version() const
    {
        return m_minor_version;
    }

    const uint32_t& get_n_layer_plane() const
    {
        return m_n_layer_plane;
    }

    void get_rendering_surface_size(uint32_t* out_width_ptr,
                                    uint32_t* out_height_ptr) const;

    void set_swap_interval(const int& in_swap_interval)
    {
        m_swap_interval = in_swap_interval;
    }
    
    void set_pixel_format_reqs(const uint32_t& in_n_alpha_bits,
                                const uint32_t& in_n_blue_bits,
                                const uint32_t& in_n_depth_bits,
                                const uint32_t& in_n_green_bits,
                                const uint32_t& in_n_red_bits,
                                const uint32_t& in_n_stencil_bits);
    
    
    inline void* 	get_gl_context_p (void) const						{return gl_context_p;}
	inline void 	set_gl_context_p (void* in_gl_context_p) 			{gl_context_p = in_gl_context_p;}
	
    inline void* 	get_vk_backend_p (void) const 						{return vk_backend_p;}
	inline void 	set_vk_backend_p (void* in_vk_backend_p) 		{vk_backend_p = in_vk_backend_p;}
	
    inline void* 	get_egl_surface_p (void) const						{return egl_surface_p;}
	inline void 	set_egl_surface_p (void* in_egl_surface_p)		 	{egl_surface_p = in_egl_surface_p;}
	

private:
    /* Private functions */
    
    /* Private variables */
	void * gl_context_p;
	void * vk_backend_p;
	
	void * egl_surface_p;
	
    //OpenGL::ContextUniquePtr   m_gl_context_ptr;
    //OpenGL::VKBackendUniquePtr m_vk_backend_ptr;

    bool                          m_is_debug_context;
    bool                          m_is_forward_compatible_context;
    uint32_t                      m_major_version;
    uint32_t                      m_minor_version;
    uint32_t                      m_n_layer_plane;
    VKGL::PixelFormatRequirements m_pixel_format_reqs;
    int                           m_swap_interval;
};

}//namespace EGL

#endif //EGL_EGLCONTEXT_H