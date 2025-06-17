#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

// Definição do nó
typedef struct No{
    int dado;
    struct No* proximo;
} No;

// Definição da lista com nó cabeça
typedef struct {
    No* cabeca; // Nó cabeça (não contém dados úteis)
    int tamanho;
} Lista;

Lista* criarLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    if(lista == NULL){
        printf("Erro: Não foi possível alocar memória para a lista\n");
        return NULL;
    }

    // Criar o nó cabeça
    lista->cabeca = (No*)malloc(sizeof(No));
    if(lista->cabeca == NULL){
        printf("Erro: Não foi possível alocar memória para a lista\n");
        free(lista);
        return NULL;
    }

    // O nó cabeça não contém dados úteis
    lista->cabeca->dado = 0; // Valor irrelevante
    lista->cabeca->proximo = NULL;
    lista->tamanho = 0;

    return lista;
}

void inserirInicio(Lista* lista, int valor){
    if(lista == NULL){
        printf("Erro: Lista não existe\n");
        return;
    }

    No* novoNo = (No*)malloc(sizeof(No));
    if(novoNo == NULL){
        printf("Erro: não foi possível alocar memória\n");
        return;
    }

    novoNo->dado = valor;
    // O novo nó aponta para o que a cabeça estava apontando
    novoNo->proximo = lista->cabeca->proximo;
    // A cabeça agora aponta para o próximo nó
    lista->cabeca->proximo = novoNo;
    lista->tamanho++;
}

void inserirFinal(Lista* lista, int valor){
    if(lista == NULL){
        printf("Erro: Lista não existe\n");
        return;
    }

    No* novoNo = (No*)malloc(sizeof(No));
    if(novoNo == NULL){
        printf("Erro: não foi possível alocar memória\n");
        return;
    }

    novoNo->dado = valor;
    novoNo->proximo = NULL;

    // Percorrer até o final (começando da cabeça)
    No* atual = lista->cabeca;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->proximo = novoNo;
    lista->tamanho++;
}

No* buscar(Lista* lista, int valor){
    if (lista == NULL) return NULL;

    // Começar do primeiro elemento real (após a cabeça)
    No* atual = lista->cabeca->proximo;
    while(atual != NULL){
        if(atual->dado == valor){
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL; // Não encontrado
}

int remover(Lista* lista, int valor){
    if (lista == NULL){
        printf("Erro: Lista não existe\n");
        return 0;
    }

    // Começar da cabeça para encontrar o nó anterior ao que será removido
    No* anterior = lista->cabeca;
    No* atual = anterior->proximo;

    while(atual != NULL){
        if (atual-> dado == valor){
            // Conectar o nó anterior ao próximo, "pulando" o atual
            anterior->proximo = atual->proximo;
            free(atual);
            lista->tamanho--;
            return 1; // Sucesso
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0; // Não encontrado
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
