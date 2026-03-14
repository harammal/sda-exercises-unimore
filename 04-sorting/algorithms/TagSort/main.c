#include <stdio.h>

extern int* TaggedSort(const int* v, size_t v_size);

int main(void) {

	int v[] = { 6, 3, 1, 4, 12, 24 };

	for (int i = 0; i < 6; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n\n");

	int* t = TaggedSort(v, 6);

	for (int i = 0; i < 6; ++i) {
		printf("%d ", t[i]);
	}
	printf("\n");

	return 0;
}