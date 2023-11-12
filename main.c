#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Bruxo.h"
#include "Paciente.h"
#include "Pocao.h"
#include "Tratamento.h"

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
	Bruxo bruxo;
	
	printf("\nDigite o codigo do bruxo: ");
	scanf("%d", &bruxo.codigo);
	
	printf("\nDigite o nome do bruxo: ");
	fflush(stdin);
	scanf("%[^\n]s", &bruxo.nome);
	
	printf("\nDigite a especialidade do bruxo: ");
	fflush(stdin);
	scanf("%[^\n]s", &bruxo.especialidade);
	
	if (SalvarBruxo(bruxo)) {
		printf("\nBruxo salvo com sucesso.");
	} else {
		printf("\nERROR");
	}
}

void listarBruxos() {
	int qtd = QuantidadeBruxos();
	Bruxo bruxo[qtd];
	
	printf("\nBruxos:");
	for (int i = 0; i < qtd; i++) {	
		ObterBruxoPeloIndice(i, &bruxo);
		printf("\nBruxo %d - Codigo: %d | Nome: %s | Especialidade: %s", i, bruxo->codigo, bruxo->nome, bruxo->especialidade);
	}
}

void excluirBruxo() {
	listarBruxos();
	
	int cod;
	printf("\nDigite o codigo do bruxo: ");
	scanf("%d", &cod);
	
	if (ApagarBruxoPeloCodigo(cod)) {
		printf("\nBruxo excluido com sucesso.");
	} else {
		printf("\nERROR");
	}
}

void alterarBruxo() {
	listarBruxos();
	
	Bruxo bruxo;
	printf("\nDigite o codigo do bruxo a ser alterado: ");
	scanf("%d", &bruxo.codigo);
	
	printf("\nDigite o novo nome do bruxo: ");
	fflush(stdin);
	scanf("%[^\n]s", &bruxo.nome);
	
	printf("\nDigite a nova especialidade do bruxo: ");
	fflush(stdin);
	scanf("%[^\n]s", &bruxo.especialidade);
	
	if (AtualizarBruxo(bruxo)) {
		printf("\nBruxo alterado com sucesso.");
	} else {
		printf("\nERROR");
	}
}

void cadastrarPaciente() {
	Paciente paciente;
	
	printf("\nDigite o codigo do paciente: ");
	scanf("%d", &paciente.codigo);
	
	printf("\nDigite o nome do paciente: ");
	fflush(stdin);
	scanf("%[^\n]s", &paciente.nome);
	
	printf("\nDigite a idade do paciente: ");
	scanf("%d", &paciente.idade);
	
	printf("\nDigite a altura do paciente: ");
	scanf("%f", &paciente.altura);
	
	if (SalvarPaciente(paciente)) {
		printf("\nPaciente salvo com sucesso.");
	} else {
		printf("\nERROR");
	}
}

void listarPacientes() {
	int qtd = QuantidadePacientes();
	Paciente paciente[qtd];
	
	printf("\nPacientes:");
	for (int i = 0; i < qtd; i++) {	
		ObterPacientePeloIndice(i, &paciente);
		printf("\nPaciente %d - Codigo: %d | Nome: %s | Idade: %d | Altura: %.2f", i, paciente->codigo, paciente->nome, paciente->idade, paciente->altura);
	}
}

void excluirPaciente() {
	listarPacientes();
	
	int cod;
	printf("\nDigite o codigo do paciente: ");
	scanf("%d", &cod);
	
	if (ApagarPacientePeloCodigo(cod)) {
		printf("\nPaciente excluido com sucesso.");
	} else {
		printf("ERROR");
	}
}

void alterarPaciente() {
	listarPacientes();
	
	Paciente paciente;
	printf("\nDigite o codigo do paciente a ser alterado: ");
	scanf("%d", &paciente.codigo);
	
	printf("\nDigite o novo nome do paciente: ");
	fflush(stdin);
	scanf("%[^\n]s", &paciente.nome);
	
	printf("\nDigite a nova idade do paciente: ");
	scanf("%d", &paciente.idade);
	
	printf("\nDigite a nova altura do paciente: ");
	scanf("%f", &paciente.altura);
	
	if (AtualizarPaciente(paciente)) {
		printf("\nPaciente alterado com sucesso.");
	} else {
		printf("\nERROR");
	}
}

void cadastrarPocao() {
	Pocao pocao;
	
	printf("\nDigite o codigo da pocao: ");
	scanf("%d", &pocao.codigo);
	
	printf("\nDigite o nome da pocao: ");
	fflush(stdin);
	scanf("%[^\n]s", &pocao.nome);
	
	printf("\nDigite o tipo da pocao: ('Liquido' ou 'Comprimido'): ");
	fflush(stdin);
	char tipo[11];
	scanf("%s", &tipo);
	strcpy(pocao.tipo, tipo);

	if (strcmp(tipo, "Liquido") == 0) {
		if (SalvarPocao(pocao)) {
			printf("\nPocao salva com sucesso.");
		} else {
			printf("\nERROR");
		}
	}
	else if (strcmp(tipo, "Comprimido") == 0) {
		if (SalvarPocao(pocao)) {
			printf("\nPocao salva com sucesso.");
		} else {
			printf("\nERROR");
		}
	}
	else {
		printf("\nTipo de pocao invalido, tente novamente.");
	}
	
}

void listarPocoes() {
	int qtd = QuantidadePocoes();
	Pocao pocao[qtd];
	
	printf("\nPocoes:");
	for (int i = 0; i < qtd; i++) {	
		ObterPocaoPeloIndice(i, &pocao);
		printf("\nPocao %d - Codigo: %d | Nome: %s | Tipo: %s", i, pocao->codigo, pocao->nome, pocao->tipo);
	}
}

void excluirPocao() {
	listarPocoes();
	
	int cod;
	printf("\nDigite o codigo da pocao: ");
	scanf("%d", &cod);
	
	if (ApagarPocaoPeloCodigo(cod)) {
		printf("\nPocao excluido com sucesso.");
	} else {
		printf("ERROR");
	}
}

void alterarPocao() {
	listarPocoes();
	
	Pocao pocao;
	printf("\nDigite o codigo da pocao a ser alterada: ");
	scanf("%d", &pocao.codigo);
	
	printf("\nDigite o novo nome da pocao: ");
	fflush(stdin);
	scanf("%[^\n]s", &pocao.nome);
	
	printf("\nDigite o novo tipo da pocao: ('Liquido' ou 'Comprimido'): ");
	fflush(stdin);
	scanf("%[^\n]s", &pocao.tipo);
	

	if ((strcmp(pocao.tipo, "Liquido") == 0) || (strcmp(pocao.tipo, "Comprimido") == 0)) {
		if (AtualizarPocao(pocao)) {
			printf("\nPocao alterado com sucesso.");
		} else {
			printf("\nERROR");
		}
	}
	else {
		printf("\nTipo de pocao invalido, tente novamente.");
	}		
}

void listarTratamentosDoPaciente() {
	int qtd = QuantidadeTratamentos();
	Tratamento tratamento;
	
	int codigo;
	
	printf("\nDigite o codigo do paciente: ");
	fflush(stdin);
	scanf("%d", &codigo);
	
	for (int i = 0; i < qtd; i++) {
		ObterTratamentoPeloIndice(i, &tratamento);
		if (tratamento.paciente == codigo) {
			
			Paciente paciente;	
			if (ObterPacientePeloCodigo(tratamento.paciente, &paciente)) {
	//			printf("\nDEBUG: %s", paciente.nome);
			} else {
				printf("\nerror");
			}
			
			Bruxo bruxo;	
			if (ObterBruxoPeloCodigo(tratamento.bruxo, &bruxo)) {
	//			printf("\nDEBUG: %s", bruxo.nome);
			} else {
				printf("\nerror");
			}
			
			Pocao pocao;
			if (ObterPocaoPeloCodigo(tratamento.medicamento, &pocao)) {
	//			printf("\nDEBUG: %s", pocao.nome);
			} else {
				printf("\nerror");
			}
			
			printf("\nOla %s! O bruxo %s receitou a pocao %s em dosagens de %d vezes por %d dias.", paciente.nome, bruxo.nome, pocao.nome, tratamento.dosagem, tratamento.dias);
		} else {
			printf("\nerror");
		}
	}
}

void listarTratamentosDoBruxo() {
	int qtd = QuantidadeTratamentos();
	Tratamento tratamento;
	
	int codigo;
	
	printf("\nDigite o codigo do bruxo: ");
	fflush(stdin);
	scanf("%d", &codigo);
	
	for (int i = 0; i < qtd; i++) {
		ObterTratamentoPeloIndice(i, &tratamento);
		if (tratamento.bruxo == codigo) {
			
			Paciente paciente;	
			if (ObterPacientePeloCodigo(tratamento.paciente, &paciente)) {
	//			printf("\nDEBUG: %s", paciente.nome);
			} else {
				printf("\nerror");
			}
			
			Bruxo bruxo;	
			if (ObterBruxoPeloCodigo(tratamento.bruxo, &bruxo)) {
	//			printf("\nDEBUG: %s", bruxo.nome);
			} else {
				printf("\nerror");
			}
			
			Pocao pocao;
			if (ObterPocaoPeloCodigo(tratamento.medicamento, &pocao)) {
	//			printf("\nDEBUG: %s", pocao.nome);
			} else {
				printf("\nerror");
			}
			
			printf("\nTratamento %d - Bruxo: %s | Paciente: %s | Medicamento: %s | Dias: %d | Dosagem: %d | \n", i, bruxo.nome, paciente.nome, pocao.nome, tratamento.dias, tratamento.dosagem);
		} else {
			printf("\nerror");
		}
	}
}

void iniciarTratamento() {
	
	Tratamento tratamento;
	
	printf("\nDigite o codigo do tratamento: ");
	fflush(stdin);
	scanf("%d", &tratamento.codigo);
	
	printf("\nDigite o codigo do bruxo: ");
	fflush(stdin);
	scanf("%d", &tratamento.bruxo);
	
	printf("\nDigite o codigo do paciente: ");
	fflush(stdin);
	scanf("%d", &tratamento.paciente);
	
	printf("\nDigite o codigo do medicamento: ");
	fflush(stdin);
	scanf("%d", &tratamento.medicamento);
	
	printf("\nDigite quantos dias: ");
	fflush(stdin);
	scanf("%d", &tratamento.dias);
	
	printf("\nDigite qual a dosagem: ");
	fflush(stdin);
	scanf("%d", &tratamento.dosagem);
	
	if (salvarTratamento(tratamento)) {
//		printf("\nDEBUG: Deu certo!!!");
	} else {
		printf("\nerror");
	}
	
}

void ampliarTratamento() {
	int qtd = QuantidadeTratamentos();
	Tratamento tratamento;
	
	int codigo;
	printf("\nDigite o codigo do paciente: ");
	fflush(stdin);
	scanf("%d", &codigo);
	
	for (int i = 0; i < qtd; i++) {
		ObterTratamentoPeloIndice(i, &tratamento);
		if (tratamento.paciente == codigo) {
			printf("\nAlterar para quantos dias?: ");
			fflush(stdin);
			scanf("%d", &tratamento.dias);
			
			printf("\nAlterar para quantas dosagens?: ");
			fflush(stdin);
			scanf("%d", &tratamento.dosagem);
			
			if (AtualizarTratamento(tratamento)) {
//				printf("\nDEBUG: deu certo");
			}
		} else {
			printf("\nERROR");
		}
	}
	
}

void excluirTratamento() {	
	int cod;
	printf("\nDigite o codigo do tratamento: ");
	scanf("%d", &cod);
	
	if (ApagarTratamentoPeloCodigo(cod)) {
		printf("Tratamento excluido com sucesso.");
	} else {
		printf("ERROR");
	}
}

int main() {
	
	if (!InicializarBruxos())
		return;
	if (!InicializarPacientes())
		return;
	if (!InicializarPocoes())
		return;
	if (!InicializarTratamentos())
		return;
		
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
        					alterarBruxo();
        					break;
        				case 4:
        					excluirBruxo();
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
        					listarPacientes();
        					break;
        				case 2:
        					cadastrarPaciente();
        					break;
        				case 3:
        					alterarPaciente();
        					break;
        				case 4:
        					excluirPaciente();
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
        					listarPocoes();
        					break;
        				case 2:
        					cadastrarPocao();
        					break;
        				case 3:
        					alterarPocao();
        					break;
        				case 4:
        					excluirPocao();
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
        					listarTratamentosDoPaciente();
        					break;
        				case 2:
        					listarTratamentosDoBruxo();
        					break;
        				case 3:
        					iniciarTratamento();
        					break;
        				case 4:
        					ampliarTratamento();
        					break;
        				case 5:
        					excluirTratamento();
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
    
    EncerraBruxos();
    EncerraPacientes();
    EncerraPocoes();
    EncerraTratamentos();
    
    return 0;
}
