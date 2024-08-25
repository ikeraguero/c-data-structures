#include <stdio.h>
#include <stdlib.h>

typedef struct Estrutura{
    int linhas;
    int colunas;
    int **matriz;
}Matriz;

void ConstruirMatrizZerada(Matriz *matA, int lin, int col) {
    matA->linhas = lin;
    matA->colunas = col;

    matA->matriz = (int**)malloc(lin * sizeof(int*));
    for (int i = 0; i < lin; i++) {
        matA->matriz[i] = (int*)malloc(col * sizeof(int));
    }

    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            matA->matriz[i][j] = 0;
        }
    }
}

void ConstruirMatriz(Matriz *mat, int lin, int col) {
    mat->linhas = lin;
    mat->colunas = col;
    
    mat->matriz = (int **)malloc(lin*sizeof(int*));
    for (int i=0; i<lin; i++) {
        mat->matriz[i] = (int *)malloc(col *sizeof(int));
    }

    for(int i=0; i<lin; i++) {
        for(int j=0; j<col; j++) {
            int valor = 0;
            //printf("[linha %d][coluna %d]: ", i+1, j+1);
            scanf("%d", &valor);
            mat->matriz[i][j] = valor;
        }
    }
}

void ImprimirMatriz(Matriz *mat) {
    for (int i=0; i<(mat->linhas); i++) {
        for (int j=0; j<(mat->colunas); j++) {
            printf("%d", mat->matriz[i][j]);
            if (j < (mat->colunas) - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

Matriz SomarMatrizes(Matriz *matA, Matriz *matB) {
    if(matA->linhas == matB->linhas && matA->colunas == matB->colunas) {
        
        Matriz soma;
        soma.linhas = matA->linhas;
        soma.colunas = matA->colunas;
        soma.matriz = (int **)malloc(soma.linhas * sizeof(int));
        for (int i; i<soma.linhas; i++) {
            soma.matriz[i] = (int *)malloc(soma.colunas * sizeof(int)) ;
        };
        for(int i = 0; i<soma.linhas; i++) {
            for(int j = 0; j<soma.colunas; j++) {
                
                soma.matriz[i][j] = matA->matriz[i][j] + matB->matriz[i][j];
            };
        }
        return soma;
    }

}

Matriz SubtrairMatrizes(Matriz *matA, Matriz *matB) {
    if(matA->linhas == matB->linhas && matA->colunas == matB->colunas) {
        Matriz sub;
        sub.linhas = matA->linhas;
        sub.colunas = matA->colunas;
        sub.matriz = (int**)malloc(sub.linhas * sizeof(int));
        for(int i=0; i<sub.linhas; i++) {
            sub.matriz[i] = (int *)malloc(sub.colunas*sizeof(int));
        };
        
        for(int i=0; i<sub.linhas; i++) {
            for(int j=0; j<sub.colunas; j++) {
                sub.matriz[i][j] = matA->matriz[i][j] - matB->matriz[i][j];
            };
        };
        
        return sub;
    }
}

int CompararMatrizes(Matriz *matA, Matriz *matB) {
    int igual = 1;
    if(matA->linhas != matB->linhas || matA->colunas != matB->colunas) {
        
        igual = 0;
        return igual;
    }
    for (int i=0; i<matA->linhas;i++) {
        for (int j=0; j<matA->colunas;j++) {
            if(matA->matriz[i][j] != matB->matriz[i][j]) {
                igual = 0;
                return igual;
            };
        };
    }
    return igual;
}

Matriz MultiplicarMatrizes(Matriz *matA, Matriz *matB) {
    Matriz resultado;
    if(matA->colunas == matB->linhas) {
        resultado.linhas = matA->linhas;
        resultado.colunas = matB->colunas;
        resultado.matriz = (int **)malloc(resultado.linhas*sizeof(int));
        for(int i=0; i<resultado.colunas; i++) {
            resultado.matriz[i] = (int *)malloc(resultado.colunas*sizeof(int));
        }
        
        for(int i=0; i<resultado.linhas; i++) {
            for(int j=0; j<resultado.colunas; j++) {
                resultado.matriz[i][j] = 0;
                for (int k = 0; k < matA->colunas; k++) {
                    resultado.matriz[i][j] += matA->matriz[i][k] * matB->matriz[k][j];
                }
            }
        }
        
    } else {
        resultado.linhas = 0;
        resultado.colunas = 0;
        resultado.matriz = NULL;
    }
    return resultado;
}

int CalcularDeterminante(Matriz *mat) {
    if(mat->linhas == mat->colunas) {
        int determinante = 0;
        if (mat->linhas == 1) {
            return mat->matriz[0][0];
        }

        if (mat->linhas == 2) {
            return mat->matriz[0][0] * mat->matriz[1][1] - mat->matriz[0][1] * mat->matriz[1][0];
        }
        
        for (int j = 0; j < mat->linhas; j++) {
            Matriz submatriz;
            submatriz.linhas = mat->linhas - 1;
            submatriz.colunas = mat->linhas - 1;
            submatriz.matriz = (int **)malloc(submatriz.linhas * sizeof(int *));
            for (int i = 0; i < submatriz.linhas; i++) {
                submatriz.matriz[i] = (int *)malloc(submatriz.colunas * sizeof(int));
            }

 
            for (int i = 1; i < mat->linhas; i++) {
                int col = 0;
                for (int k = 0; k < mat->linhas; k++) {
                    if (k == j) continue;
                    submatriz.matriz[i - 1][col] = mat->matriz[i][k];
                    col++;
                }
            }


            int subDeterminante = CalcularDeterminante(&submatriz);


            determinante += (j % 2 == 0 ? 1 : -1) * mat->matriz[0][j] * subDeterminante;

            for (int i = 0; i < submatriz.linhas; i++) {
                free(submatriz.matriz[i]);
            }
            free(submatriz.matriz);
        }

        return determinante;
    } else {
        printf("Error: Matrix is not square.\n");
        return 0; 
    }
}

int ImprimirPosicao(Matriz *mat, int lin, int col) {
    int posicao = mat->matriz[lin-1][col-1];
    return posicao;
}
