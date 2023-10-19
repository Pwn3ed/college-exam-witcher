//#define STRING 30
//#define BRUXOS 3
//#define PACIENTES 3
//#define POCOES 3
//#define TRATAMENTOS 3

//int BruxoQnt = 0;
//char BruxoNome[BRUXOS][STRING];
//char BruxoEspecialidade[BRUXOS][STRING];
//
//int PacienteQnt = 0;
//char PacienteNome[PACIENTES][STRING];
//int PacienteIdade[PACIENTES];
//float PacienteAltura[PACIENTES];
//
//int PocaoQnt = 0;
//char PocaoNome[POCOES][STRING];
//char PocaoTipo[POCOES][STRING];
//
//int TratamentoQnt = 0;
//int TratamentoBruxo[TRATAMENTOS];
//int TratamentoPaciente[TRATAMENTOS];
//int TratamentoMedicamento[TRATAMENTOS];
//int TratamentoDias[TRATAMENTOS];
//int TratamentoDosagem[TRATAMENTOS];
//
//
//void zerarArray() {
//	for (int i = 0; i < BRUXOS; i++){
//		strcpy(BruxoNome[i], "");
//		strcpy(BruxoEspecialidade[i], "");
//	}
//	
//	for (int i = 0; i < PACIENTES; i++){
//		strcpy(PacienteNome[i], "");
//		PacienteIdade[i] = 0;
//		PacienteAltura[i] = 0;
//	}
//	
//	for (int i = 0; i < POCOES; i++){
//		strcpy(PocaoNome[i], "");
//		strcpy(PocaoTipo[i], "");
//	}
//	
//	for (int i = 0; i < TRATAMENTOS; i++){
//		TratamentoBruxo[i] = -999;
//		TratamentoPaciente[i] = -999;
//		TratamentoMedicamento[i] = -999;
//		TratamentoDias[i] = -999;
//		TratamentoDosagem[i] = -999;
//	}
//}
//
//void listarBruxos() {
//	printf("\n");
//	for (int i = 0; i < BRUXOS; i++){
//		printf("Bruxo %d - Nome: %s | Especialidade: %s\n", i, BruxoNome[i], BruxoEspecialidade[i]);
//	}
//}
//
//void cadastrarBruxo() {
//	listarBruxos();
//	
//    int codigo = 0;
//    
//    printf("Digite o codigo do Bruxo: ");
//    fflush(stdin);
//    scanf("%d", &codigo);
//    
//    if (codigo >= 0 && codigo < BRUXOS) {
//    	printf("Digite o nome do Bruxo: ");
//	    fflush(stdin);
//	    scanf("%[^\n]s", &BruxoNome[codigo]);
//	    
//	    printf("Digite a especialidade do Bruxo: ");
//	    fflush(stdin);
//	    scanf("%[^\n]s", &BruxoEspecialidade[codigo]);
//	    
//	    BruxoQnt++;
//	}
//	
//}
//
//void excluirBruxo() {
//    listarBruxos();
//    
//    int codigo = 0;
//    printf("\nDigite o codigo do Bruxo: \n");	
//    fflush(stdin);
//    scanf("%d", &codigo);
//    
//    if (codigo >= 0 && codigo < BRUXOS) {
//    	strcpy(BruxoNome[codigo], "");
//    	strcpy(BruxoEspecialidade[codigo], "");
//    	
//    	BruxoQnt--;
//	}
//	else if (strcmp(BruxoNome[codigo], "") == 0) {
//		printf("Posicao vazia.");
//	}
//}
//
//void listarPocoes() {
//	printf("\n");
//	for (int i = 0; i < POCOES; i++){
//		printf("Pocao %d - Nome: %s | Tipo: %s\n", i, PocaoNome[i], PocaoTipo[i]);
//	}
//}
//
//void cadastrarPocao() {
//	listarPocoes();
//	
//    int codigo = 0;
//    int pocaoTipo = 0;
//    
//    printf("Digite o codigo da pocao: ");
//    fflush(stdin);
//    scanf("%d", &codigo);
//    
//    if (codigo >= 0 && codigo < POCOES) {
//    	printf("Digite o nome da pocao: ");
//	    fflush(stdin);
//	    scanf("%[^\n]s", &PocaoNome[codigo]);
//	    
//		printf("Digite o tipo da pocao (0 = Liquido, 1 = Comprimido): ");
//	    fflush(stdin);
//	    scanf("%d", &pocaoTipo);
//	    if (pocaoTipo == 0) {
//	    	strcpy(PocaoTipo[codigo], "Liquido");
//		}
//		else if (pocaoTipo == 1) {
//			strcpy(PocaoTipo[codigo], "Comprimido");
//		}
//		PocaoQnt++;
//	}
//	
//}
//
//void excluirPocao() {
//    listarPocoes();
//    
//    int codigo = 0;
//    printf("\nDigite o codigo da pocao: \n");	
//    fflush(stdin);
//    scanf("%d", &codigo);
//    
//    if (codigo >= 0 && codigo < BRUXOS) {
//    	strcpy(PocaoNome[codigo], "");
//    	strcpy(PocaoTipo[codigo], "");
//    	PocaoQnt--;
//	}
//}
//
//void listarPacientes() {
//	printf("\n");
//	for (int i = 0; i < PACIENTES; i++){
//		printf("Paciente %d - Nome: %s | Idade: %d | Altura: %.2f\n", i, PacienteNome[i], PacienteIdade[i], PacienteAltura[i]);
//	}
//}
//
//void cadastrarPaciente() {
//	listarPacientes();
//	
//	int codigo = 0;
//    
//    printf("Digite o codigo do paciente: ");
//    fflush(stdin);
//    scanf("%d", &codigo);
//    
//    if (codigo >= 0 && codigo < PACIENTES) {
//    	printf("Digite o nome do paciente: ");
//	    fflush(stdin);
//	    scanf("%[^\n]s", &PacienteNome[codigo]);
//	    
//		printf("Digite a idade do paciente: ");
//	    fflush(stdin);
//	    scanf("%d", &PacienteIdade[codigo]);
//	    
//	    printf("Digite a altura do paciente: ");
//	    fflush(stdin);
//	    scanf("%f", &PacienteAltura[codigo]);
//	    
//	    PacienteQnt++;
//	}
//}
//
//void excluirPaciente() {
//	listarPacientes();
//    
//    int codigo = 0;
//    printf("\nDigite o codigo do paciente: \n");	
//    fflush(stdin);
//    scanf("%d", &codigo);
//    
//    if (codigo >= 0 && codigo < PACIENTES) {
//    	strcpy(PacienteNome[codigo], "");
//    	PacienteIdade[codigo] = 0;
//    	PacienteAltura[codigo] = 0.0;
//    	PacienteQnt--;
//	}
//}
//
//void listarTratamentos() {
//	printf("\n");
//	for (int i = 0; i < TRATAMENTOS; i++){
//		printf("Tratamento %d - Bruxo: %d | Paciente: %d| Medicamento: %d | Dias: %d | Dosagem: %d | \n", i, TratamentoBruxo[i], TratamentoPaciente[i], TratamentoMedicamento[i], TratamentoDias[i], TratamentoDosagem[i]);
//	}
//
//}
//
//int getTratamentoVago() {
//	int tratamentoVago = -1;
//	for (int i = 0; i < TRATAMENTOS; i++) {
//		if (TratamentoBruxo[i] == -999) {
//			tratamentoVago = i;
//			break;
//		}
//	}
//	return tratamentoVago;
//}
//
//void iniciarTratamento() {
//	if (getTratamentoVago() != -1) {
//		int iTratamento = getTratamentoVago();
//		
//		listarBruxos();
//		int codigo = 0;
//		printf("\nDigite o codigo do bruxo: ");
//		fflush(stdin);
//		scanf("%d", &codigo);
//		
//		if (codigo >= 0 && codigo < BRUXOS) {
//			for (int i = 0; i < BRUXOS; i++){
//				if (strcmp(BruxoNome[i], "")) {
//					TratamentoBruxo[iTratamento] = codigo;
//				}
//			}
//			
//			listarPacientes();
//			int codigo = 0;
//			printf("\nDigite o codigo do paciente: ");
//			fflush(stdin);
//			scanf("%d", &codigo);
//	    	if (codigo >= 0 && codigo < PACIENTES) {
//	    		for (int i = 0; i < PACIENTES; i++){
//					if (strcmp(PacienteNome[i], "")) {
//						TratamentoPaciente[iTratamento] = codigo;
//					}
//				}
//	    		
//	    		listarPocoes();
//	    		int codigo = 0;
//				printf("\nDigite o codigo da pocao: ");
//				fflush(stdin);
//				scanf("%d", &codigo);
//				if (codigo >= 0 && codigo < POCOES) {
//					for (int i = 0; i < POCOES; i++){
//						if (strcmp(PocaoNome[i], "")) {
//							TratamentoMedicamento[iTratamento] = codigo;
//						}
//					}
//					
//					printf("\nQuantos dias?: ");
//					fflush(stdin);
//					scanf("%d", &TratamentoDias[iTratamento]);
//					
//					printf("\nQual a dose?: ");
//					fflush(stdin);
//					scanf("%d", &TratamentoDosagem[iTratamento]);
//				}
//			}
//		}
//	}
//	else {
//		printf("Nao ha tratamentos disponiveis!");
//	}
//}
//
//int getPacienteNomeById(int id) {
//	for (int i = 0; i < PACIENTES; i++) {
//		if (id == i) {
//			return id;
//		}
//	}
//}
//
//int getBruxoNomeById(int id) {
//	for (int i = 0; i < BRUXOS; i++) {
//		if (id == i) {
//			return id;
//		}
//	}
//}
//
//int getPocaoNomeById(int id) {
//	for (int i = 0; i < POCOES; i++) {
//		if (id == i) {
//			return id;
//		}
//	}
//}
//
//void listarTratamentosDoPaciente() {
//	int codigo = 0;
//	
//	printf("\nDigite o codigo do paciente: ");
//	fflush(stdin);
//	scanf("%d", &codigo);
//	
//	int value = 0;
//	if (codigo >= 0 && codigo < TRATAMENTOS) {
//		for (int i = 0; i < TRATAMENTOS; i++) {
//			if (codigo == TratamentoPaciente[i]) {
//				printf("Ola %s! O bruxo %s receitou a pocao %s tipo %s, em dosagens de %d vezes por %d dias.", PacienteNome[getPacienteNomeById(codigo)], BruxoNome[getBruxoNomeById(TratamentoBruxo[i])], PocaoNome[getPocaoNomeById(TratamentoMedicamento[i])], PocaoTipo[getPocaoNomeById(TratamentoMedicamento[i])], TratamentoDosagem[i], TratamentoDias[i]);
//			}
//		}
//		printf("\nPaciente nao encontrado!");
//	}
//	else {
//		printf("\nPaciente nao encontrado!");
//	}
//}
//
//void apagarTratamento() {
//	int codigo = 0;
//	printf("\nDigite o codigo do paciente: ");
//	fflush(stdin);
//	scanf("%d", &codigo);
//	if (codigo >= 0 && codigo < TRATAMENTOS) {
//		for (int i = 0; i < TRATAMENTOS; i++) {
//			if (codigo == TratamentoPaciente[i]) {
//				TratamentoBruxo[i] = -999;
//				TratamentoPaciente[i] = -999;
//				TratamentoMedicamento[i] = -999;
//				TratamentoDias[i] = -999;
//				TratamentoDosagem[i] = -999;
//				break;
//			}
//		}
//	}	
//}
//
//void listarPacientesDoBruxo() {
//	int codigo = 0;
//	printf("\nDigite o codigo do bruxo: ");
//	fflush(stdin);
//	scanf("%d", &codigo);
//	if (codigo >= 0 && codigo < TRATAMENTOS) {
//		for (int i = 0; i < TRATAMENTOS; i++) {
//			if (codigo == TratamentoBruxo[i]) {
//				printf("Tratamento %d - Bruxo: %d | Paciente: %d| Medicamento: %d | Dias: %d | Dosagem: %d | \n", i, TratamentoBruxo[i], TratamentoPaciente[i], TratamentoMedicamento[i], TratamentoDias[i], TratamentoDosagem[i]);
//				break;
//			}
//		}
//	}
//}
//
//void ampliarTratamento() {
//	listarTratamentos();
//	
//	int codigo = 0;
//	printf("\nDigite o codigo do paciente: ");
//	fflush(stdin);
//	scanf("%d", &codigo);
//	if (codigo >= 0 && codigo < TRATAMENTOS) {
//		for (int i = 0; i < TRATAMENTOS; i++) {
//			if (codigo == TratamentoPaciente[i]) {
//				int dias = 0;
//				printf("\nAlterar para quantos dias?: ");
//				fflush(stdin);
//				scanf("%d", &dias);
//				TratamentoDias[i] = dias;
//				
//				int dosagem = 0;
//				printf("\nAlterar para quantas dosagens?: ");
//				fflush(stdin);
//				scanf("%d", &dosagem);
//				TratamentoDosagem[i] = dosagem;
//				
//				break;
//			}
//		}
//	}
//}
