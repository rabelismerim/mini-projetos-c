

#include <conio.h>
#include <stdio.h>

main()
{

    int num, snum=0, qt=0;
    int media;
    
    printf("digite um número:");
    scanf("%d",&num);

    while(num!=9999)
    {
    snum+=num;
    qt++;
    printf("%d\n", num);
    printf("digite um numero:");
    scanf("%d", &num);
    }
    media=snum/qt;
    printf("media=%d", media);
getch();
}