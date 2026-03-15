#include "differenza.h"
#include <stdlib.h>

Item* ListCopy(const Item* i) {
	Item* list_copy = ListCreateEmpty(); // Creo una lista vuota (NULL pointer)

	// Itero tutti gli elementi della lista da copiare
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		// Aggiungo l'elemento corrente della lista di input alla nuova lista
		// usando la primitiva ListInsertBack(), la quale si occupa di allocare
		// opportunamente la memoria e aggiornare i puntatori!
		list_copy = ListInsertBack(list_copy, ListGetHeadValue(i));
	}

	return list_copy;
}

Item* Differenza(const Item* i1, const Item* i2) {
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return ListCreateEmpty();
	}
	if (ListIsEmpty(i1)) {
		return ListCopy(i2);
	}
	if (ListIsEmpty(i2)) {
		return ListCopy(i1);
	}
	Item* diff = ListCreateEmpty();
	const Item* tmp1 = i1;
	const Item* tmp2 = i2;

	int p = 0;

	while (!ListIsEmpty(tmp1) || !ListIsEmpty(tmp2)) {
		int s = 0, m = 0, r = 0;

		if (!ListIsEmpty(tmp1)) {
			s = *ListGetHeadValue(tmp1) - '0';
		}
		if (!ListIsEmpty(tmp2)) {
			m = *ListGetHeadValue(tmp2) - '0';
		}

		s -= p;
		p = 0;
		if (s < m) {
			p = 1;
			s += 10;
		}
		r = s - m;

		ElemType e = (ElemType) (r + '0');
		diff = ListInsertBack(diff, &e);

		if (!ListIsEmpty(tmp1)) {
			tmp1 = ListGetTail(tmp1);
		}
		if (!ListIsEmpty(tmp2)) {
			tmp2 = ListGetTail(tmp2);
		}
	}

	return diff;
}