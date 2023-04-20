#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable : 4996)

#include "funcionarios.h"
#include "input.h"
#include "IRS.h"
#include "Tabelas.h"
#include "Listagens.h"
#define FILENAME "informacoes.bin"


 void escreverFicheiro(Funcionarios funcionarios) {

    FILE *fp = fopen(FILENAME, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }
    else {  
		if (funcionarios.size > 0)
		{
		    fwrite(&funcionarios, sizeof (Funcionarios), 1, fp);
	       	    fwrite(funcionarios.array, sizeof(Funcionario), funcionarios.size, fp);
		}

        fclose(fp);
    }
}

 void carregaFicheiro(Funcionarios *funcionarios) {

	 FILE *fp = fopen(FILENAME, "rb");
	 if (fp == NULL) {
		 return;
	 }
	 else {
		 if (fread(funcionarios, sizeof(Funcionarios), 1, fp) == 1)
		 {
			 funcionarios->array = NULL;
			 funcionarios->size = 0;
			 Funcionario f;
			 /* Attempt to read */
			 while (fread(&f, sizeof(Funcionario), 1, fp) == 1) {
				 funcionarios_Add(funcionarios, f);
			 }
		 }
		 fclose(fp);
	 }
 }

int main() {
    Funcionarios funcionarios;
    int opcao, x, jp;
    char *current_day, *current_time, guardar, carregar;
    float valorSS[3];
    struct IRS irs;

	//inicializa array dinâmico
	funcionarios_Init(&funcionarios);

    //carrega os valores da tabela
    irs.NC.nLinhas = ler_csv(FILEPATH_NC, irs.NC.values);
    irs.CUT.nLinhas = ler_csv(FILEPATH_CUT, irs.CUT.values);
    irs.CDT.nLinhas = ler_csv(FILEPATH_CDT, irs.CDT.values);

    
    strcpy(irs.NC.filename, FILEPATH_NC);
    strcpy(irs.CUT.filename, FILEPATH_CUT);
    strcpy(irs.CDT.filename, FILEPATH_CDT);


    if (ler_csv_SS(FILEPATH_SS, valorSS) == 0) {
        printf("Erro ao ler tabela SS");
        return 1;
    }
        printf("Deseja carregar informações inseridas? (S-Sim  N-Não)\n");
                scanf(" %c", &carregar);
                if (carregar == 'S' || carregar == 's') {

               carregaFicheiro(&funcionarios);

                }
                else{

                }
          printf("|---------------------------|\n");
          printf("|          J&V LDA          |\n");
          printf("|---------------------------|\n");

    do {
        printf("\n|---------------------------|\n");
          printf("|            MENU           |\n");
          printf("|---------------------------|");
        printf("\n|   1 - Inserir             |");
        printf("\n|   2 - Procurar            |");
        printf("\n|   3 - Editar              |");
        printf("\n|   4 - Remover             |");
        printf("\n|   5 - Listar              |");
        printf("\n|   6 - Cálculo Salarial    |");
        printf("\n|   7 - Tabelas             |");
        printf("\n|   8 - Listagens           |");
        printf("\n|   0 - Sair                |");
        printf("\n|---------------------------|");
        printf("\nNº Funcionarios Inseridos: %d", funcionarios.contador);

        printf("\nOpcão: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                      printf("Deseja guardar as informações inseridas? (S-Sim  N-Não)\n");
                scanf(" %c", &guardar);
                if (guardar == 'S' || guardar == 's') {
               
               escreverFicheiro(funcionarios);
                }
                else{
                    break;
                }
                break;
            case 1:
                inserirFuncionario(&funcionarios);
                break;
            case 2:
                procuraImprimeFuncionario(&funcionarios);
                break;
            case 3:
                atualizarFuncionarios(&funcionarios);
                break;
            case 4:
                removerFuncionarios(&funcionarios);
                break;
            case 5:
                listarFuncionarios(&funcionarios);
                break;
            case 6:
                calculoSalarial(&funcionarios, valorSS);
                break;
            case 7:
                imprimirAlterarTabela(&irs, valorSS);
                break;

            case 8:
                printf("|------------------------------|\n");
                printf("|  1- Listar Cargos            |\n");
                printf("|  2- Listar Generos           |\n");
                printf("|  3- Listar IRS/Salarios      |\n");
                printf("|  4- Premios Obtidos          |\n");
                printf("|  5- Média de Idades          |\n");
                printf("|------------------------------|\n");
                printf("Opção: ");
                scanf("%d", &jp);
                switch (jp) {
                    case 1:
                        listarCargo(funcionarios);
                        break;
                    case 2:
                        listarGenero(funcionarios);
                        break;
                    case 3:
                        listarIrsSSSalarios(funcionarios);
                        break;
                    case 4:
                        listarPremios(funcionarios);
                        break;
                    case 5:
                        listarIdades(funcionarios);
                        break;
                    default:
                        printf("\nOpcão invalida!");
                        break;
                }
            default:
                break;
        }
    } while (opcao != 0);
	
	free (funcionarios.array);
    return 0;
}