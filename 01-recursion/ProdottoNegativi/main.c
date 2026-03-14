#include "prodotto_negativi.h"

int main(void) {
	int p;

	p = ProdottoNegativi(2, 3);
	p = ProdottoNegativi(3, 2);
	p = ProdottoNegativi(2, 0);
	p = ProdottoNegativi(0, 2);
	p = ProdottoNegativi(2, -1);
	p = ProdottoNegativi(-2, -3);

	return 0;
}