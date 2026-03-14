//#include "fattoriale.h"

static unsigned long long FattorialeRec(int n, unsigned long long p) {
	// Caso base
	if (n == 1 || n == 0) {
		return p;
	}

	return FattorialeRec(n - 1, p * n);
}

unsigned long long Fattoriale(int n) {
	// Caso particolare
	if (n < 0) {
		return 0;
	}

	return FattorialeRec(n, 1);
}