#include "utils.h"
#define MAX 1000
#define PARA 10000

void SolveTask3() {
     char paragrafemici[MAX];
    char paragraf[PARA];

    while (fgets(paragrafemici, sizeof(paragrafemici), stdin)) {
        strncat(paragraf, paragrafemici, strlen(paragrafemici));
    }  //  concatenam paragrafele mici

    char cuvinte[MAX][MAX];
    char carspeciale[] = " ,.;!\n";
    int i = 0;
    char *token = strtok(paragraf, carspeciale);
    int counter = 0;  //  declaram un counter ce numara cate cuvinte sunt
    while (token != NULL) {
        strncpy(cuvinte[i], token, strlen(token));  //  extrag toate cuvintele
        i++;
        token = strtok(NULL, carspeciale);
        counter++;
    }

    char spatiu[] = " ";
    for (i = 0; i <= counter; i++) {
        strncat(cuvinte[i], spatiu, strlen(spatiu));
    }  //  punem spatiu cuvintelor la final

    for (i = 0; i <= counter; i++) {
        strncat(cuvinte[i], cuvinte[i + 1], strlen(cuvinte[i+1]));
    }  //  aflam grupurile

    if (counter % 3 != 0 || counter % 5 != 0) {
        counter--;
    }  //  verificam daca ultima pereche are un singur termen

    char grupfinal[MAX][MAX];
    int nraparitii[MAX];

    for (i = 0; i < counter; i++) {
        for (int j = i; j < counter; j++) {
            if (strcmp(cuvinte[i], cuvinte[j]) == 0) {
                strncpy(grupfinal[i], cuvinte[i], strlen(cuvinte[i]));
                nraparitii[i]++;  //  aflu numarul de aparitii
            }
        }
    }

    for (i = 0; i < counter; i++) {
        for (int j = i + 1; j < counter; j++) {
            if (strcmp(grupfinal[i], grupfinal[j]) == 0) {
                strncpy(grupfinal[j], "0", 2);
                nraparitii[j] = 0;
            }  //  anulez grupurile dublate
        }
    }
    int duble = 0;
    for (i = 0; i < counter; i++) {
        if (strcmp(grupfinal[i], "0") == 0) {
            duble++;  //  aflu numarul de dubluri
        }
    }

    printf("%d \n", counter - duble);
    for (i = 0; i < counter; i++) {
        if (strcmp(grupfinal[i], "0") != 0) {
            printf("%s %d", grupfinal[i], nraparitii[i]);
            printf("\n");
        }
    }
}
