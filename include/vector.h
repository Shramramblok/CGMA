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

Status CGMAVectorInit(CGMAVector *vec, size_t data_size);

Status CGMAVectorClean(CGMAVector *vec);

Status CGMAVectorGetVal(const CGMAVector *vec, size_t idx, void *dest);

Status CGMAVectorSetVal(CGMAVector *vec, size_t idx, const void *src);

Status CGMAVectorAppend(CGMAVector *vec, const void *data);

#endif //CGMA_VECTOR_H
