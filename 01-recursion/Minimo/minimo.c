//#include "minimo.h"

// Mia soluzione
int Minimo(const int* v, int v_size) {
	// Caso base
	if (v_size == 1) {
		return *v;
	}
	
	int min = Minimo(v + 1, v_size - 1);

	if (*v < min) {
		return *v;
	}
	else {
		return min;
	}
}

// Soluzione Prof 1 (confronto con l'ultimo)
//int Minimo(const int* v, int v_size) {
//	v_size--;
//
//	if (v_size == 0) {
//		return v[0];
//	}
//
//	int m = Minimo(v, v_size);
//	if (m < v[v_size]) {
//		return m;
//	}
//	
//	return v[v_size];
//}

// Soluzione Prof 2 (confronto con il primo)
//int MinimoRec(const int* v, int v_size, i) {
//	if (v_size - 1 == i) {
//		return v[i];
//	}
//	
//	int m = MinimoRec(v, v_size, i + 1);
//
//	if (m < v[i]) {
//		return m;
//	}
//	
//	return v[i];
//}