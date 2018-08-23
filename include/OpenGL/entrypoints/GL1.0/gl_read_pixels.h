/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_READ_PIXELS_H
#define VKGL_GL_READ_PIXELS_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglReadPixels(GLint   x,
                                           GLint   y,
                                           GLsizei width,
                                           GLsizei height,
                                           GLenum  format,
                                           GLenum  type,
                                           void*   pixels);

#endif /* VKGL_GL_READ_PIXELS_H */