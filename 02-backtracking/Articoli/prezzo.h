#ifndef PREZZO_H
#define PREZZO_H

#include <stdlib.h>
#include <stdio.h>

struct Articolo {
	char nome[11];
	int prezzo;
};
typedef struct Articolo Articolo;

extern void TrovaArticoli(const Articolo* a, size_t a_size, int sum);

#endif // !PREZZO_H