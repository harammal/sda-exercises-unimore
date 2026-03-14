#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void RegoleRec(const char* r, size_t len, int *nums, int i) {

	if (i == len + 2) {
		
		for (size_t j = 1; j <= len + 1; ++j) {
			if (r == "i" || r == "I") {
				if (nums[j] <= nums[j - 1]) {
					break;
				}
				else {
					r++;
				}
			}
			else {
				if (r == "d" || r == "D") {
					if (nums[j] >= nums[j - 1]) {
						break;
					}
					else {
						r++;
					}
				}
			}
		}

		for (size_t j = 0; j < len + 1; ++j) {
			printf("%d ", nums[i]);
		}
		printf("\n");

		return;
	}
	

	for (size_t j = i; j <= len + 1; ++j) {
		int temp = nums[i]; nums[i] = nums[j]; nums[j] = temp;
		RegoleRec(r, len, nums, i + 1);
		temp = nums[i]; nums[i] = nums[j]; nums[j] = temp;
	}
}

void Regole(const char* r) {
	size_t len = strlen(r);
	if (len == 0) {
		printf("1 \n");
	}
	else
	{
		int* nums = malloc(len + 1 * sizeof(int));

		for (int i = 0; i < len + 1; ++i) {
			nums[i] = i + 1;
		}
		RegoleRec(r, len, nums, 1);
	}
}