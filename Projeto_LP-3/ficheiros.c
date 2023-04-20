#include <stdio.h>
#include <stdlib.h>
#include "ficheiros.h"
#include <string.h>

#pragma warning (disable : 4996)
/**
 * carrega o .csv para matriz de valores
 * @param filename
 * @param values
 * @return nº de linhas lidas
 */
int ler_csv(const char *filename, float values[MAX_LINHAS][MAX_COLUNAS])
{
	char ch, tmp[20];

	int i = 0, iLinha = 0, iColuna =0;


	FILE *fp = fopen(filename, "r");

	if (fp == NULL)
		return (EXIT_FAILURE);

	while ((ch = getc(fp)) != EOF) {
		if (ch == SEPARADOR_CSV || ch == '\n')
		{
			tmp[i] = '\0';
			i = 0;	

			values[iLinha][iColuna++] = atof(tmp);

			if (iColuna == MAX_COLUNAS)
				iColuna = 0;
			if (ch == '\n')
				iLinha++;
		}
		else if(ch != '\r')
		{
			if (ch == SEPARADOR_DECIMAL)
				ch = '.';
			tmp[i++] = ch;
		}
	}
	
	fclose(fp);

	return iLinha;
}

int ler_csv_SS(const char *filename, float values[3])
{
    char data[20];
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
            return 0;

    int i=0;
    while (fgets(data, 20, fp) != NULL) {
        
        for(int i=0; i<strlen(data); i++)
            if (data[i] == SEPARADOR_DECIMAL)
		data[i] = '.';
        
        values[i++] = atof(data);
    }

    fclose(fp);
    return 1;
}

/**
 * obtem o valor da tabela na posição da linha x, coluna y
 * @param linha
 * @param coluna
 * @param valor
 * @return 1 se sucesso, 0 se falhou
 */
char obter_valor(int linha, int coluna, float *valor)
{
	char ch, tmp[20];
	int i = 0, iLinha = 0, iColuna = 0;


	FILE *fp = fopen(FILEPATH_NC, "r");
        FILE *fp1 = fopen(FILEPATH_CUT, "r");
        FILE *fp2 = fopen(FILEPATH_CDT, "r");
         FILE *fp3 = fopen(FILEPATH_SS, "r");

	if (fp == NULL)
		return (EXIT_FAILURE);

	while ((ch = getc(fp)) != EOF && iLinha<=linha) {

		if ((ch == SEPARADOR_CSV || ch == '\n') && iLinha == linha)
		{
			tmp[i] = '\0';
			i = 0;

			if (iLinha == linha && iColuna == coluna)
			{
				*valor= atof(tmp);
                                fclose(fp);
				return SUCCESS;
			}

			iColuna++;
			if (iColuna == MAX_COLUNAS)
				iColuna = 0;

		}
		else if (iLinha == linha && ch != '\r')
		{
			if (ch == SEPARADOR_DECIMAL)
				ch = '.';
			tmp[i++] = ch;
		}

		if (ch == '\n')
			iLinha++;
	}

	fclose(fp);
        fclose(fp1);
        fclose(fp2);
         fclose(fp3);

	return NOT_SUCCESS;
}

/**
 * altera o valor da tabela na posição da linha x, coluna y
 * @param filename
 * @param linha
 * @param coluna
 * @param valor
 * @return 1 se sucesso, 0 se falhou
 */
 char altera_valor(const char *filename, int linha, int coluna, float valor)
 {
	char ch, tmp[20];
	char valorStr[20];
	int i=0, len=0, iLinha=0, iColuna=0, casas_decimais=2;


	FILE *fp = fopen(filename, "r+");

	if (fp == NULL)
		return (EXIT_FAILURE);

	while ((ch = getc(fp)) != EOF && iLinha <= linha) {

		if ((ch == SEPARADOR_CSV || ch == '\n') && iLinha == linha)
		{
			tmp[i] = '\0';
			i = 0;

			if (iLinha == linha && iColuna == coluna)
			{
				//recua no ficheiro x caracteres
				len = strlen(tmp);
				fseek(fp,-len-1, SEEK_CUR);

				//convert float para string, com o tamanho igual ao que estava no ficheiro
				sprintf(valorStr, "%*.*f", strlen(tmp), casas_decimais, valor);

				//substitui o '.' pelo SEPARADOR_DECIMAL
				for (int j = 0; j < len; j++)
					if (tmp[j] == '.')
						tmp[j] == SEPARADOR_DECIMAL;
				//substitui pelo novo valor
				fputs(valorStr, fp);
				fclose(fp);
                                
				return SUCCESS;
			}

			if (iColuna++ == MAX_COLUNAS)
				iColuna = 0;

		}
		else if (iLinha == linha && ch != '\r')
		{
			if (ch == SEPARADOR_DECIMAL)
				ch = '.';
			tmp[i++] = ch;
		}

		if (ch == '\n')
			iLinha++;
	}

	fclose(fp);
	return NOT_SUCCESS;
}