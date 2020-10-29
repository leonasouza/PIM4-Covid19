#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
#include "./cadastros/structs.c"

/*
* Arquivo com:
    nome
    idade
    cep
*/
void cabecalho() {
    system("cls");
    printf("==================\n");
    printf("=====COVID-19=====\n");
    printf("==================\n");
}

int opcao; logado=0;
pacienteLogradouro;pacienteCep;
char usuario[20]; senha[20];
pacienteNome[50];pacienteTelefone[20];pacienteRua[50];pacienteComplemento[50];pacienteBairro[50];pacienteCidade[50];
pacienteEstado[2];pacienteEmail[30];pacienteDataDiagnostico[10];pacienteComorbidade[50];
Usuario structUsuario[MAX_USUARIOS];
Paciente structPaciente[MAX_PACIENTES];


int main(void) {
    setlocale(LC_ALL, "Portuguese"); //permite acentuação em geral
    system("chcp 1252"); //permite input com acentuação
    strcpy(structUsuario[0].login, "admin");
    strcpy(structUsuario[0].senha, "admin");
    strcpy(structPaciente[0].nome, "João da Silva");
    strcpy(structPaciente[0].telefone, "11 95555-5555");
    strcpy(structPaciente[0].rua, "Rua dos Bobos");
    structPaciente[0].logradouro=0;
    strcpy(structPaciente[0].complemento, "");
    strcpy(structPaciente[0].bairro, "Jardim dos Jardins");
    strcpy(structPaciente[0].cidade, "São Paulo");
    strcpy(structPaciente[0].estado, "SP");
    structPaciente[0].cep=01234567;
    structPaciente[0].nasc.dia=01;
    structPaciente[0].nasc.mes=12;
    structPaciente[0].nasc.ano=2000;
    strcpy(structPaciente[0].email, "email@email.com");
    strcpy(structPaciente[0].dataDiagnostico, "01/01/2020");
    strcpy(structPaciente[0].comorbidade, "Diabetes");

    do {
        cabecalho();
        printf("1 - Fazer login\n");
        printf("2 - Cadastrar usuário\n");
        scanf("%d",&opcao);
        switch (opcao) {
            case 1:
                system("cls");
                printf("Usuário: ");
                scanf("%s",&usuario);
                printf("Senha: ");
                scanf("%s",&senha);
                for (int i=0; i<MAX_USUARIOS; i++) {
                   if (strcmp(structUsuario[i].login, usuario)==0 && strcmp(structUsuario[i].senha, senha)==0) {
                        logado=1;
                        break;
                    }
                }
                if (logado==0) {
                    printf("Dados incorretos\n");
                    system("pause");
                    break;
                }
                break;
            case 2:
                system("cls");
                printf("Selecione um nome de usuário: ");
                scanf("%s",&usuario);
                printf("Escolha uma senha: ");
                scanf("%s",&senha);
                if (usuario!="" && senha!="") {
                    for (int i=0; i<MAX_USUARIOS; i++) {
                        if (strcmp(structUsuario[i].login,"")==0) {
                            strcpy(structUsuario[i].login, usuario);
                            strcpy(structUsuario[i].senha, senha);
                            printf("Usuário cadastrado com sucesso\n");
                            system("pause");
                            break;
                        }
                    }
                }
                break;
        }
    } while(logado!=1);

    opcao=0;

    do {
        cabecalho();
        printf("Olá, %s. Selecione uma opção:\n\n",usuario);
        printf("1 - Cadastrar paciente\n");
        printf("2 - Listar todos os pacientes\n");
        printf("3 - Listar pacientes do grupo de risco\n");
        printf("9 - Fechar o sistema\n");
        scanf("%d",&opcao);
        switch (opcao) {
            case 1:
                cabecalho();
                fflush(stdin);
                printf("Cadastro de pacientes\n");
                printf("Nome: ");
                fgets(pacienteNome, sizeof pacienteNome, stdin);
                strtok(pacienteNome, "\n");
                printf("Cidade: ");
                fgets(pacienteCidade, sizeof pacienteCidade, stdin);
                strtok(pacienteCidade, "\n");
                for (int i=0;i<MAX_PACIENTES;i++) {
                    if (strcmp(structPaciente[i].nome, "")==0) {
                        strcpy(structPaciente[i].nome, pacienteNome);
                        strcpy(structPaciente[i].cidade, pacienteCidade);
                        break;
                    }
                }
                printf("Paciente cadastrado com sucesso\n");
                system("pause");
                break;
            case 2:
                cabecalho();
                for (int i=0;i<MAX_PACIENTES;i++) {
                    if (strcmp(structPaciente[i].nome, "")!=0) {
                        printf("Nome: %s | Cidade: %s | Bairro: %s\n", structPaciente[i].nome, structPaciente[i].cidade, structPaciente[i].bairro);
                    }
                }
                system("pause");
                break;
            case 3:
                cabecalho();
                for (int i=0;i<MAX_PACIENTES;i++) {
                    if (strcmp(structPaciente[i].comorbidade, "")!=0) {
                        printf("Nome: %s | Cidade: %s | Comorbidade: %s\n", structPaciente[i].nome, structPaciente[i].cidade, structPaciente[i].comorbidade);
                    }
                }
                printf("A lista de pacientes do grupo de risco foi salva automaticamente em um arquivo externo\n");
                system("pause");
                break;
        }
    } while (opcao!=9);
    return 0;
}

