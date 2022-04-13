/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_REFERENCE_H
#define VKGL_VK_REFERENCE_H

#define GL_GLEXT_PROTOTYPES

#include "Khronos/GL/gl.h"
#include "Anvil/include/misc/types.h"
#include "OpenGL/reference.h"
#include <chrono>

namespace OpenGL
{
    typedef struct VKBufferPayload
    {
        OpenGL::TimeMarker  backend_buffer_creation_time_marker;
        Anvil::Buffer*      buffer_ptr;
        OpenGL::TimeMarker  frontend_object_creation_time_marker;
        GLuint              id;

        VKBufferPayload(const GLuint&             in_id,
                              const OpenGL::TimeMarker& in_frontend_object_creation_time_marker,
                              Anvil::Buffer*            in_buffer_ptr,
                              const OpenGL::TimeMarker& in_backend_buffer_creation_time_marker)
           :backend_buffer_creation_time_marker   (in_backend_buffer_creation_time_marker),
            buffer_ptr                            (in_buffer_ptr),
            frontend_object_creation_time_marker  (in_frontend_object_creation_time_marker),
            id                                    (in_id)
        {
            /* Stub */
        }

        bool operator==(const VKBufferPayload& in_ref) const
        {
            return (id                                     == in_ref.id                                     &&
                    backend_buffer_creation_time_marker    == in_ref.backend_buffer_creation_time_marker    &&
                    frontend_object_creation_time_marker   == in_ref.frontend_object_creation_time_marker);
        }

        bool operator!=(const VKBufferPayload& in_ref) const
        {
            return (id                                     != in_ref.id                                     ||
                    backend_buffer_creation_time_marker    != in_ref.backend_buffer_creation_time_marker    ||
                    frontend_object_creation_time_marker   != in_ref.frontend_object_creation_time_marker);
        }
    } VKBufferPayload;

    typedef struct VKImagePayload
    {
        OpenGL::TimeMarker  backend_image_creation_time_marker;
        Anvil::Image*       	image_ptr;
        Anvil::ImageView*       image_view_ptr;
        Anvil::Sampler*       	sampler_ptr;
        OpenGL::TimeMarker  frontend_object_creation_time_marker;
        GLuint              id;

        VKImagePayload(const GLuint&              in_id,
                              const OpenGL::TimeMarker& in_frontend_object_creation_time_marker,
                              Anvil::Image*             in_image_ptr,
                              Anvil::ImageView*          in_image_view_ptr,
                              Anvil::Sampler*             in_sampler_ptr,
                              const OpenGL::TimeMarker& in_backend_image_creation_time_marker)
           :backend_image_creation_time_marker (in_backend_image_creation_time_marker),
            image_ptr                           (in_image_ptr),
        	image_view_ptr                       (in_image_view_ptr),
            sampler_ptr                           (in_sampler_ptr),
            frontend_object_creation_time_marker(in_frontend_object_creation_time_marker),
            id                                  (in_id)
        {
            /* Stub */
        }

        bool operator==(const VKImagePayload& in_ref) const
        {
            return (id                                     == in_ref.id                                     &&
                    backend_image_creation_time_marker    == in_ref.backend_image_creation_time_marker    &&
                    frontend_object_creation_time_marker   == in_ref.frontend_object_creation_time_marker);
        }

        bool operator!=(const VKImagePayload& in_ref) const
        {
            return (id                                     != in_ref.id                                     ||
                    backend_image_creation_time_marker    != in_ref.backend_image_creation_time_marker    ||
                    frontend_object_creation_time_marker   != in_ref.frontend_object_creation_time_marker);
        }
    } VKImagePayload;

    typedef struct VKSwapchainPayload
    {
        Anvil::Swapchain*   swapchain_ptr;
        OpenGL::TimeMarker  time_marker;

        VKSwapchainPayload(Anvil::Swapchain*         in_swapchain_ptr,
                                 const OpenGL::TimeMarker& in_time_marker)
           :swapchain_ptr(in_swapchain_ptr),
            time_marker  (in_time_marker)
        {
            /* Stub */
        }

        bool operator==(const VKSwapchainPayload& in_ref) const
        {
            return (time_marker == in_ref.time_marker);
        }

        bool operator!=(const VKSwapchainPayload& in_ref) const
        {
            return (time_marker != in_ref.time_marker);
        }
    } VKSwapchainPayload;

    typedef ReferenceBase<VKBufferPayload>    VKBufferReference;
    typedef ReferenceBase<VKImagePayload>     VKImageReference;
    typedef ReferenceBase<VKSwapchainPayload> VKSwapchainReference;
}

#endif /* VKGL_VK_REFERENCE_H */