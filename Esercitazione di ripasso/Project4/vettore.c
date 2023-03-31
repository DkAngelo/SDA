#include "vettore.h"

int main(void) {

	struct vettore v = { NULL , 0 };
	Push(&v, 1);
	struct vettore *c = malloc(sizeof(struct vettore));
	c->data = malloc(sizeof(int) * 3);
	c->data[0] = 1;
	c->data[1] = 2;
	c->data[2] = 3;
	c->size = 3;
	Pop(&c);
}

void Push(struct vettore* v, int d) {
	v->data = realloc(v->data, v->size * sizeof(int) + 1 * sizeof(int));
	v->data[v->size] = d;
}

int Pop(struct vettore* v) {
	int a = v->data[0];
	for (size_t i = 0; i < v->size; i++) {
		v->data[i] = v->data[i + 1];
	}
	v->data = realloc(v->data, v->size - 1 * sizeof(int));
	return a;
}