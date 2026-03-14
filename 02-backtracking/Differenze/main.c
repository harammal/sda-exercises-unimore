#include <stdlib.h>

extern int* Differenze(int n, int k, size_t* v_len);

int main(void) {

	size_t v_len = 0;
	int* vcurr = Differenze(3, 12, &v_len);

	if (vcurr) {
		free(vcurr);
	}
	return 0;
}