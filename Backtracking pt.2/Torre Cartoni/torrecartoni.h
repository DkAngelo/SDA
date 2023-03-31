#if !defined TORRECARTONI_H
#define TORRECARTONI_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    unsigned p; // Peso
    unsigned a; // Altezza
    unsigned l; // Limite
} Cartone;

extern void TorreCartoni(const Cartone* c, size_t n);

#endif //TORRECARTONI_H