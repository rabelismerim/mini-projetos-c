#include<stdio.h>
#include<conio.h>
int main()

{

{
	int numero_de_canal,numero_de_pessoas,espectadores;
	float p4,p5,p7,p12;
	int n4, n5, n7, n12;
	
	n4=0;
	n5=0;
	n7=0;
	n12=0;
	numero_de_pessoas=0;
	numero_de_canal=1;
	
	do{
		printf("Informe o canal que estava sendo assistido:", &numero_de_canal);
		scanf("%d", &numero_de_canal);
		printf("Quantas pessoas estavam assistindo?",&numero_de_pessoas);
		scanf("%d",&numero_de_pessoas);
		
		if (numero_de_canal==4)
		{
		n4=n4+espectadores;	
		}
		
		else if (numero_de_canal==5)
		{
			n5=n5+espectadores;
		}
			else if (numero_de_canal=7)
		{
			n7=n7+espectadores;
		}
			else if (numero_de_canal==12)
		{
			n12=n12+espectadores;
		}
	}
	while(numero_de_canal=0);
	{
		numero_de_pessoas=numero_de_pessoas+espectadores;
		p4=100*(n4/numero_de_pessoas);
		p5=100*(n5/numero_de_pessoas);
		p7=100*(n7/numero_de_pessoas);
		p12=100*(n12/numero_de_pessoas);
	}
	
	printf(" Canal 4: ",&p4);
	printf(" Canal 5: ",&p5);
	printf(" Canal 7: ",&p7);
	printf(" Canal 12: ",&p12);
	}
	getch();
	
}
