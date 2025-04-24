#include <stdio.h>
#include <stdbool.h>

int main() {
    int qnt;
    scanf("%d", &qnt);
    int estrelas[qnt];
    for (int i = 0; i < qnt; i++) {
        scanf("%d", &estrelas[i]);
    }
    bool estrelasatacadas[qnt];
    for (int i = 0; i < qnt; i++) {
        estrelasatacadas[i] = false;
    }
    int atacadas = 0;
    int posicao = 0;
    while (posicao >= 0 && posicao < qnt && estrelas[posicao] > 0) {
        if (!estrelasatacadas[posicao]) {
            estrelasatacadas[posicao] = true;
            atacadas++;
        }
        estrelas[posicao]--;
        if (estrelas[posicao] % 2 == 0) {
            posicao++;
        } else {
            posicao--;
        }
    }
    long long int carneiros = 0;
    for (int i = 0; i < qnt; i++) {
        carneiros += estrelas[i];
    }
    printf("%d %lld\n", atacadas, carneiros);
    return 0;
}
