#include <vector.h>
#include <stdio.h>


int main(void) {
    CGMAVector vec;
    if (FAILED(CGMAVectorInit(&vec, sizeof(int)))) {
        printf("Can't initialize the vector");
        return 1;
    }

    for (int i = 0; i < 10; ++i) {
        if (FAILED(CGMAVectorAppend(&vec, &i))) {
            printf("Can't append %d to the vector", i);
            return 1;
        }
    }

    for (int i = 0; i < vec.size; ++i) {
        int tmp;
        if (FAILED(CGMAVectorGetVal(&vec, i, &tmp))) {
            printf("Can't print the number at index %d", i);
            return 1;
        } else {
            if (i != 0) printf(", ");
            printf("%d", tmp);
        }
    }

    if (FAILED(CGMAVectorClean(&vec))) {
        printf("Can't clean up the vector");
        return 1;
    }
    return 0;
}