/* Construa um programa com as seguintes opções:

1 – Incluir nova letra na fila

2 – Excluir uma letra da fila

3 – Imprimir a letra do início da fila

4 – Imprimir a letra do fim da fila

5 – Imprimir todas as letras da fila

6 – Excluir todos as letras da fila

Observação: O exercício deverá ser entregue com todas as funcionalidades exigidas. O VPL só poderá avaliar o código, uma vez que a operação "5-imprimir tudo" esteja funcionando corretamente. Os dados devem ser impressoes de maneira ENFILEIRADA.

A estrutura ser dinâmica e ao tentar remover elementos da fila vazia, deve ser informada a seguinte mensagem "Fila vazia".

O código deve ter um loop com as opções do menu, ao ser digitada uma opção inválida, o código deve encerrar. Lembresse de comentar os printfs caso o código não esteja avaliando. */

#include <stdio.h>
#include <stdlib.h>

typedef struct Registro No;

struct Registro {
    int dados;
    No *proximo;
};

typedef struct Estrutura Fila;

struct Estrutura {
    No *inicio;
    No *final;
};

Fila* aloca() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    if( f!= NULL) {
        f->inicio = NULL;
        f->final = NULL;
    }
    return f;
}

void incluir(Fila *f, char letra) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dados = letra;
    novo->proximo = NULL;
    if(f->inicio == NULL) {
        f->inicio = novo;
        f->final = novo;
    } else {
        f->final->proximo = novo;
        f->final = novo;
    }
}

char remover(Fila *f) {
    if(f->inicio == NULL) {
        printf("Fila Vazia\n");
        return '\0';
    }
    No *auxiliar = f->inicio;
    char valor = auxiliar->dados;
    f->inicio = f->inicio->proximo;
    auxiliar = NULL;
    free(auxiliar);
    return valor;
}

void imprimir_inicio(Fila *f) {
    if(f->inicio == NULL) {
        printf("Fila Vazia\n");
        return;
    }
    printf("%c ", f->inicio->dados);
}

void imprimir_ultimo(Fila *f) {
    if(f->inicio == NULL) {
        printf("Fila Vazia\n");
        return;
    }
    printf("%c ", f->final->dados);
}

void imprimir_fila(Fila *f) {
    if(f->inicio == NULL) {
        printf("Fila Vazia\n");
        return;
    }
    No *auxiliar = f->inicio;
    while(auxiliar != NULL) {
        printf("%c ", auxiliar->dados);
        auxiliar = auxiliar->proximo;
    }
    printf("\n");
}

void excluir_todos(Fila *f) {
    if(f->inicio == NULL) {
        printf("Fila Vazia\n");
        return;
    }
    while(f->inicio != NULL) {
        remover(f);
    }
}

int main() {
    Fila *fila = aloca();
    int num = 0;
    char add_char; 
    do {
        scanf("%d", &num);
        if (num < 1 || num > 6) {
        break;
        }
    switch(num) {
        case 1:
            scanf(" %c", &add_char);
            incluir(fila, add_char);
            break;
        case 2:
            remover(fila);
            break;
        case 3:
            imprimir_inicio(fila);
            break;
        case 4:
            imprimir_ultimo(fila);
            break;
        case 5:
            imprimir_fila(fila);
            break;
        case 6:
            excluir_todos(fila);
            break;
    }
    } while (num !=0);
    free(fila);
}