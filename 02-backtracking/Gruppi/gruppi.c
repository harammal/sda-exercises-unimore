#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Studente {
	char nome[21];
};
typedef struct Studente Studente;

int Gruppi(const char* filename, int n);

int main(void) {
	
	return Gruppi("nomi_01.txt", 2);
}

bool Verifica(Studente *vcurr, int vcurr_size, Studente* tocheck) {
	for (int i = 0; i < vcurr_size; ++i) {
		bool a = vcurr[i].nome[0] == tocheck->nome[0];
		bool b = (vcurr[i].nome[0] == tocheck->nome[0] + 1) || (vcurr[i].nome[0] == tocheck->nome[0] - 1);

		if (a || b) {
			return false;
		}
	}
	return true;
}

void GruppiRec(Studente *stud, int k, Studente* vcurr, int i, int n, int *nsol) {

	if (i == n) {
		printf("{ %s", vcurr[0].nome);
		for(int j = 1; j < n; ++j){
			printf(", %s", vcurr[j].nome);
		}
		printf(" }\n");

		(*nsol)++;
		return;
	}

	for (int j = 0; j < k; ++j) {
		if (Verifica(vcurr, i, stud + j)) {

			strcpy(vcurr[i].nome, stud[j].nome);
			GruppiRec(stud, k, vcurr, i + 1, n, nsol);
		}
	}
}

int Gruppi(const char* filename, int n) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return 0;
	}

	Studente* stud = NULL;
	int k = 0;

	while (1) {
		stud = realloc(stud, sizeof(Studente) * (k + 1));

		if (fscanf(f, "%20s", stud[k].nome) != 1) {
			stud = realloc(stud, sizeof(Studente) * (k));
			break;
		}
		k++;
	}

	fclose(f);

	if (n<1 || n>k) {
		free(stud);
		return 0;
	}
	
	Studente* vcurr = malloc(sizeof(Studente) * n);
	int nsol = 0;

	GruppiRec(stud, k, vcurr, 0, n, &nsol);

	free(stud);
	free(vcurr);

	return nsol;
}