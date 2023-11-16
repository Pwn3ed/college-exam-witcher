#include "Pocao.h"
#include <string.h>


Pocao* pocoes = NULL;
int MAX_POCOES = 5;
int qtdPocoes = 0; //DEFAULT
//int qtdPocoes = 3; //DEBUG

int InicializarPocoes() {
	pocoes = (Pocao*) malloc(MAX_POCOES * sizeof(Pocao));
	if (pocoes == NULL) {
		return 0;
	}
	
	// DEBUG
	
//	for (int i = 0; i < qtdPocoes; i++) {
//		pocoes[i].codigo = i;
//		strcpy(pocoes[i].nome, "Pocao");
//		strcpy(pocoes[i].tipo, "Tipo");
//	}

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
		if (pocoes == NULL) {
			MAX_POCOES -= 5;
			return 0;
		}
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
			}
			qtdPocoes--;
			if (MAX_POCOES != 4 && qtdPocoes < MAX_POCOES -4) {
				MAX_POCOES -= 4;
				pocoes = (Pocao*) realloc(pocoes, MAX_POCOES * sizeof(Pocao));
				if (pocoes == NULL) {
					MAX_POCOES += 4;
					return 0;
				}
			}
			return 1;
		}
	}
	return 0;
}

int ApagarPocaoPeloNome(char* nome) {
	
}

