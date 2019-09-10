#include "PilhaGenerica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // necess�rio para a fun��o memcpy()

void inicializa_pilha(PilhaGenerica *p, int c, int t){
    p->dados = malloc( sizeof(void *) * c );
    p->capacidade = c;
    p->topo = -1;
    p->tamInfo = t;
}

int pilha_vazia(PilhaGenerica p) {
    return p.topo == -1;
}

int pilha_cheia(PilhaGenerica p) {
    return p.topo == p.capacidade - 1;
}

int empilha(PilhaGenerica *p, void *info) {
    if(pilha_cheia(*p))
        return ERRO_PILHA_CHEIA;
    p->topo++;
    p->dados[p->topo] = malloc(p->tamInfo); // Aloca mem�ria para o dado.
    memcpy(p->dados[p->topo], info, p->tamInfo); // Copia o dado.
    return 1; // Sucesso
}

int desempilha(PilhaGenerica *p, void *info) {
    if(pilha_vazia(*p))
        return ERRO_PILHA_VAZIA;
    memcpy(info, p->dados[p->topo], p->tamInfo); // Copia o dado.
    free(p->dados[p->topo]); // Libera a mem�ria.
    p->topo--;
    return 1; // Sucesso
}

int le_topo(PilhaGenerica p, void *info) {
    if(pilha_vazia(p))
        return ERRO_PILHA_VAZIA;
    memcpy(info, p.dados[p.topo], p.tamInfo); // Copia o dado.
    return 1; // Sucesso
}

void mostra_pilha(PilhaGenerica p, void (*mostra)(void *dados) ) {
    if(pilha_vazia(p))
        printf("Pilha vazia!\n");
    else
        printf("Dados da Pilha:\n");
    int i;
    for(i=0; i<=p.topo; i++)
        mostra(p.dados[i]); // C�digo polim�rfico.
}

void desaloca_pilha(PilhaGenerica *p) {
    int i;
    for(i=0; i<=p->topo; i++) {
        free(p->dados[i]); // Libera a mem�ria dos dados em si.
        free(p->dados); // Libera a mem�ria do vetor de ponteiros.
    }
}

void mostra(char dado) {
    printf("%c", dado);
}
