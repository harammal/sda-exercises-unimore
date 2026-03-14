#include <stdlib.h>
#include <limits.h>

void BinaryGameRec(int* nums, size_t n, int i, int* max) {

	if (i == 4 * (int)n) {
		int x = ~0, y = ~0;

		for (size_t b = 0; b < (2 * n); b += 2) {
			x ^= (nums[b] & nums[b + 1]);
		}
		for (size_t b = (2 * n); b < (4 * n); b += 2) {
			y ^= (nums[b] & nums[b + 1]);
		}

		if (*max < (x - y)) {
			*max = x - y;
		}

		return;
	}

	for (int j = i; j < 4 * (int)n; j++) {
		int temp = nums[i]; nums[i] = nums[j]; nums[j] = temp;
		BinaryGameRec(nums, n, i + 1, max);
		temp = nums[i]; nums[i] = nums[j]; nums[j] = temp;
	}
}

int BinaryGame(const int* nums, size_t n) {
	int* copy = malloc(4 * n * sizeof(int));

	for (size_t i = 0; i < 4 * n; i++) {
		copy[i] = nums[i];
	}

	int max = INT_MIN;
	BinaryGameRec(copy, n, 0, &max);

	free(copy);
	return max;
}