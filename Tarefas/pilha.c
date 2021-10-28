//==============================================================================
#include <stdio.h>
#include <stdlib.h>
//==============================================================================
//DECLARAÇÃO DA ESTRUTURA DA PILHA
typedef struct reg_pilha{
      int info;
      struct reg_pilha *lig ;
};
//DECLARAÇÃO DE VARIÁVEIS AUXILIARES
//tpont é UMA REGPILHA
typedef struct reg_pilha *tpont;
//pilha é UMA REGPILHA
typedef tpont pilha;
//p É UMA REGPILHA
pilha p;
//==============================================================================
//DECLARAÇÃO DAS FUNÇÕES DA PILHA
tpont* criar (pilha p);
tpont* push (int x,pilha p);
void vazia (pilha p);
void top (pilha p);
tpont* pop(pilha p);
void imprimir(pilha p);
//==============================================================================
int main()
{
     int choice,x;
    for(;;){
     printf("\n--------------------MENU---------------------------\n\n");
          printf("1 - Para Criar pilha vazia\n");
          printf("2 - Para Empilhar(PUSH)\n");
          printf("3 - Para Verificar se a pilha esta vazia\n");
          printf("4 - Para Desempilhar(POP)\n");
          printf("5 - Para Acessar o topo da pilha\n");
          printf("6 - Mostrar elementos da pilha\n");
          printf("7 - Para Sair\n");
          printf("\n----------------------------------------------------\n\n");
          printf("Informe A Opcao: ");
          scanf("%d", &choice);
		
	//ESCOLHA DA FUNÇÃO NO MENU
      switch(choice) {
                 case 1:
                         p = criar(p);
                      break;
                 case 2:
                         printf("Digite o numero a inserir\n");
                         scanf("%d",&x);
                         p = push(x,p);
                      break;
                 case 3:
                            vazia (p);
                         system("pause");
                      break;
                 case 4:
                          p = pop (p);
                      break;
                 case 5:
                         top (p);
                         system("pause");
                      break;

                 case 6:
                         imprimir(p);
                         system("pause");
                      break;
                 case 7:
                         exit (1);
              }
       system("cls");
   }

 system("pause");
return 0;
}
//=============================================================================
pilha* criar (pilha p)
{
//INICIA A PILHA VAZIA COMO NULA
   p = NULL;

   return p;
 }
//=============================================================================
pilha* push (int x,pilha p)
{
	//FUNÇÃO DE INSERIR NÓ NO TOPO
   pilha pont;
   //ALOCA NA MEMORIA ESPAÇO SUFICIENTE PARA UM NO
   if((pont = malloc(sizeof(tpont)))==NULL)
    printf("Memoria insulficiente\n");
   else{
   	//DADO A SER AMAZENADO NO NÓ
    pont->info = x;
    //p SEMPRE SERÁ O TOPO, O NOVO ELEMENTO SEMPRE VAI ASSUMIR O LUGAR DO TOPO E VAI APONTAR PARA O SEGUNDO ELEMENTO DA PILHA
    pont->lig = p;
   }
   //RETORNA PARA ARMAZENAR EM p O NOVO TOPO
  return pont;
}
//=============================================================================
void vazia (pilha p)
{
	//VERIFICA SE A PILHA ESTA VAZIA
   if(p == NULL)
   printf("Pilha vazia\n");
   else
   printf("Pilha nao vazia\n");
}
//=============================================================================
void top (pilha p)
{
	//IMPRIME SEMPRE p->info PQ p SEMPRE SERÁ A REFERENCIA PARA O TOPO DA PILHA
    if(p!=NULL)
    printf("Topo da pilha %d",p->info);
    //SE ESTIVER VAZIA NAO TEM NADA PARA IMPRIMIR
    else
     printf("Pilha vazia\n");
}
//=============================================================================
pilha* pop(pilha p)
{
	//DECLARA UMA VARIAVEL AUXILIAR DO TIPO DO NÓ DA PILHA
   tpont aux;

   if(p==NULL){
      printf("Nao ha elementos na pilha\n");
     return;
   }
   
   //ARMAZENA O TOPO QUE SERÁ DESEMPILHADO EM AUX
   aux = p;
   //TOPO ASSUME O VALOR DO PROXIMO ELEMENTO DA PILHA
   p=p->lig;
   //ELIMINA O TOPO ANTIGO
   free(aux);
	
	//RETORNA p PARA ATUALIZAR A PILHA
   return p;
}
//==============================================================================
void imprimir(pilha p)
{
	//DECLARA UMA VARIAVEL AUXILIAR DO TIPO DO NÓ DA PILHA
   tpont aux;
	
	//SE A PILHA NÃO ESTIVER VAZIA ENTAO IMPRIME ELEMENTOS
   if(p!= NULL)
   //PERCORRE A PILHA EM LAÇO PARA IMPRIMIR ELEMENTOS ARMAZENADOS EM INFO
   for(aux = p;aux!=NULL;aux=aux->lig)
     printf("%d ",aux->info);
   //SE ESTIVER VAZIA NAO IMPRIME
   else
    printf("Pilha vazia\n");
}
