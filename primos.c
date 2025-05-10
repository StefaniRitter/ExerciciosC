#include <stdio.h>

int main()
{
    int num, primo = 1;
    float resto;
    printf("--------- Primo Ou Não? ---------\n");

    printf("Informe um número para verificar se é primo: ");
    scanf("%d", &num);
    int i = num-1;
    
    for (i=num-1; i>1; i--){
        resto = num%i;
        if (resto == 0) {
            primo = 0;
        }
    }
        
    if (primo == 1 && num != 1) {
        printf("O número %d é primo!", num);
    } else {
       printf("O número %d não é primo!", num); 
    }
        
        
    

    return 0;
}