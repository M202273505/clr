/*
 * Copyright (c) Advanced Micro Devices, Inc., or its affiliates.
 *
 * SPDX-License-Identifier: MIT
 */

#ifndef CLR_CUDA_RUNTIME_API_H
#define CLR_CUDA_RUNTIME_API_H

#include <hip/hip_runtime.h>
#include <hip/texture_types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef hipError_t cudaError_t;
typedef hipArray_t cudaArray_t;
typedef hipMipmappedArray_t cudaMipmappedArray_t;
typedef hipChannelFormatDesc cudaChannelFormatDesc;
typedef hipChannelFormatKind cudaChannelFormatKind;
typedef hipResourceDesc cudaResourceDesc;
typedef hipResourceViewDesc cudaResourceViewDesc;
typedef hipTextureDesc cudaTextureDesc;
typedef hipTextureObject_t cudaTextureObject_t;
typedef hipTextureAddressMode cudaTextureAddressMode;
typedef hipTextureFilterMode cudaTextureFilterMode;
typedef hipTextureReadMode cudaTextureReadMode;
typedef hipMemcpyKind cudaMemcpyKind;

#define cudaSuccess hipSuccess

#define cudaMemcpyHostToDevice hipMemcpyHostToDevice
#define cudaMemcpyDeviceToHost hipMemcpyDeviceToHost
#define cudaMemcpyDeviceToDevice hipMemcpyDeviceToDevice
#define cudaMemcpyDefault hipMemcpyDefault

#define cudaResourceTypeArray hipResourceTypeArray
#define cudaResourceTypeMipmappedArray hipResourceTypeMipmappedArray
#define cudaResourceTypeLinear hipResourceTypeLinear
#define cudaResourceTypePitch2D hipResourceTypePitch2D

#define cudaAddressModeWrap hipAddressModeWrap
#define cudaAddressModeClamp hipAddressModeClamp
#define cudaAddressModeMirror hipAddressModeMirror
#define cudaAddressModeBorder hipAddressModeBorder

#define cudaFilterModePoint hipFilterModePoint
#define cudaFilterModeLinear hipFilterModeLinear

#define cudaReadModeElementType hipReadModeElementType
#define cudaReadModeNormalizedFloat hipReadModeNormalizedFloat

#define cudaChannelFormatKindSigned hipChannelFormatKindSigned
#define cudaChannelFormatKindUnsigned hipChannelFormatKindUnsigned
#define cudaChannelFormatKindFloat hipChannelFormatKindFloat
#define cudaChannelFormatKindNone hipChannelFormatKindNone

#ifdef __cplusplus
#define CUDA_RUNTIME_DEFAULT(value) = value
#else
#define CUDA_RUNTIME_DEFAULT(value)
#endif

cudaChannelFormatDesc cudaCreateChannelDesc(int x, int y, int z, int w, cudaChannelFormatKind f);

cudaError_t cudaMallocArray(cudaArray_t* array, const cudaChannelFormatDesc* desc, size_t width,
                            size_t height CUDA_RUNTIME_DEFAULT(0),
                            unsigned int flags CUDA_RUNTIME_DEFAULT(0));

cudaError_t cudaMemcpy2DToArray(cudaArray_t dst, size_t wOffset, size_t hOffset, const void* src,
                                size_t spitch, size_t width, size_t height, cudaMemcpyKind kind);

cudaError_t cudaCreateTextureObject(cudaTextureObject_t* pTexObject,
                                    const cudaResourceDesc* pResDesc,
                                    const cudaTextureDesc* pTexDesc,
                                    const cudaResourceViewDesc* pResViewDesc
                                        CUDA_RUNTIME_DEFAULT(nullptr));

#undef CUDA_RUNTIME_DEFAULT

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // CLR_CUDA_RUNTIME_API_H
