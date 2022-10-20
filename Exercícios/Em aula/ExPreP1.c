#include<stdio.h>
#include<stdlib.h>
#define TAM 20

struct tpilha
{
    int topo;
    int pilha[TAM];
};

void criapilha(struct tpilha *ps)
{
    ps->topo=-1;
}

int empilha(struct tpilha *ps, int valor)
{
    if(ps->topo==TAM-1)
        return(0);
    ps->topo++;
    ps->pilha[ps->topo]=valor;
    return(1);
}

struct tfilac
{
    int ini, fim, cont;
    int filac[TAM];
};

void criafilac(struct tfilac *fc)
{
    fc->ini=0;
    fc->fim=-1;
    fc->cont=0;
}

int inserefc(struct tfilac *fc, int valor)
{
    if(fc->cont==TAM)
        return(0);
    fc->cont++;
    fc->fim=(fc->fim==TAM-1)?0:fc->fim+1;
    fc->filac[fc->fim]=valor;
    return(1);
}

struct tno
{
    int chave;
};

struct tlista
{
    int qtnos;
    struct tno lista[TAM];
};

void crialista(struct tlista *pl)
{
    pl->qtnos=0;
}

int inserelista(struct tlista *pl, int valor)
{
    if(pl->qtnos==TAM)
        return(0);
    pl->lista[pl->qtnos].chave=valor;
    pl->qtnos++;
    return(1);
}

struct tfilab
{
    int f;
    int r;
    int filab[TAM+1];
};

void criafilab(struct tfilab *fb)
{
    fb->r=0;
    fb->f=0;
}

int inserefb(struct tfilab *fb, int valor)
{
    if((fb->r+1)%(TAM+1)==fb->f)
        return(0);
    fb->r=(fb->r+1)%(TAM+1);
    fb->filab[fb->r]=valor;
    return(1);
}

main()
{
    struct tpilha p1;
    struct tfilac f1;
    struct tlista l1;
    struct tfilab f2;
    int i, menu, valor;
    criapilha(&p1);
    for(i=0;i<TAM;i++)
    {
        printf("\n valor: ");
        scanf("%d", &valor);
        empilha(&p1,valor);
    }
    printf("\n imprimindo p1...\n");
    for(i=0;i<TAM;i++)
        printf("\n\t%d",p1.pilha[i]);
    do
    {
        printf("\n 1- copia pilha p1 numa fila circular com contador f1;");
        printf("\n 2- copia pilha p1 numa lista sequencial l1;");
        printf("\n 3- copia pilha p1 numa fila circular com no bobo f2;");
        printf("\n 4- sair;\n\n ");
        scanf("%d", &menu);
        switch(menu)
        {
        case 1:
            criafilac(&f1);
            for(i=0;i<TAM;i++)
                inserefc(&f1,p1.pilha[i]);
            printf("\n imprimindo a fila circular com contador: ");
            for(i=0;i<TAM;i++)
                printf("\n\t%d", f1.filac[i]);
            printf("\n\n");
            break;
        case 2:
            crialista(&l1);
            for(i=0;i<TAM;i++)
                inserelista(&l1,p1.pilha[i]);
            printf("\n imprimindo a lista sequencial: ");
            for(i=0;i<TAM;i++)
                printf("\n\t%d", l1.lista[i]);
            printf("\n\n");
            break;
        case 3:
            criafilab(&f2);
            for(i=0;i<TAM;i++)
                inserefb(&f2,p1.pilha[i]);
            printf("\n imprimindo a fila circular com no bobo: ");
            for(i=0;i<TAM;i++)
                printf("\n\t%d", f2.filab[i]);
            printf("\n\n");
            break;
        case 4:
            printf("\n saindo...\n");
            break;
        default:
            printf("\n opcao invalida...\n");
            break;
        }
    }while(menu!=4);
}
