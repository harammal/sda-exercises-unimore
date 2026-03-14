#include <stdlib.h>
int main(void){

	int tagli[] = { 50, 20, 10, 5, 2, 1 };
	int* monete = Monete(tagli, 6, 126);

	free(monete);

	return 0;
}