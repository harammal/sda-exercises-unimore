#include <stdlib.h>
#include <stdio.h>

int G(int n) {
	if (n == 1) {
		return 1;
	}
	if (n > 1) {
		return n * G(n / 2) + G(n - 1);
	}

	return 0;
}

void Ricorsione(int n, int k) {
	if (k == n + 1) {
		return;
	}
	printf("%d ", G(k));

	Ricorsione(n, k + 1);
}

int main(int argc, char** argv) {
	if (argc != 2) {
		return 1;
	}

	char* endptr;
	int n = strtol(argv[1], &endptr, 10);
	if (*endptr != 0) {
		return 1;
	}
	if (n <= 0) {
		return 1;
	}

	Ricorsione(n, 1);

	return 0;
}