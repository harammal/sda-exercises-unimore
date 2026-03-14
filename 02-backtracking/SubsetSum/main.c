extern void BacktrackSomma(int n, int i, int vcurr[], int w[], int obiettivo,
	int sommacurr, int rimanenza, int* nsol);

int main(void) {

	int vcurr[3], w[3] = { 2, 3, 5 }, nsol = 0;

	BacktrackSomma(3, 0, vcurr, w, 5, 0, 10, &nsol);

	return 0;
}