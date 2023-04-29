#define _CRT_SECURE_NO_WARNINGS

#include "vettore.h"

Vector* VectorRead(const char* filename) {

	if (filename == NULL) {
		return NULL;
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	
	Vector* Ret = malloc(sizeof(Vector));
	Ret->size = 0;
	Ret->capacity = 1;
	Ret->data = malloc(sizeof(ElemType));

	while (1) {
		ElemType tmp;
		int a = ElemRead(f, &tmp);
		if (a <= 0) {
			break;
		}
		else {
			if (Ret->capacity == Ret->size) {
				Ret->capacity *= 2;
				Ret->data = realloc(Ret->data, Ret->capacity * sizeof(ElemType));
			}
			Ret->data[Ret->size] = tmp;
			(Ret->size)++;
		}
	}

	fclose(f);
	return Ret;
}

Vector* VectorReadSorted(const char* filename) {

	if (filename == NULL) {
		return NULL;
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	Vector* Ret = malloc(sizeof(Vector));
	Ret->size = 0;
	Ret->capacity = 1;
	Ret->data = malloc(sizeof(ElemType));

	while (1) {
		ElemType tmp;
		int a = ElemRead(f, &tmp);
		if (a <= 0) {
			break;
		}
		else {
			if (Ret->capacity == Ret->size) {
				Ret->capacity *= 2;
				Ret->data = realloc(Ret->data, Ret->capacity * sizeof(ElemType));
			}

			size_t minpos = Ret->size;
			for (size_t i = 0; i < Ret->size; i++) {
				if (ElemCompare(&tmp, &Ret->data[i]) < 0) {
					minpos = i;
					memcpy(Ret->data + i + 1, Ret->data + i, sizeof(ElemType) * (Ret->size - i));
					break;
				}
			}
			Ret->data[minpos] = tmp;
			(Ret->size)++;
		}
	}
	fclose(f);
	return Ret;
}