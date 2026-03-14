#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void OptimalIlluminationRec(int M, int R, const int* light,
    size_t light_size, bool* vcurr, bool* vbest, bool* illuminazione,
    int i, int cnt, int* cnt_best)
{
    if (i == (int)light_size) {
        // Controlla se la strada è completamente illuminata
        for (int j = 0; j < M; ++j) {
            if (!illuminazione[j]) return;
        }

        if (cnt < *cnt_best) {
            *cnt_best = cnt;
            memcpy(vbest, vcurr, light_size * sizeof(bool));
        }
        return;
    }

    // Prova con il lampione acceso
    vcurr[i] = true;
    // Salva lo stato attuale
    bool* backup = malloc(M * sizeof(bool));
    memcpy(backup, illuminazione, M * sizeof(bool));

    for (int j = (light[i] - R >= 0 ? light[i] - R : 0);
        j <= light[i] + R && j < M; ++j) {
        illuminazione[j] = true;
    }

    OptimalIlluminationRec(M, R, light, light_size, vcurr, vbest, illuminazione, i + 1, cnt + 1, cnt_best);

    // Ripristina lo stato
    memcpy(illuminazione, backup, M * sizeof(bool));
    free(backup);

    // Prova con il lampione spento
    vcurr[i] = false;
    OptimalIlluminationRec(M, R, light, light_size, vcurr, vbest, illuminazione, i + 1, cnt, cnt_best);
}

bool* OptimalIllumination(int M, int R, const int* light, size_t light_size) {
    bool* vcurr = calloc(light_size, sizeof(bool));
    bool* vbest = calloc(light_size, sizeof(bool));
    bool* illuminazione = calloc(M, sizeof(bool));

    int cnt_best = (int)light_size + 1;  // Impostato al massimo possibile
    OptimalIlluminationRec(M, R, light, light_size, vcurr, vbest, illuminazione, 0, 0, &cnt_best);

    free(vcurr);
    free(illuminazione);

    if (cnt_best > (int)light_size) {
        free(vbest);
        return NULL;
    }

    return vbest;
}

//int main(void) {
//    int M = 10, R = 2;
//    int light[] = { 2, 3, 7, 9 };
//    size_t light_size = sizeof(light) / sizeof(light[0]);
//
//    bool* res = OptimalIllumination(M, R, light, light_size);
//    if (!res) {
//        printf("NULL\n");
//    }
//    else {
//        for (size_t i = 0; i < light_size; ++i) {
//            printf("%d ", res[i]);
//        }
//        printf("\n");
//        free(res);
//    }
//
//    return 0;
//}
