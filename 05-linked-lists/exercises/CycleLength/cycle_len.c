// ANY LOOP VETTORE DI INDIRIZZI

#include "list.h"
#include <stdlib.h>

bool Find(const Item** v, size_t v_size, const Item* i) {
	for (size_t j = 0; j < v_size; ++j) {
		if (v[j] == i) {
			return true;
		}
	}
	return false;
}

int CycleLength(const Item* i) {
	if (ListIsEmpty(i)) {
		return 0;
	}

	size_t v_size = 0, cap = 2;
	const Item** v = malloc(cap * sizeof(Item*));

	while (!ListIsEmpty(i)) {
		if (Find(v, v_size, i)) {
			int len = 1;

			while (i != v[v_size - 1]) {
				i = ListGetTail(i);
				len++;
			}

			free(v);

			return len;
		}

		if (cap == v_size) {
			cap *= 2;
			v = realloc((void*)v, cap * sizeof(Item*));
		}

		v[v_size++] = i;
		i = ListGetTail(i);
	}

	free(v);

	return 0;
}