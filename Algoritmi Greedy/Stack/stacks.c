#include "stacks.h"

int CompareStacks(const void* a, const void* b) {

	const Stack* pa = a;
	const Stack* pb = b;
	unsigned sumA = 0, sumB = 0;
	for (size_t i = 0; i < pa->m; i++) {
		sumA += pa->elements[i];
	}
	for (size_t i = 0; i < pb->m; i++) {
		sumB += pb->elements[i];
	}

	return (sumA < sumB) - (sumA > sumB);
}
unsigned MaxSumNStack(Stack* stacks, size_t n)
{
	/*Check NULL pointers*/
	for (size_t i = 0; i < n; i++) {
		if (stacks[i].elements == NULL) {
			return 0;
		}
	}


	while (1) {
		qsort(stacks, n, sizeof(Stack), CompareStacks);			/*Ordinamento decrescente in base alle somme*/
		unsigned* somme = calloc(n, sizeof(unsigned));

		for (size_t i = 0; i < n; i++) {					
			for (size_t j = 0; j < stacks[i].m; j++) {
				somme[i] += stacks[i].elements[j];
			}
		}
		for (size_t i = 0; i < n; i++) {
			size_t j;
			for (j = 0; j < n; j++) {
				if (somme[i] != somme[j]) {						/*Check somme delle stack*/
					stacks[0].elements[stacks[0].m - 1] = 0;
					stacks[0].m--;
					break;
				}
			}
			if (j != n) {										/*Reitera se le somme non sono tutte uguali*/
				break;
			}
			else {
				unsigned SumMax = somme[0];
				free(somme);
				return SumMax;
			}
		}
	}
}