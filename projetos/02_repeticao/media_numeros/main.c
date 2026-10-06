#include "entrada.h"
int main(void) {
    double sum = 0;
    int count = 0, value;
    puts("MEDIA DE NUMEROS | 9999 encerra");
    while ((value = inteiro("Numero: ", -1000000, 1000000)) != 9999) {
        sum += value;
        ++count;
    }
    if (count) printf("Quantidade: %d\nMedia: %.2f\n", count, sum / count);
    else puts("Nenhum numero informado.");
    return 0;
}
