#include "Bruxo.h"
#include <string.h>
#include <stdio.h>

FILE *ptrBruxos = NULL;
Bruxo* bruxos = NULL; //V2
int MAX_BRUXOS = 5;
int qtdBruxos = 0; //DEFAULT

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
	return 0;
}

int QuantidadeBruxos() {
	return qtdBruxos;
}

int ObterBruxoPeloIndice(int indice, Bruxo* b) {
	
	Bruxo temp_bruxo;
	
	rewind(ptrBruxos);
	
	fseek(ptrBruxos, indice * sizeof(Bruxo), SEEK_SET);
	
	fread(&temp_bruxo, sizeof(Bruxo), 1, ptrBruxos);
	
	*b = temp_bruxo;
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
}

int AtualizarBruxo(Bruxo b) {
	
	rewind(ptrBruxos);
	Bruxo bruxo;
	
	for (int i = 0; i < qtdBruxos; i++) {
		fread(&bruxo, sizeof(Bruxo), 1, ptrBruxos);
		if (bruxo.codigo == b.codigo) {
			fseek(ptrBruxos, i*sizeof(Bruxo), SEEK_SET);
			fwrite(&b, sizeof(Bruxo), 1, ptrBruxos);
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
	
	EncerraBruxos();
	remove("bruxos.bin");
	fclose(temp_ptrBruxos);
	rename("temp.bin", "bruxos.bin");
	
	ptrBruxos = fopen("bruxos.bin", "r+b");
	if (ptrBruxos == NULL) {
		return 0;
	}
	
	qtdBruxos--;
		
	return 1;
}

int ApagarBruxoPeloNome(char* nome) {
	
}

