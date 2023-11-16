#include "Tratamento.h"
#include <string.h>

Tratamento *tratamentos = NULL;
int MAX_TRATAMENTOS = 5;
int qtdTratamentos = 0; //DEFAULT
//int qtdTratamentos = 3; //DEBUG


int InicializarTratamentos() {
	
	tratamentos = malloc(MAX_TRATAMENTOS * sizeof(Tratamento));
	if (tratamentos == NULL) {
		return 0;
	}
	
	// DEBUG

//	for (int i = 0; i < MAX_TRATAMENTOS; i++) {
//		tratamentos[i].codigo = i;
//		tratamentos[i].bruxo = i;
//		tratamentos[i].paciente = i;
//		tratamentos[i].medicamento = i;
//		tratamentos[i].dias = i;
//		tratamentos[i].dosagem = i;
//	}

	// DEBUG
	
	return 1;
}

int EncerraTratamentos() {
	free(tratamentos);
}

int salvarTratamento(Tratamento t) {
	if (qtdTratamentos == MAX_TRATAMENTOS) {
		MAX_TRATAMENTOS += 5;
		tratamentos = (Tratamento*) realloc(tratamentos, MAX_TRATAMENTOS * sizeof(Tratamento));
		if (tratamentos == NULL) {
			MAX_TRATAMENTOS -= 5;
			return 0;
		}
	}
	if (qtdTratamentos < MAX_TRATAMENTOS) {
		tratamentos[qtdTratamentos] = t;
		qtdTratamentos++;
		
	// DEBUG
//		for (int i = 0; i < qtdTratamentos; i++) {
//			printf("\nDEBUG: %d, %d, %d, %d, %d, %d", tratamentos[i].codigo, tratamentos[i].bruxo, tratamentos[i].paciente, tratamentos[i].medicamento, tratamentos[i].dias, tratamentos[i].dosagem);
//		}
		
		return 1;	
	}
	return 0;
}

int QuantidadeTratamentos() {
	return qtdTratamentos;
}

int ObterTratamentoPeloIndice(int indice, Tratamento *t) {
	*t = tratamentos[indice];
	return 1;
}

int ObterTratamentoPeloCodigo(int codigo, Tratamento *t) {
	for (int i = 0; i < qtdTratamentos; i++) {
		if (tratamentos[i].codigo == codigo) {
			*t = tratamentos[i];
			return 1;
		}
	}
	return 0;
}

int AtualizarTratamento(Tratamento t) {
	for (int i = 0; i < qtdTratamentos; i++) {
		if (tratamentos[i].codigo == t.codigo) {
			tratamentos[i] = t;
			return 1;
		}
	}
	return 0;
}

int ApagarTratamentoPeloCodigo(int codigo) {
	for (int i = 0; i < qtdTratamentos; i++) {
		if (tratamentos[i].codigo == codigo) {
			for (int j = i; j <qtdTratamentos-1; j++) {
				tratamentos[j] = tratamentos[j+1];
			}
			qtdTratamentos--;
			if (MAX_TRATAMENTOS != 4 && qtdTratamentos < MAX_TRATAMENTOS -4) {
				MAX_TRATAMENTOS -= 4;
				tratamentos = (Tratamento*) realloc(tratamentos, MAX_TRATAMENTOS * sizeof(Tratamento));
				if (tratamentos == NULL) {
					MAX_TRATAMENTOS += 4;
					return 0;
				}
			}
			return 1;
		}
	}
	return 0;
}

