#define _CRT_SECURE_NO_WARNINGS
#include "gioielli.h"
#include <stdio.h>

int LeggiDati(FILE* f, Gioiello** g) {
    Gioiello* letti = NULL;
    Gioiello tmp;

    int i = 0;
    while (1) {
        if (fscanf(f, "%i %f %f", &tmp.codice, &tmp.peso, &tmp.prezzo) != 3) {
            break;
        }
        letti = realloc(letti, (++i) * sizeof(Gioiello));
        letti[i - 1] = tmp;
    }

    *g = letti;

    fclose(f);
    return i;
}

int TrovaMigliore(Gioiello* g, int n) {
    float value_best = 0;
    int index_best = -1;
    for (int i = 0; i < n; ++i) {
        if (g[i].peso != 0) {
            float cur_value = g[i].peso / g[i].prezzo;
            if (index_best == -1 || cur_value > value_best) {
                value_best = cur_value;
                index_best = i;
            }
        }
    }
    return index_best;
}

Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size) {
    FILE* f;

    f = fopen(filename, "r");
    if (f == NULL) {
        return NULL;
    }

    Gioiello* g; // Gioielli disponibili
    int n = LeggiDati(f, &g);

    Gioiello* a; // Gioielli acquistati
    a = malloc(n * sizeof(Gioiello));

    float soldi_rimasti = budget;
    (*ret_size) = 0;

    while (soldi_rimasti > 0) {
        int index_best = TrovaMigliore(g, n);
        if (index_best == -1) {
            break; // Non ci sono più gioielli da comprare
        }
        if (g[index_best].prezzo <= soldi_rimasti) {
            a[(*ret_size)] = g[index_best];
            (*ret_size)++;
            soldi_rimasti -= g[index_best].prezzo;
        }
        g[index_best].peso = 0;

    }

    free(g);
    return a;
}