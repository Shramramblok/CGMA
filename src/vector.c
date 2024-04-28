#include <stdio.h>
#include "vector.h"

#define VECTOR_MIN_CAP 16


CGMAStatus CGMAVectorInit(CGMAVector *vec, size_t data_size) {
    if (vec == NULL) return CGMA_FAIL | CGMA_VECTOR_MODULE | CGMA_GOT_NULL_ERROR;
    vec->data_size = data_size;
    vec->capacity = VECTOR_MIN_CAP;
    if ((vec->buf = malloc(vec->data_size * vec->capacity)) == NULL) return CGMA_FAIL | CGMA_VECTOR_MODULE | CGMA_ALLOCATION_ERROR;
    vec->size = 0;
    return CGMA_SUCCESS | CGMA_VECTOR_MODULE;
}

CGMAStatus CGMAVectorClean(CGMAVector *vec) {
    if (vec == NULL) return CGMA_FAIL | CGMA_VECTOR_MODULE | CGMA_GOT_NULL_ERROR;
    free(vec->buf);
    return CGMA_SUCCESS | CGMA_VECTOR_MODULE;
}

CGMAStatus CGMAVectorGetVal(const CGMAVector *vec, size_t idx, void *dest) {
    if (vec == NULL) return CGMA_FAIL | CGMA_VECTOR_MODULE | CGMA_GOT_NULL_ERROR;
    if (idx >= vec->capacity) return CGMA_FAIL | CGMA_VECTOR_MODULE;
    memcpy(dest, vec->buf + vec->data_size * idx, vec->data_size);
    return CGMA_SUCCESS | CGMA_VECTOR_MODULE;
}

CGMAStatus CGMAVectorSetVal(CGMAVector *vec, size_t idx, const void *src) {
    if (vec == NULL) return CGMA_FAIL | CGMA_VECTOR_MODULE | CGMA_GOT_NULL_ERROR;
    if (idx >= vec->capacity) return CGMA_FAIL | CGMA_VECTOR_MODULE;
    memcpy(vec->buf + idx * vec->data_size, src, vec->data_size);
    return CGMA_SUCCESS | CGMA_VECTOR_MODULE;
}

CGMAStatus CGMAVectorAppend(CGMAVector *vec, const void *src) {
    void *tmp;
    if (vec == NULL) return CGMA_FAIL | CGMA_VECTOR_MODULE | CGMA_GOT_NULL_ERROR;
    if (vec->size >= vec->capacity) {
        vec->capacity *= 2;

        if ((tmp = realloc(vec->buf, sizeof(*vec->buf) * vec->capacity)) == NULL) return CGMA_FAIL | CGMA_VECTOR_MODULE | CGMA_ALLOCATION_ERROR;
        vec->buf = tmp;
    }
    CGMAVectorSetVal(vec, vec->size++, src);
    return CGMA_SUCCESS | CGMA_VECTOR_MODULE;
}