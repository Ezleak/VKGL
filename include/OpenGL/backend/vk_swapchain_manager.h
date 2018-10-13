/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_SWAPCHAIN_MANAGER_H
#define VKGL_VK_SWAPCHAIN_MANAGER_H

#include "OpenGL/types.h"
#include "OpenGL/frontend/snapshot_manager.h"

namespace OpenGL
{
    typedef std::unique_ptr<VKSwapchainManager> VKSwapchainManagerUniquePtr;

    /* NOTE: Swapchains may need to be re-created at frame acquisition time (in case WGL settings such as swap interval)
     *       are changed, or if window is resized.
     */
    class VKSwapchainManager : public IStateSnapshotAccessors
    {
    public:
        /* Public functions */

        static VKSwapchainManagerUniquePtr create(IBackend*                            in_backend_ptr,
                                                  const uint32_t&                      in_n_swapchain_images,
                                                  const VKGL::PixelFormatRequirements& in_pixel_format_reqs);

        ~VKSwapchainManager();

        VKSwapchainReferenceUniquePtr acquire_swapchain  (const OpenGL::TimeMarker& in_time_marker);
        OpenGL::TimeMarker            get_tot_time_marker()                                          const;

        void set_swap_interval(const int32_t& in_swap_interval);

        #if defined(_WIN32)
            void set_target_window(HWND in_window_handle);
        #else
            #error OS-specific bits.
        #endif

    private:
        /* Private type definitions */
        typedef struct InternalSwapchainData
        {
            Anvil::RenderingSurfaceUniquePtr rendering_surface_ptr;
            Anvil::SwapchainUniquePtr        swapchain_ptr;
            Anvil::WindowUniquePtr           window_ptr;

            InternalSwapchainData(Anvil::RenderingSurfaceUniquePtr in_rendering_surface_ptr,
                                  Anvil::SwapchainUniquePtr        in_swapchain_ptr,
                                  Anvil::WindowUniquePtr           in_window_ptr)
                :rendering_surface_ptr(std::move(in_rendering_surface_ptr) ),
                 swapchain_ptr        (std::move(in_swapchain_ptr) ),
                 window_ptr           (std::move(in_window_ptr) )
            {
                vkgl_assert(rendering_surface_ptr != nullptr);
                vkgl_assert(swapchain_ptr         != nullptr);
                vkgl_assert(window_ptr            != nullptr);
            }

            ~InternalSwapchainData()
            {
                swapchain_ptr.reset        ();
                rendering_surface_ptr.reset();
                window_ptr.reset           ();
            }
        } InternalSwapchainData;

        typedef std::unique_ptr<InternalSwapchainData> InternalSwapchainDataUniquePtr;

        typedef struct SwapchainPropsSnapshot
        {
            int32_t swap_interval;
            HWND    window_handle;

            SwapchainPropsSnapshot()
                :swap_interval(INT32_MAX),
                 window_handle(nullptr)
            {
                /* Stub */
            }

            SwapchainPropsSnapshot(const int32_t& in_swap_interval,
                                   const HWND&    in_window_handle)
                :swap_interval(in_swap_interval),
                 window_handle(in_window_handle)
            {
                /*  Stub */
            }
        } SwapchainPropsSnapshot;

        /* IStateSnapshotAccessors functions */
        std::unique_ptr<void, std::function<void(void*)> > clone_internal_data_object (const void* in_ptr)     final;
        void                                               copy_internal_data_object  (const void* in_src_ptr,
                                                                                       void*       in_dst_ptr) final;
        std::unique_ptr<void, std::function<void(void*)> > create_internal_data_object()                       final;

        /* Private functions */

        VKSwapchainManager(IBackend*                            in_backend_ptr,
                           const uint32_t&                      in_n_swapchain_images,
                           const VKGL::PixelFormatRequirements& in_pixel_format_reqs);

        InternalSwapchainDataUniquePtr create_swapchain                  (const SwapchainPropsSnapshot* in_swapchain_props_ptr) const;
        bool                           init                              ();
        void                           on_swapchain_snapshot_out_of_scope(OpenGL::TimeMarker            in_time_marker);

        Anvil::PresentModeKHR  get_present_mode_for_swapchain_props(const SwapchainPropsSnapshot*  in_swapchain_props_ptr,
                                                                    const Anvil::RenderingSurface* in_surface_ptr)         const;
        Anvil::Format          get_swapchain_format                (const SwapchainPropsSnapshot*  in_swapchain_props_ptr,
                                                                    const Anvil::RenderingSurface* in_surface_ptr)         const;
        Anvil::ImageUsageFlags get_swapchain_image_usage_flags     (const Anvil::RenderingSurface* in_surface_ptr)         const;

        /* Private variables */

        IBackend*                                                                                                          m_backend_ptr;
        std::unique_ptr<OpenGL::SnapshotManager<VKSwapchainReference, VKSwapchainReferenceUniquePtr, VKSwapchainPayload> > m_snapshot_manager_ptr;
        std::map<OpenGL::TimeMarker, InternalSwapchainDataUniquePtr>                                                       m_time_marker_to_internal_swapchain_data_map;

        const uint32_t                      m_n_swapchain_images;
        const VKGL::PixelFormatRequirements m_pixel_format_reqs;
    };
}

#endif /* VKGL_VK_SWAPCHAIN_MANAGER_H */