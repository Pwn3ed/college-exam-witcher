#include "Tratamento.h"
#include <string.h>

Tratamento *tratamentos = NULL;
int MAX_TRATAMENTOS = 5;
//int qtdTratamentos = 0; //DEFAULT
int qtdTratamentos = 3; //DEBUG


// "1. Listar tratamentos do paciente"
// "2. Listar tratamentos do bruxo"
// "3. Iniciar tratamento"
// "4. Ampliar tratamento"
// "5. Excluir tratamento"
// "0. Sair"

int InicializarTratamentos() {
	
	tratamentos = malloc(MAX_TRATAMENTOS * sizeof(Tratamento));
	if (tratamentos == NULL) {
		return 0;
	}
	
// DEBUG
	tratamentos[0].codigo = 0;
	tratamentos[0].bruxo = 0;
	tratamentos[0].paciente = 0;
	tratamentos[0].dias = 0;
	tratamentos[0].dosagem = 0;
//	
	tratamentos[1].codigo = 0;
	tratamentos[1].bruxo = 0;
	tratamentos[1].paciente = 0;
	tratamentos[1].dias = 0;
	tratamentos[1].dosagem = 0;
	
	tratamentos[2].codigo = 0;
	tratamentos[2].bruxo = 0;
	tratamentos[2].paciente = 0;
	tratamentos[2].dias = 0;
	tratamentos[2].dosagem = 0;
// DEBUG
	
	return 1;
}

int EncerraTratamentos() {
	free(tratamentos);
}

int ObterTratamentoPeloCodigo(int codigo, Tratamento *tratamento) {
	for (int i = 0; i < qtdTratamentos; i++) {
		if (codigo == tratamentos[codigo].codigo) {
			*tratamento = tratamentos[codigo];
			return 1;
		}
	}
	
}

int salvarTratamento(Tratamento tratamentos) {
	
}
