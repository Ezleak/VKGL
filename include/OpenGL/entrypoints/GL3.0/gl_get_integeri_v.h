/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_GET_INTEGERI_V_H
#define VKGL_GL_GET_INTEGERI_V_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglGetIntegeri_v(GLenum target,
                                              GLuint index,
                                              GLint* data);

#endif /* VKGL_GL_GET_INTEGERI_V_H */