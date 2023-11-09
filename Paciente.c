#include "Paciente.h"
#include <string.h>


Paciente* pacientes = NULL;
int MAX_PACIENTES = 5;
// int qtdPacientes = 0; //DEFAULT
int qtdPacientes = 3; //DEBUG

int InicializarPacientes() {
	pacientes = (Paciente*) malloc(MAX_PACIENTES * sizeof(Paciente));
	if (pacientes == NULL) {
		return 0;
	}
	
	// DEBUG
	pacientes[0].codigo = 0;
	strcpy(pacientes[0].nome, "Joao");
	pacientes[0].idade = 23;
	pacientes[0].altura = 1.61;
	
	pacientes[1].codigo = 1;
	strcpy(pacientes[1].nome, "Cabral");
	pacientes[1].idade = 21;
	pacientes[1].altura = 1.70;
	
	pacientes[2].codigo = 2;
	strcpy(pacientes[2].nome, "Alberto");
	pacientes[2].idade = 24;
	pacientes[2].altura = 1.66;
	// DEBUG

	return 1;
}

int EncerraPacientes() {
	free(pacientes);
	return 1;
}

int SalvarPaciente(Paciente p) {
	if (qtdPacientes == MAX_PACIENTES) {
		MAX_PACIENTES += 5;
		pacientes = (Paciente*) realloc(pacientes, MAX_PACIENTES * sizeof(Paciente));
	}
	if (qtdPacientes < MAX_PACIENTES) {
		pacientes[qtdPacientes] = p;
		
		qtdPacientes++;
		return 1;	
	}
	return 0;
}

int QuantidadePacientes() {
	return qtdPacientes;
}

int ObterPacientePeloIndice(int indice, Paciente* p) {
	*p = pacientes[indice];
}

int ObterPacientePeloCodigo(int codigo, Paciente* p) {
	for (int i = 0; i < qtdPacientes; i++) {
		if (pacientes[i].codigo == codigo) {
			*p = pacientes[i];
			return 1;
		}
	}
	return 0;
}

int AtualizarPaciente(Paciente p) {
	for (int i = 0; i < qtdPacientes; i++) {
		if (pacientes[i].codigo == p.codigo) {
			pacientes[i] = p;
			return 1;
		}
	}
	return 0;
}

int ApagarPacientePeloCodigo(int codigo) {
	for (int i = 0; i < qtdPacientes; i++) {
		if (pacientes[i].codigo == codigo) {
			for (int j = i; j <qtdPacientes-1; j++) {
				pacientes[j] = pacientes[j+1];
			}
			qtdPacientes--;
			return 1;
		}
	}
	return 0;
}

int ApagarPacientePeloNome(char* nome) {
	
}

