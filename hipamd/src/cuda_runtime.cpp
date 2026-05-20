/*
 * Copyright (c) Advanced Micro Devices, Inc., or its affiliates.
 *
 * SPDX-License-Identifier: MIT
 */

#include <cuda_runtime_api.h>

#ifdef _WIN32
#define DllExport extern "C" __declspec(dllexport)
#else
#define DllExport extern "C"
#endif

DllExport cudaChannelFormatDesc cudaCreateChannelDesc(int x, int y, int z, int w,
                                                      cudaChannelFormatKind f) {
  return hipCreateChannelDesc(x, y, z, w, f);
}

DllExport cudaError_t cudaMallocArray(cudaArray_t* array, const cudaChannelFormatDesc* desc,
                                      size_t width, size_t height, unsigned int flags) {
  return hipMallocArray(array, desc, width, height, flags);
}

DllExport cudaError_t cudaMemcpy2DToArray(cudaArray_t dst, size_t wOffset, size_t hOffset,
                                          const void* src, size_t spitch, size_t width,
                                          size_t height, cudaMemcpyKind kind) {
  return hipMemcpy2DToArray(dst, wOffset, hOffset, src, spitch, width, height, kind);
}

DllExport cudaError_t cudaCreateTextureObject(cudaTextureObject_t* pTexObject,
                                              const cudaResourceDesc* pResDesc,
                                              const cudaTextureDesc* pTexDesc,
                                              const cudaResourceViewDesc* pResViewDesc) {
  return hipCreateTextureObject(pTexObject, pResDesc, pTexDesc, pResViewDesc);
}
