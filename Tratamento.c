#include "Tratamento.h"
#include <string.h>

Tratamento *tratamentos = NULL;
int MAX_TRATAMENTOS = 5;
//int qtdTratamentos = 0; //DEFAULT
int qtdTratamentos = 3; //DEBUG


int InicializarTratamentos() {
	
	tratamentos = malloc(MAX_TRATAMENTOS * sizeof(Tratamento));
	if (tratamentos == NULL) {
		return 0;
	}
	
// DEBUG
	tratamentos[0].codigo = 0;
	tratamentos[0].bruxo = 0;
	tratamentos[0].paciente = 0;
	tratamentos[0].medicamento = 0;
	tratamentos[0].dias = 0;
	tratamentos[0].dosagem = 0;

	tratamentos[1].codigo = 1;
	tratamentos[1].bruxo = 1;
	tratamentos[1].paciente = 1;
	tratamentos[1].medicamento = 1;
	tratamentos[1].dias = 1;
	tratamentos[1].dosagem = 1;
	
	tratamentos[2].codigo = 2;
	tratamentos[2].bruxo = 2;
	tratamentos[2].paciente = 2;
	tratamentos[2].medicamento = 2;
	tratamentos[2].dias = 2;
	tratamentos[2].dosagem = 2;
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
	}
	if (qtdTratamentos < MAX_TRATAMENTOS) {
		tratamentos[qtdTratamentos] = t;
		
		qtdTratamentos++;
		
		for (int i = 0; i < qtdTratamentos; i++) {
			printf("\nDEBUG: %d, %d, %d, %d, %d, %d", tratamentos[i].codigo, tratamentos[i].bruxo, tratamentos[i].paciente, tratamentos[i].medicamento, tratamentos[i].dias, tratamentos[i].dosagem);
		}
		
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
			return 1;
		}
	}
	return 0;
}




