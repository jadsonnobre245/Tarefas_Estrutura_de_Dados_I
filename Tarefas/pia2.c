
#include <stdio.h>  
#include <stdlib.h>
typedef struct prato{
      int info;
      struct prato *prox ;
};
typedef struct prato *pirex;
typedef pirex pilha;
pilha p;

pirex* criarPilha (pilha p);
pirex* InserirPilha (int n,pilha p);
void verificador (pilha p);
pirex* removePilha(pilha p);
void imprimir(pilha p);

int main()
{
     int Opcao;
     int n;
    for(;;){
     printf("\n--------------------MENU PILHA---------------------------\n\n"); 
          printf("0 - Para Criar pilha vazia\n");
          printf("1 - Para adcionar itens a pilha\n");
          printf("2 - Para remover itens da pilha\n");
          printf("3 - Mostrar elementos da pilha\n");
          printf("4 - Para Sair\n");
          printf("\n----------------------------------------------------\n\n");
          printf("Informe A Opcao: ");
          scanf("%i", &Opcao);
     
      switch(Opcao) {
                 case 0:  
                         p = criarPilha(p);
                         printf("PILHA CRIADA COM SUCESSO!!");
                        printf("\n");
                      break;
                 case 1:   
                         printf("Digite o numero para inserir na pilha :\n");
                         scanf("%d",&n);
                         p = InserirPilha(n,p); 
                      break;
                 case 2:
                          removePilha(p);
                      break; 
                 case 3:     
                         imprimir(p);   
                         system("pause");               
                      break;   
                 case 4:
                         exit (1);
              }      
       system("cls");                              
   }
    
 system("pause");
return 0; 
}
//
pirex* criarPilha(pilha p)
{
   p = NULL;
   
   return p;
 }
//
pirex* InserirPilha(int n,pilha p){
     pilha novo;
   if((novo = malloc(sizeof(pirex)))==NULL)
    printf("Memoria insulficiente\n");
   else{
    novo->info = n;
    novo->prox = p;
    printf("item adcionado na pilha");
   }
  return novo; 
  printf("\n");
}
//
void verificador (pilha p)
{
   if(p == NULL)
   printf("Pilha vazia\n");
   else
   printf("Pilha nao vazia\n");
}
//
pirex* removePilha(pilha p)
{
   pirex aux;
   
   if(p==NULL){
      printf("Nao ha elementos na pilha\n");            
     return;
   }  
   aux = p->prox;
   free(p);
 
   return aux;
}
//
void imprimir(pilha p)
{
   pirex aux;
   
   if(p!= NULL)
   for(aux = p;aux!=NULL;aux=aux->prox)
     printf("[%d]",aux->info);
   else 
    printf("Pilha vazia\n");
}