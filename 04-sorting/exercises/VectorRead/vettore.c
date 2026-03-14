#define _CRT_SECURE_NO_WARNINGS
#include "vettore.h"

void PushBack(Vector* v, const ElemType *e) {
	if (v->size == v->capacity) {
		v->capacity *= 2;
		v->data = realloc(v->data, sizeof(ElemType) * v->capacity);
	}

	v->data[v->size] = ElemCopy(e);
	(v->size)++;
}

Vector* VectorRead(const char* filename) {
	if (filename == NULL) {
		return NULL;
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	Vector* v = malloc(sizeof(Vector));
	if (v == NULL) {
		return NULL;
	}

	v->capacity = 1;
	v->size = 0;
	v->data = malloc(sizeof(ElemType));
	if (v->data == NULL) {
		free(v);
		return NULL;
	}

	int lett = 0;
	ElemType e;

	while ((lett = ElemRead(f, &e)) != EOF) {
		PushBack(v, &e);	
	}

	fclose(f);

	return v;
}

void InsertionSort(ElemType *v, size_t dim) {
	for (size_t i = 1; i < dim; i++) {
		ElemType temp = ElemCopy(&v[i]);
		size_t j = i;

		while (j > 0 && (ElemCompare(&v[j - 1], &temp) == 1)) {
			ElemDelete(&v[j]);
			v[j] = ElemCopy(&v[j - 1]);
			j--;
		}
		ElemDelete(&v[j]);
		v[j] = ElemCopy(&temp);
	}
}

Vector* VectorReadSorted(const char* filename) {
	if (filename == NULL) {
		return NULL;
	}
	Vector *vsort = VectorRead(filename);

	if (vsort == NULL) {
		return NULL;
	}

	InsertionSort(vsort->data, vsort->size);

	return vsort;
}