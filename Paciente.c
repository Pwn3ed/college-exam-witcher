#include "Paciente.h"
#include <string.h>
#include <stdio.h>

FILE *ptrPacientes = NULL;
//Paciente* pacientes = NULL; //V2
int MAX_PACIENTES = 50;
int qtdPacientes = 0; //DEFAULT

int InicializarPacientes() {
	ptrPacientes = fopen("pacientes.bin", "r+b");
	
	if (ptrPacientes == NULL) {
		ptrPacientes = fopen("pacientes.bin", "w+b");
	}
	
	if (ptrPacientes == NULL) {
		return 0;
	}
	
	fseek(ptrPacientes, 0, SEEK_END);
	qtdPacientes = ftell(ptrPacientes) / sizeof(Paciente);
	rewind(ptrPacientes);
		
	return 1;
}

int EncerraPacientes() {
	fclose(ptrPacientes);
	
	return 1;
}

int SalvarPaciente(Paciente p) {
	if (qtdPacientes < MAX_PACIENTES) {
		fseek(ptrPacientes, 0, SEEK_END);
		fwrite(&p, sizeof(Paciente), 1, ptrPacientes);
		
		qtdPacientes++;
		return 1;
	}
	return 0;
}

int QuantidadePacientes() {
	return qtdPacientes;
}

int ObterPacientePeloIndice(int indice, Paciente* p) {
	Paciente temp_paciente;
	rewind(ptrPacientes);
	fseek(ptrPacientes, indice * sizeof(Paciente), SEEK_SET);
	fread(&temp_paciente, sizeof(Paciente), 1, ptrPacientes);
	*p = temp_paciente;
	
	return 1;
}

int ObterPacientePeloCodigo(int codigo, Paciente* p) {
	rewind(ptrPacientes);
	Paciente temp_paciente;
	
	for (int i = 0; i < qtdPacientes; i++) {
		fread(&temp_paciente, sizeof(Paciente), 1, ptrPacientes);
		
		if (codigo == temp_paciente.codigo) {
			*p = temp_paciente;
			return 1;
		}
	}
}

int AtualizarPaciente(Paciente p) {
	rewind(ptrPacientes);
	Paciente paciente;
	
	for (int i = 0; i < qtdPacientes; i++) {
		fread(&paciente, sizeof(Paciente), 1, ptrPacientes);
		if (paciente.codigo == p.codigo) {
			fseek(ptrPacientes, i*sizeof(Paciente), SEEK_SET);
			fwrite(&p, sizeof(Paciente), 1, ptrPacientes);
			return 1;
		}
	}
	return 0;
}

int ApagarPacientePeloCodigo(int codigo) {
	FILE *temp_ptrPacientes;
	Paciente temp_paciente;
	rewind(ptrPacientes);
	temp_ptrPacientes = fopen("temp.bin", "w+b");
	
	if (temp_ptrPacientes == NULL) {
		return 0;
	}
	
	for (int i = 0; i < qtdPacientes; i++) {
		fread(&temp_paciente, sizeof(Paciente), 1, ptrPacientes);
		
		if (codigo != temp_paciente.codigo) {
			fwrite(&temp_paciente, sizeof(Paciente), 1, temp_ptrPacientes);
		}
	}
	
	EncerraPacientes();
	remove("pacientes.bin");
	fclose(temp_ptrPacientes);
	rename("temp.bin", "pacientes.bin");
	
	ptrPacientes = fopen("pacientes.bin", "r+b");
	if (ptrPacientes == NULL) {
		return 0;
	}
	
	qtdPacientes--;
	return 1;
}

int ApagarPacientePeloNome(char* nome) {
	
}

