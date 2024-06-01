#include <stdio.h> //Biblioteca responsável por conversar com usuário.
#include <stdlib.h> //Biblioteca responsável por alocar espaço em memória.
#include <locale.h> //Biblioteca responsável por alocar texto por região.
#include <string.h> //Biblioteca responsável por cuidar das strings.

int registro() //Função que será executada quando a opção for 1.
{
 //Variáveis resposáveis pelo armazenamento das informações que serão coletadas. 
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40]; 
	
	printf(" Digite o CPF a ser cadastrado: "); //Pergunta ao usuário para realizar a coleta da informação desejada.
	scanf("%s", cpf); //Responsável pelo armazenamento da informação coletada. 
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores de string, nesse caso o valor de cpf será copiado em arquivo.
	
	FILE *file; //Responsável por buscar o tipo de arquivo que será criado no banco de dados.
	file = fopen(arquivo, "w"); //O comando "w" é responsável por criar o tipo de arquivo informado em FILE *file.
	fprintf(file,"CPF:%s",cpf); //Responsável por salvar o valor coletado pela variável.
	fclose(file); //Responsável por fechar o arquivo.
	
	file = fopen(arquivo, "a"); //O comando "a" é responsável por atualizar o arquivo file criado.
	fprintf(file, "\n"); //Será usado para fazer a separação das variáves que serão armazenadas no arquivo.
	fclose(file);
	
	printf(" Digite o Nome a ser cadastrado: "); 
	scanf("%s", nome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,"Nome:%s", nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf(" Digite o Sobrenome a ser cadastrado: "); 
	scanf("%s", sobrenome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,"Sobrenome:%s", sobrenome); 
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf(" Digite o Cargo a ser cadastrado: "); 
	scanf("%s", cargo); 
	
	file = fopen(arquivo, "a");
	fprintf(file,"Cargo:%s", cargo); 
	fclose(file);  
	
	printf("\n");
	system("pause");	
}

int consulta() //Função que será executada quando a opção for 2.
{
	setlocale(LC_ALL, "Portuguese"); //Comando que irá procurar e definir a língua que será executada.
	
	char cpf [40]; //Variável responsável por fazer a buscar no banco de dados ou pasta de armazenamento. 
	char conteudo [200]; //Váriável que será usado para armazenar o conteúdo da busca.
	
	printf(" Digite o CPF a ser consultado: "); //Pergunta ao usuário para realizar a coleta da informação desejada.
	scanf("%s", cpf); //Responsável pelo armazenamento da informação coletada.
	
	FILE *file;
	file = fopen(cpf, "r"); //Responsável por abrir o arquivo e fazer a leitura.
	
	if (file == NULL) //Estrutura usada para verificar se existem arquivos nulo, caso haja o programa retornará uma mensagem de erro para o usuário.
	{
		printf("\n\n Não foi possível abrir o arquivo, CPF não localizado!\n");
	}
	
	else //Se não houver erro o programa cairá nessa condição que trará o resultado da consulta.
	
	printf("\n Essas são as informações localizadas do usuário: \n\n");
	
	while (fgets(conteudo, 200, file) != NULL) //Estrutura que irá procurar as informações solicitadas na consulta enquanto file não for nulo, e as informações encontradas serão armazenadas na variável conteudo.
	{
		printf(" %s", conteudo); //Resposável por exibir as informações armazenadas na variável conteudo quando finalizar o laço while.
	}
	
	printf("\n\n");
	fclose(file); //Fechamento do arquivo que foi feito a leitura.
	system("pause");
}

int deletar() //Função que será executada quando a opção for 3.
{
	char cpf [40]; //Receberá o valor que será usado para buscar o cpf que será removido do banco de dados. 
	
	printf("Digite o CPF do usuário que deseja deletar: ");
	scanf("%s", cpf); //Recebe o valor a ser tratado.
	
	FILE *file;
	file = fopen(cpf, "r"); //Abrirá o arquivo cpf contido no banco de dados e fará a leitura deste arquivo.
			
	if (file == NULL) //Verifica se existe o arquivo no banco de dados, caso não exista retornará uma mensagem de erro ao usuario, do contrário cairá na condição else e fará a exclusão do arquivo. 
	{
		printf("\nO CPF do usuário não foi encontrado!\n\n");	
		system("pause");
	}
		
	else
	{
		fclose(file); //Responsavél por fechar o arquivo antes de removê-lo.
		if (remove(cpf) == 0) //Remove o arquivo do bancos de dados e verifica se a condição é verdadeira e retorna uma mensagem para usuário. 
		{
			printf("\nUsuario deletado com sucesso!\n\n");
			system("pause");
		}
	}
}


int main() //Função responsável por executrar o programa.
{
	int opcao = 0; //Variável que define a escolha do usuário no menu. 
	int laco = 1; //Variável que será executado no laço.
	
	for (laco = 1;laco = 1;) //Estrutura de repetição usada para quando houver uma escolha de opção o programa retorne ao menu.
	{
		
		system("cls"); //Limpa a tela quando o laço for executado.
		
		
		setlocale(LC_ALL, "Portuguese"); //Comando que irá procurar e definir a língua que será executada.
	
		printf("---------- Cartório da Ebac ----------\n\n"); //Início do menu.
		printf("  Escolha a opção desejada no menu:\n\n");
		printf("\t1- Registrar nomes.\n");
		printf("\t2- Consultar nomes.\n");
		printf("\t3- Deletar nomes.\n");
		printf("\t4- Sair do programa.\n\n");//Final do menu.	
	
		printf(" Digite a opção desejada: ");
		scanf("%d", &opcao); //Armazena a escolha do usuário.
		system("cls"); //Limpa a tela quando excutar o scanf.
		
		
		switch(opcao) //Início seleção.
		{
			case 1:
			registro();	//Função chamada para registrar nomes.
			break;
			
			case 2:
			consulta(); //Função chamada para consultar nomes.
			break;
			
			case 3: 
			deletar(); //Função chamada para deletar nomes. 
			break; 
			
			case 4:
			printf("Obrigado por utilizar o programa.\nSaindo do sistema...\n\n");
			return 0;
			break;
			
			default: 
				printf("\n Essa opção não está disponivél!\n\n");
				system("pause");
			break;			
		} //Fim seleção.
	}
}
