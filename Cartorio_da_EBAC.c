#include <stdio.h> //biblioteca de comunica��o com o usu�rio que funciona a fonte print
#include <stdlib.h> //biblioteca de aloca��o de mem�ria e espa�o
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar usu�rios
{
	//inicio cria��o de vari�veis/strings
	setlocale(LC_ALL, "Portuguese");
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	//final cria��o de vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado:   "); //coletando info do usu�rio
	scanf("%s", cpf); //%s refere-se a salvar as strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar valores das strings
	
	FILE *file; //chamando a fun��o file para criar um arquivo
	file = fopen (arquivo, "w"); //o arquivo aberto tem o nome que foi atribu�do e a op��o de editar com w de write
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
	file = fopen(cpf,"r"); //r � de read arquivos salvos em string cpf

	
	if(file==NULL)
	{
		printf ("\n\n Usu�rio n�o cadastrado. \n\n");
	}
	while (fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");
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
		printf("Usu�rio n�o se encontra no sistema. \n");
		system("pause");
		fclose(file);
	}
	
	else
	{
		fclose(file);
		remove(cpf); //fun��o da biblioteca

		printf("Usu�rio deletado do sistema. \n");
		system("pause");
	}
}
int main()
{
	int opcao=0; //int e cria uma vari�vel. No caso se chama op��o e volta em 0
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls"); //system "fala" com o sistema operacional. cls vai fazer com que msg que aparecia antes desapare�a
		setlocale(LC_ALL, "Portuguese"); //idioma e inclus�o de caracteres
		
		printf("### Cart�rio da EBAC ###\n\n"); //printf � a fun��o que apresenta o texto-mensagem ao usu�rio
		printf("Escolha a op��o desejada do menu:\n\n"); //fun��o \n pula linha
		printf ("\t 1 - Registrar nomes \n"); //fun��o \t da espa�o. Como um par�grafo.
		printf ("\t 2 - Consultar os nomes \n");
		printf ("\t 3 - Deletar os nomes \n\n");
		printf ("Op��o: ");
	
		scanf("%d", &opcao); //scanf l� a inclus�o do usu�rio. %d � uma vari�vel do tipo inteiro e depois referencia em qual vari�vel deve ser armazenada
	
		system("cls");
	
		switch(opcao) //v�rias escolhas
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
			printf("Essa op��o n�o est� dispon�vel. \n\n");
			system("pause");
			break;
		}
		
	
	}
}
