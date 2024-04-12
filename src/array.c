#include <stdio.h>
#include "array.h"


Status CGMAArrayInit(CGMAArray *arr, size_t data_size, size_t size) {
    if (arr == NULL) return FAIL | ARRAY_MODULE | GOT_NULL_ERROR;
    arr->data_size = data_size;
    arr->size = size;
    if ((arr->buf = malloc(arr->data_size * arr->size)) == NULL) return FAIL | ARRAY_MODULE | ALLOCATION_ERROR;

    return SUCCESS | ARRAY_MODULE;
}

Status CGMAArrayClean(CGMAArray *arr) {
    if (arr == NULL) return FAIL | ARRAY_MODULE | GOT_NULL_ERROR;
    free(arr->buf);
    return SUCCESS | ARRAY_MODULE;
}

Status CGMAArrayGetVal(const CGMAArray *arr, size_t idx, void *dest) {
    if (arr == NULL) return FAIL | ARRAY_MODULE | GOT_NULL_ERROR;
    if (idx >= arr->size) return FAIL | ARRAY_MODULE;
    memcpy(dest, arr->buf + arr->data_size * idx, arr->data_size);
    return SUCCESS | ARRAY_MODULE;
}

Status CGMAArraySetVal(CGMAArray *arr, size_t idx, const void *src) {
    if (arr == NULL) return FAIL | ARRAY_MODULE | GOT_NULL_ERROR;
    if (idx >= arr->size) return FAIL | ARRAY_MODULE;
    memcpy(arr->buf + idx * arr->data_size, src, arr->data_size);
    return SUCCESS | ARRAY_MODULE;
}