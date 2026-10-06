#3 – Solicite 3 notas de um aluno, tire a média e informe se ele foi aprovado (nota>=7); ficou de recuperação (nota>=5) ou nota<7); reprovado (nota<5).

#include <conio.h>
#include <stdio.h>
main()
{
float nota1, nota2, nota3, media;
printf("Informe a primeira nota");
scanf("%f", &nota1);
printf("Informe a segunda nota");
scanf("%f", &nota2);
printf("Informe a terceira nota");
scanf("%f", &nota3);
media = (nota1+nota2+nota3)/3;
if (media>=7) then
printf("Aprovado")
else if (media>=5) then
printf("Ficou de recuperação")
else if (media<=5) then
printf("Reprovado");
end if
return(0);
  }