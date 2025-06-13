#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct{
    char nome[50];
    int matricula;
    int idade;
    float notas[3];
    float media;
} Aluno;

void calcularMedia(Aluno *ptr){
    float soma = 0;
    for(int i = 0; i<3; i++){
        soma += ptr->notas[i];
    }

    float media = (soma / 3.0);
    ptr->media = media;
}

Aluno criarAluno(){
    Aluno x;
    Aluno *ptr = &x;
    
    printf("Nome do aluno: ");
    fgets(x.nome, 50, stdin);	// As funções de scan, se o buffer não for limpo, armazenam o "enter", e o fgets é pulado
    x.nome[strcspn(x.nome, "\n")] = 0;	// strcspn procura a string do segundo parametro, iguala a 0 (remove) e retorna a x.nome
    printf("Matricula do aluno: ");
    scanf("%d", &x.matricula);
    while (getchar() != '\n');	// Limpa o buffer do teclado (removendo \n)
    printf("Idade do aluno: ");
    scanf("%d", &x.idade);
    while (getchar() != '\n'); 
    for(int i = 0; i<3; i++){
        printf("%dª nota do aluno: ",i+1);
        scanf("%f", &x.notas[i]);
        while (getchar() != '\n');
    }
    calcularMedia(ptr);

    return x;
}

void exibirAluno(Aluno *x){
    printf("Nome: %s\n", x->nome);
    printf("Matricula: %d\n", x->matricula);
    printf("Idade: %d\n", x->idade);
    for(int i = 0; i<3; i++){
        printf("Nota %d: %.2f\n", i+1, x->notas[i]);
    }
    printf("Media das notas: %.2f\n", x->media);
}

void buscarAluno(Aluno turma[], int matricula){
    int check = 0;
    int tam = sizeof(turma);
    for(int i = 0; i<tam; i++){
        if(turma[i].matricula == matricula){
            printf("Aluno encontrado! Suas informações:\n");
            exibirAluno(&turma[i]);
            check = 1;
            break;
        }
    }
    if(check == 0){
        printf("\nAluno não encontrado!\n");
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int count = 0;
    int tam = 0;
    int escolha = 0;
    int matri = 0;
    char nomeT[30];

    printf("Nome da turma: ");
    fgets(nomeT,30, stdin);

    printf("Qual o tamanho da sua turma: ");
    scanf("%d", &tam);
    while (getchar() != '\n');

    Aluno turma[tam];

    while(escolha != -1){
        printf("\nTurma %s\nDeseja:\n1. Adicionar alunos\n2. Buscar Aluno\n(-1 para sair)\nEscolha: ", nomeT);
        scanf("%d", &escolha);
        while (getchar() != '\n');
        printf("\n");
        if(escolha == 1){
            if(count < tam){
                turma[count] = criarAluno();
                count++;
            } else {
                printf("Sua turma está cheia!\n");
            }
        } else if (escolha == 2){
            printf("Qual a matrícula do seu aluno: ");
            scanf("%d", &matri);
            while (getchar() != '\n');
            buscarAluno(turma, matri);
        } else if (escolha == -1){
            continue;
        } else {
            printf("Escolha inválida! Tente novamente!");
        }
    }

    system("Pause");
    return 0;
}
