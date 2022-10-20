#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int info;
    struct lista *prox;
};

struct lista *cria(int n)
{
    struct lista *ini, *ult, *p;
    int i, valor;
    ini=ult=NULL;
    for(i=1;i<=n;i++)
    {
        printf("\n informe um valor: ");
        scanf("%d",&valor);
        p=(struct lista *)malloc(sizeof(struct lista));
        p->info=valor;
        p->prox=NULL;
        if(ult)
            ult->prox=p;
        else
            ini=p;
        ult=p;
    }
    return(ini);
}

void imprime(struct lista *p)
{
    if(!p)
        return;
    else{
        while(p)
        {
            printf("\t%d",p->info);
            p=p->prox;
        }
    }
}

