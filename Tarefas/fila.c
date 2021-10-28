/// ESTRUTUDA DE DADOS 1 
//Fila simples que insere, remove e exibe.
//feita por Jadson Nobre 
// essa estrutura é tem a funcao de inserir no final caso o inicio esteja vazio 
// e remove do inicio.
#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{ // CRIAÇÃO DO ITEM PRA A CONTRUÇÃO DA FILA.
	int info;
	struct Nodo *prox;
}Nodo;
// ASSINATURA DAS FUNCOES.
void inserir(Nodo**,Nodo**,int); // Função que insere os itens na fila.
int retirar(Nodo**);// Função que remove os itens da fila.
void imprimir(Nodo**);// Função que imprimi os itens da fila.
 
 int main(){
	Nodo *inicio=NULL;
	Nodo *fim;
	int n; // variavel para armazenar o valor recebido para ser inserido.
	char op; // variavel que armazena a opção escolhida para realizar a ação.
	
	// estrura de repetição responsavel por apresentar as opcoes e direcionar 
	//para suas repctivas funcoes.
	for(;;){ 
		printf("estrutura de fila:\n");
		printf("[1]inserir [2]remover [3]mostrar [4]exit \n ");
		scanf("\n%c",&op);
			switch(op){
			case '1': // caso para inserir.
				printf("digite numero que deseja inserir \n");
				scanf("%i",&n);
				inserir(&inicio,&fim,n);
				break;
			case '2': // caso para remover.
				printf("\n");
				retirar(&inicio); 
				printf("\n");
				break;
			case '3':// caso para imprimir.
				printf("\n");
				printf("Itens de sua Fila:\n");
				imprimir(&inicio);
				printf("\n");
				break;
			case '4':// caso para sair do programa.
				exit(1);
				break;
		}
	}	
}
// função inserir.
void inserir(Nodo**inicio,Nodo**fim,int n){ 
	Nodo *novo=(Nodo*)malloc(sizeof(Nodo)); // novo recebe uma item vazio ou seja a estrutura pra amazenar.
	if(novo==NULL)exit(99); // se novo tiver nulo ele sair do programa.
	
	if(*inicio==NULL){ // se a inicio da fila tiver vazio ele, o inicio recebe o novo.
		*inicio=novo; 
	}
	else{ // se nao o inicio nao tiver vazio ele insere no final.
		(*fim)->prox=novo;
	}
	*fim=novo; 
	novo->info=n; // novo recebe o valor.
	novo->prox=NULL;
	

}
// função remove
int retirar(Nodo**inicio){ 
	int n;
	Nodo*aux;
	if(!*inicio){ // se inicio tiver nulo ele printa isso.
		printf("pilha vazia\n ");
		return 0;
	} // caso nao esteja ele vai removendo ate estar vazio.
	aux=*inicio; // aux recebe uma copia do valor do inicio
	n=aux->info; 
	*inicio=(*inicio)->prox; // atualiza o valor de inicio para o proximo 
	free(aux);// apaga o valor do inicio.
	return(n);
	
	
}
// funcao imprimi 
void imprimir(Nodo**inicio){
	Nodo *aux;
	aux=*inicio;
	while(aux!=NULL){ // enquanto aux tiver diferente de nulo ele imprimir o valor atual que esta 
						//armazenado em aux.
		printf("[%i]",aux->info);
		aux=aux->prox; // atualiza o valor de aux.
	}

}
