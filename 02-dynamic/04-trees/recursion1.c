/*A sequência de Fibonacci é um problema clássico no qual podemos aplicar funções recursivas. A sequência começa com dois números 0 e 1. Os números seguintes são a soma dos dois anteriores. A sequência ficaria assim: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...

O programa deve ser capaz de aceitar um número como entrada (índice) e informar o valor correspondente daquele índice na sequência de Fibonnaci. Exemplos:

Entrada: 0 -> Saída: 0

Entrada: 4 -> Saída: 3

Entrada: 6 -> Saída: 8*/

#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
    if(n<=1) {
        return n;
    }

    return fib(n-1) + fib(n-2);
};

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", fib(n));
}