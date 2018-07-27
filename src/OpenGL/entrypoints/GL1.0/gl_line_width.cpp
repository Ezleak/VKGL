#include "OpenGL/entrypoints/GL1.0/gl_line_width.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glLineWidth(GLfloat width)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLLineWidth(dispatch_table_ptr->bound_context_ptr,
                                     width);
}

void vkglLineWidth_with_validation(VKGL::Context* in_context_ptr,
                                   const GLfloat& in_width)
{
    todo;
}