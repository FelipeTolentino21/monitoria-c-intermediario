/* TIRAR DUVIDAS COM OS MONITORES:
DUVIDA 1. Na função de criar alunos, o fgets não está deixando inserir o nome
DUVIDA 2. Na mesma função ou na de exibir, os valores das notas não estão sendo inseridos/exibidos

*/
#include<stdio.h>
#include<stdlib.h>
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
    ptr->media= media;
}

Aluno criarAluno(){
    Aluno x;
    Aluno *ptr = &x;

    printf("Nome do aluno: ");
    fgets(x.nome, 50, stdin);
    printf("Matricula do aluno: ");
    scanf("%d", &x.matricula);
    printf("Idade do aluno: ");
    scanf("%d", &x.idade);
    for(int i; i<3; i++){
        printf("%dª nota do aluno: ",i+1);
        scanf("%d", &x.notas[i]);
    }
    calcularMedia(ptr);

    return x;
}

void exibirAluno(Aluno *x){
    printf("Nome: %s\n", x->nome);
    printf("Matricula: %d\n", x->matricula);
    printf("Idade: %d\n", x->idade);
    for(int i = 0; i<3; i++){
        printf("Nota %d: %.2f\n", i, x->notas[i]);
    }
    printf("Media das notas: %.2f\n", x->media);
}

void buscarAluno(Aluno turma[], int matricula){
    int check = 0;
    int tam = sizeof(turma)/sizeof(turma[0]);
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
    Aluno turma[tam];

    while(escolha != -1){
        printf("\nTurma %s\nDeseja:\n1. Adicionar alunos\n2. Buscar Aluno\n(-1 para sair)\nEscolha: ", nomeT);
        scanf("%d", &escolha);
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
            buscarAluno(turma, matri);
        } else if (escolha == -1){
            continue;
        } else {
            printf("Escolha inválida! Tente novamente!");
        }
        exibirAluno(&turma[count-1]); // USADO PARA CONFERIR SE TUDO ESTÁ CERTO (porque não ta)
    }

    system("Pause");
    return 0;
}
