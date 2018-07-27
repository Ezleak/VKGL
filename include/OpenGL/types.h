#ifndef VKGL_TYPES_H
#define VKGL_TYPES_H

#include "Khronos/GL/glcorearb.h"


#if defined(_WIN32)
    #define VKGL_API __declspec(dllexport)
#else
    #define VKGL_API
#endif

#define VKGL_APIENTRY KHRONOS_APIENTRY

#if defined(_WIN32)
    #define VKGL_THREADLOCAL __declspec(thread)
#else
    #error todo
#endif

namespace VKGL
{
    /* Forward declarations */
    class Context;

    /* VKGL GL entrypoints. */
    typedef void           (*PFNVKGLBLENDFUNCPROC)              (Context* context_ptr, const GLenum& in_sfactor, const GLenum& in_dfactor);
    typedef void           (*PFNVKGLCLEARPROC)                  (Context* context_ptr, const GLbitfield& in_mask);
    typedef void           (*PFNVKGLCLEARCOLORPROC)             (Context* context_ptr, const GLfloat& in_red, const GLfloat& in_green, const GLfloat& in_blue, const GLfloat& in_alpha);
    typedef void           (*PFNVKGLCLEARDEPTHPROC)             (Context* context_ptr, const GLdouble& in_depth);
    typedef void           (*PFNVKGLCLEARSTENCILPROC)           (Context* context_ptr, const GLint& in_s);
    typedef void           (*PFNVKGLCOLORMASKPROC)              (Context* context_ptr, const GLboolean& in_red, const GLboolean& in_green, const GLboolean& in_blue, const GLboolean& in_alpha);
    typedef void           (*PFNVKGLCULLFACEPROC)               (Context* context_ptr, const GLenum& in_mode);
    typedef void           (*PFNVKGLDEPTHFUNCPROC)              (Context* context_ptr, const GLenum& in_func);
    typedef void           (*PFNVKGLDEPTHMASKPROC)              (Context* context_ptr, const GLboolean& in_flag);
    typedef void           (*PFNVKGLDEPTHRANGEPROC)             (Context* context_ptr, const GLdouble& in_n, const GLdouble& in_f);
    typedef void           (*PFNVKGLDISABLEPROC)                (Context* context_ptr, const GLenum& in_cap);
    typedef void           (*PFNVKGLDRAWBUFFERPROC)             (Context* context_ptr, const GLenum& in_buf);
    typedef void           (*PFNVKGLENABLEPROC)                 (Context* context_ptr, const GLenum& in_cap);
    typedef void           (*PFNVKGLFINISHPROC)                 (Context* context_ptr);
    typedef void           (*PFNVKGLFLUSHPROC)                  (Context* context_ptr);
    typedef void           (*PFNVKGLFRONTFACEPROC)              (Context* context_ptr, const GLenum& in_mode);
    typedef void           (*PFNVKGLGETBOOLEANVPROC)            (Context* context_ptr, const GLenum& in_pname, GLboolean* out_data_ptr);
    typedef void           (*PFNVKGLGETDOUBLEVPROC)             (Context* context_ptr, const GLenum& in_pname, GLdouble* out_data_ptr);
    typedef GLenum         (*PFNVKGLGETERRORPROC)               (Context* context_ptr);
    typedef void           (*PFNVKGLGETFLOATVPROC)              (Context* context_ptr, const GLenum& in_pname, GLfloat* out_data_ptr);
    typedef void           (*PFNVKGLGETINTEGERVPROC)            (Context* context_ptr, const GLenum& in_pname, GLint* out_data_ptr);
    typedef const GLubyte* (*PFNVKGLGETSTRINGPROC)              (Context* context_ptr, const GLenum& in_name);
    typedef void           (*PFNVKGLGETTEXIMAGEPROC)            (Context* context_ptr, const GLenum& in_target, const GLint& in_level, const GLenum& in_format, const GLenum& in_type, void* out_pixels_ptr);
    typedef void           (*PFNVKGLGETTEXLEVELPARAMETERFVPROC) (Context* context_ptr, const GLenum& in_target, const GLint& in_level, const GLenum& in_pname, GLfloat* out_params_ptr);
    typedef void           (*PFNVKGLGETTEXLEVELPARAMETERIVPROC) (Context* context_ptr, const GLenum& in_target, const GLint& in_level, const GLenum& in_pname, GLint* out_params_ptr);
    typedef void           (*PFNVKGLGETTEXPARAMETERFVPROC)      (Context* context_ptr, const GLenum& in_target, const GLenum& in_pname, GLfloat* out_params_ptr);
    typedef void           (*PFNVKGLGETTEXPARAMETERIVPROC)      (Context* context_ptr, const GLenum& in_target, const GLenum& in_pname, GLint* out_params_ptr);
    typedef void           (*PFNVKGLHINTPROC)                   (Context* context_ptr, const GLenum& in_target, const GLenum& in_mode);
    typedef GLboolean      (*PFNVKGLISENABLEDPROC)              (Context* context_ptr, const GLenum& in_cap);
    typedef void           (*PFNVKGLLINEWIDTHPROC)              (Context* context_ptr, const GLfloat& in_width);
    typedef void           (*PFNVKGLLOGICOPPROC)                (Context* context_ptr, const GLenum& in_opcode);
    typedef void           (*PFNVKGLPIXELSTOREFPROC)            (Context* context_ptr, const GLenum& in_pname, const GLfloat& in_param);
    typedef void           (*PFNVKGLPIXELSTOREIPROC)            (Context* context_ptr, const GLenum& in_pname, const GLint& in_param);
    typedef void           (*PFNVKGLPOINTSIZEPROC)              (Context* context_ptr, const GLfloat& in_size);
    typedef void           (*PFNVKGLPOLYGONMODEPROC)            (Context* context_ptr, const GLenum& in_face, const GLenum& in_mode);
    typedef void           (*PFNVKGLREADBUFFERPROC)             (Context* context_ptr, const GLenum& in_src);
    typedef void           (*PFNVKGLREADPIXELSPROC)             (Context* context_ptr, const GLint& in_x, const GLint& in_y, const GLsizei& in_width, const GLsizei& in_height, const GLenum& in_format, const GLenum& in_type, void* out_pixels_ptr);
    typedef void           (*PFNVKGLSCISSORPROC)                (Context* context_ptr, const GLint& in_x, const GLint& in_y, const GLsizei& in_width, const GLsizei& in_height);
    typedef void           (*PFNVKGLSTENCILFUNCPROC)            (Context* context_ptr, const GLenum& in_func, const GLint& in_ref, const GLuint& in_mask);
    typedef void           (*PFNVKGLSTENCILOPPROC)              (Context* context_ptr, const GLenum& in_fail, const GLenum& in_zfail, const GLenum& in_zpass);
    typedef void           (*PFNVKGLSTENCILMASKPROC)            (Context* context_ptr, const GLuint& in_mask);
    typedef void           (*PFNVKGLTEXIMAGE1DPROC)             (Context* context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_internalformat, const GLsizei& in_width, const GLint& in_border, const GLenum& in_format, const GLenum& in_type, const void* in_pixels_ptr);
    typedef void           (*PFNVKGLTEXIMAGE2DPROC)             (Context* context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_internalformat, const GLsizei& in_width, const GLsizei& in_height, const GLint& in_border, const GLenum& in_format, const GLenum& in_type, const void* in_pixels_ptr);
    typedef void           (*PFNVKGLTEXPARAMETERFPROC)          (Context* context_ptr, const GLenum& in_target, const GLenum& in_pname, const GLfloat& in_param);
    typedef void           (*PFNVKGLTEXPARAMETERFVPROC)         (Context* context_ptr, const GLenum& in_target, const GLenum& in_pname, const GLfloat* in_params_ptr);
    typedef void           (*PFNVKGLTEXPARAMETERIPROC)          (Context* context_ptr, const GLenum& in_target, const GLenum& in_pname, const GLint& in_param);
    typedef void           (*PFNVKGLTEXPARAMETERIVPROC)         (Context* context_ptr, const GLenum& in_target, const GLenum& in_pname, const GLint* in_params_ptr);
    typedef void           (*PFNVKGLVIEWPORTPROC)               (Context* context_ptr, const GLint& in_x, const GLint& in_y, const GLsizei& in_width, const GLsizei& in_height);


    /* Dispatch table - holds all function pointers as well as miscellaneous context-specific information.
     *
     * NOTE: The reason behind the additional indirection here is to support extensions such as no_error in the future.
     */
    struct DispatchTable
    {
        Context* bound_context_ptr;

        /* GL 1.0 */
        PFNVKGLBLENDFUNCPROC              pGLBlendFunc;
        PFNVKGLCLEARPROC                  pGLClear;
        PFNVKGLCLEARCOLORPROC             pGLClearColor;
        PFNVKGLCLEARDEPTHPROC             pGLClearDepth;
        PFNVKGLCLEARSTENCILPROC           pGLClearStencil;
        PFNVKGLCOLORMASKPROC              pGLColorMask;
        PFNVKGLCULLFACEPROC               pGLCullFace;
        PFNVKGLDEPTHFUNCPROC              pGLDepthFunc;
        PFNVKGLDEPTHMASKPROC              pGLDepthMask;
        PFNVKGLDEPTHRANGEPROC             pGLDepthRange;
        PFNVKGLDISABLEPROC                pGLDisable;
        PFNVKGLDRAWBUFFERPROC             pGLDrawBuffer;
        PFNVKGLENABLEPROC                 pGLEnable;
        PFNVKGLFINISHPROC                 pGLFinish;
        PFNVKGLFLUSHPROC                  pGLFlush;
        PFNVKGLFRONTFACEPROC              pGLFrontFace;
        PFNVKGLGETBOOLEANVPROC            pGLGetBooleanv;
        PFNVKGLGETDOUBLEVPROC             pGLGetDoublev;
        PFNVKGLGETERRORPROC               pGLGetError;
        PFNVKGLGETFLOATVPROC              pGLGetFloatv;
        PFNVKGLGETINTEGERVPROC            pGLGetIntegerv;
        PFNVKGLGETSTRINGPROC              pGLGetString;
        PFNVKGLGETTEXIMAGEPROC            pGLGetTexImage;
        PFNVKGLGETTEXLEVELPARAMETERFVPROC pGLGetTexLevelParameterfv;
        PFNVKGLGETTEXLEVELPARAMETERIVPROC pGLGetTexLevelParameteriv;
        PFNVKGLGETTEXPARAMETERFVPROC      pGLGetTexParameterfv;
        PFNVKGLGETTEXPARAMETERIVPROC      pGLGetTexParameteriv;
        PFNVKGLHINTPROC                   pGLHint;
        PFNVKGLISENABLEDPROC              pGLIsEnabled;
        PFNVKGLLINEWIDTHPROC              pGLLineWidth;
        PFNVKGLLOGICOPPROC                pGLLogicOp;
        PFNVKGLPIXELSTOREFPROC            pGLPixelStoref;
        PFNVKGLPIXELSTOREIPROC            pGLPixelStorei;
        PFNVKGLPOINTSIZEPROC              pGLPointSize;
        PFNVKGLPOLYGONMODEPROC            pGLPolygonMode;
        PFNVKGLREADBUFFERPROC             pGLReadBuffer;
        PFNVKGLREADPIXELSPROC             pGLReadPixels;
        PFNVKGLSCISSORPROC                pGLScissor;
        PFNVKGLSTENCILFUNCPROC            pGLStencilFunc;
        PFNVKGLSTENCILMASKPROC            pGLStencilMask;
        PFNVKGLSTENCILOPPROC              pGLStencilOp;
        PFNVKGLTEXIMAGE1DPROC             pGLTexImage1D;
        PFNVKGLTEXIMAGE2DPROC             pGLTexImage2D;
        PFNVKGLTEXPARAMETERFPROC          pGLTexParameterf;
        PFNVKGLTEXPARAMETERFVPROC         pGLTexParameterfv;
        PFNVKGLTEXPARAMETERIPROC          pGLTexParameteri;
        PFNVKGLTEXPARAMETERIVPROC         pGLTexParameteriv;
        PFNVKGLVIEWPORTPROC               pGLViewport;

        DispatchTable();
    };
};

#endif /* VKGL_TYPES_H */