#include "Bruxo.h"
#include <string.h>


Bruxo* bruxos = NULL;
int MAX_BRUXOS = 5;
int qtdBruxos = 0;

int InicializarBruxos() {
	bruxos = malloc(MAX_BRUXOS * sizeof(int));
	for (int i = 0; i < MAX_BRUXOS; i++){
		bruxos[i].codigo = 0;
//		strcpy(bruxos[i].nome, "");
//		strcpy(bruxos[i].especialidade, "");
	}
	return 1;
}
int EncerraBruxos() {
	
}
//int SalvarBruxo(Bruxo* b) {
//	
//}
//int QuantidadeBruxos() {
//	
//}
//int ObterBruxoPeloIndice(int indice, Bruxo* b) {
//	
//}
//int ObterBruxoPeloCodigo(int codigo, Bruxo* b) {
//	
//}
//int AtualizarBruxo(Bruxo b) {
//	
//}
//int ApagarBruxoPeloCodigo(int codigo) {
//	
//}
//int ApagarBruxoPeloNome(char* nome) {
//	
//}

