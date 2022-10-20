#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int info;
    struct lista *prox;
};

struct lista *cria(int n)
{
    struct lista *ini, *aux, *p;
    int i, valor;
    ini=NULL;
    for(i=1;i<=n;i++)
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

void imprime(struct lista *p)
{
    if(!p)
    {
        printf("\n lista vazia...\n");
        return;
    }
    while(p->prox!=p)
    {
        printf("\t%d",p->info);
        p=p->prox;
    }
}

int contaNos(struct lista *p)
{
    int cont;
    if(!p)
        return(0);
    else{
        cont=1;
        while(p->prox!=p)
        {
            p=p->prox;
            cont++;
        }
        return(cont);
    }
}

struct lista *removek(struct lista *p, int k)
{
    struct lista *q, *t;
    int cont;
    if(k==1)
    {
        if(p->prox==p)
        {
            free(p);
            return(NULL);
        }
        else{
            q=p->prox;
            p->prox=q->prox;
            free(q);
            return(p);
        }
        free(q);
        return(p);
    }
    else{
        q=p->prox;
        t=p;
        cont=1;
        while(cont!=k)
        {
            t=q;
            q=q->prox;
            cont++;
        }
        t->prox=q->prox;
        if(q!=p)
        {
            free(q);
            return(p);
        }
        else{
            free(q);
            return(t);
        }
    }
}

struct lista *copia(struct lista *p)
{
    struct lista *q, *copia, *ini, *aux;
    q=p;
    ini=NULL;
    while(q->prox!=p)
    {
        copia=(struct lista *)malloc(sizeof(struct lista));
        copia->info=q->info;
        if(!ini)
        {
            copia->prox=copia;
            ini=copia;
        }
        else{
            copia->prox=ini;
            aux->prox=copia;
        }
        aux=copia;
        q=q->prox;
    }
    return(ini);
}

struct lista *insereAntesDek(struct lista *p, int k, int valor)
{
    struct lista *q, *t;
    int cont;
    q=(struct lista *)malloc(sizeof(struct lista));
    q->info=valor;
    if(k==1)
    {
        q->prox=p->prox;
        p->prox=q;
    }
    else{
        cont=1;
        t=p;
        while(cont!=k)
        {
            t=t->prox;
            cont++;
        }
        q->prox=t->prox;
        t->prox=q;
    }
    return(p);
}

struct istastruct
int main()
{
    struct lista *p, *pk, *cp;
    char m;
    int n, k, valor;
    printf("\n insira o numero de nos: ");
    scanf("%d", &n);
    printf("\n criando a lista...");
    p=cria(n);
    printf("\n imprimindo a lista...\n\n");
    imprime(p);
    printf("\n a lista tem %d nos...\n", contaNos(p));
    printf("\n insira uma posicao para ser retirado um elemento: ");
    scanf("%d", &k);
    printf("\n removendo o k-esimo elemento...\n");
    pk=removek(p,k);
    printf("\n imprimindo a lista sem o k-esimo elemento...\n\n");
    imprime(pk);
    printf("\n criando copia da lista original...\n");
    cp=copia(p);
    printf("\n imprimindo a copia da lista...\n");
    imprime(cp);
    printf("\n insira o valor: ");
    scanf("%d", &valor);
    printf("\n insira a posicao: ");
    scanf("%d", &k);
    p=insereAntesDek(p,k,valor);
    printf("\n imprimindo a nova lista...\n");
    imprime(p);
}
