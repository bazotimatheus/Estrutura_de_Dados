//Escreva um programa que leia 10 números inteiros e insira-os numa lista sequencial não ordenada sem repetição l1. Imprima a lista. Em seguida, inverta os elementos da lista usando uma pilha p1 como estrutura auxiliar. Imprima l1 invertida.

#include<stdio.h>
#define TAM 5

//Funções para a Lista Sequencial Não Ordenada

struct tno{
	int chave;
};

struct tlista{
	int qtnos;
	struct tno lista[TAM];
};

void inicializalista(struct tlista *pl)
{
	pl->qtnos=0;
}

int lista_vazia(struct tlista *pl)
{
	if(pl->qtnos==0)
		return(1);
	return(0);
}

int lista_cheia(struct tlista *pl)
{
	if(pl->qtnos==TAM)
		return(1);
	return(0);
}

void percurso(struct tlista *pl)
{
	int i;
	for(i=0;i<pl->qtnos;i++)
		printf("%d\t",pl->lista[i].chave);
}

int busca(struct tlista *pl, int x)
{
	int i;
	for(i=0;i<pl->qtnos;i++)
	{
		if(x==pl->lista[i].chave)
			return(i);
	}
	return(-1);
}

int inserelista(struct tlista *pl, int valor)
{
	int i;
	if(lista_cheia(pl))
		return(-1);
	i=busca(pl,valor);
	if(i>=0)
		return(0);
	pl->lista[pl->qtnos].chave=valor;
	pl->qtnos++;
	return(1);
}

int removelista(struct tlista *pl, int valor)
{
	int i, y;
	if(lista_vazia(pl))
		return(-1);
	i=busca(pl,valor);
	if(i<0)
		return(0);
	pl->qtnos--;
	y=pl->lista[pl->qtnos].chave;
	pl->lista[i].chave=pl->lista[pl->qtnos].chave;
	return(y);
}

//Funções para a Pilha auxiliar

struct tpilha{
	int topo;
	int pilha[TAM];
};

void inicializapilha(struct tpilha *ps)
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

int empilha(struct tpilha *ps, int valor)
{
	if(pilha_cheia(ps))
		return(0);
	ps->topo++;
	ps->pilha[ps->topo]=valor;
	return(1);
}

int desempilha(struct tpilha *ps)
{
	int y;
	if(pilha_vazia(ps))
		return(0);
	y=ps->pilha[ps->topo];
	ps->topo--;
	return(y);
}

main()
{
	struct tlista pl;
	struct tpilha ps;

	int valor, i, m;

	inicializalista(&pl);
	inicializapilha(&ps);

	for(i=0;i<TAM;i++)
	{
		printf("\nInsira um valor:\t");
		scanf("%d",&valor);
		inserelista(&pl,valor);
	}

	printf("\nImprimindo a lista.\n\n");
	percurso(&pl);

    for(i=0;i<TAM;i++)
    {
        empilha(&ps,removelista(&pl,pl.lista[i].chave));
    }

    printf("\n\nImprimindo pilha.\n");

    for(i=0;i<TAM;i++)
    {
        printf("\n%d",ps.pilha[i]);
    }

    for(i=0;i<TAM;i++)
    {
        inserelista(&pl,desempilha(&ps));
    }

    printf("\n\nImprimindo lista invertida.\n\n");
    percurso(&pl);
    printf("\n");
}
