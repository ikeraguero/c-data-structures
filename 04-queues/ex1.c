/* Construa um programa com as seguintes opções:

1 – Incluir nova letra na fila

2 – Excluir uma letra da fila

3 – Imprimir a letra do início da fila

4 – Imprimir a letra do fim da fila

5 – Imprimir todas as letras da fila

6 – Excluir todos as letras da fila*/

#include <stdio.h>
#define TAMANHO 20

typedef struct Estrutura {
    int dados[TAMANHO];
    int inicio;
    int final;
} Fila;

void alocar(Fila *f) {
    f->inicio=0;
    f->final=-1;
}

void incluir(Fila *f) {
    if(f->final == TAMANHO-1) {
        printf("Fila cheia");
        return;
    }
    char letra;
    scanf(" %c", &letra);
    f->final = f->final+1;
    f->dados[f->final] = letra;
}

void imprimir_inicio(Fila *f) {
    if(f->final == -1) {
        printf("Fila vazia\n");
        return;
    }
    printf("%c\n", f->dados[f->inicio]);
}

void imprimir_fim(Fila *f) {
    if(f->final == -1) {
        printf("Fila vazia\n");
        return;
    }
    printf("%c\n", f->dados[f->final]);
}

void imprimir_tudo(Fila *f) {
    if(f->final == -1) {
        printf("Fila vazia\n");
        return;
    }
    for(int i=f->inicio; i<=f->final; i++) {
        printf("%c ", f->dados[i]);
    }
}

void excluir_tudo(Fila *f) {
    if(f->final == -1) {
        printf("Fila vazia");
        return;
    }
    f->inicio=0;
    f->final=-1;
    
} 

int excluir(Fila *f) {
    if(f->final == -1) {
        printf("Fila vazia\n");
        return 0;
    }
    int dado = f->dados[f->inicio];
    for(int i=f->inicio; i<f->final; i++) {
        f->dados[i] = f->dados[i+1];
    }
    f->final=f->final-1;
    return dado;
}

int main() {
    Fila fila;
    alocar(&fila);
    int num = 0;
    do {
        scanf("%d", &num);
        if (num < 1 || num > 6) {
        break;
        }
    switch(num) {
        case 1: 
            incluir(&fila);
            break;
        case 2:
            excluir(&fila);
            break;
        case 3:
            imprimir_inicio(&fila);
            break;
        case 4:
            imprimir_fim(&fila);
            break;
        case 5:
            imprimir_tudo(&fila);
            break;
        case 6:
            excluir_tudo(&fila);
            break;
    }
    } while (num !=0);
}