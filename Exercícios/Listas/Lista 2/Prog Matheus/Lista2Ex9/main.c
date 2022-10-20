#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int info;
    struct lista *prox;
};

struct lista *crialsec(int n)
{
    struct lista *p, *ini, *aux;
    int i, valor;
    ini=NULL;
    for(i=0;i<=n;i++)
    {
        printf("\n informe valor: ");
        scanf("%d", &valor);
        p=(struct lista *)malloc(sizeof(struct lista));
        p->info=valor;
        if(!ini)
        {
            p->prox=p;
            ini=p;
        }
        else{
            p->prox=ini;
            aux->prox=p;
        }
        aux=p;
    }
    return(p);
}

struct lista *intersec(struct lista *p, struct lista *q)
{
    struct lista *l1, *l2, *ini, *aux, *t;
    int i, valor;
    ini=NULL;
    l1=p;
    l2=q;
    while(l2->prox!=q)
    {
        l1=p->prox;
        while(l1->prox!=p)
        {
            if(l1->info==l2->info)
            {
                t=(struct lista *)malloc(sizeof(struct lista));
                t->info=l1->info;
                if(!ini)
                {
                    t->prox=t;
                    ini=t;
                }
                else{
                    t->prox=ini;
                    aux->prox=t;
                }
                aux=t;
            }
            l1=l1->prox;
        }
        l2=l2->prox;
    }
    return(t);
}

struct lista *unir(struct lista *p1, struct lista *p2)
{
    struct lista *q, *t;
    if(!p1)
        return(p2);
    if(!p2)
        return(p1);
    else{
        q=p1;
        while(q->prox!=p1)
            q=q->prox;
        t=p2;
        while(t->prox!=p2)
            t=t->prox;
        t->prox=p1;
        q->prox=p2;
    }
}
