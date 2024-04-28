#ifndef CGMA_VECTOR_H
#define CGMA_VECTOR_H

#include <stdlib.h>
#include <string.h>
#include "status.h"


typedef struct _CGMAVector {
    void *buf;
    size_t capacity;
    size_t size;
    size_t data_size;
} CGMAVector;

CGMAStatus CGMAVectorInit(CGMAVector *vec, size_t data_size);

CGMAStatus CGMAVectorClean(CGMAVector *vec);

CGMAStatus CGMAVectorGetVal(const CGMAVector *vec, size_t idx, void *dest);

CGMAStatus CGMAVectorSetVal(CGMAVector *vec, size_t idx, const void *src);

CGMAStatus CGMAVectorAppend(CGMAVector *vec, const void *data);

#endif //CGMA_VECTOR_H
