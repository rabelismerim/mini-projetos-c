#include "entrada.h"
int main(void) {
    int men, women;
    double total;
    puts("COMPOSICAO DA TURMA");
    men = inteiro("Quantidade de homens: ", 0, 1000000);
    women = inteiro("Quantidade de mulheres: ", 0, 1000000);
    total = (double)men + women;
    if (!total) puts("Turma vazia: nao ha porcentagens a calcular.");
    else printf("Homens: %.2f%%\nMulheres: %.2f%%\nTotal: %.0f alunos\n", men * 100.0 / total, women * 100.0 / total, total);
    return 0;
}
