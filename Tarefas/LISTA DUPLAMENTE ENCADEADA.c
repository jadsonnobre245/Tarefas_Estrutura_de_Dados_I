 #include <stdio.h>
#include <stdlib.h>
typedef struct lista2{
 struct lista2 *ant;
 struct lista2 *prox;
 int info;
}Lista2;

Lista2* inicializa(void){
return NULL;
}

Lista2* crialista(int v){
    Lista2 *novo=(Lista2*)malloc(sizeof(Lista2));
    novo->info=v;
return novo;
}

Lista2* insere(Lista2 *l,int v){
    Lista2 *novo=crialista(v);
     novo->prox=l;
     novo->ant=NULL;
     if(l!=NULL){
        l->ant=novo;
     }
    return novo;
}
Lista2* busca(Lista2* l,int v){
    Lista2 *aux=l;

}
int main()
{
    Lista2 *l;
    l=inicializa();
    l=insere(l,4);
    l=insere (l,5);
    l=removek(l,5);
    printf("%d",l->info);
    return 0;
}
