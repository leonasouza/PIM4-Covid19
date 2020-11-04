#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./cadastros/structs.c"
#include "./funcoes/funcoes.h"
#define IDADE_MAXIMA 65

int opcao;logado=0;dia;mes;ano;
    pacienteLogradouro;pacienteNascimentoDia;pacienteNascimentoMes;pacienteNascimentoAno;
char usuario[21];senha[21];
    pacienteNome[51];pacienteTelefone[21];pacienteRua[51];pacienteComplemento[51];pacienteBairro[51];pacienteCidade[51];
    pacienteEstado[3];pacienteCep[10];pacienteEmail[31];pacienteDataDiagnostico[11];pacienteComorbidade[51];
FILE *arquivo;
Usuario structUsuario[MAX_USUARIOS];
Paciente structPaciente[MAX_PACIENTES];

int main(void) {
    dataAtual(); //define os valores para a data atual
    system("chcp 1252"); //configura��o para liberar acentua��o no programa
    popularPrograma(); //carrega dados aleat�rios para popular o programa

    /*do {
        cabecalho();
        printf("1 - Fazer login\n");
        printf("2 - Cadastrar usu�rio\n");
        printf("9 - Sair do sistema\n");
        scanf("%d",&opcao);
        switch (opcao) {
            case 1:
                system("cls");
                printf("Usu�rio: ");
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
                }
                break;
            case 2:
                system("cls");
                printf("Selecione um nome de usu�rio: ");
                scanf("%s",&usuario);
                printf("Escolha uma senha: ");
                scanf("%s",&senha);
                if (usuario!="" && senha!="") {
                    for (int i=0; i<MAX_USUARIOS; i++) {
                        if (strcmp(structUsuario[i].login,"")==0) {
                            strcpy(structUsuario[i].login, usuario);
                            strcpy(structUsuario[i].senha, senha);
                            printf("Usu�rio cadastrado com sucesso\n");
                            system("pause");
                            break;
                        }
                    }
                }
                break;
            case 9:
                return 0;
        }
    } while(logado!=1);*/

    opcao=0;

    do {
        cabecalho();
        printf("Ol�, %s. Selecione uma op��o:\n\n",usuario);
        printf("1 - Cadastrar paciente\n");
        printf("2 - Listar todos os pacientes\n");
        printf("3 - Listar pacientes com comorbidades\n");
        printf("4 - Exportar lista de pacientes de risco\n");
        printf("9 - Fechar o sistema\n");
        scanf("%d",&opcao);
        switch (opcao) {
            case 1:
                cabecalho();
                fflush(stdin);//configura��o para evitar erros na leitura do fgets
                printf("Cadastro de pacientes\n");
                printf("Nome: ");
                    fgets(pacienteNome, sizeof pacienteNome, stdin);
                    strcpy(pacienteNome, formatar(pacienteNome));//a fun��o formatar() evita quebra de linha caso a vari�vel esteja vazia
                printf("Endere�o (rua sem n�mero nem complemento): ");
                    fgets(pacienteRua, sizeof pacienteRua, stdin);
                    strcpy(pacienteRua, formatar(pacienteRua));
                printf("N�mero: ");
                    scanf("%i",&pacienteLogradouro);
                    fflush(stdin);
                printf("Complemento: ");
                    fgets(pacienteComplemento, sizeof pacienteComplemento, stdin);
                    strcpy(pacienteComplemento, formatar(pacienteComplemento));
                printf("Bairro: ");
                    fgets(pacienteBairro, sizeof pacienteBairro, stdin);
                    strcpy(pacienteBairro, formatar(pacienteBairro));
                printf("Cidade: ");
                fflush(stdin);
                    fgets(pacienteCidade, sizeof pacienteCidade, stdin);
                    strcpy(pacienteCidade, formatar(pacienteCidade));
                printf("Estado: ");
                    fgets(pacienteEstado, sizeof pacienteEstado, stdin);
                    strcpy(pacienteEstado, formatar(pacienteEstado));
                printf("CEP: ");
                    fgets(pacienteCep, sizeof pacienteCep, stdin);
                    strcpy(pacienteCep, formatar(pacienteCep));
                printf("Data de nascimento no formato (DD/MM/AAAA): ");
                    scanf("%i/%i/%i",&pacienteNascimentoDia,&pacienteNascimentoMes,&pacienteNascimentoAno);
                    fflush(stdin);
                printf("Telefone: ");
                    fgets(pacienteTelefone, sizeof pacienteTelefone, stdin);
                    strcpy(pacienteTelefone, formatar(pacienteTelefone));
                printf("Email: ");
                    fgets(pacienteEmail, sizeof pacienteEmail, stdin);
                    strcpy(pacienteEmail, formatar(pacienteEmail));
                printf("Data do diagn�stico: ");
                    fgets(pacienteDataDiagnostico, sizeof pacienteDataDiagnostico, stdin);
                    strcpy(pacienteDataDiagnostico, formatar(pacienteDataDiagnostico));
                printf("Comorbidade ou gravidez (n�o preencher se n�o houver): ");
                    fgets(pacienteComorbidade, sizeof pacienteComorbidade, stdin);
                    strcpy(pacienteComorbidade, formatar(pacienteComorbidade));
                for (int i=0;i<MAX_PACIENTES;i++) {
                    if (strcmp(structPaciente[i].nome, "")==0) {
                        strcpy(structPaciente[i].nome, pacienteNome);
                        strcpy(structPaciente[i].rua, pacienteRua);
                        structPaciente[i].logradouro=pacienteLogradouro;
                        strcpy(structPaciente[i].complemento, pacienteComplemento);
                        strcpy(structPaciente[i].bairro, pacienteBairro);
                        strcpy(structPaciente[i].cidade, pacienteCidade);
                        strcpy(structPaciente[i].estado, pacienteEstado);
                        strcpy(structPaciente[i].cep, pacienteCep);
                        structPaciente[i].nascimentoDia=pacienteNascimentoDia;
                        structPaciente[i].nascimentoMes=pacienteNascimentoMes;
                        structPaciente[i].nascimentoAno=pacienteNascimentoAno;
                        strcpy(structPaciente[i].telefone, pacienteTelefone);
                        strcpy(structPaciente[i].email, pacienteEmail);
                        strcpy(structPaciente[i].dataDiagnostico, pacienteDataDiagnostico);
                        strcpy(structPaciente[i].comorbidade, pacienteComorbidade);
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
                        dadosDoPaciente(i);
                    }
                }
                system("pause");
                break;
            case 3:
                cabecalho();
                for (int i=0;i<MAX_PACIENTES;i++) {
                    if (strcmp(structPaciente[i].comorbidade, "")!=0) {
                        dadosDoPaciente(i);
                    }
                }
                system("pause");
                break;
            case 4:
                arquivo = fopen("ListaDeRisco.txt","w");
                for (int i=0;i<MAX_PACIENTES;i++) {
                    int diferencaAno = ano - structPaciente[i].nascimentoAno;
                    if (strcmp(structPaciente[i].comorbidade, "")!=0) {
                        if (diferencaAno > IDADE_MAXIMA) {
                            exportarPaciente(i);
                        } else if (diferencaAno == IDADE_MAXIMA) {
                            if (mes > structPaciente[i].nascimentoMes) {
                                exportarPaciente(i);
                            } else if (mes == structPaciente[i].nascimentoMes) {
                                if (dia >= structPaciente[i].nascimentoDia) {
                                    exportarPaciente(i);
                                }
                            }
                        }
                    }
                }
                fclose(arquivo);
                cabecalho();
                printf("\nA lista de pacientes do grupo de risco foi salva automaticamente em um arquivo externo\n");
                system("pause");
                break;
        }
    } while (opcao!=9);
    return 0;
}

