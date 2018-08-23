/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_VERTEX_ATTRIB_4D_H
#define VKGL_GL_VERTEX_ATTRIB_4D_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY vkglVertexAttrib4d(GLuint   index,
                                               GLdouble x,
                                               GLdouble y,
                                               GLdouble z,
                                               GLdouble w);

#endif /* VKGL_GL_VERTEX_ATTRIB_4D_H */