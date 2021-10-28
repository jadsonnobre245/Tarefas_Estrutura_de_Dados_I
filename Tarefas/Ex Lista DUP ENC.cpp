#include <stdio.h>
#include <stdlib.h>

//ESTRUTURA DO N� DA LISTA
struct Node{
	int num;
	struct Node *prox;
	struct Node *ant;
}; 
typedef struct Node node;

int tam,elem;


//DECLARA��O DAS FUN��ES DA LISTA
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
	//INICIALIZA A LISTA (PRIMEIRO ALOCA O O INICIAL E DEPOIS CHAMA A FUN��O INICIA)
	node *LISTA = (node *) malloc(sizeof(node));
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
	inicia(LISTA);
	/////////////////////
	int opt;
	
	//AMOSTRA O MENU EM LA�O DE REPETI��O
	do{
		opt=menu();
		opcao(LISTA,opt);
	}while(opt);
	
	//LIBERA A MEM�RIA NO FINAL DE TUDO
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
	//CHAMADAS DE FUN��ES DA LISTA, DE ACORDO COM A OP��O DIGITADA PELO USU�RIO
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

//VERIFICA SE A LISTA EST� VAZIA
int vazia(node *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}

//PREPARA UM NOVO ELEMENTO (N�)
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
	novo->prox = NULL;
	
	if(vazia(LISTA)) {
		LISTA->prox=novo;
		system("cls");
	}
	else{
		//PREPARA O PRIMEIRO ELEMENTO DA LISTA PARA A BUSCA
		node *tmp = LISTA->prox;
		
		//PARA INSERIR NO FIM, BUSCA O ULTIMO ELEMENTO DA LISTA
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		
		//COM TMP = ULTIMO ELEMENTO, AJUSTA OS PONTEIROS PARA O NOVO ELEMENTO SER INSERIDO NO FINAL
		tmp->prox = novo;
		novo->prox=NULL;
		novo->ant=tmp;
	}
	//TAM SEMPRE AJUSTA O TAMANHO DA LISTA PARA SER UTILIZADO NA FUN�AO EXIBE
	tam++;
	system("cls");
}

void insereInicio(node *LISTA)
{
	node *novo=aloca();
	//SE A LISTA ESTIVER VAZIA N�O PRECISA AJUSTAR O PONTEIRO DO SEGUNDO ELEMENTO
	if(vazia(LISTA)){
		LISTA->prox = novo;
		novo->prox=NULL;
		novo->ant=NULL;
		//TAM SEMPRE AJUSTA O TAMANHO DA LISTA PARA SER UTILIZADO NA FUN�AO EXIBE
		tam++;
		system("cls");
		return;	
	}
	
	//OLDHEAD ARMAZENA O PRIMEIRO ELEMENTO DA LISTA, QUE SER� REAJUSTADO PARA O SEGUNDO ELEMENTO
	node *oldHead = LISTA->prox;
	
	//NOVO � AJUSTADO COMO PRIMEIRO ELEMENTO
	LISTA->prox = novo;
	novo->ant=NULL;
	//OLDHEAD � AJUSTADO COMO SEGUNDO ELEMENTO
	novo->prox = oldHead;
	oldHead->ant = novo;
	system("cls");
	//TAM SEMPRE AJUSTA O TAMANHO DA LISTA PARA SER UTILIZADO NA FUN�AO EXIBE
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
	//PERCORRE A LISTA E VAI IMPRIMINDO ELEMENTO POR ELEMENTO, USA TAM COMO REFER�NCIA PARA CHEGAR AT� O ULTIMO ELEMENTO
	while( tmp != NULL){
		printf("%5d", tmp->num);
		tmp = tmp->prox;
	}
	printf("\n        ");
	int count;
	for(count=0 ; count < tam ; count++)
		printf("  ^  ");
	printf("\nOrdem:");
	//IMPRIME A ORDEM, USA TAM COMO REFER�NCIA PARA CHEGAR AT� O ULTIMO N�MERO DE ORDEM
	for(count=0 ; count < tam ; count++)
		printf("%5d", count+1);
	
		
	printf("\n\n");
}

void libera(node *LISTA)
{
	//PERCORRE A LISTA E VAI LIBERANDO TODOS OS N�S
	if(!vazia(LISTA)){
		node *proxNode,
			  *atual;
		
		atual = LISTA->prox;
		while(atual != NULL){
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
		//SE A POSIL�AO INDICADA FOR 1 INSERE NO INICIO
		if(pos==1)
			insereInicio(LISTA);
		//SE N�O INSERE EM UMA POSI��O INTERMEDI�RIA
		else{
			//CRIA PONTEIROS DE REFERENCIA
			node *atual = LISTA->prox,
				 *anterior=LISTA; 
			//ALOCA UM NOVO NO QUE SER� INSERIDO
			node *novo=aloca();
			
			//PERCORRE A LISTA AT� A POSI��O DE RETIRAR INDICADA PELO USU�RIO	 
			for(count=1 ; count < pos ; count++){
					anterior=atual;
					atual=atual->prox;
			}
			//AJUSTA OS PONTEIROS PARA INSERIR O N� NA POSI��O INDICADA (NESSE CASO NOVO � INSERIDO NA LISTA)
			anterior->prox=novo;
			novo->prox = atual;
			novo->ant=anterior;
			atual->ant=novo;
			//TAM SEMPRE AJUSTA O TAMANHO DA LISTA PARA SER UTILIZADO NA FUN�AO EXIBE
			tam++;
			system("cls");
		}
			
	}else
		printf("Elemento invalido\n\n");		
}

node *retiraInicio(node *LISTA)
{
	//SE A LISTA EST� VAZIA N�O REMOVE NADA
	if(LISTA->prox == NULL){
		printf("Lista ja esta vazia\n");
		return NULL;
	}
	//SE N�O REMOVE
	else{
		//ARMAZENA O PRIMEIRO ELEMENTO QUE SER� REMOVIDO
		node *tmp = LISTA->prox;
		//O PRIMEIRO ELEMENTO VIRA O SEGUNDO
		LISTA->prox = tmp->prox;
		//REAJUSTA O PONTEIRO DO ELEMENTO ANTERIOR PARA NULL
		tmp=LISTA->prox;
		tmp->ant=NULL;
		//TAM SEMPRE AJUSTA O TAMANHO DA LISTA PARA SER UTILIZADO NA FUN�AO EXIBE
		tam--;
		return tmp;
	}
				
}

node *retiraFim(node *LISTA)
{
	//SE A LISTA EST� VAZIA N�O REMOVE NADA
	if(LISTA->prox == NULL){
		printf("Lista ja vazia\n\n");
		return NULL;
	}
	//SE N�O REMOVE
	else{
		//ARMAZENA ELEMENTO QUE FAR�O PARTE DO AJUSTE DE PONTEIROS
		node *ultimo = LISTA->prox,
			 *penultimo = LISTA;
		
		//BUSCA O ULTIMO ELEMENTO ARMAZENANDO O PENULTIMO
		while(ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
		
		//PENULTIMO QUE APONTA PARA PROX = NULL, ASSIM, O ULTIMO ELEMENTO SAI DA LISTA
		penultimo->prox = NULL;
		//TAM SEMPRE AJUSTA O TAMANHO DA LISTA PARA SER UTILIZADO NA FUN�AO EXIBE
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
		
		//SE A POSI��O DE RETIRAR FOR 1, RETIRA DO INICIO
		if(opt==1)
			return retiraInicio(LISTA);
		else{
			//SE N�O, ARMAZANA ATUAL E ANTERIOR PARA REAJUSTAR OS PONTEIROS AP�S RETIRAR O ELEMENTO
			node *atual = LISTA->prox,
				 *anterior=LISTA; 
			
			//PERCORRE A LISTA AT� A POSI��O DE RETIRAR INDICADA PELO USU�RIO
			for(count=1 ; count < opt ; count++){
				anterior=atual;
				atual=atual->prox;
			}
		//AJUSTA OS PONTEIROS PARA ELIMINAR O N� DA POSI��O INDICADA (NESSE CASO ATUAL SAI DA LISTA)
		node *tmp = atual->prox;	
		anterior->prox=tmp;
		tmp->ant=anterior;
		//TAM SEMPRE AJUSTA O TAMANHO DA LISTA PARA SER UTILIZADO NA FUN�AO EXIBE
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
	while(atual->prox != NULL){
		if (atual->num == elemento) {
			//IMPRIME O ELEMENTO QUANDO ENCONTRA
			if (atual->ant != NULL) {
				printf("\n\nAnterior: %3d     ", atual->ant->num);
			}
			printf("Busca: %3d     ", atual->num);
			if (atual->prox != NULL) {
				printf("Proximo: %3d\n\n", atual->prox->num);
			}
			
		}
		//ATUALIZA ATUAL PARA CONTINUAR COM O LOOP DE BUSCA
		atual=atual->prox;
	}
	//Imprime o ultimo elemento que o la�o wile deixa passar
	if (atual->num == elemento) {
		//IMPRIME O ELEMENTO QUANDO ENCONTRA
		if (atual->ant != NULL) {
			printf("\n\nAnterior: %3d     ", atual->ant->num);
		}
		printf("Busca: %3d     ", atual->num);
		if (atual->prox != NULL) {
			printf("Proximo: %3d\n\n", atual->prox->num);
		}
		
	}
	
}
