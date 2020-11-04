extern int dia;mes;ano;
extern Paciente structPaciente[MAX_PACIENTES];
extern Usuario structUsuario[MAX_USUARIOS];
extern FILE *arquivo;
extern const IDADE_MAXIMA;
char saida[256];
int dia;mes;ano;

void cabecalho() {
    system("cls");
    printf("==================\n");
    printf("=====COVID-19=====\n");
    printf("==================\n");
}

void dataAtual() {
    time_t agora;
    time(&agora);
    struct tm *aqui = localtime(&agora);
    dia = aqui->tm_mday;
    mes = aqui->tm_mon+1;
    ano = aqui->tm_year+1900;
}

void dadosDoPaciente(int i) {
    printf("PACIENTE: %s, diagnosticado em: %s\n", structPaciente[i].nome, structPaciente[i].dataDiagnostico);
    printf("     Cidade: %s | Bairro: %s | Estado: %s\n", structPaciente[i].cidade, structPaciente[i].bairro, structPaciente[i].estado);
    printf("     Rua: %s | N.: %d | Complemento: %s | ", structPaciente[i].rua, structPaciente[i].logradouro, structPaciente[i].complemento);
    printf("CEP: %s\n", structPaciente[i].cep);
    printf("     Nascimento: %02d/%02d/%04d | ", structPaciente[i].nascimentoDia, structPaciente[i].nascimentoMes, structPaciente[i].nascimentoAno);
    printf("Email: %s | Telefone: %s\n", structPaciente[i].email, structPaciente[i].telefone);
    printf("     Comorbidade/Gravidez: %s\n", structPaciente[i].comorbidade);
    printf("---------------------------------------------------\n");
}

void exportarPaciente(int i) {
    fprintf(arquivo, "PACIENTE: %s, diagnosticado em: %s\n", structPaciente[i].nome, structPaciente[i].dataDiagnostico);
    fprintf(arquivo, "     Cidade: %s | Bairro: %s | Estado: %s\n", structPaciente[i].cidade, structPaciente[i].bairro, structPaciente[i].estado);
    fprintf(arquivo, "     Rua: %s | N.: %d | Complemento: %s | ", structPaciente[i].rua, structPaciente[i].logradouro, structPaciente[i].complemento);
    fprintf(arquivo, "CEP: %s\n", structPaciente[i].cep);
    fprintf(arquivo, "     Nascimento: %02d/%02d/%04d | ", structPaciente[i].nascimentoDia, structPaciente[i].nascimentoMes, structPaciente[i].nascimentoAno);
    fprintf(arquivo, "Email: %s | Telefone: %s\n", structPaciente[i].email, structPaciente[i].telefone);
    fprintf(arquivo, "     Comorbidade/Gravidez: %s\n", structPaciente[i].comorbidade);
    fprintf(arquivo, "---------------------------------------------------\n");
}

void exportarPacienteDeRisco(int i,int idade) {
    fprintf(arquivo, "PACIENTE: %s, CEP: %s, IDADE:%d\n", structPaciente[i].nome, structPaciente[i].cep, idade);
    fprintf(arquivo, "---------------------------------------------------\n");
}

char* formatar(char *entrada) {
        saida[250] = strcpy(saida,"");;
    if (strcmp(entrada,"\n")==0) {
        saida[250] = strcpy(entrada,"");
    } else {
        saida[250] = strcpy(saida,entrada);
        saida[250] = strtok(saida,"\n");
    }
    return saida;
}

int verificaIdade(int i) {
    int diferencaAno = ano - structPaciente[i].nascimentoAno;
    int idade;
        if (diferencaAno > IDADE_MAXIMA) {
            idade = diferencaAno;
        } else if (diferencaAno == IDADE_MAXIMA) {
            if (mes > structPaciente[i].nascimentoMes) {
                idade = diferencaAno;
            } else if (mes == structPaciente[i].nascimentoMes) {
                if (dia >= structPaciente[i].nascimentoDia) {
                    idade = diferencaAno;
                }
            }
        }
    return idade;
}

void popularPrograma() {
    //Usuário padrão do sistema
    strcpy(structUsuario[0].login, "admin");
    strcpy(structUsuario[0].senha, "admin");
    //Pacientes aleatórios
    strcpy(structPaciente[0].nome, "José da Silva");
    strcpy(structPaciente[0].telefone, "11 95555-5555");
    strcpy(structPaciente[0].rua, "Rua dos Bobos");
    structPaciente[0].logradouro=0;
    strcpy(structPaciente[0].complemento, "");
    strcpy(structPaciente[0].bairro, "Jardim dos Jardins");
    strcpy(structPaciente[0].cidade, "São Paulo");
    strcpy(structPaciente[0].estado, "SP");
    strcpy(structPaciente[0].cep, "01234-567");
    structPaciente[0].nascimentoDia=01;
    structPaciente[0].nascimentoMes=11;
    structPaciente[0].nascimentoAno=1950;
    strcpy(structPaciente[0].email, "email@email.com");
    strcpy(structPaciente[0].dataDiagnostico, "01/01/2020");
    strcpy(structPaciente[0].comorbidade, "Diabetes");
    //Segundo paciente aleatório
    strcpy(structPaciente[1].nome, "Maria de Souza");
    strcpy(structPaciente[1].telefone, "21 5555-5555");
    strcpy(structPaciente[1].rua, "Rua de Asfalto");
    structPaciente[1].logradouro=42;
    strcpy(structPaciente[1].complemento, "apto. 101");
    strcpy(structPaciente[1].bairro, "Vila do Chaves");
    strcpy(structPaciente[1].cidade, "Rio de Janeiro");
    strcpy(structPaciente[1].estado, "RJ");
    strcpy(structPaciente[1].cep, "00000-000");
    structPaciente[1].nascimentoDia=21;
    structPaciente[1].nascimentoMes=01;
    structPaciente[1].nascimentoAno=2000;
    strcpy(structPaciente[1].email, "outro@email.com.br");
    strcpy(structPaciente[1].dataDiagnostico, "25/05/2020");
    strcpy(structPaciente[1].comorbidade, "");
}
