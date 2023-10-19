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
                printf("Saindo ...\n");
                break;
            case 1:
				do {
					printf("\n=== Bruxo ===\n");
            		submenu();
            		
            		printf("\nDigite a opcao desejada: ");
        			scanf("%d", &subopcao);
				} while (subopcao != 0);
				
                break;
            case 2:	
            	do {
            		printf("\n=== Paciente ===\n");
            		submenu();
            		
            		printf("\nDigite a opcao desejada: ");
        			scanf("%d", &subopcao);
				} while (subopcao != 0);
				
                break;
            case 3:
            	do {
            		printf("\n=== Pocao ===\n");
            		submenu();
            		
            		printf("\nDigite a opcao desejada: ");
        			scanf("%d", &subopcao);
				} while (subopcao != 0);
				
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        
        printf("\n");
        
    } while (opcao != 0);
    
    return 0;
}
