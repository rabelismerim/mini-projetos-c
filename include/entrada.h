#ifndef ENTRADA_H
#define ENTRADA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>

/* Each answer occupies one line. EOF exits cleanly, including in menus. */
static inline void texto(const char *prompt, char *out, size_t size) {
    for (;;) {
        size_t len;
        int ch;
        printf("%s", prompt);
        fflush(stdout);
        if (!fgets(out, (int)size, stdin)) exit(EXIT_SUCCESS);
        len = strlen(out);
        if (len && out[len - 1] == '\n') out[--len] = '\0';
        else if (!feof(stdin)) {
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            puts("Texto muito longo. Tente novamente.");
            continue;
        }
        if (len && out[len - 1] == '\r') out[--len] = '\0';
        if (len) return;
        puts("Digite um valor.");
    }
}
static inline double real(const char *prompt, double min, double max) {
    char line[128], *end;
    double value;
    for (;;) {
        texto(prompt, line, sizeof line);
        errno = 0;
        value = strtod(line, &end);
        while (*end == ' ' || *end == '\t') ++end;
        if (end != line && !*end && !errno && isfinite(value) && value >= min && value <= max) return value;
        printf("Entrada invalida. Use um numero entre %.2f e %.2f (decimal com ponto).\n", min, max);
    }
}
static inline int inteiro(const char *prompt, int min, int max) {
    char line[128], *end;
    long value;
    for (;;) {
        texto(prompt, line, sizeof line);
        errno = 0;
        value = strtol(line, &end, 10);
        while (*end == ' ' || *end == '\t') ++end;
        if (end != line && !*end && !errno && value >= min && value <= max) return (int)value;
        printf("Entrada invalida. Use um inteiro entre %d e %d.\n", min, max);
    }
}
#endif
