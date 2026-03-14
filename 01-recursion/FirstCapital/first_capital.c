#include <string.h>
#include <stdio.h>
#include <ctype.h>

int FirstCapital(char *s, int i) {
	if (isupper(s[i]) != 0) {
		printf("%d", i + 1);
		return 0;
	}
	else if (i + 1 < (int)strlen(s)) {
		return FirstCapital(s, i + 1);
	}
	else {
		return 2;
	}
}

int main(int argc, char **argv) {
	if (argc != 2) {
		return 1;
	}
	if (strlen(argv[1]) == 0) {
		return 2;
	}

	return FirstCapital(argv[1], 0);
}