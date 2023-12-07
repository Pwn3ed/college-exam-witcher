#include "Bruxo.h"
#include <string.h>
#include <stdio.h>

FILE *ptrBruxos = NULL;
Bruxo* bruxos = NULL; //V2
int MAX_BRUXOS = 5;
int qtdBruxos = 0; //DEFAULT
//int qtdBruxos = 3; //DEBUG

int InicializarBruxos() {
	
	ptrBruxos = fopen("bruxos.bin", "r+b");
	
	if (ptrBruxos == NULL) {
		ptrBruxos = fopen("bruxos.bin", "w+b");
	}
	
	if (ptrBruxos == NULL) {
		return 0;
	}
	
	fseek(ptrBruxos, 0, SEEK_END);
	
	qtdBruxos = ftell(ptrBruxos) / sizeof(Bruxo);
	
	rewind(ptrBruxos);
	
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
	if (qtdBruxos < MAX_BRUXOS) {
		fseek(ptrBruxos, 0, SEEK_END);
		fwrite(&b, sizeof(Bruxo), 1, ptrBruxos);
		
		qtdBruxos++;
		return 1;
	}
	
//	if (qtdBruxos == MAX_BRUXOS) {
//		MAX_BRUXOS += 5;
//		bruxos = (Bruxo*) realloc(bruxos, MAX_BRUXOS * sizeof(Bruxo));
//		if (bruxos == NULL) {
//			MAX_BRUXOS -= 5;
//			return 0;
//		}
//	}
//	if (qtdBruxos < MAX_BRUXOS) {
//		bruxos[qtdBruxos] = b;
//		qtdBruxos++;
//		return 1;	
//	}
	return 0;
}

int QuantidadeBruxos() {
	return qtdBruxos;
}

int ObterBruxoPeloIndice(int indice, Bruxo* b) {
//	InicializarBruxos();
//	FILE *temp_ptrBruxos = fopen("bruxos.bin", "rb");
	
	Bruxo temp_bruxo;
	
	rewind(ptrBruxos);
	
//	if (indice != 0)
	fseek(ptrBruxos, indice * sizeof(Bruxo), SEEK_SET);
	
	fread(&temp_bruxo, sizeof(Bruxo), 1, ptrBruxos);
	
	*b = temp_bruxo;
	
//	*b = bruxos[indice];
//	EncerraBruxos()1;
	return 1;
}

int ObterBruxoPeloCodigo(int codigo, Bruxo* b) {
	
	rewind(ptrBruxos);
	
	Bruxo temp_bruxo;
	
	for (int i = 0; i < qtdBruxos; i++) {
		fread(&temp_bruxo, sizeof(Bruxo), 1, ptrBruxos);
		
		if (codigo == temp_bruxo.codigo) {
			*b = temp_bruxo;
			return 1;
		}
	}
	
//	for (int i = 0; i < qtdBruxos; i++) {
//		if (bruxos[i].codigo == codigo) {
//			*b = bruxos[i];
//			return 1;
//		}
//	}
//	return 0;
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
	
	FILE *temp_ptrBruxos;
	Bruxo temp_bruxo;
	rewind(ptrBruxos);
	
	temp_ptrBruxos = fopen("temp.bin", "w+b");
	
	if (temp_ptrBruxos == NULL) {
		return 0;
	}
	
	for (int i = 0; i < qtdBruxos; i++) {
		fread(&temp_bruxo, sizeof(Bruxo), 1, ptrBruxos);
		
		if (codigo != temp_bruxo.codigo) {
			fwrite(&temp_bruxo, sizeof(Bruxo), 1, temp_ptrBruxos);
		}
	}
	ptrBruxos = temp_ptrBruxos;
	qtdBruxos--;
	
	fclose(temp_ptrBruxos);
		
	return 1;
}

int ApagarBruxoPeloNome(char* nome) {
	
}

