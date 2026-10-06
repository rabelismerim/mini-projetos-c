#include <stdio.h>
int main(void) {
    puts("CONTAGEM DE 1 A 500");
    for (int n = 1; n <= 500; ++n) printf("%d%c", n, n % 10 ? ' ' : '\n');
    return 0;
}
