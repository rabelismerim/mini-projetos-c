#include "entrada.h"
#include <time.h>
int main(void) {
    time_t now = time(NULL);
    struct tm *today = localtime(&now);
    int year, birth;
    if (!today) { fputs("Falha ao consultar a data.\n", stderr); return 1; }
    year = today->tm_year + 1900;
    puts("IDADE POR ANO DE NASCIMENTO");
    birth = inteiro("Ano de nascimento: ", 1, year);
    printf("Idade que completa em %d: %d anos.\n", year, year - birth);
    return 0;
}
