extern void BacktrackSubset(int n, int i, int vcurr[], int* nsol);

int main(void) {

	int vcurr[2], nsol = 0;

	BacktrackSubset(2, 0, vcurr, &nsol);

	return 0;
}