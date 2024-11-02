#include <stdio.h>
#include <stdlib.h>

typedef struct Registro No;
typedef struct Estrutura Lista;

struct Registro {
    char dados;
    No *proximo;
};

struct Estrutura {
    No *inicio;
    No *final;
    int quantidade;
};

Lista* aloca() {
    Lista *l = (Lista *) malloc(sizeof(Lista));
    if(l != NULL) {
        l->inicio = NULL;
        l->final = NULL;
        l->quantidade = 0;
    }
    return l;
}

void inserir_inicio(Lista *l, char dado) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dados = dado;
    novo->proximo = l->inicio;
    
    if(l->inicio == NULL) {
        l->final = novo;
    }
    
    l->inicio = novo;
    l->quantidade++;
}

char remover_inicio(Lista *l) {
    if (l->inicio == NULL) {
        printf("Lista vazia\n");
        return '\0';
    }

    No *auxiliar = l->inicio;
    char valor = auxiliar->dados;
    l->inicio = l->inicio->proximo;

    if (l->inicio == NULL) {
        l->final = NULL;  
    }

    free(auxiliar);
    l->quantidade--;
    return valor;
} 

void inserir_fim(Lista *l, char dado) {
    No *novo = (No *) malloc(sizeof(No));
    novo->dados = dado;
    novo->proximo = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
        l->final = novo;
    } else {
        l->final->proximo = novo;
        l->final = novo;
    }
    l->quantidade++;
}

char excluir_fim(Lista *l) {
    if (l->inicio == NULL) {
        printf("Lista vazia\n");
        return '\0';
    }

    No *auxiliar = l->inicio;
    No *anterior = NULL;
    while (auxiliar->proximo != NULL) {
        anterior = auxiliar;
        auxiliar = auxiliar->proximo;
    }

    char valor = auxiliar->dados;

    if (anterior == NULL) {  
        l->inicio = NULL;
        l->final = NULL;
    } else {
        anterior->proximo = NULL;
        l->final = anterior;
    }

    free(auxiliar);
    l->quantidade--;
    return valor;
}

void imprimir_inicio(Lista *l) {
    if (l->inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }
    printf("%c\n", l->inicio->dados);
}

void imprimir_fim(Lista *l) {
    if (l->final == NULL) {
        printf("Lista vazia\n");
        return;
    }
    printf("%c\n", l->final->dados);
}

void imprimir_list(Lista *l) {
    if (l->inicio == NULL) {
        printf("Lista vazia\n");
        return;
    }

    No *imprimir = l->inicio;
    while (imprimir != NULL) {
        printf("%c ", imprimir->dados);
        imprimir = imprimir->proximo;
    }
    printf("\n");
}

void excluir_letras_lista(Lista *l) {
    No *auxiliar = l->inicio;
    while (auxiliar != NULL) {
        No *excluir = auxiliar;
        auxiliar = auxiliar->proximo;
        free(excluir);
    }
    l->inicio = NULL;
    l->final = NULL;
    l->quantidade = 0;
}

void incluir_letra_posicao(Lista *l, char dado, int position) {
    
    if (position < 0 || position > l->quantidade + 1) {
        printf("Posição inválida\n");
        return;
    }

    if (position == 0) {
        inserir_inicio(l, dado);
        return;
    }

    if (position == l->quantidade + 1) {
        inserir_fim(l, dado);
        return;
    }

    No *novo = (No*) malloc(sizeof(No));
    novo->dados = dado;

    No *atual = l->inicio;
    for (int i = 1; i < position - 1; i++) {
        atual = atual->proximo;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;
    l->quantidade++;
}

char remover_letra_posicao(Lista *l, int position) {
    if (position < 0 || position > l->quantidade) {
        printf("Posição inválida\n");
        return '\0';
    }

    if (position == 0) {
        return remover_inicio(l);
    }

    No *atual = l->inicio;
    No *anterior = NULL;

    for (int i = 0; i < position; i++) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Erro: nó na posição %d é NULL\n", position);
        return '\0';
    }

    anterior->proximo = atual->proximo;
    char valor = atual->dados;

    if (atual == l->final) {
        l->final = anterior;
    }

    free(atual);
    l->quantidade--;
    return valor;
}

char remover_primeiraocorrencia_inicio(Lista *l, char dado) {
    if (l->inicio == NULL) {
        printf("Lista vazia\n");
        return '\0';
    }

    No *atual = l->inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->dados != dado) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        printf("Letra não encontrada\n");
        return '\0';
    }

    if (anterior == NULL) {
        return remover_inicio(l);
    }

    anterior->proximo = atual->proximo;
    char valor = atual->dados;

    if (atual == l->final) {
        l->final = anterior;
    }

    free(atual);
    l->quantidade--;
    return valor;
}

char remover_primeiraocorrencia_final(Lista *l, char dado) {
    if (l->inicio == NULL) {
        printf("Lista vazia\n");
        return '\0';
    }

    No *atual = l->inicio;
    No *anterior = NULL;
    No *ultimo = NULL;
    No *anterior_ultimo = NULL;

    while (atual != NULL) {
        if (atual->dados == dado) {
            anterior_ultimo = anterior;
            ultimo = atual;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    if (ultimo == NULL) {
        printf("Letra não encontrada\n");
        return '\0';
    }

    if (anterior_ultimo == NULL) {
        return remover_inicio(l);
    }

    anterior_ultimo->proximo = ultimo->proximo;
    char valor = ultimo->dados;

    if (ultimo == l->final) {
        l->final = anterior_ultimo;
    }

    free(ultimo);
    l->quantidade--;
    return valor;
}

int main() {
    Lista* lista = aloca();
    int num = 0;
    char add_char; 
    int position;

    do {
        scanf("%d", &num);
        if (num < 1 || num > 12) {
            break;
        }

        switch(num) {
            case 1:
                scanf(" %c", &add_char);
                inserir_inicio(lista, add_char);
                break;
            case 2:
                remover_inicio(lista);
                break;
            case 3:
                scanf(" %c", &add_char);
                inserir_fim(lista, add_char);
                break;
            case 4:
                excluir_fim(lista);
                break;
            case 5:
                imprimir_inicio(lista);
                break;
            case 6:
                imprimir_fim(lista);
                break;
            case 7:
                imprimir_list(lista);
                break;
            case 8:
                excluir_letras_lista(lista);
                break;
            case 9:
                scanf("%d", &position);
                scanf(" %c", &add_char);
                incluir_letra_posicao(lista, add_char, position);
                break;
            case 10:
                scanf("%d", &position);
                remover_letra_posicao(lista, position);
                break;
            case 11:
                scanf(" %c", &add_char);
                remover_primeiraocorrencia_inicio(lista, add_char);
                break;
            case 12:
                scanf(" %c", &add_char);
                remover_primeiraocorrencia_final(lista, add_char);
                break;
        }
    } while (num != 0);

    excluir_letras_lista(lista); 
    free(lista);
}
    