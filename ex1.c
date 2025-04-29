#include <stdio.h>

int main()
{
    int num, fat = 1;
    printf("Informe um número para saber seu fatorial: ");
    scanf("%d", &num);
    char numero = num;
    
    while (num > 0){
       fat = fat*num;
       num = num - 1;
    }
    
    printf("O fatorial de %d é igual a %d!", numero, fat);

    return 0;
}