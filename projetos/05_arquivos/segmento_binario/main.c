#include <stdio.h>
int main(void) {
    int numbers[30], segment[10];
    FILE *file;
    for (int i = 0; i < 30; ++i) numbers[i] = i;
    file = fopen("numeros.dat", "wb");
    if (!file) { perror("numeros.dat"); return 1; }
    size_t written = fwrite(numbers, sizeof *numbers, 30, file);
    int closed = fclose(file);
    if (written != 30 || closed) { fputs("Falha na gravacao.\n", stderr); return 1; }
    file = fopen("numeros.dat", "rb");
    if (!file) { perror("numeros.dat"); return 1; }
    if (fseek(file, 10L * (long)sizeof(int), SEEK_SET) || fread(segment, sizeof *segment, 10, file) != 10) {
        fputs("Falha na leitura.\n", stderr); fclose(file); return 1;
    }
    if (fclose(file)) return 1;
    puts("ARQUIVO BINARIO | segmento dos indices 10 a 19");
    for (int i = 0; i < 10; ++i) printf("%d%c", segment[i], i == 9 ? '\n' : ' ');
    return 0;
}
