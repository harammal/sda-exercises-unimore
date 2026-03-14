#include "prodotto.h"

int main(void) {
	int p;

	p = Prodotto(2, 2);
	p = Prodotto(2, 3);
	p = Prodotto(3, 2);
	p = Prodotto(2, 0);
	p = Prodotto(0, 2);
	p = Prodotto(2, -1);

	return 0;
}