#include <stdio.h>
#include <stdlib.h>
#define TAM 10

struct tpilha
{
    int topo;
    int pilha[TAM];
};

void inicializa(struct tpilha *ps)
{
    ps->topo=-1;
}

int pilha_vazia(struct tpilha *ps)
{
    if(ps->topo==-1)
        return(1);
    return(0);
}

int pilha_cheia(struct tpilha *ps)
{
    if(ps->topo==TAM-1)
        return(1);
    return(0);
}

int empilha(struct tpilha *ps,int valor)
{
    if(pilha_cheia(ps))
        return (0);
    ps->topo++;
    ps->pilha[ps->topo]=valor;
    return (1);
}

int desempilha(struct tpilha *ps)
{
    int y;
    if(pilha_vazia(ps))
        return (0);
    y=ps->pilha[ps->topo];
    ps->topo--;
    return (y);
}

int main()
{
    struct tpilha *p;
    int valor, aux;
    inicializa(p);
    printf("\n Insira o valor em decimal: ");
    scanf("%d", &valor);
    printf("\n O valor %d em binario e:\n\n", valor);
    do
    {
        aux=valor%2;
        empilha(p,aux);
        valor=valor/2;
    }while(p->topo!=-1);
    while(p->topo!=-1)
    {
        aux=desempilha(p);
        printf("%d\t", aux);
    }
}
