
#include "EGL/eglContext.h"
#include "EGL/eglSurface.h"

#include "Common/globals.h"


EGL::eglContext_t::eglContext_t()
     :m_is_debug_context             (false),
     m_is_forward_compatible_context(false),
     m_n_layer_plane                (0),
     m_major_version				(3),
     m_minor_version				(2),
     m_swap_interval				(0)
{
    memset(&m_pixel_format_reqs,
           0,
           sizeof(m_pixel_format_reqs) );
}

EGL::eglContext_t::~eglContext_t()
{
    //m_gl_context_ptr.reset();

    //m_vk_backend_ptr.reset();
}

void EGL::eglContext_t::get_rendering_surface_size(uint32_t* out_width_ptr,
                                uint32_t* out_height_ptr) const
{
	eglSurface_t* egl_surf = (eglSurface_t *)get_egl_surface_p();
	
	uint32_t width = 0;
	uint32_t height = 0;
	
	if (egl_surf) {
		width = egl_surf->get_width();
		height = egl_surf->get_height();
	}
	
	if (out_width_ptr) {*out_width_ptr = width;}
	if (out_height_ptr) {*out_height_ptr = height;}
	
}

void EGL::eglContext_t::set_pixel_format_reqs(const uint32_t& in_n_alpha_bits,
                                const uint32_t& in_n_blue_bits,
                                const uint32_t& in_n_depth_bits,
                                const uint32_t& in_n_green_bits,
                                const uint32_t& in_n_red_bits,
                                const uint32_t& in_n_stencil_bits)
{
        m_pixel_format_reqs.	n_alpha_bits  = in_n_alpha_bits;
        m_pixel_format_reqs.    n_blue_bits   = in_n_blue_bits;
        m_pixel_format_reqs.    n_depth_bits  = in_n_depth_bits;
        m_pixel_format_reqs.    n_green_bits  = in_n_green_bits;
        m_pixel_format_reqs.    n_red_bits    = in_n_red_bits;
        m_pixel_format_reqs.    n_stencil_bits = in_n_stencil_bits;
}
