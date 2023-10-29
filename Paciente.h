#define TAM 30

typedef struct {
	int codigo;
	char nome[TAM];
	int idade;
	float altura;
}Paciente;

int InicializarPacientes();
int EncerraPacientes();
int SalvarPaciente(Paciente* p);
int QuantidadePacientes();
int ObterPacientePeloIndice(int indice, Paciente* p);
int ObterPacientePeloCodigo(int codigo, Paciente* p);
int AtualizarPaciente(int codigo, Paciente* p);
int ApagarPacientePeloCodigo(int codigo);
int ApagarPacientePeloNome(char* nome);

