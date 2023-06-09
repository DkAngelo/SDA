#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void BubbleSort(int v[], size_t dim) {
    size_t i;
    int ordinato = 0;
    while (dim > 1 && !ordinato) {
        ordinato = 1;
        for (i = 0; i < dim - 1; i++)
            if (v[i] > v[i + 1]) {
                int tmp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = tmp;
                ordinato = 0;
            }
        dim--;
    }
}

void AssegnaBiscottiRec(const int* bam, size_t bam_size, const int* bis, size_t bis_size, int* ret, int i, size_t max, bool *used) {
   
    if (i == (int)max) {
        return;
    }

    size_t k;
    for (k = 0; k < bis_size; k++) {
        if (bis[k] >= bam[i] && !used[k]) {
            used[k] = true;
            (*ret)++;
            AssegnaBiscottiRec(bam, bam_size, bis, bis_size, ret, i + 1, max, used);
            break;
        }
    }
    if (k == bis_size) {
        int sumbis = 0;
        for (k = 0; k < bis_size; k++) {
            if (!used[k]) {
                used[k] = true;
                sumbis += bis[k];
                if (sumbis >= bam[i]) {
                    (*ret)++;
                    AssegnaBiscottiRec(bam, bam_size, bis, bis_size, ret, i + 1, max, used);
                    break;
                }
            }
        }
    }
}

int AssegnaBiscotti(const int* bam, size_t bam_size, const int* bis, size_t bis_size) 
{
    if (bam == NULL || bis == NULL || bam_size == 0 || bis_size == 0) {
        return 0;
    }

    int *bam_cpy = malloc(bam_size * sizeof(int));
    memcpy(bam_cpy, bam, bam_size * sizeof(int));

    int *bis_cpy = malloc(bis_size * sizeof(int));
    memcpy(bis_cpy, bis, bis_size * sizeof(int));

    BubbleSort(bis_cpy, bis_size);
    BubbleSort(bam_cpy, bam_size);

    bool* used = calloc(bis_size * sizeof(bool), 1);

    int ret = 0;
    size_t max;
    if (bam_size > bis_size) {
        max = bam_size;
    }
    else {
        max = bis_size;
    }

    AssegnaBiscottiRec(bam_cpy, bam_size, bis_cpy, bis_size, &ret, 0, max, used);
    
    free(bam_cpy);
    free(bis_cpy);
    free(used);

    return ret;
}