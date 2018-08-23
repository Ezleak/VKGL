/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_TEX_PARAMETERI_H
#define VKGL_GL_TEX_PARAMETERI_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglTexParameteri(GLenum target,
                                              GLenum pname,
                                              GLint  param);

#endif /* VKGL_GL_TEX_PARAMETERI_H */