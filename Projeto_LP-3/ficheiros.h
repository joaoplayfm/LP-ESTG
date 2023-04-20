#ifndef FICHEIROS_H
#define FICHEIROS_H



#define MAX_COLUNAS				7
#define MAX_LINHAS				150
#define MAX_PATH				300
#define FILEPATH_NC				"tabelas/NC.csv"
#define FILEPATH_CUT				"tabelas/CUT.csv"
#define FILEPATH_CDT				"tabelas/CDT.csv"
#define FILEPATH_SS				"tabelas/ss.csv"
#define SEPARADOR_DECIMAL		','
#define SEPARADOR_CSV			';'
#define SUCCESS					1
#define NOT_SUCCESS				0

int ler_csv(const char *filename, float values[MAX_LINHAS][MAX_COLUNAS]);
int ler_csv_SS(const char *filename, float values[3]);
char obter_valor(int linha, int coluna, float *valor);
char altera_valor(const char *filename, int linha, int coluna, float valor);
#endif 

