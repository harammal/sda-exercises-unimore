#include "list.h"

int main(void) {
	ElemType e[] = { {"Michele", "Firenze", 56, "Modena", "MO", "41126"},
					{"Giorgio", "Giannini", 45, "Milano", "BO", "45000"},
					{"Michele", "Araldi", 30, "Bologna", "MI", "41xxx"} };

	Item *list = ListCreateEmpty();

	for (int i = 0; i < sizeof(e) / sizeof(ElemType); ++i) {
		list = ListInsertBack(list, e + i);
	}

	ElemType* f = Find(list, "Michele");

	ListDelete(list);

	return 0;
}