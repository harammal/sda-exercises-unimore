#include "next_greater.h"
#include <limits.h>

int Lenght(const Item* list) {
	int len = 0;
	for (const Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		len++;
	}
	return len;
}

ElemType TrovaPrimoMax(const Item* list) {
	if (ListIsEmpty(ListGetTail(list))) {
		return INT_MIN;
	}

	ElemType max = list->value;

	for (const Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		ElemType val = *ListGetHeadValue(tmp);

		if (ElemCompare(&val, &max) > 0) {
			max = val;
			break;
		}
	}
	return max;
}

ElemType* NextGreater(const Item* list, size_t* answer_size) {
	if (ListIsEmpty(list)) {
		*answer_size = 0;
		return NULL;
	}

	int len = Lenght(list);
	*answer_size = len;

	ElemType *answer = malloc(sizeof(ElemType) * len);

	int i = 0;
	for (const Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		ElemType max = TrovaPrimoMax(tmp);

		if (ElemCompare(&max, ListGetHeadValue(tmp)) == 0) {
			answer[i] = INT_MIN;
		}
		else {
			answer[i] = max;
		}
		i++;
	}

	return answer;
}