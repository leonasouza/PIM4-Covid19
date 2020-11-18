#define MAX_USUARIOS 10
#define MAX_PACIENTES 50

typedef struct {
    char login[31];
    char senha[31];
} Usuario;

typedef struct {
    char nome[51];
    char telefone[21];
    char rua[51];
    int logradouro;
    char complemento[51];
    char bairro[51];
    char cidade[51];
    char estado[4];
    char cep[10];
    int nascimentoDia;
    int nascimentoMes;
    int nascimentoAno;
    char email[31];
    char dataDiagnostico[11];
    char comorbidade[51];
} Paciente;
