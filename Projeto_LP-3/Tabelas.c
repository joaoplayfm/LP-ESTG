#include <stdio.h>
#include <stdlib.h>
#include "IRS.h"
#include "Tabelas.h"
#include "ficheiros.h"

#pragma warning (disable : 4996)

/**
 * Permite alterar as tabelas
 * @param t
 */
void alteraTabela(struct Tabela *t)
{
    int linhaAlterar=-1;
    
    printf("Qual o nº linha que pretende alterar: ");
    scanf("%d", &linhaAlterar);

    if(linhaAlterar>=0)
    {               
        printf("Novo Salário: ");
        scanf("%f", &t->values[linhaAlterar][0]);
        altera_valor(t->filename, linhaAlterar, 0, t->values[linhaAlterar][0]);
        printf("Que taxa de 0 dependentes: ");
        scanf("%f", &t->values[linhaAlterar][1]);
        altera_valor(t->filename, linhaAlterar, 1, t->values[linhaAlterar][1]);
        printf("Que taxa de 1 dependentes: ");
        scanf("%f", &t->values[linhaAlterar][2]);
        altera_valor(t->filename, linhaAlterar, 2, t->values[linhaAlterar][2]);
        printf("Que taxa de 2 dependentes: ");
        scanf("%f", &t->values[linhaAlterar][3]);
        altera_valor(t->filename, linhaAlterar, 3, t->values[linhaAlterar][3]);
        printf("Que taxa de 3 dependentes: ");
        scanf("%f", &t->values[linhaAlterar][4]);
        altera_valor(t->filename, linhaAlterar, 4, t->values[linhaAlterar][4]);
        printf("Que taxa de 4 dependentes: ");
        scanf("%f", &t->values[linhaAlterar][5]);
        altera_valor(t->filename, linhaAlterar, 5, t->values[linhaAlterar][5]);
        printf("Que taxa de 5/+ dependentes: ");
        scanf("%f", &t->values[linhaAlterar][6]);
        altera_valor(t->filename, linhaAlterar, 6, t->values[linhaAlterar][6]);
    }
    else {
        printf("Registo não encontrado\n");
    }
}

/**
 * Permite imprimir as tabelas relativas ao IRS
 * @param t
 */
void imprimirTabela(struct Tabela t) 
{
        printf("|lin|nsalario|0depe|1depe|2depe|3depe|4depe|5/+dp|\n");
        printf("|---|--------|-----|-----|-----|-----|-----|-----|\n");
    for (int j = 0; j < t.nLinhas; j++)
        printf("|%3d|%8.2f|%0.3f|%0.3f|%0.3f|%0.3f|%0.3f|%0.3f|\n",j, t.values[j][0], t.values[j][1], t.values[j][2], t.values[j][3], t.values[j][4], t.values[j][5], t.values[j][6]);
        printf("|---|--------|-----|-----|-----|-----|-----|-----|\n");
}

/**
 * Permite imprimir a tabela relativas à Segurança Social
 * @param ss
 */
void imprimirTabelaSS(float ss[3]) 
{
    //Imprime tabela SS toda
    printf("|l3depe|4depe|5/+dp|\n");
    printf("%0.3f\n", ss[0]);
    printf("%0.3f\n", ss[1]);
    printf("%0.3f\n", ss[2]);

}

/**
 * Permite alterar a tabela relativa à Segurança Social
 * @param ss
 */
void alteraTabelaSS(float ss[3]){
    
        printf("Taxa Administrador: ");
        scanf("%f", &ss[0]);
        altera_valor(FILEPATH_SS, 0, 0, ss[0]);
        printf("Taxa Chefe: ");
        scanf("%f", &ss[1]);
        altera_valor(FILEPATH_SS, 1, 0, ss[1]);
        printf("Taxa Empregado: ");
        scanf("%f", &ss[2]);
        altera_valor(FILEPATH_SS, 2, 0, ss[2]);
}

/**
 * Permite aceder ao menu, onde é possivel imprimir e alterar todas as tabelas
 * @param valores
 * @param ss
 */
void imprimirAlterarTabela(struct IRS *valores, float ss[3]) 
{
    int x;
    printf("|------------------------------|\n");
    printf("|  1- Imprimir Tabela IRS NC   |\n");
    printf("|  2- Imprimir Tabela IRS CUT  |\n");
    printf("|  3- Imprimir Tabela IRS CDT  |\n");
    printf("|  4- Alterar Tabela IRS NC    |\n");
    printf("|  5- Alterar Tabela IRS CUT   |\n");
    printf("|  6- Alterar Tabela IRS CDT   |\n");
    printf("|  7- Imprimir Tabela SS       |\n");
    printf("|  8- Alterar Tabela SS        |\n");
    printf("|------------------------------|\n");
    printf("Opcão: ");
    scanf("%d", &x);
    switch (x)
    {
        case 1:
            imprimirTabela(valores->NC);
            break;
        case 2:
            imprimirTabela(valores->CDT);
            break;
            case 3:
            imprimirTabela(valores->CDT);
            break;
             case 4:
                alteraTabela(&valores->NC);
            break;
            case 5:
                alteraTabela(&valores->CDT);
                break;
            case 6:
                alteraTabela(&valores->CUT);
                break;
            case 7:
                imprimirTabelaSS(ss);
                break;
            case 8:
                alteraTabelaSS(ss);
                break;
        default:
            break;
    }
}

