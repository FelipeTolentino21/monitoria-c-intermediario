#include<stdio.h>
#include<locale.h>

// ------------------- Usada no exemplo de passagem por referência -------------------
int mani(int *a, int *b){
    *a+=1;
    *b+=2;
    printf("%d\n", *a);
    printf("%d\n", *b);
}

// ------------------- Usada no exercício 1 -------------------
void troca(int *a, int *b){
    int aux = *b;
    *a*=2;
    *b = *a;
    *a = aux*2;
}

// ------------------- Usada no exercício 2 -------------------
int soma(int *vet, int n){
    int total = 0;
    for(int i=0;i<n;i++){
        total += *(vet + i);    // O ponteiro aponta para a primeira posição (indice 0) do vetor, usando o "+i" você controla qual posição está referenciando.
                                // É a mesma coisa que usar "vet[i]"
    }
    return total;
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    /* ------------------- Exemplo de ponteiro -------------------
    int x = 10;
    int *p = &x;

    printf("%d", *p);  // Imprime 10
    */

    /* ------------------- Exemplo de passagem por referência -------------------
    int x = 0;
    int y = 5;
    int *px = &x;
    int *py = &y;
    mani(px, py);
    printf("\n%d %d", x, y);
    */

    /* ------------------- Exercício 1 do slide (Função que recebe dois ponteiros e troca os valores apontados pelo dobro da outra variável) -------------------
    // O intuíto do exercício era só dobrar x e y usando os ponteiros associados a eles, mas eu troquei eles porque foi o que entendi do enunciado, não ta errado kkkk
    int x = 20;
    int y = 40;
    int z = 2;

    int *px = &x;
    int *py = &y;

    printf("Valores originais: %d %d", x , y);
    troca(px,py);
    printf("\n\nValores trocados e em dobro: %d %d\n", x , y);
    */

    /* ------------------- Exercício 2 do slide (Crie uma função que recebe um vetor (como ponteiro) e seu tamanho e retorna a soma dos elementos -------------------
    int x[] = {1,2,3,4,5};

    int tam = sizeof(x)/sizeof(x[0]);   // A explicação para isso é que o tamanho do vetor é calculado em bytes, cada coisa que tem no vetor ocupa 4 bytes,
                                        // quando se usa o sizeof, ele pega essa quantidade em bytes, ent um vetor com 5 elementos tem 20 bytes, dividindo o
                                        // valor do primeiro sizeof, que sabe o valor todo, para um sizeof que mede 1 elemento só, fará 20/4, que dará o tamanho
                                        // correspondente do vetor
    printf("%d\n", soma(x, tam));
    */

    return 0;
}
