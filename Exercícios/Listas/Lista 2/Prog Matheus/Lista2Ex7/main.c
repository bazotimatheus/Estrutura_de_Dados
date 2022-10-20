#include <stdio.h>
#include <stdlib.h>

struct lista *circular(struct lista *p)
{
    struct lista *q;
    if(!p)
        return(NULL);
    if(!p->prox)
    {
        p->prox=p;
        return(p);
    }
    else
    {
        q=p;
        while(q->prox)
            q=q->prox;
        q->prox=p;
        return(p);
    }
}
