#include<stdio.h>
#include<locale.h>

// ------------------- Usada no exemplo de passagem por refer�ncia -------------------
int mani(int *a, int *b){
    *a+=1;
    *b+=2;
    printf("%d\n", *a);
    printf("%d\n", *b);
}

// ------------------- Usada no exerc�cio 1 -------------------
void troca(int *a, int *b){
    int aux = *b;
    *a*=2;
    *b = *a;
    *a = aux*2;
}

// ------------------- Usada no exerc�cio 2 -------------------
int soma(int *vet, int n){
    int total = 0;
    for(int i=0;i<n;i++){
        total += *(vet + i);    // O ponteiro aponta para a primeira posi��o (indice 0) do vetor, usando o "+i" voc� controla qual posi��o est� referenciando.
                                // � a mesma coisa que usar "vet[i]"
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

    /* ------------------- Exemplo de passagem por refer�ncia -------------------
    int x = 0;
    int y = 5;
    int *px = &x;
    int *py = &y;
    mani(px, py);
    printf("\n%d %d", x, y);
    */

    /* ------------------- Exerc�cio 1 do slide (Fun��o que recebe dois ponteiros e troca os valores apontados pelo dobro da outra vari�vel) -------------------
    // O intu�to do exerc�cio era s� dobrar x e y usando os ponteiros associados a eles, mas eu troquei eles porque foi o que entendi do enunciado, n�o ta errado kkkk
    int x = 20;
    int y = 40;
    int z = 2;

    int *px = &x;
    int *py = &y;

    printf("Valores originais: %d %d", x , y);
    troca(px,py);
    printf("\n\nValores trocados e em dobro: %d %d\n", x , y);
    */

    /* ------------------- Exerc�cio 2 do slide (Crie uma fun��o que recebe um vetor (como ponteiro) e seu tamanho e retorna a soma dos elementos -------------------
    int x[] = {1,2,3,4,5};

    int tam = sizeof(x)/sizeof(x[0]);   // A explica��o para isso � que o tamanho do vetor � calculado em bytes, cada coisa que tem no vetor ocupa 4 bytes,
                                        // quando se usa o sizeof, ele pega essa quantidade em bytes, ent um vetor com 5 elementos tem 20 bytes, dividindo o
                                        // valor do primeiro sizeof, que sabe o valor todo, para um sizeof que mede 1 elemento s�, far� 20/4, que dar� o tamanho
                                        // correspondente do vetor
    printf("%d\n", soma(x, tam));
    */

    return 0;
}
