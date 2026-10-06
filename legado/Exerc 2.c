

#include <conio.h>
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#define ql 8
#define qp 4
main()
{
char lojas[8][10], produtos[4][10];
float preco[4][8];
int i,j;
printf("Cadastro de Lojas \n\n");
for (j=1;j<=ql;j++)
{
printf("Informe a loja: \n");
scanf("%s",lojas[j]);
}
printf("Cadastro de Produtos \n \n");
for (i=1;i<=qp;i++)
{
printf("Informe o produto: ");
scanf("%s",produtos[i]);
}
printf("Cadastro de Precos \n");    
for (i=1;i<=qp;i++)
{
for (j=1;j<=ql;j++)
  {
  printf("Digite o preco do produto %s da loja %s:",produtos[i],lojas[j]);
  scanf("%f",&preco[i][j]);
  }
}


for (i=1;i<=qp;i++)
{
for (j=1;j<=ql;j++)
  if (preco[i][j]<120)
  {
  printf("%s %s \n",produtos[i],lojas[j]);
  printf("%1.2f \n",preco[i][j]);
  }
}
getch();
}