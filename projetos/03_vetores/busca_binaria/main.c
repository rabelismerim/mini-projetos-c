#include "entrada.h"
int main(void) {
    int values[100], size, target, left, right;
    puts("BUSCA BINARIA | vetor em ordem crescente");
    size = inteiro("Quantidade de elementos (1 a 100): ", 1, 100);
    for (int i = 0; i < size; ++i) {
        char prompt[50];
        snprintf(prompt, sizeof prompt, "Elemento %d: ", i + 1);
        values[i] = inteiro(prompt, i ? values[i - 1] : -1000000, 1000000);
    }
    target = inteiro("Numero a pesquisar: ", -1000000, 1000000);
    left = 0; right = size - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (values[middle] == target) { printf("Encontrado na posicao %d (indice %d).\n", middle + 1, middle); return 0; }
        if (values[middle] < target) left = middle + 1;
        else right = middle - 1;
    }
    puts("Numero nao encontrado.");
    return 0;
}
