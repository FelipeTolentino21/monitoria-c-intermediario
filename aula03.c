#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

/*
struct Pessoa{      // Maneira 1 de declaração
// Ao criar o struct dessa maneira, você deve na main indicar que a sua referência é um struct,
// Por exemplo, ao definir uma pessoa, você deveria escrever: "struct Pessoa p1 (args)"
    char nome[50];
    int idade;
    float altura;
};
*/


typedef struct{      // Maneira 2 de declaração
// Ao criar o struct dessa maneira, você não precisa indicar a referência de um struct,
// Por exemplo, ao definir uma pessoa, você pode escrever: "Pessoa p1 (args)"
    char nome[50];
    int idade;
    float altura;
} Pessoa;

// Passagem por valor (pega o valor atual e passa para manipular,
// ou seja, altera "localmente" o valor da variável)
int modificarIdadeVal(Pessoa p){
    return p.idade = 100;
}

// Passagem por referência (entra no endereço do ponteiro e altera na memória)
void modificarIdadeRef(Pessoa *p){
    p->idade = 100;
}


int main(){
    setlocale(LC_ALL, "Portuguese");
    //              --------------- Conceitos iniciais ---------------
    // Declaração e inicialização
    Pessoa p1 = {"João Silva", 25, 1.75};

    // Declaração e atribuição posterior
    Pessoa p2; // Maneira alternativa de declaração
    strcpy(p2.nome, "Maria Santos");
    p2.idade = 30;
    p2.altura = 1.65;

    printf("Atribuições iniciais:\n");

    // Acesso e à variável
    printf("Pessoa 1: %s, %d anos, %.2fm\n", p1.nome, p1.idade, p1.altura);
    printf("Pessoa 2: %s, %d anos, %.2fm\n", p2.nome, p2.idade, p2.altura);


    //              --------------- Atribuição e leitura ---------------
    Pessoa *ptr = &p1;

    // Duas formas de atribuição
    ptr -> idade = 40; // Forma 1
    // (*ptr).idade = 25; // Forma 2

    printf("\nAtribuição da idade usando ponteiros: \n");

    //Duas formas de leitura
    printf("A idade de p1 agora é %d\n", ptr->idade); // Forma 1
    // printf("%d\n", (*ptr).idade); // Forma 2


    printf("\nValor da idade de p1 após passagem por valor:\n %d anos\n", modificarIdadeVal(p1));
    printf("Nota se que o valor não foi alterado na memória:\n %d anos\n\n", p1.idade);

    modificarIdadeRef(ptr);
    printf("Valor da idade de p1 após passagem por referência:\n %d anos\n", p1.idade);
    printf("Nota se que o valor foi alterado na memória\n\n");

    system("Pause");
    return 0;
}
