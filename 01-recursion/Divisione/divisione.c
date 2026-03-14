//#include "prodotto.h"

static int DivisioneRec(int a, int b, int q) {

	// Caso base
	if (a - b < 0) {
		return q;
	}

	return DivisioneRec(a - b, b, q + 1);
}

int Divisione(int a, int b) {

	// Caso particolare
	if (a < 0 || b <= 0) {
		return -1;
	}
	if (a < b) {
		return 0;
	}

	return DivisioneRec(a, b, 0);
}