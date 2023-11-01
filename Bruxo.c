#include "Bruxo.h"
#include <string.h>


Bruxo* bruxos = NULL;
int MAX_BRUXOS = 5;
// int qtdBruxos = 0; //DEFAULT
int qtdBruxos = 3; //DEBUG

int InicializarBruxos() {
	bruxos = (Bruxo*) malloc(MAX_BRUXOS * sizeof(Bruxo));
	if (bruxos == NULL) {
		return 0;
	}
	
	// DEBUG
	bruxos[0].codigo = 0;
	strcpy(bruxos[0].nome, "Diego");
	strcpy(bruxos[0].especialidade, "Bruxo");
	
	bruxos[1].codigo = 1;
	strcpy(bruxos[1].nome, "Leonardo");
	strcpy(bruxos[1].especialidade, "Mago");
	
	bruxos[2].codigo = 2;
	strcpy(bruxos[2].nome, "Pablo");
	strcpy(bruxos[2].especialidade, "Deus");
	// DEBUG
	
	// zerar array
//	for (int i = 0; i < MAX_BRUXOS; i++){ 
//		bruxos[i].codigo = 0;
//		strcpy(bruxos[i].nome, "");
//		strcpy(bruxos[i].especialidade, "");
//	}
	return 1;
}
int EncerraBruxos() {
	free(bruxos);
	return 1;
}
int SalvarBruxo(Bruxo* b) {
	if (qtdBruxos == MAX_BRUXOS) {
		MAX_BRUXOS += 5;
		bruxos = (Bruxo*) realloc(bruxos, MAX_BRUXOS * sizeof(Bruxo));
	}
	if (qtdBruxos < MAX_BRUXOS) {
		bruxos[qtdBruxos].codigo = b->codigo;
		strcpy(bruxos[qtdBruxos].nome, b->nome);
		strcpy(bruxos[qtdBruxos].especialidade, b->especialidade);
		
		qtdBruxos++;
		return 1;	
	}
	return 0;
}
int QuantidadeBruxos() {
	return qtdBruxos;
}
int ObterBruxoPeloIndice(int indice, Bruxo* b) {
	*b = bruxos[indice];
}
int ObterBruxoPeloCodigo(int codigo, Bruxo* b) {
	for (int i = 0; i < qtdBruxos; i++) {
		if (b[i].codigo == codigo) {
			return 1;
		}
	}
	return 0;
}
int AtualizarBruxo(Bruxo b) {
	for (int i = 0; i < qtdBruxos; i++) {
		if (bruxos[i].codigo == b.codigo) {
			bruxos[i] = b;
			return 1;
		}
	}
	return 0;
}
int ApagarBruxoPeloCodigo(int codigo) {
	for (int i = 0; i < qtdBruxos; i++) {
		if (bruxos[i].codigo == codigo) {
			for (int j = i; j <qtdBruxos-1; j++) {
				bruxos[j].codigo = bruxos[j+1].codigo;
				strcpy(bruxos[j].nome, bruxos[j+1].nome);
				strcpy(bruxos[j].especialidade, bruxos[j+1].especialidade);
			}
			qtdBruxos--;
			return 1;
		}
	}
	return 0;
}
int ApagarBruxoPeloNome(char* nome) {
	
}

