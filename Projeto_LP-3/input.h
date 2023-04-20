#ifndef INPUT_H
#define INPUT_H

int obterInteiro(int minValor, int maxValor, char *msg);

float obterFloat(float minValor, float maxValor, char *msg);

long obterLong(long minValor, long maxValor, char *msg);

char obterChar(char *msg);

void lerString(char *string, unsigned int tamanho, char *msg);

#endif /* INPUT_H */