#include "Bruxo.h"
#include <string.h>


Bruxo* bruxos = NULL;
int MAX_BRUXOS = 5;
int qtdBruxos = 0;

int InicializarBruxos() {
	bruxos = (Bruxo*) malloc(MAX_BRUXOS * sizeof(Bruxo));
	for (int i = 0; i < MAX_BRUXOS; i++){
//		bruxos[i].codigo = 0;
//		strcpy(bruxos[i].nome, "");
//		strcpy(bruxos[i].especialidade, "");
	}
	return 1;
}
int EncerraBruxos() {
	free(bruxos);
	return 1;
}
int SalvarBruxo(Bruxo* b) {
	if (b[0].codigo < MAX_BRUXOS) {
		bruxos[qtdBruxos].codigo = b[0].codigo;
		strcpy(bruxos[qtdBruxos].nome, b[0].nome);
		strcpy(bruxos[qtdBruxos].especialidade, b[0].especialidade);
		
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
	
	
	return 1;
}
int AtualizarBruxo(Bruxo b) {
	
}
int ApagarBruxoPeloCodigo(int codigo) {
	
}
int ApagarBruxoPeloNome(char* nome) {
	
}

