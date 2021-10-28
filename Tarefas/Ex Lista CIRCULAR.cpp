#include <stdio.h>
#include <stdlib.h>

//ESTRUTURA DO NÓ DA LISTA
struct Node{
	int num;
	struct Node *prox;
	struct Node *ant;
	int flagFinal;
	//SE flagFinal = 1, entao é o ultimo elemeto
}; 
typedef struct Node node;

int tam,elem;


//DECLARAÇÃO DAS FUNÇÕES DA LISTA
void inicia(node *LISTA);
int menu(void);
void opcao(node *LISTA, int op);
node *criaNo();
void insereFim(node *LISTA);
void insereInicio(node *LISTA);
void exibe(node *LISTA);
void libera(node *LISTA);
void insere (node *LISTA);
void busca (node *LISTA, int elem);
node *retiraInicio(node *LISTA);
node *retiraFim(node *LISTA);
node *retira(node *LISTA);


int main(void)
{
	//INICIALIZA A LISTA (PRIMEIRO ALOCA O O INICIAL E DEPOIS CHAMA A FUNÇÃO INICIA)
	node *LISTA = (node *) malloc(sizeof(node));
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
	inicia(LISTA);
	/////////////////////
	int opt;
	
	//AMOSTRA O MENU EM LAÇO DE REPETIÇÃO
	do{
		opt=menu();
		opcao(LISTA,opt);
	}while(opt);
	
	//LIBERA A MEMÓRIA NO FINAL DE TUDO
	free(LISTA);
	return 0;
	}
}

void inicia(node *LISTA)
{
	LISTA->prox = NULL;
	LISTA->ant = NULL;
	tam=0;
}

int menu(void)
{
	int opt;
	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Zerar lista\n");
	printf("2. Exibir lista\n");
	printf("3. Adicionar node no inicio\n");
	printf("4. Adicionar node no final\n");
	printf("5. Escolher onde inserir\n");
	printf("6. Retirar do inicio\n");
	printf("7. Retirar do fim\n");
	printf("8. Escolher de onde tirar\n");
	printf("9. Buscar Elemento\n");
	printf("Opcao: "); scanf("%d", &opt);
	
	return opt;
}

void opcao(node *LISTA, int op)
{
	//CHAMADAS DE FUNÇÕES DA LISTA, DE ACORDO COM A OPÇÃO DIGITADA PELO USUÁRIO
	node *tmp;
	switch(op){
		case 0:
			libera(LISTA);
			break;
			
		case 1:
			libera(LISTA);
			inicia(LISTA);
			break;
		
		case 2:
			exibe(LISTA);
			break;
		
		case 3:
			insereInicio(LISTA);
			break;		
			
		case 4:
			insereFim(LISTA);
			break;
			
		case 5:
			insere(LISTA);
			break;
		
		case 6:
			tmp= retiraInicio(LISTA);
			printf("Retirado: %3d\n\n", tmp->num);
			break;
			
		case 7:
			tmp= retiraFim(LISTA);
			printf("Retirado: %3d\n\n", tmp->num);
			break;
		
		case 8:
			tmp= retira(LISTA);
			printf("Retirado: %3d\n\n", tmp->num);
			break;
		
		case 9:
			printf("Qual elemento deseja procurar? ");
			scanf("%d", &elem);
			busca(LISTA,elem);
			break;
		
		default:
			printf("Comando invalido\n\n");
	}
}

//VERIFICA SE A LISTA ESTÁ VAZIA
int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}

//PREPARA UM NOVO ELEMENTO (NÓ)
node *aloca()
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
		printf("Novo elemento: "); scanf("%d", &novo->num);
		return novo;
	}
}


void insereFim(node *LISTA)
{
	node *novo=aloca();
	novo->prox = LISTA->prox;
	
	if(vazia(LISTA)) {
		novo->flagFinal=1;
		novo->ant=LISTA->prox;
		LISTA->prox=novo;
		system("cls");
	}
	else{
		//PREPARA O PRIMEIRO ELEMENTO DA LISTA PARA A BUSCA
		node *ultimo = LISTA->prox;
		node *primeiro = LISTA->prox;
		
		//PARA INSERIR NO FIM, BUSCA O ULTIMO ELEMENTO DA LISTA
		while(ultimo->flagFinal != 1) {
			ultimo = ultimo->prox;
		}
		
		//anterior do primeiro elemento muda
		primeiro->ant=novo;
		// AJUSTA OS PONTEIROS PARA O NOVO ELEMENTO SER INSERIDO NO FINAL
		ultimo->prox = novo;
		//ultimo não é mais o elemento final
		ultimo->flagFinal=0;
		novo->ant=ultimo;
		//agora novo é o final
		novo->flagFinal=1;
	}
	//TAM SEMPRE AJUSTA O TAMANHO DA LISTA PARA SER UTILIZADO NA FUNÇAO EXIBE
	tam++;
	system("cls");
}

void insereInicio(node *LISTA)
{
	node *novo=aloca();
	//SE A LISTA ESTIVER VAZIA NÃO PRECISA AJUSTAR O PONTEIRO DO SEGUNDO ELEMENTO
	if(vazia(LISTA)){
		
		LISTA->prox = novo;
		novo->prox=LISTA->prox;
		novo->ant=LISTA->prox;
		novo->flagFinal=1;
		//TAM SEMPRE AJUSTA O TAMANHO DA LISTA PARA SER UTILIZADO NA FUNÇAO EXIBE
		tam++;
		system("cls");
		return;	
	}
	
	//OLDHEAD ARMAZENA O PRIMEIRO ELEMENTO DA LISTA, QUE SERÁ REAJUSTADO PARA O SEGUNDO ELEMENTO
	node *oldHead = LISTA->prox;
	
	//NOVO É AJUSTADO COMO PRIMEIRO ELEMENTO
	novo->ant=oldHead->ant;
	oldHead->ant->prox=novo;
	novo->prox = oldHead;
	LISTA->prox = novo;
	//OLDHEAD É AJUSTADO COMO SEGUNDO ELEMENTO
	oldHead->ant = novo;
	system("cls");
	printf("%5d", novo->ant->num);
	printf("%5d", novo->prox->num);
	printf("%5d", novo->num);
	//TAM SEMPRE AJUSTA O TAMANHO DA LISTA PARA SER UTILIZADO NA FUNÇAO EXIBE
	tam++;
}

void exibe(node *LISTA)
{
	system("cls");
	if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return ;
	}
	
	
	node *tmp;
	tmp = LISTA->prox;
	printf("Lista:");
	//PERCORRE A LISTA E VAI IMPRIMINDO ELEMENTO POR ELEMENTO, USA TAM COMO REFERÊNCIA PARA CHEGAR ATÉ O ULTIMO ELEMENTO
	while( tmp->flagFinal != 1){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("%5d", tmp->num);
	tmp = tmp->prox;
	printf("\n        ");
	int count;
	for(count=0 ; count < tam ; count++)
		printf("  ^  ");
	printf("\nOrdem:");
	//IMPRIME A ORDEM, USA TAM COMO REFERÊNCIA PARA CHEGAR ATÉ O ULTIMO NÚMERO DE ORDEM
	for(count=0 ; count < tam ; count++)
		printf("%5d", count+1);
	
		
	printf("\n\n");
}

void libera(node *LISTA)
{
	//PERCORRE A LISTA E VAI LIBERANDO TODOS OS NÓS
	if(!vazia(LISTA)){
		node *proxNode,
			  *atual;
		
		atual = LISTA->prox;
		while(atual->flagFinal != 1){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

void insere(node *LISTA)
{
	int pos,
		count;
	printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ", tam);
	scanf("%d", &pos);
	
	if(pos>0 && pos <= tam){
		//SE A POSILÇAO INDICADA FOR 1 INSERE NO INICIO
		if(pos==1)
			insereInicio(LISTA);
		//SE NÃO INSERE EM UMA POSIÇÃO INTERMEDIÁRIA
		else{
			//CRIA PONTEIROS DE REFERENCIA
			node *atual = LISTA->prox,
				 *anterior=LISTA; 
			//ALOCA UM NOVO NO QUE SERÁ INSERIDO
			node *novo=aloca();
			
			//PERCORRE A LISTA ATÉ A POSIÇÃO DE RETIRAR INDICADA PELO USUÁRIO	 
			for(count=1 ; count < pos ; count++){
					anterior=atual;
					atual=atual->prox;
			}
			//AJUSTA OS PONTEIROS PARA INSERIR O NÓ NA POSIÇÃO INDICADA (NESSE CASO NOVO É INSERIDO NA LISTA)
			anterior->prox=novo;
			novo->prox = atual;
			novo->ant=anterior;
			atual->ant=novo;
			//TAM SEMPRE AJUSTA O TAMANHO DA LISTA PARA SER UTILIZADO NA FUNÇAO EXIBE
			tam++;
			system("cls");
		}
			
	}else
		printf("Elemento invalido\n\n");		
}

node *retiraInicio(node *LISTA)
{
	//SE A LISTA ESTÁ VAZIA NÃO REMOVE NADA
	if(LISTA->prox == NULL){
		printf("Lista ja esta vazia\n");
		return NULL;
	}
	//SE NÃO REMOVE
	else{
		//ARMAZENA O PRIMEIRO ELEMENTO QUE SERÁ REMOVIDO
		node *primeiro = LISTA->prox;
		node *segundo = primeiro->prox;
		//O PRIMEIRO ELEMENTO VIRA O SEGUNDO
		LISTA->prox = segundo;
		//REAJUSTA O PONTEIRO DO ELEMENTO ANTERIOR
		segundo->ant = primeiro->ant;
		
		//TAM SEMPRE AJUSTA O TAMANHO DA LISTA PARA SER UTILIZADO NA FUNÇAO EXIBE
		tam--;
		return primeiro;
	}
				
}

node *retiraFim(node *LISTA)
{
	//SE A LISTA ESTÁ VAZIA NÃO REMOVE NADA
	if(LISTA->prox == NULL){
		printf("Lista ja vazia\n\n");
		return NULL;
	}
	//SE NÃO REMOVE
	else{
		//ARMAZENA ELEMENTO QUE FARÃO PARTE DO AJUSTE DE PONTEIROS
		node *ultimo = LISTA->prox,
			 *penultimo = LISTA;
		
		//BUSCA O ULTIMO ELEMENTO ARMAZENANDO O PENULTIMO
		while(ultimo->flagFinal != 1){
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
		
		//PENULTIMO QUE APONTA PARA PROX = NULL, ASSIM, O ULTIMO ELEMENTO SAI DA LISTA
		penultimo->prox = ultimo->prox;
		penultimo->flagFinal=1;
		//TAM SEMPRE AJUSTA O TAMANHO DA LISTA PARA SER UTILIZADO NA FUNÇAO EXIBE
		tam--;
		system("cls");
		return ultimo;		
	}
}

node *retira(node *LISTA)
{
	int opt,
		count;
	printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", tam);
	scanf("%d", &opt);
	
	if(opt>0 && opt <= tam){
		
		//SE A POSIÇÃO DE RETIRAR FOR 1, RETIRA DO INICIO
		if(opt==1)
			return retiraInicio(LISTA);
		else{
			//SE NÃO, ARMAZANA ATUAL E ANTERIOR PARA REAJUSTAR OS PONTEIROS APÓS RETIRAR O ELEMENTO
			node *atual = LISTA->prox,
				 *anterior=LISTA; 
			
			//PERCORRE A LISTA ATÉ A POSIÇÃO DE RETIRAR INDICADA PELO USUÁRIO
			for(count=1 ; count < opt ; count++){
				anterior=atual;
				atual=atual->prox;
			}
		//AJUSTA OS PONTEIROS PARA ELIMINAR O NÓ DA POSIÇÃO INDICADA (NESSE CASO ATUAL SAI DA LISTA)
		node *tmp = atual->prox;	
		anterior->prox=tmp;
		tmp->ant=anterior;
		//TAM SEMPRE AJUSTA O TAMANHO DA LISTA PARA SER UTILIZADO NA FUNÇAO EXIBE
		tam--;
		return atual;
		}
			
	}else{
		printf("Elemento invalido\n\n");
		return NULL;
	}
}


void busca(node *LISTA, int elemento)
{	
	//PEGA O PRIMEIRO ELEMENTO DA LISTA
	node *atual = LISTA->prox; 
	
	//PERCORRE A LISTA TODA PARA ENCONTRAR ELEMENTOS IGUAIS A BUSCA
	while(atual->flagFinal != 1){
		if (atual->num == elemento) {
			//IMPRIME O ELEMENTO QUANDO ENCONTRA
			printf("\n\nAnterior: %3d     ", atual->ant->num);
			printf("Busca: %3d     ", atual->num);
			printf("Proximo: %3d\n\n", atual->prox->num);
		}
		//ATUALIZA ATUAL PARA CONTINUAR COM O LOOP DE BUSCA
		atual=atual->prox;
	}
	//Imprime o ultimo elemento que o laço wile deixa passar
	if (atual->num == elemento) {
		//IMPRIME O ELEMENTO QUANDO ENCONTRA
		printf("\n\nAnterior: %3d     ", atual->ant->num);
		printf("Busca: %3d     ", atual->num);
		printf("Proximo: %3d\n\n", atual->prox->num);
	}
	
}
