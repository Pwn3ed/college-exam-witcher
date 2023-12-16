#include "Pocao.h"
#include <string.h>
#include <stdio.h>

FILE *ptrPocoes = NULL;
//Pocao* pocoes = NULL; //V2
int MAX_POCOES = 50;
int qtdPocoes = 0; //DEFAULT

int InicializarPocoes() {
	ptrPocoes = fopen("pocoes.bin", "r+b");
	
	if (ptrPocoes == NULL) {
		ptrPocoes = fopen("pocoes.bin", "w+b");
	}
	
	if (ptrPocoes == NULL) {
		return 0;
	}
	
	fseek(ptrPocoes, 0, SEEK_END);
	qtdPocoes = ftell(ptrPocoes) / sizeof(Pocao);
	rewind(ptrPocoes);
		
	return 1;
}

int EncerraPocoes() {
	fclose(ptrPocoes);
	
	return 1;
}

int SalvarPocao(Pocao p) {
	if (qtdPocoes < MAX_POCOES) {
		fseek(ptrPocoes, 0, SEEK_END);
		fwrite(&p, sizeof(Pocao), 1, ptrPocoes);
		
		qtdPocoes++;
		return 1;
	}
	return 0;
}

int QuantidadePocoes() {
	return qtdPocoes;
}

int ObterPocaoPeloIndice(int indice, Pocao* p) {
	Pocao temp_pocao;
	rewind(ptrPocoes);
	fseek(ptrPocoes, indice * sizeof(Pocao), SEEK_SET);
	fread(&temp_pocao, sizeof(Pocao), 1, ptrPocoes);
	*p = temp_pocao;
	
	return 1;
}

int ObterPocaoPeloCodigo(int codigo, Pocao* p) {
	rewind(ptrPocoes);
	Pocao temp_pocao;
	
	for (int i = 0; i < qtdPocoes; i++) {
		fread(&temp_pocao, sizeof(Pocao), 1, ptrPocoes);
		
		if (codigo == temp_pocao.codigo) {
			*p = temp_pocao;
			return 1;
		}
	}
}

int AtualizarPocao(Pocao p) {
	rewind(ptrPocoes);
	Pocao pocao;
	
	for (int i = 0; i < qtdPocoes; i++) {
		fread(&pocao, sizeof(Pocao), 1, ptrPocoes);
		if (pocao.codigo == p.codigo) {
			fseek(ptrPocoes, i*sizeof(Pocao), SEEK_SET);
			fwrite(&p, sizeof(Pocao), 1, ptrPocoes);
			return 1;
		}
	}
	return 0;
}

int ApagarPocaoPeloCodigo(int codigo) {
	FILE *temp_ptrPocoes;
	Pocao temp_pocao;
	rewind(ptrPocoes);
	temp_ptrPocoes = fopen("temp.bin", "w+b");
	
	if (temp_ptrPocoes == NULL) {
		return 0;
	}
	
	for (int i = 0; i < qtdPocoes; i++) {
		fread(&temp_pocao, sizeof(Pocao), 1, ptrPocoes);
		
		if (codigo != temp_pocao.codigo) {
			fwrite(&temp_pocao, sizeof(Pocao), 1, temp_ptrPocoes);
		}
	}
	
	EncerraPocoes();
	remove("pocoes.bin");
	fclose(temp_ptrPocoes);
	rename("temp.bin", "pocoes.bin");
	
	ptrPocoes = fopen("pocoes.bin", "r+b");
	if (ptrPocoes == NULL) {
		return 0;
	}
	
	qtdPocoes--;
	return 1;
}

int ApagarPocaoPeloNome(char* nome) {
	
}

