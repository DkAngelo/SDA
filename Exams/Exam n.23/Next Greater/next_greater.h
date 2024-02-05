#if !defined NEXT_GREATER_H
#define NEXT_GREAER_H

#include "elemtype.h"
#include "list.h"
#include <limits.h>
#include <stdlib.h>

extern ElemType* NextGreater(const Item* list, size_t* answer_size);

#endif //NEXT_GREATER_H