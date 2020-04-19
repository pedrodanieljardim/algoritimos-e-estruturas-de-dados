#include <stdio.h>
#include <stdlib.h>

/*
	Lista Simplesmente Encadeada
	� itens s�o armazenados em blocos de mem�ria denominados n�s
	� cada n� possui dois campos:
	1) campo de informa��o
	2) campo do endere�o do n� seguinte da lista
*/

typedef struct sLista{
	int info;
	struct sLista *next;
}Lista;

/*
- li.info � o conte�do da lista e
- li.next � o endere�o do proximo n�
*/

Lista* iniciaLista(Lista *li){
	/*
	Inicia o ponteiro para uma lista encadeada e lista e
	o endereco do ponteiro externo para uma lista
	encadeada
	*/
	li = NULL;
	/*
	Inicializar o ponteiro externo � lista encadeada linear
	com o valor NULL
	*/
	return li;
}

Lista* alocaNo(){
	/*
	A fun��o getnode() aloca/cria um n� para uma lista encadeada.
	*/
	return (Lista *)malloc(sizeof(Lista));
}

void liberaNo(Lista *q){
	/*liberaNo
	Liberar o espa�o de mem�ria ocupado por um n�.
	*/
	free(q);
}

// Verificar se a lista encadeada est� vazia
int verificaVazia(Lista *li){
	/*
	li � o endere�o do primeiro n� da lista encadeada...
	*/
	if(li == NULL){
		return 1;
	}else{
		return 0;
	}
}

Lista* insereNoFinalLista(Lista *li,int x){
	Lista *q;
	Lista *aux;
	
	q = alocaNo(q);
	
	if(q != NULL){
		q->info = x;
		q->next = NULL;
		
		if(verificaVazia(li)){
			li = q;
		}else{
			// percorre a lista at� chegar no ultimo n�
			aux = li;
			while(aux->next != NULL){
				aux = aux->next;
			}
			aux->next = q;
			return li;
		}
	}else{
		printf("Erro na aloca��o de n�");
		return NULL;
	}
}

Lista* insereNoInicioLista(Lista *li,int x){
	Lista *q;
	q = alocaNo(q);
	if(q != li){
		q->info = x;
		q->next = li;
		li = q;
		return li;
	}else{
		printf("Erro na aloca��o de n�");
		return NULL;
	}
}

void exibeLista(Lista *li){
	Lista *aux;
	aux = li;
	
	while(aux != NULL){
		printf("%d \n",aux->info);
		aux->info;
	}
	printf("\n");
	
}

Lista* removeInicioLista(Lista *li){
	Lista *q;
	q = li;
	if(!verificaVazia(li)){
		li = q->next;
		liberaNo(q);
		return li;
	}else{
		printf("\n Erro: Lista Vazia!");
		return NULL;
	}
}

Lista *procuraValorLista(Lista *li,int x){
	Lista *q;
	if(!verificaVazia(li)){
		q = li;
		while(q != NULL){
			if(q->info == x){
				return q;
				// encontrou o no
			}
			q = q->next;
		}
		return NULL;
	}
}

Lista *removeValorEspecifico(Lista *li,int x){
	Lista *q;
	Lista *aux;
	
	if((q = procuraValorLista(li,x)) != NULL){
		aux = li;
		if(aux == q){
			removeInicioLista(li);
		}else{
			while(aux->next != q){
				aux = aux->next;
			}
			aux->next = q->next;
			liberaNo(q);
		}
		return li; // removeu
	}
	return NULL; // nao removeu!
}

int main(){
	/*
	ponteiro externo ptrlista que
	aponta para o primeiro n� da lista...
	Sendo ptrlista o endere�o da primeira c�lula ent�o
	- ptrlista->info � o conte�do do n� e
	- ptrlista->next � o endere�o da pr�ximo n�
	*/
	
	Lista *li = iniciaLista(li);
	li = insereNoInicioLista(li,8);
	li = insereNoInicioLista(li,9);
	li = insereNoInicioLista(li,12);
	exibeLista(li);
}
