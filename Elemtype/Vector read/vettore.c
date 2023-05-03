#define _CRT_SECURE_NO_WARNINGS

#include "vettore.h"

Vector* VectorRead(const char* filename) {

	if (filename == NULL) {								//controllo se la stringa è NULL
		return NULL;
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL) {									//controllo che l'apertura sia andata a buon fine
		return NULL;
	}
	
	Vector* Ret = malloc(sizeof(Vector));				//creo la struct Vector da tornare
	Ret->size = 0;
	Ret->capacity = 1;
	Ret->data = malloc(sizeof(ElemType));

	while (1) {
		ElemType tmp;
		int a = ElemRead(f, &tmp);						//provo a leggere un elemento di tipo ElemType
		if (a <= 0) {									//se la lettura non va a buon fine, interrompo il ciclo
			break;
		}
		else {
			if (Ret->capacity == Ret->size) {			//se il vettore non può contenere altri elementi, raddoppio la capacità
				Ret->capacity *= 2;
				Ret->data = realloc(Ret->data, Ret->capacity * sizeof(ElemType));
			}
			Ret->data[Ret->size] = tmp;					//inserisco l'elemento letto in coda
			(Ret->size)++;								//aumento size (num.elementi nel vettore)
		}
	}

	fclose(f);
	return Ret;
}

Vector* VectorReadSorted(const char* filename) {

	if (filename == NULL) {						//controllo se la stringa è NULL
		return NULL;
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL) {							//controllo che l'apertura sia andata a buon fine
		return NULL;
	}

	Vector* Ret = malloc(sizeof(Vector));		//crea la struct Vector da ritornare
	Ret->size = 0;
	Ret->capacity = 1;
	Ret->data = malloc(sizeof(ElemType));

	while (1) {
		ElemType tmp;
		int a = ElemRead(f, &tmp);				//provo a leggere un elemento di tipo ElemType
		if (a <= 0) {							//se la lettura non va a buon fine, interrompo il ciclo
			break;
		}
		else {
			if (Ret->capacity == Ret->size) {		//se il vettore non può contenere un altro elemento, raddoppio la capacità
				Ret->capacity *= 2;
				Ret->data = realloc(Ret->data, Ret->capacity * sizeof(ElemType));
			}

			size_t minpos = Ret->size;																	//minpos sarà la posizione nel quale mettere l'elemento letto. 
																										//Se è maggiore rispetto al resto del vettore, verrà messo in coda
			for (size_t i = 0; i < Ret->size; i++) {
				if (ElemCompare(&tmp, &Ret->data[i]) < 0) {												//l'elemento letto è minore di un elemento del vettore
					minpos = i;																			//salvo la posizione in minpos
					memmove(Ret->data + i + 1, Ret->data + i, sizeof(ElemType) * (Ret->size - i));		//sposto gli elementi (da minpos verso destra) a destra di una posizione
					break;
				}
			}
			Ret->data[minpos] = tmp;							//metto l'elemento letto nella posizione salvata
			(Ret->size)++;										//aumento la size (num.elementi del vettore)
		}
	}
	fclose(f);
	return Ret;
}