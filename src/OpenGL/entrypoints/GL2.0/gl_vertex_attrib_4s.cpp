/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL2.0/gl_vertex_attrib_4s.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLuint&  in_index,
                     const GLshort& in_x,
                     const GLshort& in_y,
                     const GLshort& in_z,
                     const GLshort& in_w)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY glVertexAttrib4s(GLuint  index,
                                             GLshort x,
                                             GLshort y,
                                             GLshort z,
                                             GLshort w)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLVertexAttrib4s(dispatch_table_ptr->bound_context_ptr,
                                          index,
                                          x,
                                          y,
                                          z,
                                          w);
}

void vkglVertexAttrib4s_execute(VKGL::Context* in_context_ptr,
                                const GLuint&  in_index,
                                const GLshort& in_x,
                                const GLshort& in_y,
                                const GLshort& in_z,
                                const GLshort& in_w)
{
    const GLshort data[] =
    {
        in_x,
        in_y,
        in_z,
        in_w
    };

    in_context_ptr->set_vertex_attribute(in_index,
                                         VKGL::GetSetArgumentType::Short,
                                         4,
                                         false, /* in_normalized */
                                         data);
}

void vkglVertexAttrib4s_with_validation(VKGL::Context* in_context_ptr,
                                        const GLuint&  in_index,
                                        const GLshort& in_x,
                                        const GLshort& in_y,
                                        const GLshort& in_z,
                                        const GLshort& in_w)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_x,
                 in_y,
                 in_z,
                 in_w) )
    {
        vkglVertexAttrib4s_execute(in_context_ptr,
                                   in_index,
                                   in_x,
                                   in_y,
                                   in_z,
                                   in_w);
    }
}
