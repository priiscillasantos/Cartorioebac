#include <stdio.h> //Biblioteca respons�vel por conversar com usu�rio.
#include <stdlib.h> //Biblioteca respons�vel por alocar espa�o em mem�ria.
#include <locale.h> //Biblioteca respons�vel por alocar texto por regi�o.
#include <string.h> //Biblioteca respons�vel por cuidar das strings.

int usuarioExiste(char *usuario) //Verifica se o usu�rio a ser cadastrado j� existe.
{
	char arquivoLinha[100];
    char conteudoUsuario[10];
    
    FILE *file = fopen("users.txt", "r"); //Faz a abertura do arquivo que contem as informa��es dos usu�rios. 
    if (file == NULL) //Verifica se o arquivo users.txt existe. 
	{
        return 0; // Arquivo n�o existe ainda, ent�o usu�rio n�o existe
    }

    while (fgets(arquivoLinha, sizeof(arquivoLinha), file)) //Loop que faz a leitura do arquivo linha por linha.
	{
        sscanf(arquivoLinha, "Usuario:%s", conteudoUsuario); 
        if (strcmp(usuario, conteudoUsuario) == 0) //Fun��o que faz a verifica��o se as informa��es s�o correspondentes.
		{
            fclose(file);
            return 1; // Sendo correspondente, usu�rio j� existe
        }
    }

    fclose(file);
    return 0; // N�o sendo, usu�rio n�o existe
}


int registroUsuario()//Fun��o para registro de um novo usu�rio.
{
	//Vari�veis respos�veis pelo armazenamento das informa��es que ser�o coletadas. 
	char usuario[10];
	char nomeCompleto[50];
	char email[50];
	char confirmaEmail[50];
	char senha[10];
	char confirmaSenha[10];
	
	while (1) 
	{
    	printf("\nDigite o nome do usu�rio que deseja cadastrar: ");
        scanf("%s", usuario); // Vari�vel que armazenar� o usu�rio que ser� criado.

        if (usuarioExiste(usuario)) //A fun��o de verifica��o ser� chamada usando como parametro a variavel usuario para verifica��o se o usuario digitado � existente. 
		{
            printf("\nNome de usu�rio j� existe. Tente novamente.\n\n"); //Retorna para usuario digitar outro nome de usuario.
        }
		else 
		{
            break; //Caso n�o exista, continuar� o cadastro. 
        }
    }
	
	FILE *file; 
	file = fopen("users.txt", "a");//Fun��o que ir� criar o arquivo que conter� as informa��es de login e usu�rio.
	fprintf(file,"Usuario:%s\n", usuario);
	fclose(file);
		
	printf("Digite o Nome completo do usu�rio que deseja cadastrar: ");
	scanf("%s", nomeCompleto); //V�riav�l que armazenar� o Nome completo do usu�rio que ser� criado.
	
	file = fopen("users.txt", "a");//Fun��o que ir� criar o arquivo que conter� as informa��es de login e usu�rio.
	fprintf(file,"Nome Completo:%s\n", nomeCompleto);
	fclose(file);
	
	while(1)
	{
		printf("Digite o email do usu�rio que deseja cadastrar: ");
		scanf("%s", email); //V�riav�l que armazenar� o email do usu�rio que ser� criado.
		printf("Digite novamente o email do usu�rio que deseja cadastrar: ");
		scanf("%s", confirmaEmail);
		
		if (strcmp (email,confirmaEmail) == 0) // Fun��o que far� a compara��o se os campos digitados est�o iguais.
		{
			file = fopen("users.txt", "a"); //A verifica��o sendo verdadeira, a senha ser� salva no arquivo.
			fprintf(file,"Email:%s\n", email);
			fclose(file);
			break;
		}
		else 
		{
			printf("Os endere�os de email n�o correspondem. Tente novamente\n");
		}
	}
		
	while(1)
	{
		printf("Digite a senha do usu�rio que deseja cadastrar: ");
		scanf("%s", senha); //V�riav�l que armazenar� o senha do usu�rio que ser� criado.
		printf("Digite novamente a senha do usu�rio que deseja cadastrar: ");
		scanf("%s", confirmaSenha);
		
		if (strcmp (senha,confirmaSenha) == 0)// Fun��o que far� a compara��o se os campos digitados est�o iguais.
		{
			file = fopen("users.txt", "a"); //A verifica��o sendo verdadeira, a senha ser� salva no arquivo.
			fprintf(file,"Senha:%s\n\n", senha);
			fclose(file);
			break;
		}
		else 
		{
			printf("As senhas n�o correspondem. Tente novamente\n");
		}
	}
	
	printf("\nUsu�rio criado com sucesso!\n\n");
	system("pause");
	
	
}

int loginUsuario() //Fun��o para efetuar o login no sistema.
{
	setlocale(LC_ALL, "Portuguese");//Comando que ir� procurar e definir a l�ngua que ser� executada.
	
	//Vari�veis respos�veis pelo armazenamento das informa��es que ser�o coletadas. 
	char arquivoLinha[100];
	char usuario[10];
	char senha[10];
	char conteudoUsuario[10];
	char conteudoSenha[10];
	int loginSucesso = 0;
	
	printf("\nDigite login de usu�rio: ");
	scanf("%s", usuario);
	printf("Digite senha do usu�rio: ");
	scanf("%s", senha);
	
	FILE *file;
	file = fopen("users.txt","r"); //Far� a abertura do arquivo user.txt e ent�o far� a leitura para verifica��o do login.
	
	while(fgets(arquivoLinha, sizeof(arquivoLinha), file)) //Fun��o de loop que lera linha por linha at� encontrar uma combina��o de usu�rio e senha. 
	{
		sscanf(arquivoLinha, "Usuario:%s", conteudoUsuario); //Extrai o nome de usu�rio da linha lida do arquivo, que deve estar no formato "Usuario: nome_do_usuario"
		if (strcmp(usuario, conteudoUsuario) == 0)//Faz a compara��o para validar se as informa��es de usuario coletada s�o iguais a que consta no arquivo users.txt. 
		{
			fgets(arquivoLinha, sizeof(arquivoLinha), file); //Pula a linha do nome completo.
			fgets(arquivoLinha, sizeof(arquivoLinha), file); //Pula a linha do email.
			fgets(arquivoLinha, sizeof(arquivoLinha), file); //L� a linha da senha.
			
			sscanf(arquivoLinha, "Senha:%s", conteudoSenha); // //Extrai o nome de usu�rio da linha lida do arquivo, que deve estar no formato "Senha: senha_do_usu�rio"
			if (strcmp(senha, conteudoSenha) == 0) //Faz a compara��o para validar se as informa��es de senha coletada s�o iguais a que consta no arquivo users.txt.
			{
				loginSucesso = 1; //Caso a verifica��o de usu�rio e sejam verdadeiros, o login ser� definido como 1 para indicar que foi bem-sucedido. 
				break;
			}
		}
	}
	
	fclose(file); //fecha o arquivo.
		
	if (loginSucesso)//Retornando loginsucesso = 1, ir� entrar no sistema.
	{
		printf("\nLogin bem-sucedido.\n\n");
		system("pause");
		return 1;
	}
	else //Do contrario, ser� mostrado uma mensagem de erro e solicitando que o usu�rio tente o login novamente. 
	{
		printf("\nUsu�rio ou Senhas incorretos! Tente novamente.\n\n");
		system("pause");
		return 0;
	}
}

int registro() //Fun��o que ser� executada quando a op��o do menu do sistema for 1.
{
 //Vari�veis respos�veis pelo armazenamento das informa��es que ser�o coletadas. 
	char arquivoRegistro [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40]; 
	
	printf(" Digite o CPF a ser cadastrado: "); //Pergunta ao usu�rio para realizar a coleta da informa��o desejada.
	scanf("%s", cpf); //Respons�vel pelo armazenamento da informa��o coletada. 
	
	strcpy(arquivoRegistro, cpf); //Respons�vel por copiar os valores de string, nesse caso o valor de cpf ser� copiado em arquivo.
	
	FILE *file; //Respons�vel por buscar o tipo de arquivo que ser� criado no banco de dados.
	file = fopen(arquivoRegistro, "w"); //O comando "w" � respons�vel por criar o tipo de arquivo informado em FILE *file.
	fprintf(file,"CPF:%s\n",cpf); //Respons�vel por salvar o valor coletado pela vari�vel.
	fclose(file); //Respons�vel por fechar o arquivo.
	
	printf(" Digite o Nome a ser cadastrado: "); 
	scanf("%s", nome); 
	
	file = fopen(arquivoRegistro, "a");
	fprintf(file,"Nome:%s\n", nome);
	fclose(file);
	
	printf(" Digite o Sobrenome a ser cadastrado: "); 
	scanf("%s", sobrenome); 
	
	file = fopen(arquivoRegistro, "a");
	fprintf(file,"Sobrenome:%s\n", sobrenome); 
	fclose(file);
	
	printf(" Digite o Cargo a ser cadastrado: "); 
	scanf("%s", cargo); 
	
	file = fopen(arquivoRegistro, "a");
	fprintf(file,"Cargo:%s", cargo); 
	fclose(file);  
	
	printf("\n");
	system("pause");	
}

int consulta() //Fun��o que ser� executada quando a op��o do menu do sistema for 2.
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

int deletar() //Fun��o que ser� executada quando a op��o a op��o do menu for 3.
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
	int autentificacao = 0; 
	
	while (!autentificacao)
	{
		int escolha;
		
		setlocale(LC_ALL, "Portuguese"); //Comando que ir� procurar e definir a l�ngua que ser� executada.
		system("cls");
		
		printf("---------- Cart�rio da Ebac ----------\n\n"); //In�cio do menu.
		printf("\t1. Registrar novo usu�rio\n");
        printf("\t2. Login\n");
        printf("\nEscolha uma op��o: ");
        scanf("%d", &escolha);
        
        switch (escolha)
        {
        	case 1:
        	registroUsuario();
        	break;
        	
        	case 2:
        	autentificacao = loginUsuario();
        	break;
        	
        	default:
        	printf("\nOp��o inv�lida! Tente novamente.\n\n");
        	system("pause");
        	break;
        }
	}
	
	while (laco == 1) //Estrutura de repeti��o usada para quando houver uma escolha de op��o o programa retorne ao menu.
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
