#include "Pocao.h"
#include <string.h>


Pocao* pocoes = NULL;
int MAX_POCOES = 5;
// int qtdPocoes = 0; //DEFAULT
int qtdPocoes = 3; //DEBUG

int InicializarPocoes() {
	pocoes = (Pocao*) malloc(MAX_POCOES * sizeof(Pocao));
	if (pocoes == NULL) {
		return 0;
	}
	
	// DEBUG
	pocoes[0].codigo = 0;
	strcpy(pocoes[0].nome, "Cura");
	strcpy(pocoes[0].tipo, "Liquido");
	
	pocoes[1].codigo = 1;
	strcpy(pocoes[1].nome, "Sono");
	strcpy(pocoes[1].tipo, "Comprimido");
	
	pocoes[2].codigo = 2;
	strcpy(pocoes[2].nome, "Vigor");
	strcpy(pocoes[2].tipo, "Comprimido");
	// DEBUG

	return 1;
}

int EncerraPocoes() {
	free(pocoes);
	return 1;
}

int SalvarPocao(Pocao p) {
	if (qtdPocoes == MAX_POCOES) {
		MAX_POCOES += 5;
		pocoes = (Pocao*) realloc(pocoes, MAX_POCOES * sizeof(Pocao));
	}
	if (qtdPocoes < MAX_POCOES) {
		pocoes[qtdPocoes] = p;
		
		qtdPocoes++;
		return 1;	
	}
	return 0;
}

int QuantidadePocoes() {
	return qtdPocoes;
}

int ObterPocaoPeloIndice(int indice, Pocao* p) {
	*p = pocoes[indice];
	return 1;
}

int ObterPocaoPeloCodigo(int codigo, Pocao* p) {
	for (int i = 0; i < qtdPocoes; i++) {
		if (pocoes[i].codigo == codigo) {
			*p = pocoes[i];
			return 1;
		}
	}
	
	return 0;
}

int AtualizarPocao(Pocao p) {
	for (int i = 0; i < qtdPocoes; i++) {
		if (pocoes[i].codigo == p.codigo) {
			pocoes[i] = p;
			return 1;
		}
	}
	return 0;
}

int ApagarPocaoPeloCodigo(int codigo) {
	for (int i = 0; i < qtdPocoes; i++) {
		if (pocoes[i].codigo == codigo) {
			for (int j = i; j <qtdPocoes-1; j++) {
				pocoes[j] = pocoes[j+1];
//				pocoes[j].codigo = pocoes[j+1].codigo;
//				strcpy(pocoes[j].nome, pocoes[j+1].nome);
//				strcpy(pocoes[j].tipo, pocoes[j+1].tipo);
			}
			qtdPocoes--;
			return 1;
		}
	}
	return 0;
}

int ApagarPocaoPeloNome(char* nome) {
	
}

