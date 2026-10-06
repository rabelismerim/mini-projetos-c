#include <stdio.h>
int main(void) {
    puts("CONTAGEM DE 1500 A 1");
    for (int n = 1500; n >= 1; --n) printf("%d%c", n, (1501 - n) % 10 ? ' ' : '\n');
    return 0;
}
