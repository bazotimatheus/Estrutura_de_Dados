#include <stdio.h>
#define TAM 20

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
    printf("\nRemovendo da pilha.");
    y=ps->pilha[ps->topo];
    ps->topo--;
    return (y);
}

int topo_pilha(struct tpilha *ps)
{
    printf("\nElemento no topo da pilha: %d", ps->pilha[ps->topo]);
}

void imprime_pilha(struct tpilha *ps)
{
    int i;
    if(pilha_vazia(ps))
    {
        printf("\nA pilha esta vazia");
        return(0);
    }
    printf("\nImprimindo a pilha.\n\n");
    for(i=0;i<=ps->topo;i++)
        printf("%d\t", ps->pilha[i]);
}

int esvaziar_pilha(struct tpilha *ps)
{
    int y, i;
    printf("\nEsvaziando a pilha.\n");
    if(pilha_vazia(ps))
        return 0;
    for(i=-1;i<=ps->topo;ps->topo--)
    {
        y=ps->pilha[ps->topo];
    }
    return(y);
}

void main(void)
{
    struct tpilha p;
    int valor, menu=0, cont=0;

    inicializa(&p);

    while(menu!=6)
    {
        printf("\n\n1 - Inserir na pilha\n2 - Imprimir a pilha\n3 - Remover da pilha\n4 - Exibir elemento do topo da pilha\n5 - Esvaziar a pilha\n6 - Sair\n\n");
        scanf("%d", &menu);
        switch(menu)
        {
        case 1:
            printf("\nInforme um valor: ");
            scanf("%d", &valor);
            empilha(&p,valor);
            cont++;
            break;
        case 2:

            imprime_pilha(&p);
            break;
        case 3:
            desempilha(&p);
            cont--;
            break;
        case 4:
            topo_pilha(&p);
            break;
        case 5:
            esvaziar_pilha(&p);
            break;
        default:
            printf("\nO programa sera encerrado.\n\n");
            menu=6;
        }
    }
}
