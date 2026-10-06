#include "entrada.h"
#define MAX 50
typedef struct { int code, quantity; char name[64]; } Product;
static int compare(const void *a, const void *b) {
    return strcmp(((const Product *)a)->name, ((const Product *)b)->name);
}
static int save(const Product *products, int count) {
    FILE *file = fopen("vendas.csv", "w");
    int ok = 1;
    if (!file) { perror("vendas.csv"); return 0; }
    if (fprintf(file, "codigo;nome;quantidade\n") < 0) ok = 0;
    for (int i = 0; i < count; ++i)
        if (fprintf(file, "%d;%s;%d\n", products[i].code, products[i].name, products[i].quantity) < 0) ok = 0;
    if (fclose(file)) ok = 0;
    if (!ok) fputs("Falha ao salvar vendas.csv.\n", stderr);
    return ok;
}
static int load(Product *products) {
    FILE *file = fopen("vendas.csv", "r");
    char line[256];
    int count = 0;
    if (!file) {
        if (errno == ENOENT) return 0;
        perror("vendas.csv"); return -1;
    }
    if (!fgets(line, sizeof line, file) || strcmp(line, "codigo;nome;quantidade\n")) {
        fclose(file); fputs("Cabecalho invalido em vendas.csv.\n", stderr); return -1;
    }
    while (fgets(line, sizeof line, file)) {
        Product item;
        char code[32], quantity[32], tail;
        char *end;
        long parsed;
        if (count == MAX || sscanf(line, "%31[^;];%63[^;];%31[^\r\n]%c", code, item.name, quantity, &tail) != 4 || tail != '\n') goto invalid;
        errno = 0; parsed = strtol(code, &end, 10);
        if (errno || *end || parsed < 1 || parsed > 1000000) goto invalid;
        item.code = (int)parsed;
        errno = 0; parsed = strtol(quantity, &end, 10);
        if (errno || *end || parsed < 0 || parsed > 1000000) goto invalid;
        item.quantity = (int)parsed;
        for (int i = 0; i < count; ++i) if (products[i].code == item.code) goto invalid;
        products[count++] = item;
    }
    if (ferror(file)) goto invalid;
    if (fclose(file)) return -1;
    return count;
invalid:
    fclose(file);
    fputs("Arquivo vendas.csv invalido. Corrija-o antes de continuar.\n", stderr);
    return -1;
}
int main(void) {
    Product products[MAX];
    int count = load(products), option;
    if (count < 0) return 1;
    puts("CADASTRO DE VENDAS | persistencia em vendas.csv");
    do {
        puts("\n1 Cadastrar | 2 Listar | 3 Ordenar por nome | 5 Sair");
        option = inteiro("Opcao: ", 1, 5);
        switch (option) {
        case 1: {
            Product item;
            int duplicate = 0;
            if (count == MAX) { puts("Limite de 50 produtos atingido."); break; }
            item.code = inteiro("Codigo: ", 1, 1000000);
            for (int i = 0; i < count; ++i) if (products[i].code == item.code) duplicate = 1;
            if (duplicate) { puts("Codigo ja cadastrado."); break; }
            do {
                texto("Nome (sem ponto e virgula): ", item.name, sizeof item.name);
                if (strchr(item.name, ';')) puts("O nome nao pode conter ponto e virgula.");
            } while (strchr(item.name, ';'));
            item.quantity = inteiro("Quantidade: ", 0, 1000000);
            products[count++] = item;
            if (!save(products, count)) return 1;
            puts("Produto salvo."); break;
        }
        case 2: {
            int total = 0;
            puts("CODIGO | PRODUTO | QUANTIDADE");
            for (int i = 0; i < count; ++i) {
                printf("%d | %s | %d\n", products[i].code, products[i].name, products[i].quantity);
                total += products[i].quantity;
            }
            printf("Produtos: %d | Unidades: %d\n", count, total); break;
        }
        case 3:
            qsort(products, (size_t)count, sizeof *products, compare);
            if (!save(products, count)) return 1;
            puts("Produtos ordenados por nome."); break;
        case 4: puts("Opcao invalida."); break;
        }
    } while (option != 5);
    return 0;
}
