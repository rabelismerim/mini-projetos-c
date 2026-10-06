#include "entrada.h"
int main(void) {
    double sum = 0, average;
    puts("BOLETIM DO ALUNO");
    for (int i = 1; i <= 3; ++i) {
        char prompt[40];
        snprintf(prompt, sizeof prompt, "Nota %d (0 a 10): ", i);
        sum += real(prompt, 0, 10);
    }
    average = sum / 3;
    printf("Media: %.2f\nSituacao: %s\n", average,
           average >= 7 ? "Aprovado" : average >= 5 ? "Recuperacao" : "Reprovado");
    return 0;
}
