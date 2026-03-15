#include "dlgemelli.h"

int Len(const Item* i) {
	int len = 0;
	for (const Item* tmp = i; !DListIsEmpty(tmp); tmp = DListGetTail(tmp)) {
		len++;
	}
	return len;
}

int SommaGemelli(const Item* i) {
	int len = Len(i);
	if (len == 0 || len == 1) {
		return 0;
	}

    const Item* front = i;
    const Item* back = i;
    while (DListGetTail(back) != NULL) {
        back = DListGetTail(back);
    }

    ElemType somma_max = 0, somma_curr;

    for (int k = 0; k <= len / 2 - 1; ++k) {
        somma_curr = *DListGetHeadValue(front) + *DListGetHeadValue(back);
        if (somma_curr > somma_max) {
            somma_max = somma_curr;
        }

        front = DListGetTail(front);
        back = DListGetPrev(back);
    }

    return somma_max;
}