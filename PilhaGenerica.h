#define ERRO_PILHA_CHEIA -1
#define ERRO_PILHA_VAZIA -2

typedef struct{
    void **dados;
    int capacidade, topo;
    int tamInfo;
}PilhaGenerica;

void inicializa_pilha(PilhaGenerica *p, int c, int t);
int pilha_vazia(PilhaGenerica p);
int pilha_cheia(PilhaGenerica p);
int empilha(PilhaGenerica *p, void *info);
int desempilha(PilhaGenerica *p, void *info);
int le_topo(PilhaGenerica p, void *info);
int mostra_pilha(PilhaGenerica p, void (*mostra)(void *dados) );
void desaloca_pilha(PilhaGenerica *p);
