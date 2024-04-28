#include <stdio.h>
#include "array.h"


CGMAStatus CGMAArrayInit(CGMAArray *arr, size_t data_size, size_t size) {
    if (arr == NULL) return CGMA_FAIL | CGMA_ARRAY_MODULE | CGMA_GOT_NULL_ERROR;
    arr->data_size = data_size;
    arr->size = size;
    if ((arr->buf = malloc(arr->data_size * arr->size)) == NULL) return CGMA_FAIL | CGMA_ARRAY_MODULE | CGMA_ALLOCATION_ERROR;

    return CGMA_SUCCESS | CGMA_ARRAY_MODULE;
}

CGMAStatus CGMAArrayClean(CGMAArray *arr) {
    if (arr == NULL) return CGMA_FAIL | CGMA_ARRAY_MODULE | CGMA_GOT_NULL_ERROR;
    free(arr->buf);
    return CGMA_SUCCESS | CGMA_ARRAY_MODULE;
}

CGMAStatus CGMAArrayGetVal(const CGMAArray *arr, size_t idx, void *dest) {
    if (arr == NULL) return CGMA_FAIL | CGMA_ARRAY_MODULE | CGMA_GOT_NULL_ERROR;
    if (idx >= arr->size) return CGMA_FAIL | CGMA_ARRAY_MODULE;
    memcpy(dest, arr->buf + arr->data_size * idx, arr->data_size);
    return CGMA_SUCCESS | CGMA_ARRAY_MODULE;
}

CGMAStatus CGMAArraySetVal(CGMAArray *arr, size_t idx, const void *src) {
    if (arr == NULL) return CGMA_FAIL | CGMA_ARRAY_MODULE | CGMA_GOT_NULL_ERROR;
    if (idx >= arr->size) return CGMA_FAIL | CGMA_ARRAY_MODULE;
    memcpy(arr->buf + idx * arr->data_size, src, arr->data_size);
    return CGMA_SUCCESS | CGMA_ARRAY_MODULE;
}