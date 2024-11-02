/*Defina uma função recursiva que calcule o maior divisor comum (M.D.C.) entre dois números a e b, onde a > b.

Entrada: 10 5 -> Saída: 5

Entrada: 60 8 -> Saída: 4*/

#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y) {
    if(x==0) return y;
    if(y==0) return x;

    return gcd(y, x%y);
}

int main() {
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    printf("%d", gcd(n1, n2));
}