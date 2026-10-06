#include "entrada.h"
#define CAPACIDADE 10
int main(void) {
    int values[CAPACIDADE], count = 0, start = 0, option;
    puts("FILA CIRCULAR (FIFO) | capacidade: 10");
    do {
        puts("\n1 Inserir | 2 Remover | 3 Consultar | 4 Listar | 5 Esvaziar | 6 Sair");
        option = inteiro("Opcao: ", 1, 6);
        switch (option) {
        case 1:
            if (count == CAPACIDADE) puts("Estrutura cheia.");
            else {
                int value = inteiro("Numero: ", -1000000, 1000000);
                values[(start + count) % CAPACIDADE] = value;
                ++count;
                printf("Inserido: %d\n", value);
            }
            break;
        case 2:
            if (!count) puts("Estrutura vazia.");
            else {
                printf("Removido: %d\n", values[start]);
                start = (start + 1) % CAPACIDADE;
                --count;
            }
            break;
        case 3:
            if (!count) puts("Estrutura vazia.");
            else printf("Primeiro: %d\n", values[start]);
            break;
        case 4:
            printf("Elementos (%d/10):", count);
            for (int i = 0; i < count; ++i) printf(" %d", values[(start + i) % CAPACIDADE]);
            puts("");
            break;
        case 5: count = 0; start = 0; puts("Estrutura esvaziada."); break;
        }
    } while (option != 6);
    puts("Programa encerrado.");
    return 0;
}
