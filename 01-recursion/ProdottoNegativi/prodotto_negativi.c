//#include "prodotto_negativi.h"
#include "stdlib.h"

int ProdottoNegativiRec(int a, int b, int p, int segno) {

	// Caso base
	if (b == 0) {
		return p * segno;
	}

	return ProdottoNegativiRec(a, b - 1, p + a, segno);
}

int ProdottoNegativi(int a, int b){

	// Caso particolare
	if (a < 0 && b < 0) {
		return ProdottoNegativiRec(abs(a), abs(b), 0, 1);
	}
	else {
		if (a < 0 || b < 0) {
			return ProdottoNegativiRec(abs(a), abs(b), 0, -1);
		}
	}

	if (a == 0 || b == 0) {
		return 0;
	}

	return ProdottoNegativiRec(a, b, 0, 1);
}