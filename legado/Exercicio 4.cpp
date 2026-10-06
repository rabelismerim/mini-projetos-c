#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *arg;
    int num[30];
    int vet[10];
    for (int i=0;i<30;i++)
    {
        num[i]=i;
        arq=fopen("numeros.dat","wb");
        fwrite(num, sizeof(int),30,arq);
        fclose(arq);
        arq=fopen("numeros.dat","rb");
        fseek(arq,10*sizeof(int),SEEK_SET);
        fread(vet,sizeof(int),10,arq);
        printf("\nSegmento do Vetor\n");
        for(int i=o; i<10; i++)
        printf("%d\t",vet[i]);
        getch();
}
    
