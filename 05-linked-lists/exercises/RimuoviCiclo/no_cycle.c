#include "no_cycle.h"

bool Find(Item** v, size_t v_size, Item* i) {
	for (size_t j = 0; j < v_size; ++j) {
		if (v[j] == i) {
			return true;
		}
	}
	return false;
}

void RemoveCycle(Item* i) {
	if (ListIsEmpty(i)) {
		return;
	}

	size_t cap = 2, v_size = 0;
	Item** v = malloc(cap * sizeof(Item*));

	while (!ListIsEmpty(i)) {

		if (Find(v, v_size, i)) {
			while (v[v_size - 1] != i) {
				i = ListGetTail(i);
			}
			i->next = NULL;

			free(v);

			return;
		}

		if (cap == v_size) {
			cap *= 2;
			v = realloc((void*)v, cap * sizeof(Item*));
		}

		v[v_size++] = i;
		i = ListGetTail(i);
	}


	free(v);

	return;
}