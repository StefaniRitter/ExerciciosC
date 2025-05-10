#include <stdio.h>
#include <string.h>

int main() {
    char frase[100], palavra[20];
    int i, j, cont = 0, igual;

    printf("Digite uma frase: ");
    gets(frase);

    printf("Digite a palavra que deseja procurar: ");
    gets(palavra);

    int tam_f = strlen(frase);
    int tam_p = strlen(palavra);

    for (i = 0; i <= tam_f - tam_p; i++) {
        igual = 1; 

        for (j = 0; j < tam_p; j++) {
            if (frase[i + j] != palavra[j]) {
                igual = 0; 
                break;
            }
        }

        if (igual == 1) {
            cont++;
        }
    }

    printf("A palavra '%s' aparece %d vezes na frase.\n", palavra, cont);
    return 0;
}
