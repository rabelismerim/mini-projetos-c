#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MenuPrincipal();
int INSERIR();
int REMOVER();
void PRIMEIROELEMENTO();
void IMPRIMIR();
void ESVAZIAR();

#define MAX 10

typedef int telem;
typedef struct{
        telem v[MAX];
        int inicio;
        int final;
        int tam;
        } tfila;
 
void criar (tfila *F);
int vazia (tfila F);
int primelem (tfila F, telem *dado);
void imprimir (tfila F);
int inserir (tfila *F, telem dado);
int remover (tfila *F, telem *dado); 



tfila NUMEROS;
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
               case 1:INSERIR();
				break;
			case 2:REMOVER();
				break;
			case 3:PRIMEIROELEMENTO();
				break;
			case 4:IMPRIMIR();
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
	printf("EDITOR DE FILA\n");
	printf("\n1 - INSERIR\n");
	printf("\n2 - REMOVER\n");
	printf("\n3 - EXIBIR PRIMEIRO ELEMENTO\n");
	printf("\n4 - EXIBIR FILA\n");
	printf("\n5 - SAIR\n");
	scanf("%d",&opcao);
}    

int INSERIR()
{
     telem num;
	 system("cls");
	 printf("INSERIR DADOS\n");
	 printf("Digite um numero inteiro:");
	 scanf("%d",&num);
     getch();
}

//-------------------------

void criar (tfila *F)
{
F->inicio = 0;
F->final = -1;
F-> tam = 0;     
}        

int vazia(tfila F)
{
    return(F.tam == 0);
}

int primelem (tfila F, telem *dado)
{
    if (vazia(F)) return 0; /* Erro: Fila vazia */
    *dado = F.v[F.inicio];
    return (1);
}
int inserir (tfila *F, telem valor)
{
    if (F->tam ==MAX) return 0;
    (F->tam)++;
    F->final = (F->final +1) % MAX;
    F->v[F->final] = valor;
    return(1);
}
int remover (tfila *F, telem *valor)
{
    if(vazia(*F)) return 0; /* Erro fila vazia */
    primelem (*F,valor);
    (F->tam)--;
    F->inicio = (F->inicio +1) % MAX;
    return(1);
}

void IMPRIMIR(tfila *F)
{
 int i;
 if (F->inicio < F->final)
{
  for (i=F->inicio; i<=F->final; i++)
      {
       printf("%4d %16d\n",i,F -> v[i]);
       }
}
 else
 {
  for(i=F->inicio; i<MAX; i++)
  {
printf("%4d %16d\n", i,F -> v[i]);
  }
  for (i=0; i<=F->final; i++)
  {
printf("%4d %16d\n",i,F -> v[i]);
  }
  }
return;
  }
