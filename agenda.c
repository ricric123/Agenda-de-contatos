#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 50
#include <string.h>

struct tipo_endereco{
	char rua[80], bairro[80];
	int num;
};

struct tipo_telefone{
	int ddd;
	char num[8];
};

struct tipo_contato{
	char nome[80];
	struct tipo_endereco end;
	struct tipo_telefone tel;
};

//variáveis globais
struct tipo_contato vet[TAM];
int cont;
//protótipo de função e procedimento
void addContato(char *nome, char *rua, int numE, char *bairro, int ddd, char *numT);
int getContato(char *nome);
void listarBairro(char *bairro);
int getQuantDDD(int ddd);
void listarTodos();

main(){
	setlocale(LC_ALL, "");
	//variáveis locais
	int op, ddd, numE, i, pos;
	cont=0;
	char nome[80], bairro[80], rua[80], numT[8];
	
	
	do{
		// apresentar as opções do menu
		system("cls");
		printf("# Agenda de contatos #\n\n");
		printf("1-inserir contato\n");
		printf("2-Consultar contato\n");
		printf("3-Listar contatos por bairro\n");
		printf("4-Consultar quantidade de contatos por ddd\n");
		printf("5-Listar todos\n");
		printf("6-Sair\n\n");
		printf("Opção: ");
		scanf("%d", &op);
		
		switch(op){
			case 1:		
				printf("Nome: ");
				fflush(stdin);
				gets(nome);
				printf("Rua: ");
				fflush(stdin);
				gets(rua);
				printf("Numero: ");
				scanf("%d", &numE);
				printf("Bairro: ");
				fflush(stdin);
				gets(bairro);
				printf("DDD: ");
				scanf("%d", &ddd);
				printf("Telefone: ");
				fflush(stdin);
				gets(numT);
				// CHAMADA DE PROCEDIMENTO addContato
				addContato(nome, rua, numE, bairro, ddd, numT);
				break;
			case 2:
				printf("Informe um nome: ");
				fflush(stdin);
				gets(nome);
				pos=getContato(nome);
				
				if(pos==-1){
					printf("Nome nao cadastrado.\n\n");
				}else {
					printf("Nome: %s\n", vet[pos].nome);
					printf("Rua: %s Numero: %d Bairro: %s\n", vet[pos].end.rua, vet[pos].end.num, vet[pos].end.bairro);
					printf("Telefone: (0%d) %s\n\n", vet[pos].tel.ddd, vet[pos].tel.num);
				}
				break;
			case 3:
				printf("Opção 3\n");
				break;
			case 4:
				printf("Opção 4\n");
				break;
			case 5:
				listarTodos();
				break;
			case 6:
				printf("Opção 6\n");
				break;
			default:
				printf("Opção invalida. Tente novamente.\n\n");							
		}
		
		getch();
		
	}while(op!=6);
}

//copiar os parâmetros de entrada para um posição específica do vetor
void addContato(char *nome, char *rua, int numE, char *bairro, int ddd, char *numT){
	//copiar o campo nome
	strcpy(vet[cont].nome,nome);
	
	//copiar os campos do endereço
	strcpy(vet[cont].end.rua, rua);
	vet[cont].end.num=numE;
	strcpy(vet[cont].end.bairro, bairro);
	
	//copiar os campos do telefone
	vet[cont].tel.ddd=ddd;
	strcpy(vet[cont].tel.num, numT);
	
	cont++;
}

void listarTodos(){
	int i;
	
	for(i=0;i<cont;i++){
		printf("Nome: %s\n", vet[i].nome);
		printf("Rua: %s Numero: %d Bairro: %s\n", vet[i].end.rua, vet[i].end.num, vet[i].end.bairro);
		printf("Telefone: (0%d) %s\n\n", vet[i].tel.ddd, vet[i].tel.num);
	}
}

int getContato(char *nome){
	int i;
	for(i=0;i<cont;i++){
		if(strcmp(vet[i].nome, nome)==0){
			return i;
		}
	}
	return -1;
}

void listarBairro(char *bairro){
	int i;
	for(i=0;i<cont;i++){
		if(strcmp(vet[i].end.bairro, bairro)==0){
			printf("Nome: %s\n", vet[i].nome);
		}
	}
}
