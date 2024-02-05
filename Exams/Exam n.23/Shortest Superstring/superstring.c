#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

static char* Overlap(const char* str1, const char* str2, int* overlapping) {
    const int len1 = (int)strlen(str1);
    const int len2 = (int)strlen(str2);
    const int lenShort = len1 < len2 ? len1 : len2;
    const int lenLong = len1 < len2 ? len2 : len1;
    const char* strShort = len1 < len2 ? str1 : str2;
    const char* strLong = len1 < len2 ? str2 : str1;
    // Check if strShort is a substring of strLong
    if (strstr(strLong, strShort) != NULL) {
        char* res = malloc(lenLong + 1);
        strcpy(res, strLong);
        *overlapping = lenShort;
        return res;
    }
    int maxOverlap = 0;
    bool longGoesFirst = true;
    // Try to put strShort at the end of strLong
    for (int i = lenShort - 1; i > 0; --i) {
        if (strncmp(strLong + lenLong - i, strShort, i) == 0) {
            maxOverlap = i;
            break;
        }
    }
    // Try to put strLong and the end of strShort
    for (int i = lenShort - 1; i > maxOverlap; --i) {
        if (strncmp(strLong, strShort + lenShort - i, i) == 0) {
            if (i > maxOverlap) {
                maxOverlap = i;
                longGoesFirst = false;
            }
            break;
        }
    }
    char* res = malloc(lenLong + lenShort - maxOverlap + 1);
    if (longGoesFirst) {
        strcpy(res, strLong);
        strcpy(res + lenLong, strShort + maxOverlap);
    }
    else {
        strcpy(res, strShort);
        strcpy(res + lenShort, strLong + maxOverlap);
    }
    *overlapping = maxOverlap;
    return res;
}

char* SolveSuperstringRec(const char** v, size_t v_size, bool *vused, char * res, int *used) {
   
    int max2;
    for (int i = 0; i < (int)v_size; i++) {
        if (!vused[i]) {
            max2 = i;
            break;
        }
    }
    int maxoverlap = 0;

    for (int i = 0; i < (int)v_size; i++) {
        int overlap;
        if (!vused[i]) {
            Overlap(res, v[i], &overlap);
            if (maxoverlap < overlap) {
                maxoverlap = overlap;
                max2 = i;
            }
        }
    }

    char* res1 = Overlap(res, v[max2], &maxoverlap);
    vused[max2] = 1;
    (*used)++;
    if (*used == (int)v_size) {
        return res1;
    }
    else {
        free(res1);
    }

    return SolveSuperstringRec(v, v_size, vused, res1, used);
}
char* SolveSuperstring(const char** v, size_t v_size) {
    
    if (v == NULL || v_size < 1) {
        return NULL;
    }
    else if (v_size == 1) {
        char* res = calloc(strlen(v[0]) + 1, sizeof(char));
        strcpy(res, v[0]);
        return res;
    }

    int max1 = 0;
    int max2 = 1;
    int maxoverlap = 0;

    for (int i = 0; i < (int)v_size - 1; i++) {

        for (int j = i + 1; j < (int)v_size; j++) {
            int overlap;
            Overlap(v[i], v[j], &overlap);
            if (maxoverlap < overlap) {
                maxoverlap = overlap;
                max1 = i;
                max2 = j;
            }
        }
    }

    char *res = Overlap(v[max1], v[max2], &maxoverlap);
    bool* vused = calloc(v_size * sizeof(bool), 1);
    vused[max1] = 1;
    vused[max2] = 1;
    int used = 2;

    char* SuperString = SolveSuperstringRec(v, v_size, vused, res, &used);
    free(res);
    free(vused);
    return SuperString;
}