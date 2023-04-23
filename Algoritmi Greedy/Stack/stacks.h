#if !defined STACKS_H
#define STACKS_H

#include <stdlib.h>

typedef struct {
    unsigned* elements;
    size_t m;
} Stack;

extern unsigned MaxSumNStack(Stack* stacks, size_t n);

#endif //STACKS_H