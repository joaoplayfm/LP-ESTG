
#include <stdio.h>
#include <stdlib.h>
#include "Listagens.h"
#include "funcionarios.h"

int contChefe = 0, contAdmin = 0, contEmp = 0;

/**
 * Permite listar o numero de cargos existentes
 * @param funcionario
 */
void imprimirCargo(Funcionario funcionario) {
    printf("%d ---> %s", funcionario.codigo, funcionario.nome);
    if(funcionario.op == 1){
    printf("\nCargo: Chefe\n");
    contChefe++;
    }
    else if(funcionario.op == 2){
        printf("\nCargo: Administrador\n");
        contAdmin++;
    }
    else if(funcionario.op == 3){
        printf("\nCargo: Empregado\n");
        contEmp++;
    }
    printf("\nExistem %d Chefes\n", contChefe);
    printf("Existem %d Administradores\n", contAdmin);
    printf("Existem %d Empregados\n", contEmp);
}

void listarCargo(Funcionarios funcionarios) {
	if (funcionarios.contador > 0) {
		int i;
		for (i = 0; i < funcionarios.size; i++) {
			if (funcionarios.array[i].apagado == 0)
			{
				printf("-----------------------------\n");
				imprimirCargo(funcionarios.array[i]);
			}
        }
    } else {
        printf(ERRO_LISTA_VAZIA);
    }
}

int contHomem = 0, contMulher = 0;

/**
 * Permite listar o nº de homens, e o nº de mulheres, que trabalham na empresa
 * @param funcionario
 */
void imprimirGenero(Funcionario funcionario) {
    printf("%d ---> %s\n", funcionario.codigo, funcionario.nome);
        if(funcionario.genero == 1){
            printf("Genero: Masculino\n");
        contHomem++;       
    }
    else {
             printf("Genero: Feminino\n");
        contMulher++;
    }
    printf("\nExistem %d Homem", contHomem);
    printf("\nExistem %d Mulheres\n", contMulher);
}
void listarGenero(Funcionarios funcionarios) {
	if (funcionarios.contador > 0) {
		int i;
		for (i = 0; i < funcionarios.size; i++) {
			if (funcionarios.array[i].apagado == 0)
			{
				printf("-----------------------------\n");
				imprimirGenero(funcionarios.array[i]);
			}
        }
    } else {
        printf(ERRO_LISTA_VAZIA);
    }
}


/**
 * Esta função permite imprimir o Salário Liquido, os valores de IRS, e os valores da Segurança Social 
 * @param funcionario
 */
void imprimirIrsSSSalarios(Funcionario funcionario) {
    printf("%d ---> %s\n", funcionario.codigo, funcionario.nome);
    printf("IRS ---> %f\n", funcionario.irs);
    printf("Segurança Social ---> %f\n", funcionario.ss);
    printf("\nSalário: %f\n", funcionario.salLiquido);
    
}

void listarIrsSSSalarios(Funcionarios funcionarios) {
	if (funcionarios.contador > 0) {
        int i;
		for (i = 0; i < funcionarios.size; i++) {
			if (funcionarios.array[i].apagado == 0)
			{
				printf("-----------------------------\n");
				imprimirIrsSSSalarios(funcionarios.array[i]);
			}

        }
    } else {
        printf(ERRO_LISTA_VAZIA);
    }
}

/**
 * Esta função permite listar os prémios ganhos pelos funcionarios
 * @param funcionario
 */
void imprimirPremios(Funcionario funcionario) {
    printf("%d ---> %s\n", funcionario.codigo, funcionario.nome);
    printf("Horas Estras(€) ---> %f\n", funcionario.horasextras);
    printf("Diuturnidades(€) ---> %f\n", funcionario.diuturnidades);
    printf("Bónus(€) ---> %f\n", funcionario.bonus);
    printf("Prémios de produtividade(€) ---> %f\n", funcionario.premio);
}
void listarPremios(Funcionarios funcionarios) {
	if (funcionarios.contador > 0) {
		int i;
		for (i = 0; i < funcionarios.size; i++) {
			if (funcionarios.array[i].apagado == 0)
			{
				printf("-----------------------------\n");
				imprimirPremios(funcionarios.array[i]);
			}
        }
    } else {
        printf(ERRO_LISTA_VAZIA);
    }
}
void imprimirIdades(Funcionario funcionario) {
   
}
/**
 * Esta função permite imprimir a média de idades
 * @param funcionarios
 */
void listarIdades(Funcionarios funcionarios) {
    int soma=0;
	if (funcionarios.contador > 0) {
		int i;
		for (i = 0; i < funcionarios.size; i++) {
			if (funcionarios.array[i].apagado == 0)
			{
				printf("-----------------------------\n");
				soma = soma + funcionarios.array[i].idade;
				imprimirIdades(funcionarios.array[i]);
			}
        }
        int media= soma/funcionarios.contador;
        printf("A média de idades da empresa é: %d", media);
    } else {
        printf(ERRO_LISTA_VAZIA);
    }
}
