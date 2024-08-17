#include <stdio.h>

int main() {
    int num;
    do {
    scanf("%i", &num);
    } while (!num || num < 1 || num > 5);

    switch (num)
    {
    case 1: {
        int num1;
        scanf("%i", &num1);
        if(num1%2==0) {
            printf("PAR \n");
        } else {
            printf("ÍMPAR\n");
        }
        break;
    };

    case 2: {
        int num1;
        scanf("%i", &num1);
            int primo = 1;
            if(num1 <= 1) {
                primo=0;
            } else {

            for(int i=2; i<=num1/2; i++) {
                if(num1%i ==0 ){
                    primo=0;
                    break;
                }
            }
            }
            if(primo) {
                printf("PRIMO \n");
            } else {
                printf("COMPOSTO \n");
            }
            break;
    };

    case 3: {
        int num1, num2, num3, num4;
        scanf("%i %i %i %i", &num1, &num2, &num3, &num4);
        float media = (num1+num2+num3+num4)/4;
        if(media <=1.7) {
            printf("Reprovado \n");
        }
        else if(media >1.7 && media < 7) {
            printf("Exame \n");
        } else {
            printf("Aprovado \n");
        }
        break;
    }
    case 4: {
        int num1, num2, num3;
        scanf("%i %i %i", &num1, &num2, &num3);
        if(num1 == num2 && num2 == num3) {
            printf("Equilátero");
        } else if(num1==num2 && num2 != num3 || num2 == num1 && num1 != num3 || num3==num1 && num1 != num2) {
            printf("Isósceles");
        } else if(num1 != num2 && num2 != num3) {
            printf("Escaleno");
        };
        break;
    }
    case 5: {
        int num1;
        int fatorial = 1;
        scanf("%i", &num1);

        for(int i=1; i<=num1; i++) {
            fatorial = fatorial * i;
        }
        printf("%i \n", fatorial);
        break;
    }
    
    default:
        break;
    }
}