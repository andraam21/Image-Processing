task1:	Pentru a fi mai usor de lucrat cu numarul, am folosit un vector in care sa salvam
valoarea acestuia in binar. Pentru n(numarul de operatii) si dim(dimensiunea) l-am prelucrat
prin shiftari, dupa care am incrementat valorile.Pentru a vedea care sunt operatiile am creat
o functie care citeste valoarea in binar a numarului initial si intoare o variabila de tip
char.Aceste valori le salvam intr-un alt vector, pentru a avea toate operatiile la un loc. 
task2: Dupa ce am aflat numarul de operatii, operatiile si dimensiunea continuam prin a calcula
cate numere mai trebuie citite prin intermediul formulei date.Ne folosim de o variabila de tip 
float pe care o rotunjim, iar daca aproximarea se face prin lipsa atunci incrementam valoarea 
ei.Introducem ulterior numerele intr-un alt vector si in functie de dimensiune le prelucram 
prin shiftari repetate(mai intai la stanga pentru a scapa de bitii care nu ne intereseaza si 
dupa la dreapta, astfel incat forma binara sa reprezinte operandul de care avem nevoie).Dupa 
aceasta etapa facem calculele finale utilizand vectorul in care se afla operatiile si cel in 
care avem operanzii, returnand in cele din urma rezultatul cerut. 
