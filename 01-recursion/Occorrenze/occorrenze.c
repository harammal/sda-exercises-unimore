#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

    if (argc != 3) {
        fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: \"occorrenze <s> < c>\"");
        return 1;
    }

    size_t len = strlen(argv[1]);
    int count = 0;

    for (size_t i = 0; i < len; i++) {
        if (argv[1][i] == argv[2][0]) {
            count++;
        }
    }

    printf("%d", count);

    return 0;
}
