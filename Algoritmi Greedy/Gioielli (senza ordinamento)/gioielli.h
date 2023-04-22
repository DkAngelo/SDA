#if !defined GIOIELLI_H
#define GIOIELLI_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int codice;
    float peso;
    float prezzo;
} Gioiello;

extern Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size);

#endif //GIOIELLI_H