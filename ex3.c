#include <stdio.h>

int main()
{
    int num, i = 1, x = 1;
    printf("Quantos ímpares você deseja imprimir? ");
    scanf("%d", &num);
    
    printf("Os primeiros %d ímpares são ", num);
    for(i; i<num-1; i++){
        printf("%d, ", x);
        x+=2;
    }
    
    printf("%d e %d.", x, x+2);

    return 0;
}
