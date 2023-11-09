
typedef struct {
	int codigo;
	int bruxo;
	int paciente;
	int medicamento;
	int dias;
	int dosagem;
}Tratamento;

int InicializarTratamentos();
int EncerraTratamentos();
int salvarTratamento(Tratamento t);
int ObterTratamentoPeloCodigo(int codigo, Tratamento *t);
