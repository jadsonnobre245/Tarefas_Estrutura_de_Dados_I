#include <stdio.h>
#include <stdlib.h>
typedef struct arv{
int info;
struct arv *esq;
struct arv *dir;
}Arv;

Arv *inicializa(void);
Arv *cria(int v,Arv *sae,Arv *sad);
int vazia(Arv *a);
void imprime (Arv *a);
void imprimepad(Arv *a);
Arv *libera(Arv *a);
int busca(Arv *a,int c);
int max(Arv *a,Arv*b);
int altura(Arv *a);
Arv *inserenode(Arv *a,Arv *b);
int iguais(Arv *a,Arv *b);
void imprimenivel(Arv *a,int k,int x);
void imprimenivel1(Arv *a,int k);
