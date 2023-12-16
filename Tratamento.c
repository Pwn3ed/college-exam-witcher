#include "Tratamento.h"
#include <string.h>
#include <stdio.h>

FILE *ptrTratamentos = NULL;
Tratamento *tratamentos = NULL; //V2
int MAX_TRATAMENTOS = 50;
int qtdTratamentos = 0; //DEFAULT

int InicializarTratamentos() {
	ptrTratamentos = fopen("tratamentos.bin", "r+b");
	
	if (ptrTratamentos == NULL) {
		ptrTratamentos = fopen("tratamentos.bin", "w+b");
	}
	
	if (ptrTratamentos == NULL) {
		return 0;
	}
	
	fseek(ptrTratamentos, 0, SEEK_END);
	qtdTratamentos = ftell(ptrTratamentos) / sizeof(Tratamento);
	rewind(ptrTratamentos);
	
	return 1;
}

int EncerraTratamentos() {
	fclose(ptrTratamentos);
}

int salvarTratamento(Tratamento t) {
	if (qtdTratamentos < MAX_TRATAMENTOS) {
		fseek(ptrTratamentos, 0, SEEK_END);
		fwrite(&t, sizeof(Tratamento), 1, ptrTratamentos);
		
		qtdTratamentos++;
		printf("\nDEBUG: tratamento salvo com sucesso");
		return 1;
	}
	
//	for (int i = 0; i < qtdTratamentos; i++) {
//		if (t.bruxo == tratamentos[i].bruxo || t.paciente == tratamentos[i].paciente || t.medicamento == tratamentos[i].medicamento) {
//			return 0;
//		}
//	}

	return 0;
}

int QuantidadeTratamentos() {
	return qtdTratamentos;
}

int ObterTratamentoPeloIndice(int indice, Tratamento *t) {
	Tratamento temp_tratamento;
	rewind(ptrTratamentos);
	fseek(ptrTratamentos, indice * sizeof(Tratamento), SEEK_SET);
	fread(&temp_tratamento, sizeof(Tratamento), 1, ptrTratamentos);
	*t = temp_tratamento;
	return 1;
}

int ObterTratamentoPeloCodigo(int codigo, Tratamento *t) {
	rewind(ptrTratamentos);
	Tratamento temp_tratamento;
	
	for (int i = 0; i < qtdTratamentos; i++) {
		fread(&temp_tratamento, sizeof(Tratamento), 1, ptrTratamentos);
		
		if (codigo == temp_tratamento.codigo) {
			*t = temp_tratamento;
			return 1;
		}
	}
}

int AtualizarTratamento(Tratamento t) {
	rewind(ptrTratamentos);
	Tratamento temp_tratamento;
	
	for (int i = 0; i < qtdTratamentos; i++) {
		fread(&temp_tratamento, sizeof(Tratamento), 1, ptrTratamentos);
		
		if (t.codigo == temp_tratamento.codigo) {
			fseek(ptrTratamentos, i*sizeof(Tratamento), SEEK_SET);
			fwrite(&t, sizeof(Tratamento), 1, ptrTratamentos);
			return 1;
		}
	}
}

int ApagarTratamentoPeloCodigo(int codigo) {
	FILE *temp_ptrTratamentos;
	Tratamento temp_tratamento;
	rewind(ptrTratamentos);
	temp_ptrTratamentos = fopen("temp.bin", "w+b");
	
	if (temp_ptrTratamentos == NULL) {
		return 0;
	}
	
	for (int i = 0; i < qtdTratamentos; i++) {
		fread(&temp_tratamento, sizeof(Tratamento), 1, ptrTratamentos);
		
		if (codigo != temp_tratamento.codigo) {
			fwrite(&temp_tratamento, sizeof(Tratamento), 1, temp_ptrTratamentos);
		}
	}
	
	EncerraTratamentos();
	remove("tratamentos.bin");
	fclose(temp_ptrTratamentos);
	rename("temp.bin", "tratamentos.bin");
	
	ptrTratamentos = fopen("tratamentos.bin", "r+b");
	if (ptrTratamentos == NULL) {
		return 0;
	}
	
	qtdTratamentos--;
	return 1;
}

