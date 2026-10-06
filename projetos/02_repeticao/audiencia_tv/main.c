#include "entrada.h"
int main(void) {
    const int channels[] = {4, 5, 7, 12};
    double viewers[4] = {0}, total = 0;
    int channel;
    puts("AUDIENCIA DE TV | canal 0 encerra");
    while ((channel = inteiro("Canal (4, 5, 7, 12): ", 0, 12)) != 0) {
        int index = -1;
        for (int i = 0; i < 4; ++i) if (channels[i] == channel) index = i;
        if (index < 0) { puts("Canal nao pesquisado."); continue; }
        int people = inteiro("Pessoas assistindo: ", 0, 1000000);
        viewers[index] += people;
        total += people;
    }
    if (!total) { puts("Nenhum espectador registrado."); return 0; }
    for (int i = 0; i < 4; ++i) printf("Canal %2d: %6.2f%% (%.0f pessoas)\n", channels[i], viewers[i] * 100 / total, viewers[i]);
    return 0;
}
