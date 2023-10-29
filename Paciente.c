#include "Paciente.h"
#include <string.h>


Paciente* pacientes = NULL;
int MAX_PACIENTES = 5;
// int qtdPacientes = 0; //DEFAULT
int qtdPacientes = 3; //DEBUG

int InicializarPacientes() {
	pacientes = (Paciente*) malloc(MAX_PACIENTES * sizeof(Paciente));
	
	// DEBUG
	pacientes[0].codigo = 0;
	strcpy(pacientes[0].nome, "Diego");
	pacientes[0].idade = 23;
	pacientes[0].altura = 1.61;
	
	pacientes[1].codigo = 1;
	strcpy(pacientes[1].nome, "Leonardo");
	pacientes[1].idade = 21;
	pacientes[1].altura = 1.70;
	
	pacientes[2].codigo = 2;
	strcpy(pacientes[2].nome, "Pablo");
	pacientes[2].idade = 24;
	pacientes[2].altura = 1.66;
	// DEBUG

	return 1;
}

int EncerraPacientes() {
	free(pacientes);
	return 1;
}

int SalvarPaciente(Paciente* p) {
	if (qtdPacientes < MAX_PACIENTES) {
		pacientes[qtdPacientes].codigo = p->codigo;
		strcpy(pacientes[qtdPacientes].nome, p->nome);
		pacientes[qtdPacientes].idade = p->idade;
		pacientes[qtdPacientes].altura = p->altura;
		
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
		if (p[i].codigo == codigo) {
			return 1;
		}
	}
	
	return 0;
}

int AtualizarPaciente(int codigo, Paciente* p) {
	for (int i = 0; i < qtdPacientes; i++) {
		if (pacientes[i].codigo == codigo) {
			pacientes[i].codigo = p->codigo;
			strcpy(pacientes[i].nome, p->nome);
			pacientes[i].idade = p->idade;
			pacientes[i].altura = p->altura;
			return 1;
		}
	}
	return 0;
}

int ApagarPacientePeloCodigo(int codigo) {
	for (int i = 0; i < qtdPacientes; i++) {
		if (pacientes[i].codigo == codigo) {
			for (int j = i; j <qtdPacientes-1; j++) {
				pacientes[j].codigo = pacientes[j+1].codigo;
				strcpy(pacientes[j].nome, pacientes[j+1].nome);
				pacientes[j].idade = pacientes[j+1].idade;
				pacientes[j].altura = pacientes[j+1].altura;
			}
			qtdPacientes--;
			return 1;
		}
	}
	return 0;
}

int ApagarPacientePeloNome(char* nome) {
	
}

