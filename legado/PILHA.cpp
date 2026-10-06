#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MenuPrincipal();
void EMPILHAR();
void DESEMPILHAR();
void EXIBIRELEMENTODOTOPO();
void EXIBIRPILHA();
void ESVAZIAR();



#define MAX 10

typedef int telem;

typedef struct {
	telem v[MAX];
	int topo;
	} tpilha;



void criar (tpilha *P);
int vazia (tpilha P);
int cheia (tpilha P);
int tamanho (tpilha P);
int elemtopo (tpilha P, telem *dado);
int push (tpilha *P, telem dado);
int pop (tpilha *P, telem *dado);
void imprimir (tpilha P);



tpilha NUMEROS;
int opcao;

main()
{
	int fim=0;
    criar (&NUMEROS);
	do
	{
		MenuPrincipal();
		switch (opcao)
		{
			case 1:EMPILHAR();
				break;
			case 2:DESEMPILHAR();
				break;
			case 3:EXIBIRELEMENTODOTOPO();
				break;
			case 4:EXIBIRPILHA();
				break;
			case 5:ESVAZIAR();
				break;
			case 6:fim=1;
				break;
			default: printf("Opcao invalida\n");
				getch();
		}
	}
    while (!(fim));
	printf("Programa encerrado");
	getch();
}
void MenuPrincipal()
{
	system ("cls");
	printf("EDITOR DE PILHA\n");
	printf("\n1 - EMPILHAR\n");
	printf("\n2 - DESEMPILHAR\n");
	printf("\n3 - EXIBIR ELEMENTO DO TOPO\n");
	printf("\n4 - EXIBIR PILHA\n");
	printf("\n5 - ESVAZIAR\n");
	printf("\n6 - SAIR\n");
	scanf("%d",&opcao);
}
void EMPILHAR()
{
    
	telem num;
	system("cls");
	printf("EMPILHAR DADOS\n");
	printf("Digite um numero inteiro:");
	scanf("%d",&num);
	if (!(push (&NUMEROS,num)))
	
         {
                printf("NUMERO MAXIMO DE ELEMENTOS INSERIDOS");
                getch();
		        return;
		        
          }
          printf("O NUMERO %d FOI EMPILHADO NA POSICAO %d",NUMEROS.v[NUMEROS.topo],NUMEROS.topo);
          getch();
                   
}
void DESEMPILHAR() 
{
     telem num;
     printf(" DESEMPILHAR DADOS \n");
     if (!(pop(&NUMEROS,&num)))
     {
     printf("PILHA VAZIA");
     getch();
     return;
     }
     else
     {
         printf("O NUMERO %d FOI DESEMPILHADO DA PILHA",num);
         }
     getch();
}
void EXIBIRELEMENTODOTOPO()
{
 telem num;
 printf(" TOPO DA PILHA ");
 if(!(elemtopo (NUMEROS,&num)))
 {
               printf("NENHUM NUMERO INSERIDO");
               getch();
               return;
               }
               printf("O NUMERO %d ESTA NO TOPO DA PILHA",num);
               getch();
 }
 void EXIBIRPILHA()
{
  printf("   EXIBINDO PILHA\n   ");
  printf("NUMEROS                 \n");
  if (vazia(NUMEROS))
  {
                     printf("NENHUM NUMERO INSERIDO");
                     getch();
                     return;
  }
  imprimir(NUMEROS);
  getch();
  	
}
void ESVAZIAR()
{     
  telem num;
  if (vazia(NUMEROS))
  {
                     printf("NENHUM NUMERO INSERIDO");
                     getch();
                     return;
  }
while (!(tamanho(NUMEROS)==0))
{
      pop (&NUMEROS, &num);
}
printf("PILHA ESVAZIADA");
getch();
}
//================== FUNCÕES BÁSICAS =======================
int tamanho (tpilha P)
{
    return (P.topo);
    

}
void imprimir (tpilha P)
{
int y;
if (P.topo==-1)
printf("\nPILHA VAZIA\n");
else
for (y=0; y<=P.topo; y++)
printf("%d \n" , P.v[y]);
}
void criar (tpilha *p)
{
     p->topo= -1;
}

int  vazia (tpilha P)
{
      return (P.topo == -1);
}

int elemtopo (tpilha P, telem *dado)
{
     if (vazia(P)) return 0;
     *dado =P.v[P.topo];
     return 1;
}

int push (tpilha *p, telem dado)
  { 
           if (p->topo == MAX-1) 
           return 0;
           p->v[++p->topo] = dado;
           return 1;
  }    

int pop (tpilha *p, telem *dado)
{
if (vazia(*p)) return 0;
*dado = p->v[p->topo--];
return 1;
}
