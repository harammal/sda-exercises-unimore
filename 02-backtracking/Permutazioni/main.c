extern void Permutazioni(int n, int i, int vcurr[], int* nsol);

int main(void) {

	int vcurr[3] = {0, 1, 2}, nsol = 0;

	Permutazioni(3, 0, vcurr, &nsol);
	return 0;
}