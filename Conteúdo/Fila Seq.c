//Fila Sequencial

#include <stdio.h>
#include <stdlib.h>
#define TAM 100

struct tfila
{
    int f, r;
    int fila[TAM];
};

void inicializa(struct tfila *pf)
{
    pf->r=0;
    pf->f=0;
}

int fila_vazia(struct tfila *pf)
{
    if(pf->f==pf->r)
        return(1);
    return(0);
}

int fila_cheia(struct tfila *pf)
{
    if((pf->r+1)%TAM==pf->f)
        return(1);
    return(0);
}

int insere_fila(struct tfila *pf, int valor)
{
    if(fila_cheia(pf))
        return(0);
    pf->r=(pf->r+1)%TAM;
    pf->fila[pf->r]=valor;
    return(1);
}

int remove_fila(struct tfila *pf,int *elem);
{
    if(fila_vazia(pf))
        return(0);
    pf->f=(pf->f+1)%TAM;
    *elem=pf->fila[pf->f];
    return(1);
}

