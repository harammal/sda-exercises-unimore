//#include "fibonacci.h"
#include <stdlib.h>

//static int FibonacciRec(int n) {
//
//	// Caso base
//	if (n <= 1) {
//		return n;
//	}
//
//	return FibonacciRec(n - 1) + FibonacciRec(n - 2);
//}
//
//int Fibonacci(int n) {
//
//	// Caso particolare
//	if (n < 0) {
//		return -1;
//	}
//
//	return FibonacciRec(n);
//}

// Con memorizzazione
static int FibonacciRec(int n, int *memory) {

	// Caso base
	if (n <= 1) {
		return n;
	}

	if (memory[n] == 0) {
		memory[n] = FibonacciRec(n - 1, memory) + FibonacciRec(n - 2, memory);
	}

	return memory[n];
}

int Fibonacci(int n) {

	// Caso particolare
	if (n < 0) {
		return -1;
	}

	int* memory = calloc(n + 1, sizeof(int));
	int ret = FibonacciRec(n, memory);
	free(memory);

	return ret;
}