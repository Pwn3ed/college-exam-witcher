#include "Pocao.h"
#include <string.h>


Pocao* pocoes = NULL;
int MAX_POCOES = 5;
// int qtdPocoes = 0; //DEFAULT
int qtdPocoes = 3; //DEBUG

int InicializarPocoes() {
	pocoes = (Pocao*) malloc(MAX_POCOES * sizeof(Pocao));
	
	// DEBUG
	pocoes[0].codigo = 0;
	strcpy(pocoes[0].nome, "Diego");
	strcpy(pocoes[0].tipo, "Liquido");
	
	pocoes[1].codigo = 1;
	strcpy(pocoes[1].nome, "Leonardo");
	strcpy(pocoes[1].tipo, "Comprimido");
	
	pocoes[2].codigo = 2;
	strcpy(pocoes[2].nome, "Pablo");
	strcpy(pocoes[2].tipo, "Comprimido");
	// DEBUG

	return 1;
}

int EncerraPocoes() {
	free(pocoes);
	return 1;
}

int SalvarPocao(Pocao* p) {
	if (qtdPocoes < MAX_POCOES) {
		pocoes[qtdPocoes].codigo = p->codigo;
		strcpy(pocoes[qtdPocoes].nome, p->nome);
		strcpy(pocoes[qtdPocoes].tipo, p->tipo);
		
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
}

int ObterPocaoPeloCodigo(int codigo, Pocao* p) {
	for (int i = 0; i < qtdPocoes; i++) {
		if (p[i].codigo == codigo) {
			return 1;
		}
	}
	
	return 0;
}

int AtualizarPocao(int codigo, Pocao* p) {
	for (int i = 0; i < qtdPocoes; i++) {
		if (pocoes[i].codigo == codigo) {
			pocoes[i].codigo = p->codigo;
			strcpy(pocoes[i].nome, p->nome);
			strcpy(pocoes[i].tipo, p->tipo);
			return 1;
		}
	}
	return 0;
}

int ApagarPocaoPeloCodigo(int codigo) {
	for (int i = 0; i < qtdPocoes; i++) {
		if (pocoes[i].codigo == codigo) {
			for (int j = i; j <qtdPocoes-1; j++) {
				pocoes[j].codigo = pocoes[j+1].codigo;
				strcpy(pocoes[j].nome, pocoes[j+1].nome);
				strcpy(pocoes[j].tipo, pocoes[j+1].tipo);
			}
			qtdPocoes--;
			return 1;
		}
	}
	return 0;
}

int ApagarPocaoPeloNome(char* nome) {
	
}

