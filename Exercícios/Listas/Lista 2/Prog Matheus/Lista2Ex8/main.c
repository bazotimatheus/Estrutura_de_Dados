#include <stdio.h>
#include <stdlib.h>

int contanos(struct lista *p)
{
    struct lista *q;
    int cont=1;
    if(!p)
        return(0);
    else{
        q=p;
        while(q->prox!=p)
        {
            q=q->prox;
            cont++;
        }
        return(cont);
    }
}

struct lista *corta(struct lista *p)
{
    struct lista *q, *t, *r;
    int cont=1, k;
    k=contanos(p);
    q=p;
    t=p->prox;
    while(cont!=(k/2))
    {
        q=q->prox;
        t=t->prox;
        cont++;
    }
    r=p;
    while(r->prox!=p)
        r=r->prox;
    r->prox=t;
    q->prox=p;
    return(p);
}
