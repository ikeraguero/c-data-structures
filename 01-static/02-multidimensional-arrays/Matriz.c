typedef struct Estrutura{
    int linhas;
    int colunas;
    int **matriz;
}Matriz;

void ConstruirMatrizZerada(Matriz *matA, int lin,  int col) {
    matA->linhas = lin;
    matA->colunas = col;
    for (int i =0; i<lin; i++) {
        for (int j =0; j<col; j++) {
            matA->matriz[i][j] = 0;
        }
    }
}

void ConstruirMatriz(Matriz *mat, int lin, int col) {
    
}