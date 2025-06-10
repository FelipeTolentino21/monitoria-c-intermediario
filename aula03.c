#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/*
struct Pessoa{      // Maneira 1 de declara��o
// Ao criar o struct dessa maneira, voc� deve na main indicar que a sua refer�ncia � um struct,
// Por exemplo, ao definir uma pessoa, voc� deveria escrever: "struct Pessoa p1 (args)"
    char nome[50];
    int idade;
    float altura;
};
*/


typedef struct{      // Maneira 2 de declara��o
// Ao criar o struct dessa maneira, voc� n�o precisa indicar a refer�ncia de um struct,
// Por exemplo, ao definir uma pessoa, voc� pode escrever: "Pessoa p1 (args)"
    char nome[50];
    int idade;
    float altura;
} Pessoa;

// Passagem por valor (pega o valor atual e passa para manipular,
// ou seja, altera "localmente" o valor da vari�vel)
int modificarIdadeVal(Pessoa p){
    return p.idade = 100;
}

// Passagem por refer�ncia (entra no endere�o do ponteiro e altera na mem�ria)
void modificarIdadeRef(Pessoa *p){
    p->idade = 100;
}


int main(){
    setlocale(LC_ALL, "Portuguese");
    //              --------------- Conceitos iniciais ---------------
    // Declara��o e inicializa��o
    Pessoa p1 = {"Jo�o Silva", 25, 1.75};

    // Declara��o e atribui��o posterior
    Pessoa p2; // Maneira alternativa de declara��o
    strcpy(p2.nome, "Maria Santos");
    p2.idade = 30;
    p2.altura = 1.65;

    printf("Atribui��es iniciais:\n");

    // Acesso e � vari�vel
    printf("Pessoa 1: %s, %d anos, %.2fm\n", p1.nome, p1.idade, p1.altura);
    printf("Pessoa 2: %s, %d anos, %.2fm\n", p2.nome, p2.idade, p2.altura);


    //              --------------- Atribui��o e leitura ---------------
    Pessoa *ptr = &p1;

    // Duas formas de atribui��o
    ptr -> idade = 40; // Forma 1
    // (*ptr).idade = 25; // Forma 2

    printf("\nAtribui��o da idade usando ponteiros: \n");

    //Duas formas de leitura
    printf("A idade de p1 agora � %d\n", ptr->idade); // Forma 1
    // printf("%d\n", (*ptr).idade); // Forma 2


    printf("\nValor da idade de p1 ap�s passagem por valor:\n %d anos\n", modificarIdadeVal(p1));
    printf("Nota se que o valor n�o foi alterado na mem�ria:\n %d anos\n\n", p1.idade);

    modificarIdadeRef(ptr);
    printf("Valor da idade de p1 ap�s passagem por refer�ncia:\n %d anos\n", p1.idade);
    printf("Nota se que o valor foi alterado na mem�ria\n\n");

    system("Pause");
    return 0;
}
