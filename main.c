#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bruxo.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// scanf completo para string: "%[^\n]s"
// fflush(stdin)




void menu() {
    printf("\n=== Clinica Geralt de Rivia ===\n");
    printf("\n");
    printf("1. Bruxo\n");
    printf("2. Paciente\n");
    printf("3. Pocao\n");
    printf("4. Tratamento\n");
    printf("\n");
    printf("0. Sair\n");
}

void submenu() {
    printf("\n");
    printf("1. Listar\n");
    printf("2. Cadastrar\n");
    printf("3. Alterar\n");
    printf("4. Excluir\n");
    printf("\n");
    printf("0. Sair\n");
}

void submenuTratamento() {
    printf("\n");
    printf("1. Listar tratamentos do paciente\n");
    printf("2. Listar tratamentos do bruxo\n");
    printf("3. Iniciar tratamento\n");
    printf("4. Ampliar tratamento\n");
    printf("5. Excluir tratamento\n");
    printf("\n");
    printf("0. Sair\n");
}

void cadastrarBruxo() {
	Bruxo b1;
	
	printf("\nDigite o codigo do bruxo: ");
	scanf("%d", &b1.codigo);
	
	printf("\nDigite o nome do bruxo: ");
	fflush(stdin);
	scanf("%[^\n]s", &b1.nome);
	
	printf("\nDigite a especialidade do bruxo: ");
	fflush(stdin);
	scanf("%[^\n]s", &b1.especialidade);
	
	if (SalvarBruxo(&b1)) {
		printf("Bruxo salvo com sucesso.");
	} else {
		printf("ERROR");
	}
}

void listarBruxos() {
	int qtd = QuantidadeBruxos();
	Bruxo* ptr;
	ObterBruxoPeloCodigo(0, ptr);
	printf("\n%d", ptr);
	ptr[2].codigo = 2;
	printf("\n%d", ptr[2].codigo);

//	Bruxo* bruxos = (Bruxo*) malloc(qtd * sizeof(Bruxo));	
//	bruxos[0].codigo = 2;

//	printf("\n%u, %d", bruxos, bruxos[0].codigo);
//	Bruxo b[]
	
	for (int i = 0; i < qtd; i++) {	
//		ObterBruxoPeloIndice([i], ptr[i].codigo);
//		printf("Bruxo %d - Nome: %s | Especialidade: %s\n", i, BruxoNome[i], BruxoEspecialidade[i]);
	}
}

int main() {
	
	if (InicializarBruxos()) {
		printf("Bruxos Inicializados");
	}
	else {
		printf("ERROR");
	}
	
    int opcao, subopcao;
    do {
        menu();
        
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 0:
                printf("\nSaindo do programa ...\n");
                break;
            case 1:
				do {
					printf("\n=== Bruxo ===\n");
            		submenu();
            		
            		printf("\nDigite a opcao desejada: ");
        			scanf("%d", &subopcao);
        			
        			switch (subopcao) {
        				case 0:
        					printf("\nSaindo do submenu ...");
        					break;
        				case 1:
        					listarBruxos();
        					break;
        				case 2:
        					cadastrarBruxo();
        					break;
        				case 3:
        					break;
        				case 4:
        					break;
					}
				} while (subopcao != 0);
				
                break;
            case 2:	
            	do {
            		printf("\n=== Paciente ===\n");
            		submenu();
            		
            		printf("\nDigite a opcao desejada: ");
        			scanf("%d", &subopcao);
        			
        			switch (subopcao) {
        				case 0:
        					printf("\nSaindo do submenu ...");
        					break;
        				case 1:
        					break;
        				case 2:
        					break;
        				case 3:
        					break;
        				case 4:
        					break;
					}
				} while (subopcao != 0);
				
                break;
            case 3:
            	do {
            		printf("\n=== Pocao ===\n");
            		submenu();
            		
            		printf("\nDigite a opcao desejada: ");
        			scanf("%d", &subopcao);
        			
        			switch (subopcao) {
        				case 0:
        					printf("\nSaindo do submenu ...");
        					break;
        				case 1:
        					break;
        				case 2:
        					break;
        				case 3:
        					break;
        				case 4:
        					break;
					}
				} while (subopcao != 0);
				
                break;
            case 4:
            	do {
            		printf("\n=== Tratamento ===\n");
            		submenuTratamento();
            		
            		printf("\nDigite a opcao desejada: ");
        			scanf("%d", &subopcao);
        			
        			switch (subopcao) {
        				case 0:
        					printf("\nSaindo do submenu ...");
        					break;
        				case 1:
        					break;
        				case 2:
        					break;
        				case 3:
        					break;
        				case 4:
        					break;
					}
				} while (subopcao != 0);
            	
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        
        printf("\n");
        
    } while (opcao != 0);
    
    return 0;
}
