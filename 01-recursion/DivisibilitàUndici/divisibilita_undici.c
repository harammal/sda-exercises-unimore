#include <stdlib.h>
#include <stdio.h>

void Divisibile(int n) {
	int copy = n, cifre_d = 0, cifre_p = 0;
	while (copy > 0) {
		cifre_d += (copy % 10);
		copy /= 10;
		cifre_p += (copy % 10);
		copy /= 10;
	}

	n = abs(cifre_d - cifre_p);
	if (n > 10) {
		Divisibile(n);
	}
	else if (n > 0) {
		printf("Non multiplo di 11.");
		return;
	}
	else if (n == 0) {
		printf("Multiplo di 11.");
		return;
	}
}

int main(int argc, char** argv) {
	if (argc != 2) {
		return 1;
	}

	char* endptr;
	int n = strtol(argv[1], &endptr, 10);
	if (*endptr != 0 || n < 0) {
		return 1;
	}

	Divisibile(n);

	return 0;
}