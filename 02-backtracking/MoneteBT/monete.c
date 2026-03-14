#include <stdlib.h>
#include <stdio.h>

void CombinaMoneteRec(int b, const int* m, size_t m_size, int *vcurr, int i, int somma, int *nsol) {

	if (somma == b) {
		(*nsol)++;

		for (size_t j = 0; j < m_size; ++j) {
			printf("%d ", vcurr[j]);
		}

		printf("\n");
		return;
	}

	if(somma > b || i >= (int)m_size) {
		return;
	}

	if (m[i] + somma <= b) {
		vcurr[i]++;
		CombinaMoneteRec(b, m, m_size, vcurr, i, somma + m[i], nsol);
		vcurr[i]--;
	}

	CombinaMoneteRec(b, m, m_size, vcurr, i + 1, somma, nsol);
}

int CombinaMonete(int b, const int* m, size_t m_size) {

	int* vcurr = calloc(m_size, sizeof(int));
	int nsol = 0;
	CombinaMoneteRec(b, m, m_size, vcurr, 0, 0, &nsol);

	free(vcurr);

	return nsol;
}

//int main(void) {
//
//	int m[] = { 1, 2, 50, 10, 5, 20 };
//
//	CombinaMonete(4, m, 6);
//
//	return 0;
//}