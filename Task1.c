#include "utils.h"
#define LUNGIME 150
#define MIN 15
#define ZECE 10

char miscare_a(int x1, int x2, int x3, int x4) {
    char miscare = 0;
    if (x1 > x2 && x1 > x3 && x1 > x4) {
        miscare = 'R';
    }  //  right
    if (x2 > x1 && x2 > x3 && x2 > x4) {
        miscare = 'U';
    }  //  up
    if (x3 > x1 && x3 > x2 && x3 > x4) {
        miscare = 'L';
    }  //  left
    if (x4 > x1 && x4 > x2 && x4 > x3) {
        miscare = 'D';
    }  //  down
    return miscare;
}

char miscare_b(char *v, int n) {
    int palindrom = 1;
    int prim = 1;
    int i = 0, j = 1;
    int ultimul = 0;
    if (v[n - 1] == '\n') {
        ultimul = 1;
    }
    char miscare = 0;
    for (i = 1; i < (n / 2) + 1; i++) {
        if ((v[i] - '0') != (v[n - j - ultimul] - '0')) {
            palindrom = 0;
        }
        j++;
    }  //  verificam daca este palindrom
    int numar = (v[n - 2 - ultimul] - '0') * ZECE + (v[n - 1 - ultimul] - '0');
    for (i = 2; i < (numar / 2); i++) {
        if (numar % i == 0) {
            prim = 0;
        }
    }  //  aflam numarul de la final si verificam daca este prim
    if (palindrom == 1) {
        if (prim == 1) {
            miscare = 'L';
        }
        if (prim == 0) {
            miscare = 'R';
        }
    }
    if (palindrom == 0) {
        if (prim == 1) {
            miscare = 'U';
        }
        if (prim == 0) {
            miscare = 'D';
        }
    }
    return miscare;
}

char miscare_c(char *v, int n) {
    int i = 0;
    int S = 0;
    int n1 = (v[1] - '0'), k1 = (v[2] - '0');
    char miscare = 0;
    for (i = 0; i < k1; i++) {
        S = S + v[((k1 * i) % n1) + 3] - '0';
    }  //  aflam suma in mod circular
    if (S % 4 == 0) {
        miscare = 'L';
    }
    if (S % 4 == 1) {
        miscare = 'U';
    }
    if (S % 4 == 2) {
        miscare = 'R';
    }
    if (S % 4 == 3) {
        miscare = 'D';
    }
    return miscare;
}

void SolveTask1() {
    int N = 0, M = 0;
    scanf("%d %d\n", &N, &M);
    char string[LUNGIME] = {0};
    fgets(string, sizeof(string), stdin);
    int i = 0, j = 0;
    char matrix[N][M];
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            matrix[i][j] = 0;
        }
    }
    const char spatiu[5] = " ";
    char *cod = NULL;
    cod = strtok(string, spatiu);
    char miscari[MIN];
    int k = 0;
    while (cod != NULL) {
        int lungime = strlen(cod);
        if (cod[0] == 'a') {
            miscari[k] = miscare_a(cod[1], cod[2], cod[3], cod[4]);
        }
        if (cod[0] == 'b') {
            miscari[k] = miscare_b(cod, lungime);
        }
        if (cod[0] == 'c') {
            miscari[k] = miscare_c(cod, lungime);
        }

        cod = strtok(NULL, spatiu);
        k++;
    }

    char *misc[MIN];
    misc[0] = &(matrix[0][0]);  //  pointerul de la inceputul matricei

    for (i = 0; i <= k; i++) {
        if (miscari[i] == 'D') {
            misc[i + 1] = misc[i] + M;
        }
        if (miscari[i] == 'L') {
            misc[i + 1] = misc[i] - 1;
        }
        if (miscari[i] == 'R') {
            misc[i + 1] = misc[i] + 1;
        }
        if (miscari[i] == 'U') {
            misc[i + 1] = misc[i] - M;
        }
    }  //  mutam pointerii in fuctie de miscare
    char *s = 0;
    for (i = 0; i <= k; i++) {
        *misc[i] = s + 1;
        s++;
    }  //  atribuim fiecarui pointer numarul miscarii

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
