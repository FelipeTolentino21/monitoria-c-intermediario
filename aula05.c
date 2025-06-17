#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

// Defini��o do n�
typedef struct No{
    int dado;
    struct No* proximo;
} No;

// Defini��o da lista com n� cabe�a
typedef struct {
    No* cabeca; // N� cabe�a (n�o cont�m dados �teis)
    int tamanho;
} Lista;

Lista* criarLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if(lista == NULL){
        printf("Erro: N�o foi poss�vel alocar mem�ria para a lista\n");
        return NULL;
    }

    // Criar o n� cabe�a
    lista->cabeca = (No*)malloc(sizeof(No));
    if(lista->cabeca == NULL){
        printf("Erro: N�o foi poss�vel alocar mem�ria para a lista\n");
        free(lista);
        return NULL;
    }

    // O n� cabe�a n�o cont�m dados �teis
    lista->cabeca->dado = 0; // Valor irrelevante
    lista->cabeca->proximo = NULL;
    lista->tamanho = 0;

    return lista;
}

void inserirInicio(Lista* lista, int valor){
    if(lista == NULL){
        printf("Erro: Lista n�o existe\n");
        return;
    }

    No* novoNo = (No*)malloc(sizeof(No));
    if(novoNo == NULL){
        printf("Erro: n�o foi poss�vel alocar mem�ria\n");
        return;
    }

    novoNo->dado = valor;
    // O novo n� aponta para o que a cabe�a estava apontando
    novoNo->proximo = lista->cabeca->proximo;
    // A cabe�a agora aponta para o pr�ximo n�
    lista->cabeca->proximo = novoNo;
    lista->tamanho++;
}

void inserirFinal(Lista* lista, int valor){
    if(lista == NULL){
        printf("Erro: Lista n�o existe\n");
        return;
    }

    No* novoNo = (No*)malloc(sizeof(No));
    if(novoNo == NULL){
        printf("Erro: n�o foi poss�vel alocar mem�ria\n");
        return;
    }

    novoNo->dado = valor;
    novoNo->proximo = NULL;

    // Percorrer at� o final (come�ando da cabe�a)
    No* atual = lista->cabeca;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->proximo = novoNo;
    lista->tamanho++;
}

No* buscar(Lista* lista, int valor){
    if (lista == NULL) return NULL;

    // Come�ar do primeiro elemento real (ap�s a cabe�a)
    No* atual = lista->cabeca->proximo;
    while(atual != NULL){
        if(atual->dado == valor){
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL; // N�o encontrado
}

int remover(Lista* lista, int valor){
    if (lista == NULL){
        printf("Erro: Lista n�o existe\n");
        return 0;
    }

    // Come�ar da cabe�a para encontrar o n� anterior ao que ser� removido
    No* anterior = lista->cabeca;
    No* atual = anterior->proximo;

    while(atual != NULL){
        if (atual-> dado == valor){
            // Conectar o n� anterior ao pr�ximo, "pulando" o atual
            anterior->proximo = atual->proximo;
            free(atual);
            lista->tamanho--;
            return 1; // Sucesso
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0; // N�o encontrado
}

void liberarLista(Lista* lista){
    if(lista == NULL) return;

    No* atual = lista->cabeca;
    while (atual != NULL){
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(lista);
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    Lista* lista = criarLista();
    if (lista == NULL) return 1;

    inserirFinal(lista, 27);
    inserirInicio(lista, 1111);
    inserirFinal(lista, 27);
    inserirInicio(lista, 1);
    inserirInicio(lista, 48);

    No* encontrado = buscar(lista, 27);
    if(encontrado != NULL){
        printf("Econtrado: %d\n", encontrado->dado);
    }


    liberarLista(lista);
    system("Pause");
    return 0;
}
