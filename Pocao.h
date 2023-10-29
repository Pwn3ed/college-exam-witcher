#define TAM 30

typedef struct {
	int codigo;
	char nome[TAM];
	char tipo[TAM];
}Pocao;

int InicializarPocoes();
int EncerraPocoes();
int SalvarPocao(Pocao* p);
int QuantidadePocoes();
int ObterPocaoPeloIndice(int indice, Pocao* p);
int ObterPocaoPeloCodigo(int codigo, Pocao* p);
int AtualizarPocao(int codigo, Pocao* p);
int ApagarPocaoPeloCodigo(int codigo);
int ApagarPocaoPeloNome(char* nome);

