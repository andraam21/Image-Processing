#include "utils.h"
#define MAX 1000
#define LUNGIME 15
#define CIFRE 10
#define ALFABET 26

char *codcaesar(char *S, int K) {
    int lungime = strlen(S);
    for (int i = 0; i < lungime; i++) {
        if ('0' <= S[i] && S[i] <= '9') {
            if (S[i] % '0' < K % CIFRE) {
                S[i] = S[i] - K % CIFRE + CIFRE;
            } else {
                S[i] = S[i] - K % CIFRE;
            }
        }
        if ('A' <= S[i] && S[i] <= 'Z') {
            if (S[i] % 'A' < K % ALFABET) {
                S[i] = S[i] - K % ALFABET + ALFABET;
            } else {
                S[i] = S[i] - K % ALFABET;
            }
        }
        if ('a' <= S[i] && S[i] <= 'z') {
            if (S[i] % 'a' < K % ALFABET) {
                S[i] = S[i] - K % ALFABET + ALFABET;
            } else {
                S[i] = S[i] - K % ALFABET;
            }
        }
    }  //  comparam elementele stringului cu codul ASCII
    //  folosim cheia sa le "rotim"
    return S;
}

void SolveTask2() {
    char tip[LUNGIME] = {0};
    scanf("%s", tip);
    char caesar[LUNGIME] = "caesar";
    char vigenere[LUNGIME] = "vigenere";
    char addition[LUNGIME] = "addition";

    if (strcmp(tip, caesar) == 0) {
        int K = 0, i = 0;
        char S[MAX] = {0};
        scanf("%d\n", &K);
        scanf("%s", S);
        char *Sfinal = codcaesar(S, K);
        printf("%s", Sfinal);
    }

    if (strcmp(tip, vigenere) == 0) {
        char K[LUNGIME] = {0}, Key[LUNGIME] = {0};
        char S[MAX] = {0};
        int i = 0;
        scanf("%s\n", K);
        scanf("%s", S);

        int lungkey = strlen(K);
        int lungcod = strlen(S);

        for (i = 0; i < lungkey; i++) {
            Key[i] = K[i] - 'A';
        }  //  aflam pozitiile literelor in alfabet

        for (i = 0; i < lungcod; i++) {
            if ('0' <= S[i] && S[i] <= '9') {
                S[i] = S[i] - Key[i % lungkey] % CIFRE;
                if (S[i] < '0') {
                    S[i] = S[i] + CIFRE;
                }
            }
            if ('A' <= S[i] && S[i] <= 'Z') {
                S[i] = S[i] - Key[i % lungkey] % ALFABET;
                if (S[i] < 'A') {
                    S[i] = S[i] + ALFABET;
                }
            }
            if ('a' <= S[i] && S[i] <= 'z') {
                S[i] = S[i] - Key[i % lungkey] % ALFABET;
                if (S[i] < 'a') {
                    S[i] = S[i] + ALFABET;
                }
            }
        }
        printf("%s", S);
    }

    if (strcmp(tip, addition) == 0) {
        int K = 0, i = 0, j = 0, inceput = 0, counter = 0;
        char N1[MAX] = {0}, N2[MAX] = {0};
        char SUMA[MAX] = {'0'};
        char *N1final = NULL, *N2final = NULL;

        scanf("%d\n", &K);
        scanf("%s\n%s", N1, N2);

        N1final = codcaesar(N1, K);
        N2final = codcaesar(N2, K);

        int lungime1 = strlen(N1);
        int lungime2 = strlen(N2);

        if (lungime1 > lungime2) {  //  mutam numarul mai mic pe prima pozitie
            char *aux = N1final;
            N1final = N2final;
            N2final = aux;
            int auxi = lungime1;
            lungime1 = lungime2;
            lungime2 = auxi;
        }

        j = lungime2 - 1;
        for (i = lungime1 - 1; i >= 0; i--) {
            SUMA[j + 1] = N1final[i] + N2final[j] - '0';
            j--;
        }  //  adunam cele doua numere
        while (j >= 0) {
            SUMA[j + 1] = N2final[j];
            j--;
        }  //  daca cel de-al doilea numar are mai multe cifre
        //  acestea se vor copia in suma finala
        for (i = lungime2; i >= 0; i--) {
            if (SUMA[i] > '9') {
                SUMA[i] -= CIFRE;
                SUMA[i - 1] = SUMA[i - 1] + 1;
            }
        }  //  daca suma cifrelor depaseste 9 incrementam elementul precedent
        while (SUMA[inceput] == '0') {
            counter++;
            inceput++;
        }
        for (i = counter; i < lungime2 + 1; i++) {
            printf("%c", SUMA[i]);
        }
    }
}
