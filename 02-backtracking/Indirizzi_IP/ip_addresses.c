#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

static int is_valid_part(const char* s, int len) {
    // Lunghezza non valida
    if (len < 1 || len > 3) return 0;

    // Controllo zeri iniziali
    if (len > 1 && s[0] == '0') return 0;

    // Converti in numero
    int num = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9') return 0;
        num = num * 10 + (s[i] - '0');
    }

    // Controllo intervallo 0-255
    return num >= 0 && num <= 255;
}

static void backtrack(const char* s, int pos, int parts, char* current, int* count) {
    int len = (int)strlen(s);

    // Caso base: abbiamo trovato 4 parti valide e consumato tutta la stringa
    if (parts == 4 && pos == len) {
        // Rimuovi l'ultimo punto e stampa
        current[strlen(current) - 1] = '\0';
        printf("%s\n", current);
        (*count)++;
        current[strlen(current)] = '.';
        return;
    }

    // Troppe parti o stringa troppo lunga/corta
    if (parts >= 4 || pos >= len || (4 - parts) * 3 < len - pos) return;

    // Prova tutte le possibili lunghezze per la parte corrente (1-3 cifre)
    char temp[4];
    for (int i = 1; i <= 3 && pos + i <= len; i++) {
        // Copia la sottostringa
        strncpy(temp, s + pos, i);
        temp[i] = '\0';

        // Verifica se la parte è valida
        if (is_valid_part(temp, i)) {
            // Salva la lunghezza corrente del risultato
            int curr_len = (int)strlen(current);

            // Aggiungi la parte corrente e un punto
            strcat(current, temp);
            strcat(current, ".");

            // Ricorsione
            backtrack(s, pos + i, parts + 1, current, count);

            // Backtrack: ripristina la stringa
            current[curr_len] = '\0';
        }
    }
}

int RestoreIPs(const char* s) {
    int count = 0;
    char current[16] = { 0 }; // Buffer per l'indirizzo IP (max 15 caratteri: 4*3 cifre + 3 punti + 1 terminatore)

    // Controllo lunghezza stringa
    int len = (int)strlen(s);
    if (len < 4 || len > 12) return 0;

    backtrack(s, 0, 0, current, &count);
    return count;
}