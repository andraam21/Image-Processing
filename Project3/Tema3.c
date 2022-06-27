#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "bmp_header.h"
#define CINCI 5
#define SASE 6
#define SAPTE 7
#define OPT 8
#define MAX 10000
#define MIN 100

int *draw_function(int y1, int x1, int y2,
 int x2, int culoare, int creion, int *matrix, int width, int height) {
    int yfinal = 0, xfinal = 0, dimx = 0, dimy = 0, aux = 0;
    int grosime = creion / 2;  //  grosimea fata de pixelul principal

    if (x1 < x2) {
        dimx = x2 - x1;
    } else {
        dimx = x1 - x2;
    }
    if (y1 < y2) {
        dimy = y2 - y1;
    } else {
        dimy = y1 - y2;
    }

    if (dimy > dimx) {
        if (y2 > y1) {
            for (int k = y1; k <= y2; k++) {
                //  gasesc pixelul principal
                xfinal = (k - y1) * (x2 - x1) + x1 * (y2 - y1);
                xfinal = xfinal / (y2 - y1);
                //  bordez pixelul principal
                for (int i = 0; i <= grosime; i++) {
                    for (int j = 0; j <= grosime; j++) {
                        //  verific daca linia trasata iese din imagine
                        if (xfinal - i >= 0 && k - j >= 0 && k + j < width) {
                            matrix[(xfinal - i) * width + k + j] = culoare;
                            matrix[(xfinal - i) * width + k - j] = culoare;
                        }
                        if (xfinal + i < height && k + j < width
                         && k - j >= 0) {
                            matrix[(xfinal + i) * width + k + j] = culoare;
                            matrix[(xfinal + i) * width + k - j] = culoare;
                        }
                    }
                }
            }
        }
        if (y1 > y2) {
            for (int k = y2; k <= y1; k++) {
                xfinal = (k - y1) * (x2 - x1) + x1 * (y2 - y1);
                xfinal = xfinal / (y2 - y1);

                for (int i = 0; i <= grosime; i++) {
                    for (int j = 0; j <= grosime; j++) {
                        if (xfinal - i >= 0 && k - j >= 0 && k + j < width) {
                            matrix[(xfinal - i) * width + k + j] = culoare;
                            matrix[(xfinal - i) * width + k - j] = culoare;
                        }
                        if (xfinal + i < height && k + j < width
                         && k - j >= 0) {
                            matrix[(xfinal + i) * width + k + j] = culoare;
                            matrix[(xfinal + i) * width + k - j] = culoare;
                        }
                    }
                }
            }
        }
    }
    if (dimy <= dimx) {
        if (x2 > x1) {
            for (int k = x1; k <= x2; k++) {
                yfinal = (k - x1) * (y2 - y1) + (x2 - x1) * y1;
                yfinal = yfinal / (x2 - x1);

                for (int i = 0; i <= grosime; i++) {
                    for (int j = 0; j <= grosime; j++) {
                        if (yfinal - i >= 0 && k - j >= 0 && k + j <= height) {
                            matrix[(yfinal - i) + (k + j) * width] = culoare;
                            matrix[(yfinal - i) + (k - j) * width] = culoare;
                        }
                        if (yfinal + i < width && k + j < height
                         && k - j >= 0) {
                            matrix[(yfinal + i) + (k + j) * width] = culoare;
                            matrix[(yfinal + i) + (k - j) * width] = culoare;
                        }
                    }
                }
            }
        }
        if (x1 > x2) {
            for (int k = x2; k <= x1; k++) {
                yfinal = (k - x1) * (y2 - y1) + (x2 - x1) * y1;
                yfinal = yfinal / (x2 - x1);

                for (int i = 0; i <= grosime; i++) {
                    for (int j = 0; j <= grosime; j++) {
                        if (yfinal - i >= 0 && k - j >= 0
                         && yfinal + i < width) {
                            matrix[(yfinal - i) + (k + j) * width] = culoare;
                            matrix[(yfinal - i) + (k - j) * width] = culoare;
                        }
                        if (k + j < height && k - j >= 0) {
                            matrix[(yfinal + i) + (k + j) * width] = culoare;
                            matrix[(yfinal + i) + (k - j) * width] = culoare;
                        }
                    }
                }
            }
        }
    }
    return matrix;
}
int *fill_function(int y, int x, int *matrix,
 int culoare, int width, int height) {
    int dim = width * height;
    int culoare_veche = matrix[x * width + y];  //  retin vechea culoare
    matrix[x * width + y] = culoare;
    //  caut recursiv toti vecinii pixelului initial
    //  daca au culoarea initiala atunci o schimb cu cea nou setata
    if (x >= 0 && y >= 0) {
        if (y + 1 < width) {
            if (matrix[x * width + y + 1] == culoare_veche) {
                fill_function(y + 1, x, matrix, culoare, width, height);
                matrix[x * width + y + 1] = culoare;
            }
        }
        if (y - 1 >= 0) {
            if (matrix[x * width + y - 1] == culoare_veche) {
                fill_function(y - 1, x, matrix, culoare, width, height);
                matrix[x * width + y - 1] = culoare;
            }
        }
        if (x + 1 < height) {
            if (matrix[(x + 1) * width + y] == culoare_veche) {
                fill_function(y, x + 1, matrix, culoare, width, height);
                matrix[(x + 1) * width + y] = culoare;
            }
        }
        if (x - 1 >= 0) {
            if (matrix[(x - 1) * width + y] == culoare_veche) {
                fill_function(y, x - 1, matrix, culoare, width, height);
                matrix[(x - 1) * width + y] = culoare;
            }
        }
    }
    return matrix;
}

int main() {
    char comanda[MIN];
    char comenzi[MAX];
    char parametrii[MIN][MIN];
    int i = 0, m = 0;
    char quit[] = "quit\n";

    while (fgets(comanda, sizeof(comanda), stdin)
     && strcmp(comanda, quit) != 0) {
        strncat(comenzi, comanda, sizeof(comanda));
    }  //  concatenez toate comenzile

    char *token = strtok(comenzi, " ");

    while (token != NULL) {
        strncpy(parametrii[m], token, strlen(token));
        m++;
        token = strtok(NULL, " \n");
    }  //  retin fiecare parametru

    char edit[] = "edit";
    char save[] = "save";
    char insert[] = "insert";
    char set[] = "set";
    char draw[] = "draw";
    char fill[] = "fill";

    int dim = 0, dim1 = 0;
    int *matrix = NULL;
    int *overmatrix = NULL;
    int R = 0, G = 0, B = 0;
    int culoare = 0, creion = 0;

    bmp_fileheader *Imag = (bmp_fileheader *)malloc(sizeof(bmp_fileheader));
    if (Imag == NULL) {
        printf("Alocarea nu a reusit");  //  verific alocare
    }
    bmp_infoheader *Imag_0 = (bmp_infoheader *)malloc(sizeof(bmp_infoheader));
    if (Imag_0 == NULL) {
        printf("Alocarea nu a reusit");
    }
    bmp_fileheader *OverImag = (bmp_fileheader *)malloc(sizeof(bmp_fileheader));
    if (OverImag == NULL) {
        printf("Alocarea nu a reusit");
    }
    bmp_infoheader *OverImag_0 = (bmp_infoheader *)
    malloc(sizeof(bmp_infoheader));
    if (OverImag_0 == NULL) {
        printf("Alocarea nu a reusit");
    }

    for (int n = 0; n < m; n++) {
        if (strcmp(parametrii[n], edit) == 0) {
            FILE *desimag = fopen(parametrii[n + 1], "rb");

            fread(&(Imag->fileMarker1), sizeof(char), 1, desimag);
            fread(&(Imag->fileMarker2), sizeof(char), 1, desimag);
            fread(&(Imag->bfSize), sizeof(unsigned int), 1, desimag);
            fread(&(Imag->unused1), sizeof(unsigned short), 1, desimag);
            fread(&(Imag->unused2), sizeof(unsigned short), 1, desimag);
            fread(&(Imag->imageDataOffset), sizeof(unsigned int), 1, desimag);
            fread(&(Imag_0->biSize), sizeof(unsigned int), 1, desimag);
            fread(&(Imag_0->width), sizeof(signed int), 1, desimag);
            fread(&(Imag_0->height), sizeof(signed int), 1, desimag);
            fread(&(Imag_0->planes), sizeof(unsigned short), 1, desimag);
            fread(&(Imag_0->bitPix), sizeof(unsigned short), 1, desimag);
            fread(&(Imag_0->biCompression), sizeof(unsigned int), 1, desimag);
            fread(&(Imag_0->biSizeImage), sizeof(unsigned int), 1, desimag);
            fread(&(Imag_0->biXPelsPerMeter), sizeof(int), 1, desimag);
            fread(&(Imag_0->biYPelsPerMeter), sizeof(int), 1, desimag);
            fread(&(Imag_0->biClrUsed), sizeof(unsigned int), 1, desimag);
            fread(&(Imag_0->biClrImportant), sizeof(unsigned int), 1, desimag);

            i = 0;
            dim = (Imag_0->width * Imag_0->height);
            matrix = calloc(dim, sizeof(int));
            if (matrix == NULL) {
                printf("Nu s-a reusit alocarea");
            }
            while (i < dim) {
                fread(&matrix[i], sizeof(char), 3, desimag);
                i++;
            }  //  grupez octetii cate 3 pentru a forma un pixel

            fclose(desimag);
        }

        if (strcmp(parametrii[n], save) == 0) {
            FILE *salimag = fopen(parametrii[n + 1], "wb");

            fwrite(&Imag->fileMarker1, sizeof(unsigned char), 1, salimag);
            fwrite(&Imag->fileMarker2, sizeof(unsigned char), 1, salimag);
            fwrite(&Imag->bfSize, sizeof(unsigned int), 1, salimag);
            fwrite(&Imag->unused1, sizeof(unsigned short), 1, salimag);
            fwrite(&Imag->unused2, sizeof(unsigned short), 1, salimag);
            fwrite(&Imag->imageDataOffset, sizeof(unsigned int), 1, salimag);
            fwrite(&Imag_0->biSize, sizeof(unsigned int), 1, salimag);
            fwrite(&Imag_0->width, sizeof(unsigned int), 1, salimag);
            fwrite(&Imag_0->height, sizeof(unsigned int), 1, salimag);
            fwrite(&Imag_0->planes, sizeof(unsigned short), 1, salimag);
            fwrite(&Imag_0->bitPix, sizeof(unsigned short), 1, salimag);
            fwrite(&Imag_0->biCompression, sizeof(unsigned int), 1, salimag);
            fwrite(&Imag_0->biSizeImage, sizeof(unsigned int), 1, salimag);
            fwrite(&Imag_0->biXPelsPerMeter, sizeof(int), 1, salimag);
            fwrite(&Imag_0->biYPelsPerMeter, sizeof(int), 1, salimag);
            fwrite(&Imag_0->biClrUsed, sizeof(unsigned int), 1, salimag);
            fwrite(&Imag_0->biClrImportant, sizeof(unsigned int), 1, salimag);

            for (i = 0; i < dim; i++) {
                fwrite(&matrix[i], sizeof(char), 3, salimag);
            }  //  salvez informatiile in noul file

            fclose(salimag);
        }

        if (strcmp(parametrii[n], insert) == 0) {
            FILE *insert = fopen(parametrii[n + 1], "rb");

            int col = atoi(parametrii[n + 2]);
            int lin = atoi(parametrii[n + 3]);

            fread(&(OverImag->fileMarker1), sizeof(char), 1, insert);
            fread(&(OverImag->fileMarker2), sizeof(char), 1, insert);
            fread(&(OverImag->bfSize), sizeof(unsigned int), 1, insert);
            fread(&(OverImag->unused1), sizeof(unsigned short), 1, insert);
            fread(&(OverImag->unused2), sizeof(unsigned short), 1, insert);
            fread(&(OverImag->imageDataOffset), sizeof(unsigned int),
             1, insert);
            fread(&(OverImag_0->biSize), sizeof(unsigned int), 1, insert);
            fread(&(OverImag_0->width), sizeof(signed int), 1, insert);
            fread(&(OverImag_0->height), sizeof(signed int), 1, insert);
            fread(&(OverImag_0->planes), sizeof(unsigned short), 1, insert);
            fread(&(OverImag_0->bitPix), sizeof(unsigned short), 1,
             insert);
            fread(&(OverImag_0->biCompression), sizeof(unsigned int), 1,
             insert);
            fread(&(OverImag_0->biSizeImage), sizeof(unsigned int), 1,
             insert);
            fread(&(OverImag_0->biXPelsPerMeter), sizeof(int), 1, insert);
            fread(&(OverImag_0->biYPelsPerMeter), sizeof(int), 1, insert);
            fread(&(OverImag_0->biClrUsed), sizeof(unsigned int), 1, insert);
            fread(&(OverImag_0->biClrImportant), sizeof(unsigned int), 1,
             insert);

            i = 0;
            dim1 = (OverImag_0->width * OverImag_0->height);
            overmatrix = calloc(dim1, sizeof(int));
            if (overmatrix == NULL) {
                printf("Nu s-a reusit alocarea");
            }
            while (i < dim1) {
                fread(&overmatrix[i], sizeof(char), 3, insert);
                i++;
            }
            int y = Imag_0->height;
            int x = Imag_0->width;
            int y1 = OverImag_0->height;
            int x1 = OverImag_0->width;

            i = 0;
            int sar = 0;
            int marg = lin * x + col;

            while ((i + sar) < x1 * y1 && (marg + i) < x * y) {
                matrix[marg + i] = overmatrix[i + sar];
                if ((i + 1 + sar) % x1 == 0 && (col + x1) < x) {
                    marg += x;
                    marg -= x1;
                }  //  poza inserata e mai mica decat originala
                if ((i + 1 + marg) % x == 0 && (col + x1) > x) {
                    sar += x1;
                    sar += col;
                    sar -= x;
                    marg += col;
                }  // poza depaseste marginea
                i++;
            }

            fclose(insert);
        }
        if (strcmp(parametrii[n], set) == 0) {
            if (strcmp(parametrii[n + 1], "draw_color") == 0) {
                R = atoi(parametrii[n + 2]);
                G = atoi(parametrii[n + 3]);
                B = atoi(parametrii[n + 4]);

                unsigned char Rchar = *((unsigned char *)&R);
                unsigned char Gchar = *((unsigned char *)&G);
                unsigned char Bchar = *((unsigned char *)&B);

                culoare = Rchar;
                culoare <<= OPT;
                culoare += Gchar;
                culoare <<= OPT;
                culoare += Bchar;
                //  transform cei 3 octeti pentru culoare intr un pixel
            }
            if (strcmp(parametrii[n + 1], "line_width") == 0) {
                creion = atoi(parametrii[n + 2]);
            }
        }

        if (strcmp(parametrii[n], draw) == 0) {
            if (strcmp(parametrii[n + 1], "line") == 0) {
                int y1 = atoi(parametrii[n + 2]);
                int x1 = atoi(parametrii[n + 3]);
                int y2 = atoi(parametrii[n + 4]);
                int x2 = atoi(parametrii[n + CINCI]);

                int *matrixaux = draw_function(y1, x1, y2, x2,
                 culoare, creion, matrix, Imag_0->width, Imag_0->height);

                for (i = 0; i < dim; i++) {
                    matrix[i] = matrixaux[i];
                }
            }
            if (strcmp(parametrii[n + 1], "rectangle") == 0) {
                int y1 = atoi(parametrii[n + 2]);
                int x1 = atoi(parametrii[n + 3]);
                int width = atoi(parametrii[n + 4]);
                int height = atoi(parametrii[n + CINCI]);

                //  aflu coordonatele dreptunghiului
                int y2 = width + y1;
                int y3 = y2;
                int y4 = y1;
                int x2 = x1;
                int x3 = x1 + height;
                int x4 = x3;

                if (x4 > Imag_0->height) {
                    x4 = Imag_0->height;
                }

                if (y2 > Imag_0->width) {
                    y2 = Imag_0->width;
                }

                int *matrixaux = draw_function(y1, x1, y4, x4, culoare,
                 creion, matrix, Imag_0->width, Imag_0->height);
                int *matrixaux1 = draw_function(y2, x2, y1, x1, culoare,
                 creion, matrixaux, Imag_0->width, Imag_0->height);
                if (x3 < Imag_0->height && y3 < Imag_0->width) {
                    int *matrixaux2 = draw_function(y2, x2, y3, x3, culoare,
                     creion, matrixaux1, Imag_0->width, Imag_0->height);
                    int *matrixaux3 = draw_function(y3, x3, y4, x4, culoare,
                     creion, matrixaux2, Imag_0->width, Imag_0->height);

                    for (i = 0; i < dim; i++) {
                        matrix[i] = matrixaux3[i];
                    }
               //  daca dreptunghiul iese din imagine
                //  nu se mai traseaza toate liniile complet
                 } else {
                    for (i = 0; i < dim; i++) {
                        matrix[i] = matrixaux1[i];
                    }
                }
            }
            if (strcmp(parametrii[n + 1], "triangle") == 0) {
                int y1 = atoi(parametrii[n + 2]);
                int x1 = atoi(parametrii[n + 3]);
                int y2 = atoi(parametrii[n + 4]);
                int x2 = atoi(parametrii[n + CINCI]);
                int y3 = atoi(parametrii[n + SASE]);
                int x3 = atoi(parametrii[n + SAPTE]);

                int *matrixaux = draw_function(y1, x1, y2, x2, culoare,
                 creion, matrix, Imag_0->width, Imag_0->height);
                int *matrixaux1 = draw_function(y3, x3, y2, x2, culoare,
                 creion, matrixaux, Imag_0->width, Imag_0->height);
                int *matrixaux2 = draw_function(y3, x3, y1, x1, culoare,
                 creion, matrixaux1, Imag_0->width, Imag_0->height);

                for (i = 0; i < dim; i++) {
                    matrix[i] = matrixaux2[i];
                }
            }
        }
        if (strcmp(parametrii[n], fill) == 0) {
            int y = atoi(parametrii[n + 1]);
            int x = atoi(parametrii[n + 2]);
            if (matrix[x * Imag_0->width + y] != culoare) {
                int *matrixaux = fill_function(y, x, matrix, culoare,
                 Imag_0->width, Imag_0->height);
                for (i = 0; i < dim; i++) {
                    matrix[i] = matrixaux[i];
                }
            }
        }
    }
    free(Imag);
    free(Imag_0);
    free(OverImag);
    free(OverImag_0);
    free(matrix);
    free(overmatrix);
    return 0;
}
