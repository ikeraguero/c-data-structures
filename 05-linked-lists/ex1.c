/* Construa um programa com as seguintes opções:

1 – Incluir letra no início

2 – Remover letra do início

3 – Incluir letra no fim

4 – Excluir letra do fim

5 – Imprimir a letra do início

6 – Imprimir a letra do fim 

7 – Imprimir todas as letras da lista

8 – Excluir todos as letras da lista

9 - Incluir letra em uma determinada posicao

10 - Remover letra de uma determinada posicao

11 - Remover a primeira ocorrencia de uma letra a partir do inicio

12 - Remover a primeira ocorrencia de uma letra a partir do fim */

#include <stdio.h>
#define TAMANHO 20

typedef struct Estrutura {
    int dados[TAMANHO];
    int qtd;
} Lista;

void alocar(Lista *l) {
    l->qtd= 0;
}

void inserir_inicio(Lista *l) {
    char dado;
    scanf(" %c", &dado);
    if(l->qtd==TAMANHO) {
        return;
    }
    for (int i = l->qtd; i > 0; i--) {
    l->dados[i] = l->dados[i - 1];
}

    l->dados[0] = dado;
    l->qtd++;
}

char remover_inicio(Lista *l) {
    char dado = l->dados[0];
    for(int i=0; i < l->qtd-1; i++) {
        l->dados[i] = l->dados[i+1];
    }
    l->qtd--;
    return dado;
}

void incluir_fim(Lista *l) {
    char dado;
    scanf(" %c", &dado);
    l->dados[l->qtd] = dado;
    l->qtd++;
}

char remover_fim(Lista *l) {
    char dado = l->dados[l->qtd-1];
    l->qtd--;
    return dado;
}

void imprimir_inicio(Lista *l) {
    printf("%c ", l->dados[0]);
}

void imprimir_fim(Lista *l) {
    printf("%c", l->dados[l->qtd-1]);
}

void imprimir_lista(Lista *l) {
    if(l->qtd == 0 ) {
        printf("Lista vazia");
        return;
    }
    for(int i=0; i<l->qtd; i++) {
        printf("%c ", l->dados[i]);
    }
}

void excluir_lista(Lista *l) {
    l->qtd=0;
}

void incluir_posicao(Lista *l) {
    char dado;
    int indice;
    scanf("%d", &indice);
    scanf(" %c", &dado);
    for(int i=l->qtd; i>indice; i--) {
        l->dados[i] = l->dados[i-1];
    }
    l->dados[indice] = dado;
    l->qtd++;
}

char remover_posicao(Lista *l) {
     int indice;
     scanf("%d", &indice);
    char dado = l->dados[indice];
    for(int i=indice; i<l->qtd; i++) {
        l->dados[i] = l->dados[i+1];
    }
    l->qtd--;
    return dado;

}

char remover_primeira_ocorrencia_inicio(Lista *l) {
    int indice = 0;
    char dado;
    char letra;
    scanf(" %c", &letra);
    for(int i=0; i<l->qtd-1; i++) {
        if(l->dados[i] == letra) {
            indice = i; 
            dado = l->dados[i];
            break;
        }
    }
    for(int i=indice; i<l->qtd-1; i ++) {
        l->dados[i] = l->dados[i+1];
    }
    l->qtd--;
    return dado;
}

char remover_primeira_ocorrencia_fim(Lista *l) {
    int indice = 0;
    char dado;
    char letra;
    scanf(" %c", &letra);
    for(int i=l->qtd-1; i>0; i--) {
        if(l->dados[i] == letra) {
            indice = i; 
            dado = l->dados[i];
            break;
        }
    }
    for(int i=indice; i<l->qtd-1; i ++) {
        l->dados[i] = l->dados[i+1];
    }
    l->qtd--;
    return dado;

}

int main() {
    Lista lista;
    alocar(&lista);
    int num = 0;
    do {
        scanf("%d", &num);
        if (num < 1 || num > 12) {
        break;
        }
    switch(num) {
        case 1: 
            inserir_inicio(&lista);
            break;
        case 2:
            remover_inicio(&lista);
            break;
        case 3:
            incluir_fim(&lista);
            break;
        case 4:
            remover_fim(&lista);
            break;
        case 5:
            imprimir_inicio(&lista);
            break;
        case 6:
            imprimir_fim(&lista);
            break;
        case 7:
            imprimir_lista(&lista);
            break;
        case 8:
            excluir_lista(&lista);
            break;
        case 9:
            incluir_posicao(&lista);
            break;
        case 10:
            remover_posicao(&lista);
            break;
        case 11:
            remover_primeira_ocorrencia_inicio(&lista);
            break;
        case 12:
            remover_primeira_ocorrencia_fim(&lista);
            break;
    }
    } while (num !=0);
}