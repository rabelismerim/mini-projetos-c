

#include <conio.h>
#include <stdio.h>
#define N S
main()
{
int i, m,e,d;
int x;
int encontrou;
int vet[N];
for (i=0; i<N; i++)
{
printf("Digite o numero a ser pesquisado:");
scanf("%d",&x);
e=0;
d=N-1;
encontrou=0;
while ((e<=d)&&((encontrou))
{
m=(e+d)/2;
if (vet[m]<x)
e=m+1;
else
d=m-1;
}
if (encontrou)
printf("Numero encontrado na posição= %d", m+1);
else
printf("Numero não encontrado");
getch();
}