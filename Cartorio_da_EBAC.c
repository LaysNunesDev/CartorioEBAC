#include <stdio.h> //biblioteca de comunicação com o usuário que funciona a fonte print
#include <stdlib.h> //biblioteca de alocação de memória e espaço
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar usuários
{
	//inicio criação de variáveis/strings
	setlocale(LC_ALL, "Portuguese");
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//final criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado:   "); //coletando info do usuário
	scanf("%s", cpf); //%s refere-se a salvar as strings
	
	strcpy(arquivo, cpf); //responsável por copiar valores das strings
	
	FILE *file; //chamando a função file para criar um arquivo
	file = fopen (arquivo, "w"); //o arquivo aberto tem o nome que foi atribuído e a opção de editar com w de write
	fprintf(file, cpf); //printf que salva o texto no file
	fclose (file); //tem que fechar o arquivo
	
	file = fopen(arquivo, "a"); // abrindo o arquivo
	fprintf (file, ", ");
	fclose (file);
	
	printf("Digite o nome a ser cadastrado:  ");
	scanf("%s", nome);
	file = fopen(arquivo, "a");
	fprintf (file, nome);
	fclose (file);
	
	file = fopen(arquivo, "a"); // abrindo o arquivo
	fprintf (file, " ");
	fclose (file);
	
	printf("Digite o sobrenome a ser cadastrado:  ");
	scanf("%s", sobrenome);
	file = fopen(arquivo, "a");
	fprintf (file, sobrenome);
	fclose (file);
	
	file = fopen(arquivo, "a"); // abrindo o arquivo salvo na string arquivo
	fprintf (file, ", ");
	fclose (file);
	
	printf("Digite o cargo a ser cadastrado:  " );
	scanf("%s", cargo);
	file = fopen(arquivo, "a");
	fprintf (file, cargo);
	fclose (file);

	printf ("\n\n");
	system ("pause");
	
}
int consulta ()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:   ");
	scanf("%s", cpf);
	FILE *file;
	file = fopen(cpf,"r"); //r é de read arquivos salvos em string cpf

	
	if(file==NULL)
	{
		printf ("\n\n Usuário não cadastrado. \n\n");
	}
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
int deletar()
{
	char cpf[40];

	printf("Digite CPF a ser deletado:    ");
	scanf("%s", cpf); //ler arquivo

	FILE *file;
	file = fopen(cpf, "r");

	
	if(file== NULL)
	{
		printf("Usuário não se encontra no sistema. \n");
		system("pause");
		fclose(file);
	}
	
	else
	{
		fclose(file);
		remove(cpf); //função da biblioteca

		printf("Usuário deletado do sistema. \n");
		system("pause");
	}
}
int main()
{
	int opcao=0; //int e cria uma variável. No caso se chama opção e volta em 0
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //system "fala" com o sistema operacional. cls vai fazer com que msg que aparecia antes desapareça
		setlocale(LC_ALL, "Portuguese"); //idioma e inclusão de caracteres
		
		printf("### Cartório da EBAC ###\n\n"); //printf é a função que apresenta o texto-mensagem ao usuário
		printf("Escolha a opção desejada do menu:\n\n"); //função \n pula linha
		printf ("\t 1 - Registrar nomes \n"); //função \t da espaço. Como um parágrafo.
		printf ("\t 2 - Consultar os nomes \n");
		printf ("\t 3 - Deletar os nomes \n\n");
		printf ("Opção: ");
	
		scanf("%d", &opcao); //scanf lê a inclusão do usuário. %d é uma variável do tipo inteiro e depois referencia em qual variável deve ser armazenada
	
		system("cls");
	
		switch(opcao) //várias escolhas
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf ("Obrigada por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível. \n\n");
			system("pause");
			break;
		}
		
	
	}
}
