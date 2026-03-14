#include <stdlib.h>
#include <stdio.h>

int Josephus(int n, int k) {
	if (n == 1) {
		return 0;
	}

	return (Josephus(n - 1, k) + k) % n;
}

int main(int argc, char** argv) {
	if (argc != 3) {
		return 1;
	}

	char* endptr;
	int n = strtol(argv[1], &endptr, 10);
	if (*endptr != 0) {
		return 1;
	}
	int k = strtol(argv[2], &endptr, 10);
	if (*endptr != 0) {
		return 1;
	}

	if (n <= 0 || k <= 0) {
		return 1;
	}

	printf("%d", Josephus(n, k));

	return 0;
}