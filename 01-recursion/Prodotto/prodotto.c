//#include "prodotto.h"

static int ProdottoRec(int a, int b, int p) {
	
	// Caso base
	if (b == 0) {
		return p;
	}

	return ProdottoRec(a, b - 1, p + a);
}

int Prodotto(int a, int b) {

	// Caso particolare
	if (a < 0 || b < 0) {
		return -1;
	}
	if (a == 0 || b == 0) {
		return 0;
	}

	return ProdottoRec(a, b, 0);
}