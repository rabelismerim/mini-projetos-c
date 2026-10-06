#include "entrada.h"
#define LOJAS 8
#define PRODUTOS 4
int main(void) {
    char stores[LOJAS][64], products[PRODUTOS][64], prompt[160];
    double prices[PRODUTOS][LOJAS];
    puts("COMPARADOR DE PRECOS | 8 lojas, 4 produtos");
    for (int j = 0; j < LOJAS; ++j) {
        snprintf(prompt, sizeof prompt, "Nome da loja %d: ", j + 1);
        texto(prompt, stores[j], sizeof stores[j]);
    }
    for (int i = 0; i < PRODUTOS; ++i) {
        snprintf(prompt, sizeof prompt, "Nome do produto %d: ", i + 1);
        texto(prompt, products[i], sizeof products[i]);
    }
    for (int i = 0; i < PRODUTOS; ++i) for (int j = 0; j < LOJAS; ++j) {
        snprintf(prompt, sizeof prompt, "%s em %s (R$): ", products[i], stores[j]);
        prices[i][j] = real(prompt, 0, 1000000);
    }
    puts("\nOFERTAS ABAIXO DE R$ 120.00");
    int found = 0;
    for (int i = 0; i < PRODUTOS; ++i) for (int j = 0; j < LOJAS; ++j)
        if (prices[i][j] < 120) { printf("%-20s | %-20s | R$ %.2f\n", products[i], stores[j], prices[i][j]); ++found; }
    if (!found) puts("Nenhuma oferta encontrada.");
    return 0;
}
