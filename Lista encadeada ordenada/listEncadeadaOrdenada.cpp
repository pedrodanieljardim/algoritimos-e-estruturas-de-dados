#include <stdio.h>
#include <stdlib.h>

typedef struct sCelula{
	int info;
	struct sCelula *next;
}Celula;

Celula *init(Celula *lista){
	/*
	-> Inicia o ponteiro para uma lista encadeada
	-> lista � o endere�o do ponteiro externo para uma lista encadeada 
	*/
	lista = NULL;
	printf("Lista Encadeada iniciada com sucesso!");
	return lista;
}

Celula *getNode(){
	/*
		A fun��o getnode() aloca/cria um n� para uma lista encadeada.
	*/
	return (Celula *)malloc(sizeof(Celula));
}

int isEmpty(Celula *lista){
	/*
	->  Verificar se a lista encadeada est� vazia 
	-> lista � o endere�o do primeiro n� da lista encadeada 
	-> 1 para lista vazia e 0 para lista n�o vazia...
	*/
	if(lista == NULL){
		return 1;
	}else
		return 0;
}

void freeNode(Celula *q){
	/* Liberar o espa�o de mem�ria ocupado por um n�, aonde q � o endere�o do n� a ser liberado */
	free(q);
}

void showList(Celula *lista){
	Celula *aux;
	aux = lista;
	
	int i = 0;
	printf("\n		Printando a Lista....			\n");

	// enquanto aux n�o encontrar o final, ele printa o conte�do do pr�ximo....
	while(aux != NULL){
		printf("\n Posicao da lista encadeada [%d] = %d\n",i,aux->info);
		aux = aux->next;
		i += 1;
	}
}

Celula *insertOrdLista(Celula *lista, int x){
	/*
	- Inser��o Ordenada:
		 Insere um n� mantendo a lista ordenada
	- Algoritmo: 
		- Se a lista estiver vazia:
			Faz o ponteiro externo apontar para o novo n�...
		- Caso contr�rio, encontra o primeiro n� maior ou igual ao novo n�	
			Faz o novo n� apontar para o n� atual e Faz o n� anterior apontar para o novo n�..
	*/
	Celula *atual = lista;
	Celula *anterior = NULL;
	Celula *q;
	
	q = getNode();
	
	if(q != NULL){
		q->info = x;
		q->next = NULL;
		/* procura posi��o para inser��o */
		while(atual != NULL && atual->info < x){
			anterior = atual;
			atual = atual->next;
		}
		/* insere elemento */
		if(atual == lista){
			q->next = lista;
			lista = q;
		}else{
			/* insere no meio e fim... */
			anterior->next = q;
			q->next = atual;
		}
		return lista;
	}else{
		printf("\n erro de aloca��o de n�!");
		return NULL;
	}	
}

int procuraLista(Celula *lista, int y){
	Celula *q;
	q = lista;
	int i = 0;
	if(q != NULL){
		while(q->next != NULL){
			if(q->info == y){
				return 1;
			}
			q = q->next;
			if(q->info == y){
				return 1;
			}
			i++;
		}
		printf("\nValor nao encontrado!");
		return 0;
	}
}

Celula *moveToFront(Celula *lista, int x){
	Celula *q;
	Celula *aux;
	
	q = getNode();
	
	q->info = x;
	q->next = lista;
	
	aux = lista;
	// aloca um n� para q
	int p = procuraLista(lista, x);
	if(p == 1){
		if(lista->next != NULL){
			while(aux->next->info != x){
				aux = aux->next;
			}
			
			if(aux->next->next == NULL){
				// serve apenas se ele for o �ltimo....
				freeNode(aux->next);
				aux->next = NULL;
				lista = q;	
			}
			if(aux->next->next != NULL){
				aux->next->info = aux->next->next->info;
				aux->next = aux->next->next;
				lista = q;	
			}
							
			printf("\n foi usado o metodo de mover-para-frente com sucesso! ");
			return lista;
		}
	}else{
		return NULL;
	}
}

Celula *transpoeValor(Celula *lista, int x){
	Celula *q;
	q = lista;
	int p = procuraLista(lista, x);
	if(p == 1){
		if(lista->next != NULL){
			while(q->next->info == x){
				q = q->next;
			}
				int guarda = q->next->info;
				q->next->info = q->info;
				q->info = guarda;
				return lista;				
		}
		printf("Impossivel mover o primeiro da lista para frente!");
	}
}

Celula *removeFirst(Celula *lista){
	Celula *q;
	q = lista;
	if(isEmpty(lista) == 0){
		lista = q->next;
		// lista recebe o pr�ximo n�....
		printf("\n o valor %d removido do inicio da lista encadeada! ", q->info);
		freeNode(q);
		// o n� q � eliminado (primeiro n�)......
		return lista;
	}else{
		printf("Lista Vazia!");
	}
}

Celula *removeLast(Celula *lista){
	Celula *q;
	Celula *aux;
	q = lista;
	int i = 0;
	if(isEmpty(lista) == 0){
		if(lista->next == NULL){
			// quer dizer que a lista tem apenas um valor....
			freeNode(lista);
		}else{
			while(q->next->next != NULL){
			// procura o pen�ltimo elemento de uma lista, para ter uma refer�ncia do �ltimo....
				q = q->next;
			}
		}
		freeNode(q->next);
		q->next = NULL;
		printf("\n o valor foi removido do final da lista encadeada! ");
		// o n� q � eliminado (primeiro n�)......
		return lista;
	}else{
		printf("Lista Vazia!");
	}	
}	

int main (){
	int loopMenu = 1;
	int chooseMenu;
	Celula *l;
	printf("=============================================\n");
	l = init(l);
	int input;
	while (loopMenu == 1){
		printf("\n===============================================================================");
		printf("\n				  MENU 							");
		printf("\n 1) Mostra Lista Encadeada.......");
		printf("\n 2) Insere Ordenadamente.......");
		printf("\n 3) Metodo de mover-para-frente .......");		
		printf("\n 4) Metodo de transposicao.......");
		printf("\n 5) Remove valor no final da Lista Encadeada.......");
		printf("\n 6) Remove determinado valor da lista Encadeada.......");
		printf("\n 7) Sair.......");
		printf("\n===============================================================================");
		printf("\nDigite o Valor para a Operacao: ");
		scanf("%d",&chooseMenu);
		switch(chooseMenu){
			case 1:
				// case 1
				showList(l);
				break;
			case 2:
				// case 2
				printf("\nValor a ser colocado no inserido ordenadamente na Lista Encadeada: ");
				scanf("%d",&input);
				l = insertOrdLista(l,input);
				break;
			case 3:
				// case 3
				printf("\nValor a ser colocado no inicio da Lista Encadeada: ");
				scanf("%d",&input);
				l = moveToFront(l, input);
				// l = insertFirst(l,input);
				break;
			case 4:
				// case 4
				printf("\nValor a ser transposto na Lista Encadeada: ");
				scanf("%d",&input);
				l = transpoeValor(l, input);
				break;
			case 5:
				// case 5
				l = removeFirst(l);
				break;
			case 6:
				l = removeLast(l);
				// case 6
				break;
			case 7:
				printf("\nValor a ser colocado no final da Lista Encadeada: ");
				scanf("%d",&input);
				// l = removeValue(l,input);
				// case 7
				break;

			case 8:
				
			case 9:
				printf("\nValor a ser colocado no topo da Lista Encadeada: ");
				scanf("%d", &input);
				l = moveToFront(l,input);
				break;
			case 10:
				printf("Encerrando o Loop do menu!");
				loopMenu = 0;
				// case 8
				break;
			default:
				printf("Opcao Invalida!");
		}	
	}
	return 0;	
}
