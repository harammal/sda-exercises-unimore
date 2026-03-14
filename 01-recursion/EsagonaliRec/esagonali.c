#include <stdlib.h>
#include <stdio.h>

void Esagonali(int max, int somma, int n) {
	if (somma <= max) {
		printf("%d ", somma);
	}
	else {
		return;
	}

	Esagonali(max, somma + (6 * n), n + 1);
}


int main(int argc, char** argv) {
	if (argc != 2) {
		return 1;
	}

	char* endptr;
	int max = strtol(argv[1], &endptr, 10);
	if (*endptr != 0 || max <= 0) {
		return 1;
	}

	Esagonali(max, 1, 1);

	return 0;
}