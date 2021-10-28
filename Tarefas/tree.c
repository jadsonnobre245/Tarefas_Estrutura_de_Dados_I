#include <stdio.h>
#include <stdlib.h>                                                          
typedef struct arv{
int info;
struct arv *esq;
struct arv *dir;
}Arv;

Arv *inicializa(void){
    return NULL;
}

Arv *cria(int v,Arv *sae,Arv *sad){
    Arv *p=(Arv*)malloc(sizeof(Arv));
    p->info=v;
    p->esq=sae;
    p->dir=sad;
    return p;
}
int vazia(Arv *a){
return a==NULL;
}

void imprime (Arv *a){
    if(!vazia(a)){
        imprime(a->esq);
        imprime(a->dir);
        printf("%d",a->info);
    }
}

void imprimepad(Arv *a){
    printf("<");
        if(!vazia(a)){
            imprimepad(a->esq);
            printf("%d",a->info);
            imprimepad(a->dir);
        }
    printf(">");
}

void imprimenivel1(Arv *a,int k){
   if(!altura(a)==k){
      printf("%d",a->info);
   }else{
   imprimenivel1(a->esq,k);
    imprimenivel1(a->dir,k);
   }
}

Arv *libera(Arv *a){
    if(!vazia(a)){
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
return NULL;
}

int busca(Arv *a,int c){
    if(vazia(a)){
        return 0;
    }
    return (a->info==c||busca(a->esq,c)||busca(a->dir,c));
}

int max(Arv *a,Arv*b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

int altura(Arv *a){
    if(vazia(a)){
        return 0;
    }
return 1+(max(altura(a->esq),altura(a->dir)));
}

Arv *inserenode(Arv *a,Arv *b){
    if(a->esq==NULL){
        return a->esq=b;
    }else if(a->dir==NULL){
    return  a->dir=b;
    }
    if(a->info>b->info){
        return inserenode(a->esq,b);
    }else{
        return inserenode(a->dir,b);
    }
return a;
}

int iguais(Arv *a,Arv *b){
    if(vazia(a)&&vazia(b)){
        return 1;
    }
    if(vazia(a)||vazia(b)){
        return 0;
    }
return((a->info == b->info)&&iguais(a->dir,b->dir)&&iguais(a->esq,b->esq));
}

