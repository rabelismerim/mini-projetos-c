#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

void MenuPrincipal();
void Entrada();
void Saida();
void Ordenacao();

#define NMax 50

typedef struct _FichaVendas
{
        int quantidade, quantidade_total, codigo;
        char NomeProduto[20];
        }FichaVendas;

FichaVendas Vendas[NMax];      
int opcao,op_ord,n,i;

main()
{
FILE *arg;
      
      int fim=0;
      do
      {
         MenuPrincipal();      
         switch (opcao)
         {
             case 1:Entrada();
                    break;
             case 2:Saida();
                    break;
             case 3:Ordenacao();
                    break;
             case 5:fim=1;
                    break;
             default: printf("Opcao invalida\n");
                      getch();
         }
      }while (!(fim));
      printf("Fim do programa");
      getch();
}

void MenuPrincipal()
{
     system("cls");
     printf("         M E N U   P R I N C I P A L\n");
     printf("\n1 - Entrada de Dados\n");
     printf("\n2 - Saida de Dados\n");
     printf("\n3 - Ordenacao\n");     
     printf("\n5 - Sair\n");
     printf("\nEscolha uma das opcoes:");
     scanf("%d",&opcao);
}
void Entrada()
{
     int i;
     char x;
     system("cls");
     printf("           E N T R A D A  D E  D A D OS\n");     
     printf("Digite a quantidade de produtos (maximo 50):");
     scanf("%d",n);
     for (i=1;i<n;i++)
      {
          x=getchar();
          printf("Digite o nome do Produto:");
          gets(Vendas[i].NomeProduto);
          printf("Digite a quantidade do produto:");
          scanf("%d",&Vendas[i].quantidade);
          arq=fopen("Vendas.dat","wb");
        
          fwrite(&Vendas, sizeof(Vendas),N,arq);
          fclose(arq);
          printf("Dados Gravados com sucesso");
      }    
}

void Saida()
{
     int i,N;
     system("cls");
     printf("         S A I D A  D E  D A D O S  -  L I S T A G E M\n");
     printf("\nNome Produto          Codigo                  Quantidade\n");
     
     
     for(i=1;i<N;i++)
        {
                      printf("Nome:");
                      scanf("%s",&Vendas[i].NomeProduto);
                      printf("Quantidade:");
                      scanf("%d",&Vendas[i].quantidade);
        }              
                      
                      printf("Quantidade Total:");
                      scanf("%d",&Vendas[i].quantidade_total);

                 
         getch();
}

    

