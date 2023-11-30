#include "Bruxo.h"
#include <string.h>
#include <stdio.h>

FILE *ptrBruxos = NULL;
Bruxo* bruxos = NULL; //V2
int MAX_BRUXOS = 5;
int qtdBruxos = 0; //DEFAULT
//int qtdBruxos = 3; //DEBUG

int InicializarBruxos() {
	ptrBruxos = fopen("bruxos.salve", "w");
	
	if (ptrBruxos == NULL) {
		return 0;
	}
	
	// V2
//	bruxos = (Bruxo*) malloc(MAX_BRUXOS * sizeof(Bruxo));
//	if (bruxos == NULL) {
//		return 0;
//	}
	
	// DEBUG

//	for (int i = 0; i < MAX_BRUXOS; i++) {
//		bruxos[i].codigo = i;
//		strcpy(bruxos[i].nome, "Bruxo");
//		strcpy(bruxos[i].especialidade, "Especialidade");
//	}

	// DEBUG
	
	return 1;
}

int EncerraBruxos() {
	fclose(ptrBruxos);
	return 1;
}

int SalvarBruxo(Bruxo b) {
	if (qtdBruxos == MAX_BRUXOS) {
		MAX_BRUXOS += 5;
		bruxos = (Bruxo*) realloc(bruxos, MAX_BRUXOS * sizeof(Bruxo));
		if (bruxos == NULL) {
			MAX_BRUXOS -= 5;
			return 0;
		}
	}
	if (qtdBruxos < MAX_BRUXOS) {
		bruxos[qtdBruxos] = b;
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
	return 1;
}

int ObterBruxoPeloCodigo(int codigo, Bruxo* b) {
	for (int i = 0; i < qtdBruxos; i++) {
		if (bruxos[i].codigo == codigo) {
			*b = bruxos[i];
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
				bruxos[j] = bruxos[j+1];
			}
			qtdBruxos--;
			if (MAX_BRUXOS != 4 && qtdBruxos < MAX_BRUXOS -4) {
				MAX_BRUXOS -= 4;
				bruxos = (Bruxo*) realloc(bruxos, MAX_BRUXOS * sizeof(Bruxo));
				if (bruxos == NULL) {
					MAX_BRUXOS += 4;
					return 0;
				}
			}
			return 1;
		}
	}
	return 0;
}

int ApagarBruxoPeloNome(char* nome) {
	
}

