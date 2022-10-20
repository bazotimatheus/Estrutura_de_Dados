#include <stdio.h>
#define TAM 5

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

int percurso(struct tlista *pl)
{
	int i;
	if(pl->qtnos==0)
    {
        printf("\nA lista esta vazia.\n");
        return(0);
    }
	printf("\nImprimindo a lista.\n\n");
	for(i=0;i<pl->qtnos;i++)
		printf("%d\t",pl->lista[i].chave);
    return(1);
}

int busca(struct tlista *pl, int x)
{
	int i;
	for(i=0;i<pl->qtnos;i++)
	{
		if(x==pl->lista[i].chave)
			return(i+1);
	}
	return(-1);
}

int inserelista1(struct tlista *pl)
{
	int i, valor;
	if(lista_cheia(pl))
		return(-1);
    printf("\nInsira um valor: ");
    scanf("%d", &valor);
	i=busca(pl,valor);
	if(i>=0)
		return(0);
	pl->lista[pl->qtnos].chave=valor;
	pl->qtnos++;
	return(1);
}

int inserelista2(struct tlista *pl,int valor)
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

int esvaziarlista(struct tlista *pl)
{
    int i, y;
    if(lista_vazia(pl))
    {
        printf("\nA lista ja esta vazia.\n");
        return(0);
    }
    for(;pl->qtnos!=0;pl->qtnos--)
    {
        pl->lista[pl->qtnos].chave=NULL;
    }
    return(1);
}

main()
{
    struct tlista pl1, pl2;
    int i, menu, valor;

    inicializalista(&pl1);

    do
    {
        printf("\n\nEDITOR DE LISTA\n\n1-Inserir na lista\n2-Imprimir a lista\n3-Remover um elemento\n4-Mostrar posicao de um elemento\n5-Criar copia da lista\n6-Esvaziar a lista\n7-Sair\n\nOPCAO: ");
        scanf("%d", &menu);

        switch(menu)
        {
        case 1:
            inserelista1(&pl1);
            break;
        case 2:
            percurso(&pl1);
            break;
        case 3:
            printf("\nInsira o valor que sera retirado da lista.\n");
            scanf("%d", &valor);
            if(removelista(&pl1,valor)==0)
                printf("\nO valor nao esta na lista.\n");
            else
                removelista(&pl1,valor);
            break;
        case 4:
            printf("\nInsira o valor procurado.\n");
            scanf("%d", &valor);
            if(busca(&pl1,valor)==-1)
                printf("\nO valor nao esta na lista.\n");
            else
                printf("\nO valor requerido esta na posicao %d.",busca(&pl1,valor));
            break;
        case 5:
            inicializalista(&pl2);
            printf("\nCopiando a lista em outra.\n");
            for(i=0;i<pl1.qtnos;i++)
            {
                inserelista2(&pl2,pl1.lista[i].chave);
            }
            percurso(&pl2);
            break;
        case 6:
            esvaziarlista(&pl1);
            break;
        case 7:
            printf("\nFIM DO PROGRAMA\n\n");
            break;
        default:
            printf("\nValor nao valido. Tente novamente.\n");
            break;
        }
    }while(menu!=7);
}
