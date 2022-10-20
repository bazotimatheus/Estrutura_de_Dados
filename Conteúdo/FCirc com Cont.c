//Fila Circular com Contador

#include <stdio.h>
#include <stdlib.h>
#define TAM 100

struct tfila
{
    int ini;
    int fim;
    int cont;
    int fila[TAM];
};

int fila_vazia(struct tfila *pf)
{
    if(pf->cont==0)
        return(1);
    return(0);
}

int fila_cheia(struct tfila *pf);
{
    if(pf->cont==TAM)
        return(1);
    return(0);
}

int insere_fila(struct tfila *pf)
{
    if(fila_cheia(pf))
        return(0);
    pf->cont++;
    pf->fim=(pf->fim==TAM-1)?0:pf->fim+1;
    pf->fila[pf->fim]=valor;
    return(1);
}

int remove_fila(struct tfila *pf, int *elem)
{
    if(fila_vazia(pf))
        return(0);
    pf->cont--;
    *elem=pf->fila[pf->ini];
    pf->ini=(pf->ini==TAM-1)?0:pf->ini+1;
    return(1);
}

