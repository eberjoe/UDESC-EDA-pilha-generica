#include "PilhaGenerica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // necessário para a função memcpy()

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
    p->dados[p->topo] = malloc(p->tamInfo); // Aloca memória para o dado.
    memcpy(p->dados[p->topo], info, p->tamInfo); // Copia o dado.
    return 1; // Sucesso
}

int desempilha(PilhaGenerica *p, void *info) {
    if(pilha_vazia(*p))
        return ERRO_PILHA_VAZIA;
    memcpy(info, p->dados[p->topo], p->tamInfo); // Copia o dado.
    free(p->dados[p->topo]); // Libera a memória.
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
        mostra(p.dados[i]); // Código polimórfico.
}

void desaloca_pilha(PilhaGenerica *p) {
    int i;
    for(i=0; i<=p->topo; i++) {
        free(p->dados[i]); // Libera a memória dos dados em si.
        free(p->dados); // Libera a memória do vetor de ponteiros.
    }
}

void mostra(char dado) {
    printf("%c", dado);
}
