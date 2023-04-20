#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionarios.h"
#include "input.h"
#include "ficheiros.h"
#include <limits.h>

#pragma warning (disable : 4996)
/**
 * Esta função permite listar os dados dos funcionarios
 * @param funcionario
 */
void imprimirFuncionario(Funcionario funcionario) {
    printf("|------------------------------------------------|\n");
    printf("|Código ---> %d                                  \n", funcionario.codigo);
    printf("|------------------------------------------------|\n");
    printf("|Nome ---> %s                                    \n", funcionario.nome);
    printf("|------------------------------------------------|\n");
    printf("|Nascimento ---> %d-%d-%d                        \n", funcionario.data_nascimento.dia, funcionario.data_nascimento.mes, funcionario.data_nascimento.ano);
    printf("|------------------------------------------------|\n");
    printf("|Número de Telemóvel --> %ld                     \n", funcionario.numTele);
    printf("|------------------------------------------------|\n");
    printf("|Morada ---> %s                                  \n", funcionario.morada);
    printf("|------------------------------------------------|\n");
    printf("|Código Postal ---> %s                           \n", funcionario.cp);
    printf("|------------------------------------------------|\n");
    printf("|Número Dependestes ---> %d                      \n", funcionario.numDependentes);
    printf("|------------------------------------------------|\n");
    printf("|Data Entrada ---> %d-%d-%d                      \n", funcionario.data_entrada.dia, funcionario.data_entrada.mes, funcionario.data_entrada.ano);
    printf("|------------------------------------------------|\n");
    
    if(funcionario.genero == 1){
    printf("|Genero ---> Masculino                           \n");
    printf("|------------------------------------------------|\n");
    }
    else {
    printf("|Genero ---> Feminino                            \n");
    printf("|------------------------------------------------|\n");
    }
    if(funcionario.op == 1){
    printf("|Cargo ---> Chefe                                \n");
    printf("|------------------------------------------------|\n");
    }
    else if(funcionario.op == 2){
    printf("|Cargo ---> Administrador                        \n");
    printf("|------------------------------------------------|\n");
    }
    else if(funcionario.op == 3){
    printf("|Cargo ---> Empregado                            \n");
    printf("|------------------------------------------------|\n");
    }
      if(funcionario.estadoCivil == 1){
    printf("|Estado Civil ---> Nao Casado                    \n");
    printf("|------------------------------------------------|\n");
    }
      else if(funcionario.estadoCivil == 2){
    printf("|Estado Civil ---> Casado Unico Titular          \n");
    printf("|------------------------------------------------|\n");
    }
      else if(funcionario.estadoCivil == 3){
    printf("|Estado Civil ---> Casado Dois Titulares         \n");
    printf("|------------------------------------------------|\n");
    }
    if (funcionario.data_saida.dia == 0 && funcionario.data_saida.mes == 0 && funcionario.data_saida.ano == 0) {
    } else {
    printf("|Data Saída ---> %d-%d-%d                        |\n", funcionario.data_saida.dia, funcionario.data_saida.mes, funcionario.data_saida.ano);
    printf("|------------------------------------------------|\n");
    }
}

/**
 * Esta função permite procurar funcionarios já inseridos
 * @param funcionarios
 * @param codigo
 * @return i se encontrar o funcionario -1 se não encontrar
 */
int procurarFuncionario(Funcionarios *funcionarios, int codigo) {

    for (int i = 0; i < funcionarios->size; i++) {
        if (funcionarios->array[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

/**
 * Esta função permite inserir funcionários
 * @param funcionarios
 * @return 0 se sucesso, -1 não sucesso
 */
int inserirFuncionario(Funcionarios *funcionarios) {
 
    int codigo = obterInteiro(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_OBTER_NUM_FUNCIONARIO);
    char x;
    long obterLong(long minValor, long maxValor, char *msg);
    if (procurarFuncionario(funcionarios, codigo) == -1) {

        Funcionario f;
		f.apagado = 0;
        f.codigo = codigo;
        
        lerString(f.nome, MAX_NOME_FUNCIONARIO, MSG_OBTER_NOME);
       
        f.numTele = obterLong(900000000, 999999999, MSG_NUM_TELEMOVEL);
        
        lerString(f.morada, MAX_NOME_FUNCIONARIO, MSG_OBTER_MORADA);
        
        lerString(f.cp, MAX_NOME_FUNCIONARIO, MSG_OBTER_CP);
        
        do{
            int diasTrabalho = obterInteiro(MIN_NUM_FUNCIONARIO, INT_MAX, OBTER_DIAS_TRABALHO);
            f.diasTrabalho = diasTrabalho;
        if(f.diasTrabalho >= 0 && f.diasTrabalho <=22){
            
        }
        else {
             puts(VALOR_INVALIDO);
        }
        }while (f.diasTrabalho < 0 || f.diasTrabalho >22);
        
        do{
        int nFimSemana = obterInteiro(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_FIM_SEMANA);
        f.nFimSemana = nFimSemana;
        if (f.nFimSemana >= 0 && f.nFimSemana <=10){
            
        }
        else {
            puts(VALOR_INVALIDO);
        }
        }while (f.nFimSemana < 0 || f.nFimSemana >10);

        f.diasTotais = f.diasTrabalho + f.nFimSemana;
        
        printf("\nData de Nascimento:\n");
        f.data_nascimento.dia = obterInteiro(MIN_DIA, MAX_DIA, OBTER_DIA_NASC);
        f.data_nascimento.mes = obterInteiro(MIN_MES, MAX_MES, OBTER_MES_NASC);
        f.data_nascimento.ano = obterInteiro(MIN_ANO, MAX_ANO, OBTER_ANO_NASC);
        
        f.idade = 2021 - f.data_nascimento.ano;
        printf("Idade ---> %d\n", f.idade);
        
        int op = obterInteiro(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_OBTER_CARGO);
        f.op = op;
        
        int estadoCivil = obterInteiro(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_ESTADO_CIVIL);
        f.estadoCivil = estadoCivil;
        
        int numDependentes = obterInteiro(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_NUM_DEPENDENTES);
        f.numDependentes = numDependentes;

        int genero = obterInteiro(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_OBTER_GENERO);
        f.genero = genero;
        do {
            printf("\nEntrada na Empresa:\n");
            f.data_entrada.dia = obterInteiro(MIN_DIA, MAX_DIA, OBTER_DIA_ENTRADA);
            f.data_entrada.mes = obterInteiro(MIN_MES, MAX_MES, OBTER_MES_ENTRADA);
            f.data_entrada.ano = obterInteiro(MIN_ANO, MAX_ANO, OBTER_ANO_ENTRADA);
            if (f.data_nascimento.ano <= f.data_entrada.ano) {
                break;
            } else {
                puts(DATA_INVALIDA);
            }
        } while (f.data_nascimento.ano > f.data_entrada.ano);

        do {
            printf("Continua na Empresa(S-Sim  N-Não): ");
            scanf(" %c", &x);
            if (x == 'N' || x == 'n') {
                do {
                    printf("------------------\n");
                    printf("Saída da Empresa:\n");
                    f.data_saida.dia = obterInteiro(MIN_DIA, MAX_DIA, OBTER_DIA_SAIDA);
                    f.data_saida.mes = obterInteiro(MIN_MES, MAX_MES, OBTER_MES_SAIDA);
                    f.data_saida.ano = obterInteiro(MIN_ANO, MAX_ANO, OBTER_ANO_SAIDA);
                    if (f.data_saida.ano > f.data_entrada.ano) {
                        break;
                    } else {
                        puts(DATA_INVALIDA);
                    }
                } while (f.data_saida.ano < f.data_entrada.ano ||
                        f.data_saida.ano < f.data_nascimento.ano);
                break;

            } else if (x == 'S' || x == 's') {
				f.data_saida.dia = 0;
				break;

            } else if (x != 's' || x != 'S' && x != 'n' || x != 'N') {
                puts(VALOR_INVALIDO);
            }
        } while (x != 's' || x != 'S');
		if (funcionarios_Add(funcionarios, f) == 1)
		{
			funcionarios->contador++;
			return 0;
		}

    }
    
    printf(ERRO_FUNCIONARIO_EXISTE);
    return -1;
}

/**
 * Esta função permite editar os dados de um funcionário
 * @param funcionario
 */
void atualizarFuncionario(Funcionario *funcionario) {
    lerString((*funcionario).nome, MAX_NOME_FUNCIONARIO, MSG_OBTER_NOME);
    lerString((*funcionario).morada, MAX_NOME_FUNCIONARIO, MSG_OBTER_MORADA);
    lerString((*funcionario).cp, MAX_NOME_FUNCIONARIO, MSG_OBTER_CP);
    (*funcionario).numTele = obterLong(900000000, 999999999, MSG_NUM_TELEMOVEL);
    (*funcionario).op = obterFloat(0, 999999999, MSG_OBTER_CARGO);
    (*funcionario).numDependentes = obterInteiro(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_NUM_DEPENDENTES);
    (*funcionario).estadoCivil = obterFloat(0, 999999999, MSG_ESTADO_CIVIL);
    (*funcionario).diasTrabalho = obterFloat(0, 999999999, OBTER_DIAS_TRABALHO);
    (*funcionario).nFimSemana = obterFloat(0, 999999999, MSG_FIM_SEMANA);
}

/**
 * Esta função permite realizar o cáculo salarial
 * @param funcionarios
 * @param valorSS
 */
void calculoSalarial(Funcionarios *funcionarios, float valorSS[3]) {
    Funcionario *funcionario;
    int codigo = procurarFuncionario(funcionarios, obterInteiro(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_CALCULO_FUNCIONARIO));
    
    if (codigo != -1) {
        funcionario =&funcionarios->array[codigo];
    }
    else {
        printf(ERRO_FUNCIONARIO_NAO_EXISTE);
        return;
    }  
    float salBruto;
    float valuesEstadoCivil[MAX_LINHAS][MAX_COLUNAS];
    int nlinhas=0;
        float valHora = obterFloat(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_VALOR_HORA);
        funcionario->valHora = valHora;
        float subAlim = obterFloat(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_SUB_ALIMENTACAO);
        funcionario->subAlim = subAlim;
        float horasextras = obterFloat(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_OBTER_HORAS);
        funcionario->horasextras = horasextras;
        float diuturnidades = obterFloat(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_OBTER_DIUTURNIDADES);
        funcionario->diuturnidades = diuturnidades;
        float bonus = obterFloat(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_OBTER_BONUS);
        funcionario->bonus = bonus;
        float premio = obterFloat(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_OBTER_PREMIO);
        funcionario->premio = premio;
        funcionario->bonusTotal = funcionario->horasextras + funcionario->diuturnidades + funcionario->bonus + funcionario->premio;
        funcionario->nfaltas = (22 - funcionario->diasTrabalho);
        printf("\nFaltou: %d dias\n", funcionario->nfaltas);
        printf("Dias Totais Trabalhados ---> %d\n", funcionario->diasTotais);
        funcionario->subAlimentacao = funcionario->subAlim * funcionario->diasTotais;
        funcionario->nFimSemana = funcionario->valHora * 8 * 1.5 * funcionario->nFimSemana;
        if(funcionario->nfaltas <= 3){
            funcionario->bonusTotal = funcionario->bonusTotal + 10;
        }
        else {
            
        }
        if(funcionario->idade >= 40 && funcionario->idade <= 65){
            funcionario->bonusTotal = funcionario->bonusTotal + 25;
        }
        else {
            
        }
        switch(funcionario ->estadoCivil){
            case 1:
                nlinhas = ler_csv(FILEPATH_NC, valuesEstadoCivil);
                break;
            case 2:
                nlinhas = ler_csv(FILEPATH_CUT, valuesEstadoCivil);
                break;
            case 3:
                nlinhas = ler_csv(FILEPATH_CDT, valuesEstadoCivil);
                break;
        }


        switch (funcionario->op) {
            case 1:
                funcionario->ss = ((((funcionario->valHora * 8) * funcionario->diasTrabalho)
                        + funcionario->bonusTotal + funcionario->nFimSemana) * valorSS[1] );
                break;
            case 2:
                funcionario->ss = ((((funcionario->valHora * 8) * funcionario->diasTrabalho)
                        + funcionario->bonusTotal + funcionario->nFimSemana) * valorSS[0]);
                break;
            case 3:
                funcionario->ss = ((((funcionario->valHora * 8) * funcionario->diasTrabalho)
                        + funcionario->bonusTotal + funcionario->nFimSemana) * valorSS[2]);
                break;
        }
        salBruto = (((funcionario->valHora * 8) * funcionario->diasTrabalho)
                        + funcionario->bonusTotal + funcionario->nFimSemana);
        
        float salarioTabela=0;
        float taxaDependentes=0;
        for(int i = 1; i < nlinhas; i++)
        {
            if(salBruto < valuesEstadoCivil[i][0])
            {
                salarioTabela = valuesEstadoCivil[i-1][0];
                taxaDependentes = valuesEstadoCivil[i-1][funcionario->numDependentes+1];
                break;
            }
        }
        funcionario->irs = salBruto * taxaDependentes;
        funcionario->salLiquido = salBruto + funcionario->subAlimentacao - funcionario->ss - funcionario->irs;
      printf("\n|----------------------------------------------------------------|\n");
        printf("|Salário Bruto --->                      %f€         \n", salBruto);
        printf("|----------------------------------------------------------------|\n");
        printf("|Subsidio Alimentação --->               %f€         \n", funcionario->subAlimentacao);
        printf("|----------------------------------------------------------------|\n");
        printf("|Bónus Total --->                        %f€         \n", funcionario->bonusTotal);
        printf("|----------------------------------------------------------------|\n");
        printf("|Valor Bruto Segurança Social --->       %f€         \n", funcionario->ss);
        printf("|----------------------------------------------------------------|\n");
        printf("|IRS --->                                %f€         \n", funcionario->irs);
        printf("|----------------------------------------------------------------|\n");
        printf("|Salário Liquido -->                     %f€         \n", funcionario->salLiquido);
        printf("|----------------------------------------------------------------|\n");
    }

/**
 * Esta função permite ler o código de funcionario que vai ser listado
 * @param funcionarios
 */
void procuraImprimeFuncionario(Funcionarios *funcionarios) {
    int codigo = procurarFuncionario(funcionarios, obterInteiro(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_PROCURAR_FUNCIONARIO));

    if (codigo != -1) {
        imprimirFuncionario(funcionarios->array[codigo]);
    } else {
        printf(ERRO_FUNCIONARIO_NAO_EXISTE);
    }
}

/**
 * Esta função permite ler o código de funcionario que vai ser editado
 * @param funcionarios
 */
void atualizarFuncionarios(Funcionarios *funcionarios) {
    int codigo = procurarFuncionario(funcionarios, obterInteiro(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_EDITAR_FUNCIONARIO));

    if (codigo != -1) {
        atualizarFuncionario(&funcionarios->array[codigo]);
    } else {
        printf(ERRO_FUNCIONARIO_NAO_EXISTE);
    }
}

/**
 * Esta função permite remover um funcionário da lista, mas não apaga os seus dados
 * @param funcionarios
 */
void removerFuncionarios(Funcionarios *funcionarios) {
    int i = procurarFuncionario(funcionarios, obterInteiro(MIN_NUM_FUNCIONARIO, INT_MAX, MSG_REMOVER_FUNCIONARIO));

    if (i != -1) {
		funcionarios->array[i].apagado = 1;
		funcionarios->contador--;
    } else {
        printf(ERRO_FUNCIONARIO_NAO_EXISTE);
    }
}

/**
 * Permite listar os funcionarios
 * @param funcionarios
 */
void listarFuncionarios(Funcionarios *funcionarios) {
    if (funcionarios->size > 0) {
        int i;
        for (i = 0; i < funcionarios->size; i++) {
			if (funcionarios->array[i].apagado == 0)
			{
				imprimirFuncionario(funcionarios->array[i]);
			}
        }
    } else {
        printf(ERRO_LISTA_VAZIA);
    }

}

/**
 * Esta função permite alocar um funcionario na memória
 * @param array
 * @param item
 * @return 1 se sucesso, 0 se ocorrer um erro
 */
void funcionarios_Init(Funcionarios *array)
{
	Funcionario *func_pointer;

	func_pointer = (Funcionario *)malloc(sizeof(Funcionario));

	if (func_pointer == NULL)
	{
		printf("Impossível alocar memória.\n");
		free(func_pointer);
		exit(0);
	}
	else
	{
		array->array = func_pointer;
		array->size = 0;
		array->contador = 0;
	}
}

/**
 * Esta função permite realocar um funcionario na memória
 * @param array
 * @param item
 * @return 1 se sucesso, 0 se ocorrer um erro
 */
char funcionarios_Add(Funcionarios *array, Funcionario item)
{
	Funcionario *func_pointer;

	array->size += 1;

	func_pointer = (Funcionario *)realloc(array->array, array->size * sizeof(Funcionario));

	if (func_pointer == NULL)
	{
		printf("Impossível realocar memória\n");
		free(func_pointer);
		return 0;
	}
	else
	{
		array->array = func_pointer;
		array->array[array->size - 1] = item;
		return 1;
	}
}
