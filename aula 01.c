#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>  // Usado para trocar a lingua do compilador

int add(int a, int b){      // Usada no exemplo de função
    return a+b;
}
int mult(int a, int b){
    return a*b;
}


int main(){
	// 					====== RESUMO ======
	setlocale(LC_ALL, "Portuguese");	// Troca a lingua para português
	printf("Olá\n\n");

	/*					------ Exemplo de printf e scanf ------
	int num;

	printf("Digite um numero: ");
	scanf("%d", &num);
	printf("Numero digitado: %d", num);
	*/

	/*					------ Exemplo de uso com tabela ascii ------
	int num;

	printf("Digite um numero: ");
	scanf("%d", &num);
	printf("Numero digitado na tabela ascii: %c", num);  // Digite 104 por exemplo
	*/

	/*					------ Exemplo de uso de if e else ------
	int num;

	printf("Digite um numero: ");
	scanf("%d", &num);
	if(num<0){
		printf("Numero digitado e negativo");
	} else if(num>=10&&num<=20){
		printf("Numero digitado e maior ou igual a 10 e menor ou igual a 20");
	} else {
		printf("Numero digitado e maior que 20");
	}
	*/

	/*					------ Exemplo básico de for ------
	for(int i=1;i<=10;i++){
		printf("%d\n", i);
	}
	*/

	/*					------ Exemplo de vetor ------
	// Tem outros estilos de inicialização de vetor além do usado nesse exemplo, como:
	// int x[] = {1,2,3,4,5,6};		Usa tamanho automático
	// ou
	// int x[3];					Define os elementos conforme o índice
	//
	// int x[0] = 1;
	// int x[1] = 2;
	// int x[2] = 3;

	int x[6] = {1,2,3,4,5,6};
	for(int i=0;i<6;i++){
		printf("%d\n", x[i]);
	}
	*/

	/*					------ Exemplo de preenchimento de um vetor ------
	int x[6];
	printf("Preencha o vetor com 6 numeros\n");
	for(int i=0;i<6;i++){
		printf("Numero %d: ", i+1);
		scanf("%d", &x[i]);
	}
	printf("\n");
	for(int i=0;i<6;i++){
		printf("Numero na posição %d: %d\n", i, x[i]);
	}
    */

	/*					------ Exemplo de Strings usando fgets e fputs ------
	char nome[20] = "";

	printf("Digite seu nome: ");
	// char *fgets (char *str, int count, FILE *stream);
	fgets(nome, 20, stdin); // Tamanho da string, podia ser sizeof(nome),
                            // o fgets fecha a string automaticamente com '\0'
	printf("Seu nome é: ");
	// int fputs(const char *str, FILE *stream);
	fputs(nome, stdout);
    */

	/*					------ Exemplo de Strings pronta e print com for ------
	char str[6] = "Felipe\0";   // Vale-se notar que o "\0" é usado para fechar a string,
	for(int i=0;i<6;i++){       // não é obrigatório mas evita erros.
		printf("%c", str[i]);
	}
    */

    /*					------ Exemplo de Strings usando scanf("%s") e print com for ------
	char str[20] = "";

	printf("Digite seu nome: ");
	scanf("%s", &str);

	printf("Seu nome é: ");
	for(int i=0;i<6;i++){
		printf("%c", str[i]);
	}
    */

    /*					------ Exemplo de quanto ocupa uma string de char e um array de int ------
	int num[5];                     // Ambos vão ser 20 porque cada int ocupa 4 bytes,
	char string[20];                // por consequencia, um double ocupa 8 bytes, dando 40
	printf("%d\n", sizeof(num));
	printf("%d", sizeof(string));
    */

    /*					------ Atividade passada em sala (Contar quantas letra 'a' tem em Banana) ------
    char str[] = "Banana\0";
    int count = 0;
    for(int i=0;i<sizeof(str);i++){
        if(str[i] == 'a'){
            count++;
        }
    }
    printf("Existem %d letras 'a' em Banana", count);
    */

    /*					------ Atividade passada em sala (Trocar as letras maiúsculas e minúsculas) ------
    char str[40];

    printf("Digite algo: ");
    fgets(str, sizeof(str), stdin);

    for(int i=0;i<sizeof(str);i++){
        if(str[i]>=65&&str[i]<=90){
            str[i]+=32;
        } else if(str[i]>=97&&str[i]<=122) {
            str[i]-=32;
        }
    }
    printf("Seu texto com maiúsculas e minúsculas trocados é: ");
    fputs(str, stdout);
    */

    /* 					------ Exemplo de preenchimento e print de uma matriz ------
    float notas[3][5];
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<5;j++){
            printf("Digite nota [%d][%d]: ",i,j);
            scanf("%f", &notas[i][j]);
        }
    }
    for(i=0;i<3;i++){
            printf("\n");
        for(j=0;j<5;j++){
            printf("Nota [%d][%d]: %.1f\t",i,j, notas[i][j]);
        }
    }
    */

    /*					------ Exemplo de uso da função add ------
    int x = 2;
    int y = 2;
    printf("Soma de x + y: %d\n", add(x,y));
    */

    /*					------ Atividade passada em sala (Criar uma função que aceita 2 inteiros e retorna a multiplicação) ------
    int x,y;
    printf("Digite o 1º número: ");
    scanf("%d", &x);
    printf("Digite o 2º número: ");
    scanf("%d", &y);
    printf("Resultado de x*y: %d", mult(x,y));
    */

    system("pause");
	return 0;
}
