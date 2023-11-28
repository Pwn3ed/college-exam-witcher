#include "Paciente.h"
#include <string.h>


Paciente* pacientes = NULL;
int MAX_PACIENTES = 5;
int qtdPacientes = 0; //DEFAULT
//int qtdPacientes = 3; //DEBUG

int InicializarPacientes() {
	pacientes = (Paciente*) malloc(MAX_PACIENTES * sizeof(Paciente));
	if (pacientes == NULL) {
		return 0;
	}
	
	// DEBUG
	
//	for (int i = 0; i < MAX_PACIENTES; i ++) {
//		pacientes[i].codigo = i;
//		strcpy(pacientes[i].nome, "Paciente");
//		pacientes[i].idade = i;
//		pacientes[i].altura = i;
//	}
	
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
		if (pacientes == NULL) {
			MAX_PACIENTES -= 5;
			return 0;
		}
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
	return 1;
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
			if (MAX_PACIENTES != 4 && qtdPacientes < MAX_PACIENTES -4) {
				MAX_PACIENTES -= 4;
				pacientes = (Paciente*) realloc(pacientes, MAX_PACIENTES * sizeof(Paciente));
				if (pacientes == NULL) {
					MAX_PACIENTES += 4;
					return 0;
				}
			}
			return 1;
		}
	}
	return 0;
}

int ApagarPacientePeloNome(char* nome) {
	
}

