

#ifndef IRS_H
#define IRS_H
#include "ficheiros.h"

struct Tabela
{
    float values[MAX_LINHAS][MAX_COLUNAS];
    int nLinhas;
    char filename[MAX_PATH];
};

struct IRS
{
    struct Tabela NC;
    struct Tabela CUT;
    struct Tabela CDT;
};

#endif /* IRS_H */

