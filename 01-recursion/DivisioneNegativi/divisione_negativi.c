//#include "divisione_negativi.h"

static int DivisioneNegativiRec(int a, int b, int q, int segno) {

	// Caso base
	if (a - b < 0) {
		return q * segno;
	}

	return DivisioneNegativiRec(a - b, b, q + 1, segno);
}

int DivisioneNegativi(int a, int b) {

	// Caso particolare
	if (abs(a) < abs(b)) {
		return 0;
	}

	if (a < 0 && b < 0) {
		return DivisioneNegativiRec(abs(a), abs(b), 0, 1);
	}
	else {
		if (a < 0 || b < 0) {
			return DivisioneNegativiRec(abs(a), abs(b), 0, -1);
		}
	}

	if (abs(b) == 0) {
		return INT_MAX;
	}

	return DivisioneNegativiRec(a, b, 0, 1);
}