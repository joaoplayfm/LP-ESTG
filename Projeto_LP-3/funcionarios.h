#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

#include "IRS.h"

#define MIN_NUM_FUNCIONARIO                 0

#define MAX_NOME_FUNCIONARIO                31
#define MSG_OBTER_NOME                      "Insira o nome do funcionario: "

#define MAX_CP_FUNC                         30
#define MSG_OBTER_CP                        "Código Postal: "

#define MAX_MORADA_FUNC                     1000
#define MSG_OBTER_MORADA                    "Morada: "

#define MIN_DIA                             0
#define MAX_DIA                             31
#define MAX_DIA_TRABALHO                    1000
#define OBTER_DIA_NASC                      "\tDia: "

#define MIN_MES                             1
#define MAX_MES                             12
#define OBTER_MES_NASC                      "\tMês: "

#define MIN_ANO                             1900
#define MAX_ANO                             2021
#define OBTER_ANO_NASC                      "\tAno: "

#define OBTER_DIA_ENTRADA                   "\tDia: "        
#define OBTER_MES_ENTRADA                   "\tMês: "
#define OBTER_ANO_ENTRADA                   "\tAno: "

#define OBTER_DIA_SAIDA                     "\tDia: "
#define OBTER_MES_SAIDA                     "\tMês: "
#define OBTER_ANO_SAIDA                     "\tAno: "

#define ERRO_FUNCIONARIO_NAO_EXISTE         "O funcionario não existe na lista."
#define ERRO_LISTA_VAZIA                    "A lista de funcionarios está vazia."
#define ERRO_FUNCIONARIO_EXISTE             "O número de funcionario já se encontra atribuído."
#define VALOR_INVALIDO                      "O valor inserido é inválido."
#define DATA_INVALIDA                       "\nA data inserida é inválida.\nPor Favor volte a inserir a data.\n"


#define MSG_OBTER_NUM_FUNCIONARIO           "Insira o código de funcionario: "
#define OBTER_DIAS_TRABALHO                 "Insira os dias que trabalhou(sem contar com fins de semana): "
#define MSG_PROCURAR_FUNCIONARIO            "Insira o código do funcionario que deseja procurar: "
#define MSG_REMOVER_FUNCIONARIO             "Insira o código do funcionario que deseja remover: "
#define MSG_EDITAR_FUNCIONARIO              "Insira o código do funcionario que deseja editar: "
#define MSG_CALCULO_FUNCIONARIO             "Insira o código do funcionario para efectuar o Cálculo Salarial: "
#define MSG_NUM_TELEMOVEL                   "Insira o número de telemóvel: "
#define MSG_NUM_DEPENDENTES                 "\nInsira o número de dependentes: "
#define MSG_VALOR_HORA                      "Valor por hora: "
#define MSG_SUB_ALIMENTACAO                 "Subsidio de Alimentação(Por Dia(€)): "
#define MSG_OBTER_DIUTURNIDADES             "Diuturnidades(€): "
#define MSG_OBTER_BONUS                     "Bónus(€): "
#define MSG_OBTER_PREMIO                    "Prémios de produtividade(€): "
#define MSG_OBTER_HORAS                     "Horas Extras(€): "
#define MSG_OBTER_CARGO                     "\n1 ---> Chefe\n2 ---> Administrador\n3 ---> Empregado\nCargo: "
#define MSG_ESTADO_CIVIL                    "\n1 ---> Nao Casado\n2 ---> Casado Unico Titular\n3 ---> Casado Dois Titulares\nEstado Civil: "
#define MSG_OBTER_GENERO                    "\n1---> Masculino\t2---> Feminino\nGenero: "
#define MSG_BONUS_AMTIGUIDADE               "Bónus de Antiguidasde na Empresa(€): "
#define MSG_OBTER_IDADE                     "Idade: "
#define MSG_FIM_SEMANA                      "Número de Dias Trabalhados ao Fim de Semana: "

typedef struct {
    int ano, mes, dia;
} Data;

typedef struct {
    int codigo, numDependentes, diasTrabalho, op, estadoCivil, genero, nfaltas, idade, nFimSemana, diasTotais;
    char nome[MAX_NOME_FUNCIONARIO], morada[MAX_MORADA_FUNC], cp[MAX_CP_FUNC];
    float valHora, subAlim, horasextras, diuturnidades, bonus, premio, irs, salLiquido, ss, subAlimentacao, bonusTotal;
    long numTele;
    Data data_nascimento, data_entrada, data_saida;
	char apagado;
} Funcionario;


typedef struct
{
	Funcionario *array;
	int size; //todos os registos
	int contador; //registos nao apagados

} Funcionarios;

void procuraImprimeFuncionario(Funcionarios *funcionarios);
void atualizarFuncionarios(Funcionarios *funcionarios);
void removerFuncionarios(Funcionarios *funcionarios);
void listarFuncionarios(Funcionarios *funcionarios);
void calculoSalarial(Funcionarios *funcionarios, float valorSS[3]);
void listarFaltas(Funcionarios funcionarios);
int inserirFuncionario(Funcionarios *funcionarios);
//retorna 0 se inserido com sucesso
void funcionarios_Init(Funcionarios *array);
char funcionarios_Add(Funcionarios *array, Funcionario item);
#endif 
