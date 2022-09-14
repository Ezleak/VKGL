/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_REFERENCE_H
#define VKGL_GL_REFERENCE_H

#define GL_GLEXT_PROTOTYPES

#include "Khronos/GL/gl.h"
#include "OpenGL/reference.h"
#include <chrono>

namespace OpenGL
{
    typedef struct GLPayload
    {
        GLuint             id;
        OpenGL::TimeMarker object_creation_time;
        OpenGL::TimeMarker time_marker;

        GLPayload(const GLuint&             in_id,
                        const OpenGL::TimeMarker& in_time_marker,
                        const OpenGL::TimeMarker& in_object_creation_time)
           :id                  (in_id),
            object_creation_time(in_object_creation_time),
            time_marker         (in_time_marker)
        {
            /* Stub */
        }

        bool operator==(const GLPayload& in_ref) const
        {
            return (id                   == in_ref.id                   &&
                    object_creation_time == in_ref.object_creation_time &&
                    time_marker          == in_ref.time_marker);
        }

        bool operator!=(const GLPayload& in_ref) const
        {
            return (id                   != in_ref.id                   ||
                    object_creation_time != in_ref.object_creation_time ||
                    time_marker          != in_ref.time_marker);
        }
    } GLPayload;

    struct GLContextStatePayload;

    typedef ReferenceBase<GLPayload>             GLBufferReference;
    typedef ReferenceBase<GLContextStatePayload> GLContextStateReference;
    typedef ReferenceBase<GLPayload>             GLFramebufferReference;
    typedef ReferenceBase<GLPayload>             GLProgramReference;
    typedef ReferenceBase<GLPayload>             GLRenderbufferReference;
    typedef ReferenceBase<GLPayload>             GLShaderReference;
    typedef ReferenceBase<GLPayload>             GLTextureReference;
    typedef ReferenceBase<GLPayload>             GLVAOReference;

    typedef std::unique_ptr<GLProgramReference, std::function<void(GLProgramReference*)> > GLProgramReferenceUniquePtr;

    typedef struct GLContextStatePayload
    {
        OpenGL::TimeMarker time_marker;

        GLContextStatePayload(const OpenGL::TimeMarker& in_time_marker);

        bool operator==(const GLContextStatePayload& in_ref) const
        {
            return (time_marker == in_ref.time_marker);
        }

        bool operator!=(const GLContextStatePayload& in_ref) const
        {
            return (time_marker != in_ref.time_marker);
        }
    } GLContextStatePayload;
}

#endif /* VKGL_GL_REFERENCE_H */