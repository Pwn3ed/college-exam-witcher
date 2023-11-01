
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
int ObterTratamentoPeloCodigo(int codigo, Tratamento *tratamento);
int salvarTratamento(Tratamento tratamento);
