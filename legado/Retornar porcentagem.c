#2 - Solicite a quantidade de homens e a quantidade de mulheres de uma turma e informe a porcentagem (separadamente) de cada gênero.

#include <conio.h>
#include <stdio.h>
main()
{
    float porcentagem_homens, porcentagem_mulheres;
	int qt_homens, qt_mulheres, qt_total;
	printf("Informe a quantidade de homens");
	scanf(&qt_homens);
	printf("Informe a quantidade de mulheres");
	scanf(&qt_mulheres);
	qt_total = qt_homens + qt_mulheres;
	porcentagem_mulheres = (qt_mulheres*100)/qt_total;
	porcentagem_homens = (qt_homens*100)/qt_total;
	printf("A porcentagem de mulheres é:" %10.2f\n\n", porcentagem_mulheres);
	printf("A porcentagem de homens é:" %10.2f\n\n", porcentagem_homens);
    return(0);
  }