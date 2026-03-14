#include <stdlib.h>

extern int BinaryGame(const int* nums, size_t n);

int main(void) {

	int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	return BinaryGame(nums, 2);
}