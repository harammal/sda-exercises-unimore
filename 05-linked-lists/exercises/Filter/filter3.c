// MODIFICA DIRETTA DELLA LISTA (VERSIONE BOLELLI)

#include "list.h"
#include <stdlib.h>

Item* Filter(Item* i, ElemType e) {
	Item* r = i;
	Item* p = NULL;

	while (!ListIsEmpty(i)) {
		if (ElemCompare(ListGetHeadValue(i), &e) >= 0) {

			if (p == NULL) {
				r = i->next;

				ElemDelete(&i->value);
				free(i);
				
				i = r;
			}
			else {
				p->next = i->next;

				ElemDelete(&i->value);
				free(i);
				
				i = p->next;
			}
		}
		else {
			p = i;
			i = i->next;
		}
	}
	return r;
}