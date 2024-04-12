#ifndef CGMA_ARRAY_H
#define CGMA_ARRAY_H

#include <stdlib.h>
#include <string.h>
#include "status.h"


typedef struct _CGMAArray {
    void *buf;
    size_t size;
    size_t data_size;
} CGMAArray;

Status CGMAArrayInit(CGMAArray *arr, size_t data_size, size_t size);

Status CGMAArrayClean(CGMAArray *arr);

Status CGMAArrayGetVal(const CGMAArray *arr, size_t idx, void *dest);

Status CGMAArraySetVal(CGMAArray *arr, size_t idx, const void *src);

#endif //CGMA_ARRAY_H
