/*O estudante deverá escrever o arquivo Matriz.c com todas as funções definidas no arquivo Matriz.h. Para que o sistema possa avaliar seu código, é crucial que a função para imprimir a matriz esteja implementada. A impressão deve separar os elementos de cada coluna com um espaçamento simples e os elementos de cada linha com uma quebra de linha.

As leituras e impressões de tela já são realizadas pelo programa Principal.c. Elabore as funções de modo que sejam devidamente interpretadas pelo programa principal.

Observações: O estudante deve focar em escrever o arquivo Matriz.c, preservando o arquivo Principal.c e o arquivo Matriz.h. Contudo, pequenas modificações poderão ser realizadas nos demais arquivos caso o estudante julgue necessário.*/

#include <stdio.h>
#include <stdlib.h>
#include "Matriz.h"

int main(){
    Matriz matA, matB, matC;
    int lin, col, opcao;
    int PosLin, PosCol;

    printf("\nEscolha uma opção:\n");
    printf("1. Construir Matriz zerada\n"); 
    printf("2. Construir Matriz\n");        
    printf("3. Somar Matrizes\n");          
    printf("4. Subtrair Matrizes\n");       
    printf("5. Comparar Matrizes\n");       
    printf("6. Multiplicar Matrizes\n");    
    printf("7. Calcular Determinante\n");  
    printf("8. Imprimir Posição\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            //CONSTRUINDO MATRIZ A ZERADA
            printf("Digite o número de linhas: ");
            scanf("%d", &lin);
            printf("Digite o número de colunas: ");
            scanf("%d", &col);
            ConstruirMatrizZerada(&matA, lin, col);

            //IMPRIMINDO A MATRIZ A
            ImprimirMatriz(&matA);
            break;
        case 2:
            //CONSTRUINDO MATRIZ A
            printf("Digite o número de linhas: ");
            scanf("%d", &lin);
            printf("Digite o número de colunas: ");
            scanf("%d", &col);
            ConstruirMatriz(&matA, lin, col);

            //IMPRIMINDO A MATRIZ A
            ImprimirMatriz(&matA);
            break;
        case 3:
            //CONSTRUINDO MATRIZ A
            printf("Digite o número de linhas: ");
            scanf("%d", &lin);
            printf("Digite o número de colunas: ");
            scanf("%d", &col);
            ConstruirMatriz(&matA, lin, col);

            //CONSTRUINDO MATRIZ B
            printf("Digite o número de linhas: ");
            scanf("%d", &lin);
            printf("Digite o número de colunas: ");
            scanf("%d", &col);
            ConstruirMatriz(&matB, lin, col);

            //SOMANDO NA MATRIZ C
            matC = SomarMatrizes(&matA, &matB);
            ImprimirMatriz(&matC);
            break;
        case 4:
            //CONSTRUINDO MATRIZ A
            printf("Digite o número de linhas: ");
            scanf("%d", &lin);
            printf("Digite o número de colunas: ");
            scanf("%d", &col);
            ConstruirMatriz(&matA, lin, col);

            //CONSTRUINDO MATRIZ B
            printf("Digite o número de linhas: ");
            scanf("%d", &lin);
            printf("Digite o número de colunas: ");
            scanf("%d", &col);
            ConstruirMatriz(&matB, lin, col);

            //SOMANDO NA MATRIZ C
            matC = SubtrairMatrizes(&matA, &matB);
            ImprimirMatriz(&matC);
            break;
        case 5:
            //CONSTRUINDO MATRIZ A
            printf("Digite o número de linhas: ");
            scanf("%d", &lin);
            printf("Digite o número de colunas: ");
            scanf("%d", &col);
            ConstruirMatriz(&matA, lin, col);

            //CONSTRUINDO MATRIZ B
            printf("Digite o número de linhas: ");
            scanf("%d", &lin);
            printf("Digite o número de colunas: ");
            scanf("%d", &col);
            ConstruirMatriz(&matB, lin, col);

            //COMPARANDO
            if (CompararMatrizes(&matA, &matB)){
                printf("IGUAIS\n");
            }else{
                printf("DIFERENTES\n");
            }
            break;
        case 6:
            //CONSTRUINDO MATRIZ A
            printf("Digite o número de linhas: ");
            scanf("%d", &lin);
            printf("Digite o número de colunas: ");
            scanf("%d", &col);
            ConstruirMatriz(&matA, lin, col);

            //CONSTRUINDO MATRIZ B
            printf("Digite o número de linhas: ");
            scanf("%d", &lin);
            printf("Digite o número de colunas: ");
            scanf("%d", &col);
            ConstruirMatriz(&matB, lin, col);

            //MULTIPLICANDO NA MATRIZ C
            matC = MultiplicarMatrizes(&matA, &matB);
            ImprimirMatriz(&matC);
            break;
        case 7:
            //CONSTRUINDO MATRIZ A
            printf("Digite o número de linhas: ");
            scanf("%d", &lin);
            printf("Digite o número de colunas: ");
            scanf("%d", &col);
            ConstruirMatriz(&matA, lin, col);

            //CALCULANDO DETERMINANTE
            printf("%d\n", CalcularDeterminante(&matA));
            break;
        case 8:
            //CONSTRUINDO MATRIZ A
            printf("Digite o número de linhas: ");
            scanf("%d", &lin);
            printf("Digite o número de colunas: ");
            scanf("%d", &col);
            ConstruirMatriz(&matA, lin, col);

            //IMPRIMINDO POSICAO
            printf("Digite a linha: ");
            scanf("%d", &PosLin);
            printf("Digite a colunas: ");
            scanf("%d", &PosCol);
            printf("%d\n", ImprimirPosicao(&matA, PosLin, PosCol));
            break;
    }

    return 0;
}