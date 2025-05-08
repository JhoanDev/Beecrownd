#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

int main() {
    Fila *f = cria_fila();
    if (!f) {
        printf("Erro ao criar fila.\n");
        return 1;
    }

    fila_insere(f, strdup("linha 1"));
    fila_insere(f, strdup("linha 2"));
    fila_insere(f, strdup("linha 3"));

    char *linha;
    while ((linha = fila_retira(f)) != NULL) {
        printf("Retirado: %s\n", linha);
        free(linha); 
    }

    fila_libera(f);

    return 0;
}
