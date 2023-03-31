#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static void SubsetKRec(int n, int k, int i, bool *vcurr, int *nsol, int nelem) {
    if (nelem == k) {
        (*nsol)++;
        printf("{ ");
        for (int j = 0; j < n; ++j) {
            if (vcurr[j]) {
                printf("%i ", j);
            }
        }
        printf("}, ");
        return;
    }
    
    if (i == n){
        return;
    }
    
    vcurr[i] = 0;
    SubsetKRec(n, k, i + 1, vcurr, nsol, nelem);

    vcurr[i] = 1;
    SubsetKRec(n, k, i + 1, vcurr, nsol, nelem + 1);
    vcurr[i] = 0;
}

int SubsetK(int n, int k) {
    bool *vcurr = malloc(sizeof(bool) * n);
    int nsol = 0;
    SubsetKRec(n, k, 0, vcurr, &nsol, 0);
    free(vcurr);
    return nsol;
}

int main(void){
    int sol = SubsetK(4, 2);
    return EXIT_SUCCESS;
}