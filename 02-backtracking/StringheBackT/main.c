#include <stdio.h>

extern void BacktrackStr(int n);
extern void BacktrackStrMod(int n, int k);

int main(void) {

	BacktrackStr(2);
	printf("\n\n");

	BacktrackStrMod(3, 2);
	printf("\n");

	return 0;
}