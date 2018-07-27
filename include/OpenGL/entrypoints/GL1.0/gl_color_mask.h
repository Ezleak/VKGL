#ifndef VKGL_GL_COLOR_MASK_H
#define VKGL_GL_COLOR_MASK_H

#include "OpenGL/types.h"

VKGL_API void VKGL_APIENTRY glColorMask(GLboolean red,
                                        GLboolean green,
                                        GLboolean blue,
                                        GLboolean alpha);

void vkglColorMask_with_validation(VKGL::Context*   in_context_ptr,
                                   const GLboolean& in_red,
                                   const GLboolean& in_green,
                                   const GLboolean& in_blue,
                                   const GLboolean& in_alpha);

#endif /* VKGL_GL_COLOR_MASK_H */