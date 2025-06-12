#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<limits.h>

/*
Contar quantas vezes um mesmo n�mero aparece, seja ele o maior ou o menor n�mero, armazenar num count

Usar a lista principal, tamanho dela e esse count para checar em quais posi��es os n�meros maiores e
menores est�o

Armazenar essas posi��es em um array, que ser� o retorno dessa fun��o

Na main, fazer uma checagem, se o count for =1, print normal, se for >1, printar o n�mero correspondente
(maior ou menor) e as posi��es em que ele aparece.

Entender tamb�m como a fun��o menor pega o menor n�mero de um array de n�meros negativos
*/

int maior(int x[], int tam){
    int numMaior = INT_MIN;
    for(int i = 0; i<tam; i++){
        if(x[i]>numMaior){
            numMaior = x[i];
        }
    }
    return numMaior;
}

int menor(int x[], int tam){
    int numMenor = INT_MAX;
    for(int i = 0; i<numMenor; i++){
        if(x[i]<numMenor){
            numMenor = x[i];
        }
    }
    return numMenor;
}

int pos(int x[], int tam, int num){
    for(int i=0; i<tam; i++){
        if(num == x[i]){
            return i+1;
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    /* Exerc�cio 1
    int qnt = 0;
    printf("Quantas idades voc� quer digitar: ");
    scanf("%d", &qnt);
    int *idades = (int*)calloc(qnt, sizeof(int));
    if(idades == NULL){
        printf("Deu erro!");
        return 1;
    }

    for(int i = 0; i<qnt ; i++){
        printf("Idade %d: ",i+1);
        scanf("%d", &idades[i]);
    }
    printf("\nIdades digitadas:\n");
    for(int i = 0; i<qnt ; i++){
        printf("Idade %d: %d\n",i+1, idades[i]);
    }

    free(idades);
    idades = NULL;
    */
    int qnt = 0;
    printf("Qual o tamanho do seu array: ");
    scanf("%d", &qnt);
    int *nums = (int*)calloc(qnt, sizeof(int));
    if(nums == NULL){
        printf("Deu erro!");
        return 1;
    }
    printf("Digite seus n�meros:\n");
    for(int i = 0; i<qnt ; i++){
        printf("Num %d: ",i+1);
        scanf("%d", &nums[i]);
    }
    printf("Maior n�mero � %d e est� na posi��o %d do array\n", maior(nums,qnt), pos(nums, qnt, maior(nums,qnt)));
    printf("Menor n�mero � %d e est� na posi��o %d do array\n", menor(nums,qnt), pos(nums, qnt, menor(nums,qnt)));

    free(nums);
    nums = NULL;

    system("Pause");
    return 0;
}
