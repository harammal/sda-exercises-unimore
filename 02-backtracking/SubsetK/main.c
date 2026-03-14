extern void SubsetK(int n, int i, int k, int vcurr[], int count, int* nsol);

int main(void) {
	int vcurr[3], nsol = 0;

	SubsetK(3, 0, 2, vcurr, 0, &nsol);

	return 0;
}