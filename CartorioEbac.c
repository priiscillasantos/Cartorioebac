#include <stdio.h> //Biblioteca responsável por conversar com usuário.
#include <stdlib.h> //Biblioteca responsável por alocar espaço em memória.
#include <locale.h> //Biblioteca responsável por alocar texto por região.
#include <string.h> //Biblioteca responsável por cuidar das strings.

int usuarioExiste(char *usuario) //Verifica se o usuário a ser cadastrado já existe.
{
	char arquivoLinha[100];
    char conteudoUsuario[10];
    
    FILE *file = fopen("users.txt", "r"); //Faz a abertura do arquivo que contem as informações dos usuários. 
    if (file == NULL) //Verifica se o arquivo users.txt existe. 
	{
        return 0; // Arquivo não existe ainda, então usuário não existe
    }

    while (fgets(arquivoLinha, sizeof(arquivoLinha), file)) //Loop que faz a leitura do arquivo linha por linha.
	{
        sscanf(arquivoLinha, "Usuario:%s", conteudoUsuario); 
        if (strcmp(usuario, conteudoUsuario) == 0) //Função que faz a verificação se as informações são correspondentes.
		{
            fclose(file);
            return 1; // Sendo correspondente, usuário já existe
        }
    }

    fclose(file);
    return 0; // Não sendo, usuário não existe
}


int registroUsuario()//Função para registro de um novo usuário.
{
	//Variáveis resposáveis pelo armazenamento das informações que serão coletadas. 
	char usuario[10];
	char nomeCompleto[50];
	char email[50];
	char confirmaEmail[50];
	char senha[10];
	char confirmaSenha[10];
	
	while (1) 
	{
    	printf("\nDigite o nome do usuário que deseja cadastrar: ");
        scanf("%s", usuario); // Variável que armazenará o usuário que será criado.

        if (usuarioExiste(usuario)) //A função de verificação será chamada usando como parametro a variavel usuario para verificação se o usuario digitado é existente. 
		{
            printf("\nNome de usuário já existe. Tente novamente.\n\n"); //Retorna para usuario digitar outro nome de usuario.
        }
		else 
		{
            break; //Caso não exista, continuará o cadastro. 
        }
    }
	
	FILE *file; 
	file = fopen("users.txt", "a");//Função que irá criar o arquivo que conterá as informações de login e usuário.
	fprintf(file,"Usuario:%s\n", usuario);
	fclose(file);
		
	printf("Digite o Nome completo do usuário que deseja cadastrar: ");
	scanf("%s", nomeCompleto); //Váriavél que armazenará o Nome completo do usuário que será criado.
	
	file = fopen("users.txt", "a");//Função que irá criar o arquivo que conterá as informações de login e usuário.
	fprintf(file,"Nome Completo:%s\n", nomeCompleto);
	fclose(file);
	
	while(1)
	{
		printf("Digite o email do usuário que deseja cadastrar: ");
		scanf("%s", email); //Váriavél que armazenará o email do usuário que será criado.
		printf("Digite novamente o email do usuário que deseja cadastrar: ");
		scanf("%s", confirmaEmail);
		
		if (strcmp (email,confirmaEmail) == 0) // Função que fará a comparação se os campos digitados estão iguais.
		{
			file = fopen("users.txt", "a"); //A verificação sendo verdadeira, a senha será salva no arquivo.
			fprintf(file,"Email:%s\n", email);
			fclose(file);
			break;
		}
		else 
		{
			printf("Os endereços de email não correspondem. Tente novamente\n");
		}
	}
		
	while(1)
	{
		printf("Digite a senha do usuário que deseja cadastrar: ");
		scanf("%s", senha); //Váriavél que armazenará o senha do usuário que será criado.
		printf("Digite novamente a senha do usuário que deseja cadastrar: ");
		scanf("%s", confirmaSenha);
		
		if (strcmp (senha,confirmaSenha) == 0)// Função que fará a comparação se os campos digitados estão iguais.
		{
			file = fopen("users.txt", "a"); //A verificação sendo verdadeira, a senha será salva no arquivo.
			fprintf(file,"Senha:%s\n\n", senha);
			fclose(file);
			break;
		}
		else 
		{
			printf("As senhas não correspondem. Tente novamente\n");
		}
	}
	
	printf("\nUsuário criado com sucesso!\n\n");
	system("pause");
	
	
}

int loginUsuario() //Função para efetuar o login no sistema.
{
	setlocale(LC_ALL, "Portuguese");//Comando que irá procurar e definir a língua que será executada.
	
	//Variáveis resposáveis pelo armazenamento das informações que serão coletadas. 
	char arquivoLinha[100];
	char usuario[10];
	char senha[10];
	char conteudoUsuario[10];
	char conteudoSenha[10];
	int loginSucesso = 0;
	
	printf("\nDigite login de usuário: ");
	scanf("%s", usuario);
	printf("Digite senha do usuário: ");
	scanf("%s", senha);
	
	FILE *file;
	file = fopen("users.txt","r"); //Fará a abertura do arquivo user.txt e então fará a leitura para verificação do login.
	
	while(fgets(arquivoLinha, sizeof(arquivoLinha), file)) //Função de loop que lera linha por linha até encontrar uma combinação de usuário e senha. 
	{
		sscanf(arquivoLinha, "Usuario:%s", conteudoUsuario); //Extrai o nome de usuário da linha lida do arquivo, que deve estar no formato "Usuario: nome_do_usuario"
		if (strcmp(usuario, conteudoUsuario) == 0)//Faz a comparação para validar se as informações de usuario coletada são iguais a que consta no arquivo users.txt. 
		{
			fgets(arquivoLinha, sizeof(arquivoLinha), file); //Pula a linha do nome completo.
			fgets(arquivoLinha, sizeof(arquivoLinha), file); //Pula a linha do email.
			fgets(arquivoLinha, sizeof(arquivoLinha), file); //Lê a linha da senha.
			
			sscanf(arquivoLinha, "Senha:%s", conteudoSenha); // //Extrai o nome de usuário da linha lida do arquivo, que deve estar no formato "Senha: senha_do_usuário"
			if (strcmp(senha, conteudoSenha) == 0) //Faz a comparação para validar se as informações de senha coletada são iguais a que consta no arquivo users.txt.
			{
				loginSucesso = 1; //Caso a verificação de usuário e sejam verdadeiros, o login será definido como 1 para indicar que foi bem-sucedido. 
				break;
			}
		}
	}
	
	fclose(file); //fecha o arquivo.
		
	if (loginSucesso)//Retornando loginsucesso = 1, irá entrar no sistema.
	{
		printf("\nLogin bem-sucedido.\n\n");
		system("pause");
		return 1;
	}
	else //Do contrario, será mostrado uma mensagem de erro e solicitando que o usuário tente o login novamente. 
	{
		printf("\nUsuário ou Senhas incorretos! Tente novamente.\n\n");
		system("pause");
		return 0;
	}
}

int registro() //Função que será executada quando a opção do menu do sistema for 1.
{
 //Variáveis resposáveis pelo armazenamento das informações que serão coletadas. 
	char arquivoRegistro [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40]; 
	
	printf(" Digite o CPF a ser cadastrado: "); //Pergunta ao usuário para realizar a coleta da informação desejada.
	scanf("%s", cpf); //Responsável pelo armazenamento da informação coletada. 
	
	strcpy(arquivoRegistro, cpf); //Responsável por copiar os valores de string, nesse caso o valor de cpf será copiado em arquivo.
	
	FILE *file; //Responsável por buscar o tipo de arquivo que será criado no banco de dados.
	file = fopen(arquivoRegistro, "w"); //O comando "w" é responsável por criar o tipo de arquivo informado em FILE *file.
	fprintf(file,"CPF:%s\n",cpf); //Responsável por salvar o valor coletado pela variável.
	fclose(file); //Responsável por fechar o arquivo.
	
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

int consulta() //Função que será executada quando a opção do menu do sistema for 2.
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

int deletar() //Função que será executada quando a opção a opção do menu for 3.
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
	int autentificacao = 0; 
	
	while (!autentificacao)
	{
		int escolha;
		
		setlocale(LC_ALL, "Portuguese"); //Comando que irá procurar e definir a língua que será executada.
		system("cls");
		
		printf("---------- Cartório da Ebac ----------\n\n"); //Início do menu.
		printf("\t1. Registrar novo usuário\n");
        printf("\t2. Login\n");
        printf("\nEscolha uma opção: ");
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
        	printf("\nOpção inválida! Tente novamente.\n\n");
        	system("pause");
        	break;
        }
	}
	
	while (laco == 1) //Estrutura de repetição usada para quando houver uma escolha de opção o programa retorne ao menu.
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
