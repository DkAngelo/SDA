#include <stdlib.h>
#include <stdbool.h>

//NOT WORKING

bool CircleSortRec(int* v, size_t v_size) {

	if (v_size == 1) {
		return true;
	}

	bool ord = false;
	while (!ord) {
		ord = true;
		bool a, b;
		for (int start = 0, end = (int)v_size - 1; start < (int)v_size / 2; start++, end--) {
			if (v[start] > v[end]) {
				ord = false;
				int tmp = v[start];
				v[start] = v[end];
				v[end] = tmp;
			}
		}
		if (v_size % 2 != 0) {
			if (v[v_size / 2] > v[v_size / 2 + 1]) {
				ord = false;
				int tmp = v[v_size / 2];
				v[v_size / 2] = v[v_size / 2 + 1];
				v[v_size / 2 + 1] = tmp;
			}
			a = CircleSortRec(v, (v_size + 1) / 2);
			b = CircleSortRec(v + (v_size + 1) / 2, v_size / 2);
		}
		else {
			a = CircleSortRec(v, v_size / 2);
			b = CircleSortRec(v + v_size / 2, v_size / 2);
		}

		ord = a && b;
	}

}
void CircleSort(int* v, size_t v_size) {

	if (v == NULL || v_size == 0) {
		return;
	}
	if (v_size == 1) {
		return;
	}

	bool ord = false;
	while (!ord) {
		ord = true;
		for (int start = 0, end = (int)v_size - 1; start < (int)v_size / 2; start++, end--) {
			if (v[start] > v[end]) {
				ord = false;
				int tmp = v[start];
				v[start] = v[end];
				v[end] = tmp;
			}
		}
		if (v_size % 2 != 0) {
			if (v[v_size / 2] > v[v_size / 2 + 1]) {
				ord = false;
				int tmp = v[v_size / 2];
				v[v_size / 2] = v[v_size / 2 + 1];
				v[v_size / 2 + 1] = tmp;
			}
			bool a = CircleSortRec(v,(v_size + 1)/ 2);
			bool b = CircleSortRec(v + (v_size + 1) / 2, v_size / 2);
		}
		else {
			bool a = CircleSortRec(v, v_size / 2);
			bool b = CircleSortRec(v + v_size / 2, v_size / 2);
		}	

	}
}

int main(void) {

	int v[] = { 3, -1, 1, 5 };
	CircleSort(v, 4);
	int v1[] = { 3, -1, 1, 5, 2 };
	CircleSort(v, 5);
}