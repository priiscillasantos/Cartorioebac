#include <stdio.h> //Biblioteca respons�vel por conversar com usu�rio.
#include <stdlib.h> //Biblioteca respons�vel por alocar espa�o em mem�ria.
#include <locale.h> //Biblioteca respons�vel por alocar texto por regi�o.
#include <string.h> //Biblioteca respons�vel por cuidar das strings.

int registro() //Fun��o que ser� executada quando a op��o for 1.
{
 //Vari�veis respos�veis pelo armazenamento das informa��es que ser�o coletadas. 
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40]; 
	
	printf(" Digite o CPF a ser cadastrado: "); //Pergunta ao usu�rio para realizar a coleta da informa��o desejada.
	scanf("%s", cpf); //Respons�vel pelo armazenamento da informa��o coletada. 
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores de string, nesse caso o valor de cpf ser� copiado em arquivo.
	
	FILE *file; //Respons�vel por buscar o tipo de arquivo que ser� criado no banco de dados.
	file = fopen(arquivo, "w"); //O comando "w" � respons�vel por criar o tipo de arquivo informado em FILE *file.
	fprintf(file,"CPF:%s",cpf); //Respons�vel por salvar o valor coletado pela vari�vel.
	fclose(file); //Respons�vel por fechar o arquivo.
	
	file = fopen(arquivo, "a"); //O comando "a" � respons�vel por atualizar o arquivo file criado.
	fprintf(file, "\n"); //Ser� usado para fazer a separa��o das vari�ves que ser�o armazenadas no arquivo.
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

int consulta() //Fun��o que ser� executada quando a op��o for 2.
{
	setlocale(LC_ALL, "Portuguese"); //Comando que ir� procurar e definir a l�ngua que ser� executada.
	
	char cpf [40]; //Vari�vel respons�vel por fazer a buscar no banco de dados ou pasta de armazenamento. 
	char conteudo [200]; //V�ri�vel que ser� usado para armazenar o conte�do da busca.
	
	printf(" Digite o CPF a ser consultado: "); //Pergunta ao usu�rio para realizar a coleta da informa��o desejada.
	scanf("%s", cpf); //Respons�vel pelo armazenamento da informa��o coletada.
	
	FILE *file;
	file = fopen(cpf, "r"); //Respons�vel por abrir o arquivo e fazer a leitura.
	
	if (file == NULL) //Estrutura usada para verificar se existem arquivos nulo, caso haja o programa retornar� uma mensagem de erro para o usu�rio.
	{
		printf("\n\n N�o foi poss�vel abrir o arquivo, CPF n�o localizado!\n");
	}
	
	else //Se n�o houver erro o programa cair� nessa condi��o que trar� o resultado da consulta.
	
	printf("\n Essas s�o as informa��es localizadas do usu�rio: \n\n");
	
	while (fgets(conteudo, 200, file) != NULL) //Estrutura que ir� procurar as informa��es solicitadas na consulta enquanto file n�o for nulo, e as informa��es encontradas ser�o armazenadas na vari�vel conteudo.
	{
		printf(" %s", conteudo); //Respos�vel por exibir as informa��es armazenadas na vari�vel conteudo quando finalizar o la�o while.
	}
	
	printf("\n\n");
	fclose(file); //Fechamento do arquivo que foi feito a leitura.
	system("pause");
}

int deletar() //Fun��o que ser� executada quando a op��o for 3.
{
	char cpf [40]; //Receber� o valor que ser� usado para buscar o cpf que ser� removido do banco de dados. 
	
	printf("Digite o CPF do usu�rio que deseja deletar: ");
	scanf("%s", cpf); //Recebe o valor a ser tratado.
	
	FILE *file;
	file = fopen(cpf, "r"); //Abrir� o arquivo cpf contido no banco de dados e far� a leitura deste arquivo.
			
	if (file == NULL) //Verifica se existe o arquivo no banco de dados, caso n�o exista retornar� uma mensagem de erro ao usuario, do contr�rio cair� na condi��o else e far� a exclus�o do arquivo. 
	{
		printf("\nO CPF do usu�rio n�o foi encontrado!\n\n");	
		system("pause");
	}
		
	else
	{
		fclose(file); //Responsav�l por fechar o arquivo antes de remov�-lo.
		if (remove(cpf) == 0) //Remove o arquivo do bancos de dados e verifica se a condi��o � verdadeira e retorna uma mensagem para usu�rio. 
		{
			printf("\nUsuario deletado com sucesso!\n\n");
			system("pause");
		}
	}
}


int main() //Fun��o respons�vel por executrar o programa.
{
	int opcao = 0; //Vari�vel que define a escolha do usu�rio no menu. 
	int laco = 1; //Vari�vel que ser� executado no la�o.
	
	for (laco = 1;laco = 1;) //Estrutura de repeti��o usada para quando houver uma escolha de op��o o programa retorne ao menu.
	{
		
		system("cls"); //Limpa a tela quando o la�o for executado.
		
		
		setlocale(LC_ALL, "Portuguese"); //Comando que ir� procurar e definir a l�ngua que ser� executada.
	
		printf("---------- Cart�rio da Ebac ----------\n\n"); //In�cio do menu.
		printf("  Escolha a op��o desejada no menu:\n\n");
		printf("\t1- Registrar nomes.\n");
		printf("\t2- Consultar nomes.\n");
		printf("\t3- Deletar nomes.\n");
		printf("\t4- Sair do programa.\n\n");//Final do menu.	
	
		printf(" Digite a op��o desejada: ");
		scanf("%d", &opcao); //Armazena a escolha do usu�rio.
		system("cls"); //Limpa a tela quando excutar o scanf.
		
		
		switch(opcao) //In�cio sele��o.
		{
			case 1:
			registro();	//Fun��o chamada para registrar nomes.
			break;
			
			case 2:
			consulta(); //Fun��o chamada para consultar nomes.
			break;
			
			case 3: 
			deletar(); //Fun��o chamada para deletar nomes. 
			break; 
			
			case 4:
			printf("Obrigado por utilizar o programa.\nSaindo do sistema...\n\n");
			return 0;
			break;
			
			default: 
				printf("\n Essa op��o n�o est� disponiv�l!\n\n");
				system("pause");
			break;			
		} //Fim sele��o.
	}
}
