#include <stdio.h>
#include <stdlib.h>
#include "PilhaGenerica.h"

void mostra_char(void *x) {
    char *p = x;
    printf("%c\n", *p);
}

int main() {
    PilhaGenerica p1;
    inicializa_pilha(&p1, 10, sizeof(char));
    char x = 'a';
    empilha(&p1, &x);
    x = 'b';
    empilha(&p1, &x);
    mostra_pilha(p1, mostra_char);
    printf("%d\n", mostra_char);
}
