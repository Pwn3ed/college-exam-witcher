#define TAM 30

typedef struct {
	int codigo;
	char nome[TAM];
	char especialidade[TAM];
}Bruxo;

int InicializarBruxos();
int EncerraBruxos();
int SalvarBruxo(Bruxo* b);
int QuantidadeBruxos();
int ObterBruxoPeloIndice(int indice, Bruxo* b);
int ObterBruxoPeloCodigo(int codigo, Bruxo* b);
int AtualizarBruxo(Bruxo b);
int ApagarBruxoPeloCodigo(int codigo);
int ApagarBruxoPeloNome(char* nome);

