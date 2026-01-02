#include <stdio.h>
#include <stdlib.h>

void print_clear(char *s,int len) {
    printf("|");
    for (int i = 0; i < len; i++) {
        if (s[i] <= 0x20 || s[i] >= 0x7E) {
            //inlocuim fiecare caracter special cu un punct
            printf(".");
        }
        else {
            //in caz contrat printam caracterul
            printf("%c", s[i]);
        }
    }
    printf("|");
}

//Probabil bug (While loop nu se termina niciodata deci nu putem afisa ultimi octeti
//daca nu avem o linie de 2 octeti

int main() {
    int character;
    int mem_index = 0;
    char *s = (char *)calloc(0x10, sizeof(char));
    while ((character = getchar()) != EOF && character != '\n') {

        s[mem_index % 0x10] = (char)character;
        if (mem_index % 0x10 == 0x0) {
            printf("%08x ", mem_index);
        }
        printf("%02x ",character);
        mem_index++;
        if ((mem_index % 0x10) == 0x0) {

            print_clear(s, 0x10);
            printf("\n");
            
        }


    }

    printf("%*s",3*(0x10 - (mem_index % 0x10)), " ");
    print_clear(s, (mem_index % 0x10));
    printf("\n%08x ",mem_index);
    printf("\n");

    //printf("Finish\n");

    free(s);
    return 0;
}

