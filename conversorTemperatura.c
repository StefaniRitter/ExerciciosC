#include <stdio.h>

int main()
{
    float celsius, fahren;
    printf("-------- Conversor de Temperatura --------\n");
    
    printf("Informe uma temperatura em Fahrenheit: ");
    scanf("%f", &fahren);
    
    celsius = (fahren-32)*5;
    celsius = celsius/9;
    printf("Essa temperatura equivale a %.2fC", celsius);

    return 0;
}
