#include <stdlib.h>
#include <limits.h>
#include <string.h>

void GuidaLaPulceRec(const int* f, size_t f_size, int a, int b, int n, int h, size_t* v_bestsize, size_t v_size, char* vcurr, char* vbest, int i, int sum) {
	if (i != 0) {
		for (size_t j = 0; j < f_size; j++) {
			if (sum == f[j]) {
				return;
			}
		}

		if (v_size > *v_bestsize) {
			return;
		}
		else if (v_size < *v_bestsize) {
			if (sum == h) {
				*v_bestsize = v_size;
				memcpy(vbest, vcurr, v_size * sizeof(char));
				return;
			}
		}
	}
	if (i == n) {
		return;
	}
	vcurr[i] = 'a';
	GuidaLaPulceRec(f, f_size, a, b, n, h, v_bestsize, v_size + 1, vcurr, vbest, i + 1, sum + a);
	if (sum - b > 0 && vcurr[i - 1] != 'b' && (i - 1) >= 0) {
		vcurr[i] = 'b';
		GuidaLaPulceRec(f, f_size, a, b, n, h, v_bestsize, v_size + 1, vcurr, vbest, i + 1, sum - b);
	}
	vcurr[i] = rand();
}
char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size) {

	char* vcurr = malloc(n * sizeof(char));
	char* vbest = malloc(n * sizeof(char));
	size_t v_bestsize = UINT_MAX;
	GuidaLaPulceRec(f, f_size, a, b, n, h, &v_bestsize, 0, vcurr, vbest, 0, 0);
	free(vcurr);

	if (v_bestsize == UINT_MAX) {
		*ret_size = 0;
		free(vbest);
		return NULL;
	}

	vbest = realloc(vbest, v_bestsize * sizeof(char));
	*ret_size = v_bestsize;
	return vbest;
}