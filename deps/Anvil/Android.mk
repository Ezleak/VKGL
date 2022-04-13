LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := Anvil

LOCAL_C_INCLUDES := $(LOCAL_PATH)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/deps
LOCAL_C_INCLUDES += $(LOCAL_PATH)/deps/glslang
LOCAL_C_INCLUDES += $(LOCAL_PATH)/deps/glslang/include

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)

LOCAL_SRC_FILES := \
    $(LOCAL_PATH)/src/misc/memalloc_backends/backend_oneshot.cpp \
    $(LOCAL_PATH)/src/misc/memalloc_backends/backend_vma.cpp \
    $(LOCAL_PATH)/src/misc/base_pipeline_create_info.cpp \
    $(LOCAL_PATH)/src/misc/base_pipeline_manager.cpp \
    $(LOCAL_PATH)/src/misc/buffer_create_info.cpp \
    $(LOCAL_PATH)/src/misc/buffer_view_create_info.cpp \
    $(LOCAL_PATH)/src/misc/compute_pipeline_create_info.cpp \
    $(LOCAL_PATH)/src/misc/debug.cpp \
    $(LOCAL_PATH)/src/misc/debug_marker.cpp \
    $(LOCAL_PATH)/src/misc/debug_messenger_create_info.cpp \
    $(LOCAL_PATH)/src/misc/descriptor_pool_create_info.cpp \
    $(LOCAL_PATH)/src/misc/descriptor_set_create_info.cpp \
    $(LOCAL_PATH)/src/misc/device_create_info.cpp \
    $(LOCAL_PATH)/src/misc/dummy_window.cpp \
    $(LOCAL_PATH)/src/misc/external_handle.cpp \
    $(LOCAL_PATH)/src/misc/event_create_info.cpp \
    $(LOCAL_PATH)/src/misc/fence_create_info.cpp \
    $(LOCAL_PATH)/src/misc/formats.cpp \
    $(LOCAL_PATH)/src/misc/fp16.cpp \
    $(LOCAL_PATH)/src/misc/framebuffer_create_info.cpp \
    $(LOCAL_PATH)/src/misc/graphics_pipeline_create_info.cpp \
    $(LOCAL_PATH)/src/misc/image_create_info.cpp \
    $(LOCAL_PATH)/src/misc/image_view_create_info.cpp \
    $(LOCAL_PATH)/src/misc/instance_create_info.cpp \
    $(LOCAL_PATH)/src/misc/io.cpp \
    $(LOCAL_PATH)/src/misc/library.cpp \
    $(LOCAL_PATH)/src/misc/memory_allocator.cpp \
    $(LOCAL_PATH)/src/misc/memory_block_create_info.cpp \
    $(LOCAL_PATH)/src/misc/object_tracker.cpp \
    $(LOCAL_PATH)/src/misc/page_tracker.cpp \
    $(LOCAL_PATH)/src/misc/pools.cpp \
    $(LOCAL_PATH)/src/misc/render_pass_create_info.cpp \
    $(LOCAL_PATH)/src/misc/rendering_surface_create_info.cpp \
    $(LOCAL_PATH)/src/misc/sampler_create_info.cpp \
    $(LOCAL_PATH)/src/misc/sampler_ycbcr_conversion_create_info.cpp \
    $(LOCAL_PATH)/src/misc/semaphore_create_info.cpp \
    $(LOCAL_PATH)/src/misc/shader_module_cache.cpp \
    $(LOCAL_PATH)/src/misc/swapchain_create_info.cpp \
    $(LOCAL_PATH)/src/misc/time.cpp \
    $(LOCAL_PATH)/src/misc/types.cpp \
    $(LOCAL_PATH)/src/misc/types_classes.cpp \
    $(LOCAL_PATH)/src/misc/types_struct.cpp \
    $(LOCAL_PATH)/src/misc/types_utils.cpp \
    $(LOCAL_PATH)/src/misc/vulkan.cpp \
    $(LOCAL_PATH)/src/misc/window.cpp \
    $(LOCAL_PATH)/src/misc/window_android.cpp \
    $(LOCAL_PATH)/src/misc/window_factory.cpp \
    $(LOCAL_PATH)/src/wrappers/buffer.cpp \
    $(LOCAL_PATH)/src/wrappers/buffer_view.cpp \
    $(LOCAL_PATH)/src/wrappers/command_buffer.cpp \
    $(LOCAL_PATH)/src/wrappers/command_pool.cpp \
    $(LOCAL_PATH)/src/wrappers/compute_pipeline_manager.cpp \
    $(LOCAL_PATH)/src/wrappers/debug_messenger.cpp \
    $(LOCAL_PATH)/src/wrappers/descriptor_pool.cpp \
    $(LOCAL_PATH)/src/wrappers/descriptor_set.cpp \
    $(LOCAL_PATH)/src/wrappers/descriptor_set_group.cpp \
    $(LOCAL_PATH)/src/wrappers/descriptor_set_layout.cpp \
    $(LOCAL_PATH)/src/wrappers/descriptor_set_layout_manager.cpp \
    $(LOCAL_PATH)/src/wrappers/descriptor_update_template.cpp \
    $(LOCAL_PATH)/src/wrappers/device.cpp \
    $(LOCAL_PATH)/src/wrappers/event.cpp \
    $(LOCAL_PATH)/src/wrappers/fence.cpp \
    $(LOCAL_PATH)/src/wrappers/framebuffer.cpp \
    $(LOCAL_PATH)/src/wrappers/graphics_pipeline_manager.cpp \
    $(LOCAL_PATH)/src/wrappers/image.cpp \
    $(LOCAL_PATH)/src/wrappers/image_view.cpp \
    $(LOCAL_PATH)/src/wrappers/instance.cpp \
    $(LOCAL_PATH)/src/wrappers/memory_block.cpp \
    $(LOCAL_PATH)/src/wrappers/physical_device.cpp \
    $(LOCAL_PATH)/src/wrappers/pipeline_cache.cpp \
    $(LOCAL_PATH)/src/wrappers/pipeline_layout.cpp \
    $(LOCAL_PATH)/src/wrappers/pipeline_layout_manager.cpp \
    $(LOCAL_PATH)/src/wrappers/query_pool.cpp \
    $(LOCAL_PATH)/src/wrappers/queue.cpp \
    $(LOCAL_PATH)/src/wrappers/render_pass.cpp \
    $(LOCAL_PATH)/src/wrappers/rendering_surface.cpp \
    $(LOCAL_PATH)/src/wrappers/sampler.cpp \
    $(LOCAL_PATH)/src/wrappers/sampler_ycbcr_conversion.cpp \
    $(LOCAL_PATH)/src/wrappers/semaphore.cpp \
    $(LOCAL_PATH)/src/wrappers/shader_module.cpp \
    $(LOCAL_PATH)/src/wrappers/swapchain.cpp \
    $(LOCAL_PATH)/src/misc/glsl_to_spirv.cpp \
    

LOCAL_CFLAGS = -g -std=c++11 -Wall
LOCAL_CFLAGS += -frtti -fno-exceptions
LOCAL_CFLAGS += -fpermissive
LOCAL_CFLAGS += -D_DEBUG
#LOCAL_CFLAGS += -O3
#LOCAL_CFLAGS += -funwind-tables -fvisibility=hidden

LOCAL_CFLAGS += -DVK_USE_PLATFORM_ANDROID_KHR

#LOCAL_CFLAGS += -DANVIL_LINK_STATICALLY_WITH_VULKAN_LIB
LOCAL_CFLAGS += -DANVIL_USE_BUILT_IN_VULKAN_HEADERS
LOCAL_CFLAGS += -DANVIL_LINK_WITH_GLSLANG
LOCAL_CFLAGS += -DANVIL_USE_BUILT_IN_GLSLANG

#building as a static lib

LOCAL_STATIC_LIBRARIES := OSDependent
LOCAL_STATIC_LIBRARIES += OGLCompiler
LOCAL_STATIC_LIBRARIES += HLSL
LOCAL_STATIC_LIBRARIES += glslang
LOCAL_STATIC_LIBRARIES += SPIRV

include $(BUILD_STATIC_LIBRARY)

include $(LOCAL_PATH)/deps/glslang/Android.mk
