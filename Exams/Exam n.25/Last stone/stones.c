#include "maxheap.h"
#include <stdlib.h>

void Pop(Heap* h, ElemType* popped) {
    if (h->size == 0) {
        popped = NULL;
        return;
    }
    *popped = ElemCopy(&h->data[0]);
    ElemSwap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    h->data = realloc(h->data, sizeof(ElemType) * h->size);
    HeapMaxMoveDown(h, 0);
    return;
}

int LastStoneWeight(Heap* h) {
    while (1) {
        if (h->size == 0) {
            return 0;
        }
        else if (h->size == 1) {
            ElemType last;
            Pop(h, &last);
            return (int)last;
        }
        else {
            ElemType x, y;
            Pop(h, &x);
            Pop(h, &y);
            ElemType ris;
            if (x != y) {
                ris = x - y;
                HeapMaxInsertNode(h, &ris);
            }
            else {
                continue;
            }
        }
    }
}