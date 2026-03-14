#include <stdlib.h>
#include <stdio.h>

extern int* CacciatorePreda(const char* v, size_t v_size, int u);

int main(void) {

	size_t v_size = 5;
	int* vbest = CacciatorePreda("CPPCP", v_size, 1);

	printf("\nVbest: ");
	for (int i = 0; i < (int)v_size; ++i) {
		printf("%d ", vbest[i]);
	}
	printf("\n");

	free(vbest);
	return 0;
}